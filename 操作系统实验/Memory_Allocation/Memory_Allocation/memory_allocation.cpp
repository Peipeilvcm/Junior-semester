
#include<iostream>
#include<Windows.h>
#include<thread>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<string>
#include<iomanip>
#include<exception>
using namespace std;

#define PAGE_UNKNOWN 0x0										//未知页
#define MEM_UNKNOWN_TYPE 0x0

#define EXTRACT(VAR) {VAR,#VAR}

typedef struct trace {		//跟踪每次分配活动数据结构
	LPVOID start;			//起始地址大小
	long size;				//分配大小
}Trace;

int main()
{
	try
	{
		const vector<pair<DWORD, string>> protectArray
		{													//五种访问权限
			EXTRACT(PAGE_READONLY),							//只读
			EXTRACT(PAGE_READWRITE),						//读和写
			EXTRACT(PAGE_EXECUTE),							//执行
			EXTRACT(PAGE_EXECUTE_READ),						//执行读
			EXTRACT(PAGE_EXECUTE_READWRITE)					//执行读写
		};
		vector<Trace> traceInfo(protectArray.size());

		size_t outputCount = 0;
		auto outputStatus = [&](ostream &os)
		{
			const int AlignmentWidth = 25;					//对其宽度

			const static vector<string> actionArray
			{
				"保留","提交","加锁","解锁","回收","释放"
			};

			const static unordered_map<DWORD, string> protectMap
			{
				EXTRACT(PAGE_UNKNOWN),						//0x0
				EXTRACT(PAGE_NOACCESS),						//0x01
				EXTRACT(PAGE_READONLY),						//0x02
				EXTRACT(PAGE_READWRITE),					//0x04
				EXTRACT(PAGE_WRITECOPY),					//0x08
				EXTRACT(PAGE_EXECUTE),						//0x10
				EXTRACT(PAGE_EXECUTE_READ),					//0x20
				EXTRACT(PAGE_EXECUTE_READWRITE),            //0x40
				EXTRACT(PAGE_EXECUTE_WRITECOPY),            //0x80
				EXTRACT(PAGE_GUARD),						//0x100
				EXTRACT(PAGE_NOCACHE),						//0x200
				EXTRACT(PAGE_WRITECOMBINE),					//0x400
				EXTRACT(PAGE_REVERT_TO_FILE_MAP)			//0x800
			};

			const static unordered_map<DWORD, string> stateMap
			{
				EXTRACT(MEM_COMMIT),
				EXTRACT(MEM_RESERVE),
				EXTRACT(MEM_FREE)
			};

			const static unordered_map<DWORD, string> typeMap
			{
				EXTRACT(MEM_UNKNOWN_TYPE),
				EXTRACT(MEM_IMAGE),
				EXTRACT(MEM_MAPPED),
				EXTRACT(MEM_PRIVATE)
			};

			SYSTEM_INFO systemInfo;
			GetSystemInfo(&systemInfo);						//查询系统信息

			if (!outputCount)
			{//第一次输出
				os << setw(AlignmentWidth) << "PageSize : " << systemInfo.dwPageSize << endl;
			}

			if (outputCount%actionArray.size() == 0)
			{
				os << "\nCase: " << protectArray[outputCount / actionArray.size()].second << endl;
			}

			os << actionArray[outputCount % actionArray.size()] << endl;

			MEMORYSTATUS memStatus;
			GlobalMemoryStatus(&memStatus);

			// Reference:
			// https://msdn.microsoft.com/en-us/library/windows/desktop/aa366902(v=vs.85).aspx
			// https://msdn.microsoft.com/en-us/library/windows/desktop/aa366775(v=vs.85).aspx

			MEMORY_BASIC_INFORMATION memBasicInfo;
			VirtualQuery(traceInfo[outputCount / actionArray.size()].start, &memBasicInfo, sizeof(MEMORY_BASIC_INFORMATION));

			os << setw(AlignmentWidth) << "BaseAddress " << memBasicInfo.BaseAddress << endl;
			os << setw(AlignmentWidth) << "AllocationBase " << memBasicInfo.AllocationBase << std::endl;
			os << setw(AlignmentWidth) << "AllocationProtect " << protectMap.at(memBasicInfo.AllocationProtect) << endl;
			os << setw(AlignmentWidth) << "RegionSize / PageSize " << memBasicInfo.RegionSize / systemInfo.dwPageSize << endl;
			os << setw(AlignmentWidth) << "Protect " << protectMap.at(memBasicInfo.Protect) << endl;
			os << setw(AlignmentWidth) << "State " << stateMap.at(memBasicInfo.State) << endl;
			os << setw(AlignmentWidth) << "Type " << typeMap.at(memBasicInfo.Type) << endl;

			outputCount++;
		};

		auto outputError = [](ostream &os)
		{
			auto dwError = GetLastError();
			HLOCAL hlocal = NULL; // Buffer that gets the error message string
								  // Use the default system locale since we look for Windows messages
								  // Note: this MAKELANGID combination has a value of 0
			DWORD systemLocale = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);

			// Get the error code's textual description
			BOOL fOk = FormatMessageA(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS |
				FORMAT_MESSAGE_ALLOCATE_BUFFER,
				NULL, dwError, systemLocale,
				(char *)&hlocal, 0, NULL);
			if (!fOk)
			{
				// Is it a network-related error?
				HMODULE hDll = LoadLibraryEx(TEXT("netmsg.dll"), NULL,
					DONT_RESOLVE_DLL_REFERENCES);
				if (hDll != NULL)
				{
					fOk = FormatMessageA(
						FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS |
						FORMAT_MESSAGE_ALLOCATE_BUFFER,
						hDll, dwError, systemLocale,
						(char *)&hlocal, 0, NULL);
					FreeLibrary(hDll);
				}
			}

			if (fOk && (hlocal != NULL))
			{
				os << (const char *)LocalLock(hlocal) << std::endl;
				LocalFree(hlocal);
			}
			else
				os << "Could not Get Error Msg for " << dwError << std::endl;
		};

		auto semaphoreAlloc = CreateSemaphore(NULL, 1, 1, NULL);
		auto semaphoreTrack = CreateSemaphore(NULL, 0, 1, NULL);
		auto isEndTrack = false;

		auto threadAlloc = thread([&]()
		{
			SYSTEM_INFO info;
			GetSystemInfo(&info);

			size_t index = 0;
			for (const auto protection : protectArray)
			{
				auto syncWrapper = [&](auto callback)
				{
					WaitForSingleObject(semaphoreAlloc, INFINITE);
					callback();
					ReleaseSemaphore(semaphoreTrack, 1, NULL);
				};

				// Reference:
				// https://msdn.microsoft.com/en-us/library/windows/desktop/aa366887(v=vs.85).aspx

				// Reverse
				syncWrapper([&]()
				{
					traceInfo[index].size = (index + 1) * info.dwPageSize;
					traceInfo[index].start = VirtualAlloc(NULL, traceInfo[index].size,
						MEM_RESERVE, PAGE_NOACCESS);
				});

				// Commit
				syncWrapper([&]()
				{
					traceInfo[index].start = VirtualAlloc(traceInfo[index].start,
						traceInfo[index].size,
						MEM_COMMIT, protection.first);
				});

				// Lock
				syncWrapper([&]()
				{
					if (!VirtualLock(traceInfo[index].start,
						traceInfo[index].size))
						outputError(std::cout);
				});

				// Unlock
				syncWrapper([&]()
				{
					if (!VirtualUnlock(traceInfo[index].start,
						traceInfo[index].size))
						outputError(std::cout);
				});

				// Decommit
				syncWrapper([&]()
				{
					if (!VirtualFree(traceInfo[index].start,
						traceInfo[index].size, MEM_DECOMMIT))
						outputError(std::cout);
				});

				// Release
				syncWrapper([&]()
				{
					if (!VirtualFree(traceInfo[index].start, 0, MEM_RELEASE))
						outputError(std::cout);
				});

				index++;
			}
			isEndTrack = true;
		});

		auto threadTrack = std::thread([&]()
		{
			std::ofstream ofs("OutputMemState.txt");
			while (!isEndTrack)
			{
				WaitForSingleObject(semaphoreTrack, INFINITE);
				outputStatus(ofs);
				ReleaseSemaphore(semaphoreAlloc, 1, NULL);
			}
		});

		if (threadAlloc.joinable()) threadAlloc.join();
		if (threadTrack.joinable()) threadTrack.join();

		CloseHandle(semaphoreAlloc);
		CloseHandle(semaphoreTrack);
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}

	system("pause");
	return 0;
}