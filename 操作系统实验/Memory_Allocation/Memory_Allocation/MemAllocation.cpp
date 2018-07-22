
#include <iostream>
#include <fstream>
#include <thread>
#include <functional>
#include <vector>
#include <exception>
#include <windows.h>
using namespace std;

typedef struct operation{				//һ���ڴ����
	int time;//��ʼʱ��
	int block;//�ڴ�ҳ��
	int oper;//����
	int protection;//Ȩ��
}Operation;

typedef struct trace {					//����ÿ�η��������ݽṹ
	LPVOID start;//��ʼ��ַ
	long size;   //����Ĵ�С
}Trace;

int main()
{
	auto semaphoreTrack = CreateSemaphore(NULL, 1, 1, NULL);
	auto semaphoreAlloc = CreateSemaphore(NULL, 1, 1, NULL);
	auto isEnd = false;

	//׷���߳�
	auto threadTrack = thread([&]() {
		ofstream outfile("outMemState.txt");		//����ض���
		
		auto outputInfo = [&]() {
			
			/*//����һ����ʾϵͳ��Ϣ��ÿ�β�����ϵͳ��Ϣ����
			//��Ҫ�鿴ϵͳ��Ϣ������ȡ��ע��
			
			SYSTEM_INFO systemInfo;					//��ȡϵͳ��Ϣ
			GetSystemInfo(&systemInfo);
			//���ϵͳ��Ϣ
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

			MEMORYSTATUS status;					//��ȡ�ڴ�״̬����
			GlobalMemoryStatus(&status);
			//����ڴ���Ϣ
			outfile << "dwAvailPageFile" << '\t' << status.dwAvailPageFile << endl;
			outfile << "dwAvailPhys" << '\t' << status.dwAvailPhys << endl;
			outfile << "dwAvailVirtual" << '\t' << status.dwAvailVirtual << endl;
			outfile << "dwLength" << '\t' << status.dwLength << endl;
			outfile << "dwMemoryLoad" << '\t' << status.dwMemoryLoad << endl;
			outfile << "dwTotalPageFile" << '\t' << status.dwTotalPageFile << endl;
			outfile << "dwTotalPhys" << '\t' << status.dwTotalPhys << endl;
			outfile << "dwTotalVirtual" << '\t' << status.dwTotalVirtual << endl;
			outfile << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;

			
			

			/* //����һ����ʾ�ڴ������Ϣ��ÿ�β������ڴ������Ϣ����
			//��Ҫ�鿴�ڴ������Ϣ������ȡ��ע��
			MEMORY_BASIC_INFORMATION memBasicInfo;//�ڴ������Ϣ
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
			// �ȴ�allocatorһ���ڴ��������
			WaitForSingleObject(semaphoreTrack, INFINITE);
			outputInfo();
			// �ͷ��ź���֪ͨallocator����ִ����һ���ڴ����
			ReleaseSemaphore(semaphoreAlloc, 1, NULL);
		}

		outfile.close();
	});


	//ģ������߳�
	auto threadAlloc = thread([&]() {
		ifstream in("opfile", ifstream::binary);

		Operation op;
		SYSTEM_INFO systemInfo;
		GetSystemInfo(&systemInfo);

		Trace traceArray[5];	//5�ֶ�ӦȨ��

		const vector<DWORD> protection = {
			PAGE_READONLY,
			PAGE_READWRITE,
			PAGE_EXECUTE,
			PAGE_EXECUTE_READ,
			PAGE_EXECUTE_READWRITE,
			PAGE_READONLY
		};

		size_t index = 0;		//��Ӧ����
		const vector<function<void(void)>> action = {
			//����һ������
			[&]()
			{
				cout << "Reserve Now" << endl;

				traceArray[index].start = VirtualAlloc(NULL, op.block * systemInfo.dwPageSize,
					MEM_RESERVE, PAGE_NOACCESS);
				traceArray[index].size = op.block * systemInfo.dwPageSize;
				cout << "starting address:"
					<< traceArray[index].start << '\t' << "size:" << traceArray[index].size << endl;
			},

			//�ύһ������
			[&]()
			{
				cout << "Commit Now" << endl;

				traceArray[index].start = VirtualAlloc(traceArray[index].start,
					traceArray[index].size, MEM_COMMIT, protection[op.protection]);
				cout << "starting address:"
					<< traceArray[index].start << '\t' << "size:" << traceArray[index].size << endl;
			},

			//��סһ������
			[&]()
			{
				cout << "Lock Now" << endl;
				cout << "starting address:" << traceArray[index].start << '\t' <<
					"size:" << traceArray[index].size << endl;
				if (!VirtualLock(traceArray[index].start, traceArray[index].size))
				{
					cout << GetLastError() << endl;//GetLastError()�������ش����
				}	
			},

			// ����һ������
			[&]()
			{
				cout << "Unlock Now" << endl;
				cout << "starting address:" << traceArray[index].start <<
					'\t' << "size:" << traceArray[index].size << endl;
				if (!VirtualUnlock(traceArray[index].start, traceArray[index].size))
				{
					cout << GetLastError() << endl;			//���ش����
				}
			},

			// ����һ������
			[&]()
			{
				cout << "Decommit Now" << endl;
				cout << "starting address:" << traceArray[index].start << '\t' <<
					"size:" << traceArray[index].size << endl;
				if (!VirtualFree(traceArray[index].start, traceArray[index].size, MEM_DECOMMIT))
				{
					cout << GetLastError() << endl;			//���ش����
				}
			},

			// �ͷ�һ������
			[&]()
			{
				cout << "Release Now" << endl;
				cout << "starting address:" << traceArray[index].start << '\t' <<
					"size:" << traceArray[index].size << endl;
				if (!VirtualFree(traceArray[index].start, 0, MEM_RELEASE))
				{
					cout << GetLastError() << endl;			//���ش����
				}	
			}
		};

		try
		{
			while (1)
			{
				//�ȴ�tracker��ӡ�������ź���
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
				//0-������1-�ύ��2-����3-������4-���գ�5-�ͷ�
				action[op.oper]();
				index++;

				//�ͷ��ź���֪ͨtracker���Դ�ӡ��Ϣ
				ReleaseSemaphore(semaphoreTrack, 1, NULL);
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
		}

		in.close();		//�ر�д���ļ�

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