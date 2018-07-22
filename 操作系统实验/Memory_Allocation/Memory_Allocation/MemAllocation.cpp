
#include <iostream>
#include <fstream>
#include <thread>
#include <functional>
#include <vector>
#include <exception>
#include <windows.h>
using namespace std;

typedef struct operation{				//一次内存操作
	int time;//起始时间
	int block;//内存页数
	int oper;//操作
	int protection;//权限
}Operation;

typedef struct trace {					//跟踪每次分配活动的数据结构
	LPVOID start;//起始地址
	long size;   //分配的大小
}Trace;

int main()
{
	auto semaphoreTrack = CreateSemaphore(NULL, 1, 1, NULL);
	auto semaphoreAlloc = CreateSemaphore(NULL, 1, 1, NULL);
	auto isEnd = false;

	//追踪线程
	auto threadTrack = thread([&]() {
		ofstream outfile("outMemState.txt");		//输出重定向
		
		auto outputInfo = [&]() {
			
			/*//以下一段显示系统信息，每次操作后系统信息不变
			//如要查看系统信息，可以取消注释
			
			SYSTEM_INFO systemInfo;					//获取系统信息
			GetSystemInfo(&systemInfo);
			//输出系统信息
			outfile << "dwActiveProcessorMask" << '\t' << systemInfo.dwActiveProcessorMask << endl;
			outfile << "dwAllocationGranularity" << '\t' << systemInfo.dwAllocationGranularity << endl;
			outfile << "dwNumberOfProcessors" << '\t' << systemInfo.dwNumberOfProcessors << endl;
			outfile << "dwOemId" << '\t' << systemInfo.dwOemId << endl;
			outfile << "dwPageSize" << '\t' << systemInfo.dwPageSize << endl;
			outfile << "dwProcessorType" << '\t' << systemInfo.dwProcessorType << endl;
			outfile << "lpMaximumApplicationAddress" << '\t' << systemInfo.lpMaximumApplicationAddress << endl;
			outfile << "lpMinimumApplicationAddress" << '\t' << systemInfo.lpMinimumApplicationAddress << endl;
			outfile << "wProcessorArchitecture" << '\t' << systemInfo.wProcessorArchitecture << endl;
			outfile << "wProcessorLevel" << '\t' << systemInfo.wProcessorLevel << endl;
			outfile << "wProcessorRevision" << '\t' << systemInfo.wProcessorRevision << endl;
			outfile << "wReserved" << '\t' << systemInfo.wReserved << endl;
			outfile << "************************************************************************************" << endl;
			
			*/

			MEMORYSTATUS status;					//获取内存状态数据
			GlobalMemoryStatus(&status);
			//输出内存信息
			outfile << "dwAvailPageFile" << '\t' << status.dwAvailPageFile << endl;
			outfile << "dwAvailPhys" << '\t' << status.dwAvailPhys << endl;
			outfile << "dwAvailVirtual" << '\t' << status.dwAvailVirtual << endl;
			outfile << "dwLength" << '\t' << status.dwLength << endl;
			outfile << "dwMemoryLoad" << '\t' << status.dwMemoryLoad << endl;
			outfile << "dwTotalPageFile" << '\t' << status.dwTotalPageFile << endl;
			outfile << "dwTotalPhys" << '\t' << status.dwTotalPhys << endl;
			outfile << "dwTotalVirtual" << '\t' << status.dwTotalVirtual << endl;
			outfile << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;

			
			

			/* //以下一段显示内存基本信息，每次操作后内存基本信息不变
			//如要查看内存基本信息，可以取消注释
			MEMORY_BASIC_INFORMATION memBasicInfo;//内存基本信息
			VirtualQuery(systemInfo.lpMinimumApplicationAddress, &memBasicInfo,
				sizeof(MEMORY_BASIC_INFORMATION));
			outfile << "AllocationBase" << '\t' << memBasicInfo.AllocationBase << endl;
			outfile << "AllocationProtect" << '\t' << memBasicInfo.AllocationProtect << endl;
			outfile << "BaseAddress" << '\t' << memBasicInfo.BaseAddress << endl;
			outfile << "Protect" << '\t' << memBasicInfo.Protect << endl;
			outfile << "RegionSize" << '\t' << memBasicInfo.RegionSize << endl;
			outfile << "State" << '\t' << memBasicInfo.State << endl;
			outfile << "Type" << '\t' << memBasicInfo.Type << endl;
			outfile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

			*/
		};

		while (!isEnd)
		{
			// 等待allocator一次内存分配活动结束
			WaitForSingleObject(semaphoreTrack, INFINITE);
			outputInfo();
			// 释放信号量通知allocator可以执行下一次内存分配活动
			ReleaseSemaphore(semaphoreAlloc, 1, NULL);
		}

		outfile.close();
	});


	//模拟分配线程
	auto threadAlloc = thread([&]() {
		ifstream in("opfile", ifstream::binary);

		Operation op;
		SYSTEM_INFO systemInfo;
		GetSystemInfo(&systemInfo);

		Trace traceArray[5];	//5种对应权限

		const vector<DWORD> protection = {
			PAGE_READONLY,
			PAGE_READWRITE,
			PAGE_EXECUTE,
			PAGE_EXECUTE_READ,
			PAGE_EXECUTE_READWRITE,
			PAGE_READONLY
		};

		size_t index = 0;		//对应操作
		const vector<function<void(void)>> action = {
			//保留一个区域
			[&]()
			{
				cout << "Reserve Now" << endl;

				traceArray[index].start = VirtualAlloc(NULL, op.block * systemInfo.dwPageSize,
					MEM_RESERVE, PAGE_NOACCESS);
				traceArray[index].size = op.block * systemInfo.dwPageSize;
				cout << "starting address:"
					<< traceArray[index].start << '\t' << "size:" << traceArray[index].size << endl;
			},

			//提交一个区域
			[&]()
			{
				cout << "Commit Now" << endl;

				traceArray[index].start = VirtualAlloc(traceArray[index].start,
					traceArray[index].size, MEM_COMMIT, protection[op.protection]);
				cout << "starting address:"
					<< traceArray[index].start << '\t' << "size:" << traceArray[index].size << endl;
			},

			//锁住一个区域
			[&]()
			{
				cout << "Lock Now" << endl;
				cout << "starting address:" << traceArray[index].start << '\t' <<
					"size:" << traceArray[index].size << endl;
				if (!VirtualLock(traceArray[index].start, traceArray[index].size))
				{
					cout << GetLastError() << endl;//GetLastError()函数返回错误号
				}	
			},

			// 解锁一个区域
			[&]()
			{
				cout << "Unlock Now" << endl;
				cout << "starting address:" << traceArray[index].start <<
					'\t' << "size:" << traceArray[index].size << endl;
				if (!VirtualUnlock(traceArray[index].start, traceArray[index].size))
				{
					cout << GetLastError() << endl;			//返回错误号
				}
			},

			// 回收一个区域
			[&]()
			{
				cout << "Decommit Now" << endl;
				cout << "starting address:" << traceArray[index].start << '\t' <<
					"size:" << traceArray[index].size << endl;
				if (!VirtualFree(traceArray[index].start, traceArray[index].size, MEM_DECOMMIT))
				{
					cout << GetLastError() << endl;			//返回错误号
				}
			},

			// 释放一个区域
			[&]()
			{
				cout << "Release Now" << endl;
				cout << "starting address:" << traceArray[index].start << '\t' <<
					"size:" << traceArray[index].size << endl;
				if (!VirtualFree(traceArray[index].start, 0, MEM_RELEASE))
				{
					cout << GetLastError() << endl;			//返回错误号
				}	
			}
		};

		try
		{
			while (1)
			{
				//等待tracker打印结束的信号量
				WaitForSingleObject(semaphoreAlloc, INFINITE);

				in.read(reinterpret_cast<char *>(&op), sizeof(Operation));
				if (in.eof())
				{
					isEnd = true;
					break;
				}
				if (op.protection == 0)
					index = 0;
				this_thread::sleep_for(chrono::milliseconds(op.time));
				//0-保留；1-提交；2-锁；3-解锁；4-回收；5-释放
				action[op.oper]();
				index++;

				//释放信号量通知tracker可以打印信息
				ReleaseSemaphore(semaphoreTrack, 1, NULL);
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
		}

		in.close();		//关闭写入文件

	});

	if (threadAlloc.joinable())
		threadAlloc.join();
	if (threadTrack.joinable())
		threadTrack.join();

	CloseHandle(semaphoreAlloc);
	CloseHandle(semaphoreTrack);

	system("pause");
	return 0;
}