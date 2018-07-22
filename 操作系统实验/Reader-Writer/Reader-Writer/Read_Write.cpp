#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

#define READER 'R'				//读者
#define WRITER 'W'				//写者
#define INTE_PER_SEC 1000		//每秒时钟中断数目
#define MAX_THREAD_NUM 64		//最大线程数
#define MAX_FILE_NUM 32			//最大数据文件数目
#define MAX_STR_LEN 32			//字符串长度

int readCount = 0;				//读者数目
int writeCount = 0;				//写者数目

CRITICAL_SECTION RP_Write;		//临界区
CRITICAL_SECTION cs_Write;
CRITICAL_SECTION cs_Read;

typedef struct threadInfo
{
	int serial;					//线程序号
	char type;					//线程类别(R为读者，W为写者
	double delay;				//线程创建后，延时时间
	double persist;				//线程持续时间
}ThreadInfo;

/***********************
 *  读者优先-读者进程  *
 *infoPtr:读者线程信息 *	
 ***********************/	
void ReadPriority_RThread(ThreadInfo *infoPtr)
{
	HANDLE h_Mutex;				//互斥变量
	h_Mutex = OpenMutex(MUTEX_ALL_ACCESS, false, "mutex_for_readCount");

	DWORD wait_for_mutex;		//等待互斥变量所有权
	DWORD m_delay;				//延迟时间
	DWORD m_persist;			//读文件持续时间
	int m_serial;				//线程序号

	//从参数中获取信息
	m_serial = infoPtr->serial;
	m_delay = infoPtr->delay*INTE_PER_SEC;
	m_persist = infoPtr->persist*INTE_PER_SEC;
	Sleep(m_delay);				//暂时挂起，延迟时间的时长

	printf("Reader thread %d sends the reading require.\n", m_serial);
	

	//等待互斥信号，保证对readcount的访问、修改、互斥
	wait_for_mutex = WaitForSingleObject(h_Mutex, -1);		//P操作
															//读者数目增加
	readCount++;
	

	if (readCount == 1)
	{
		//如果是第一个读者，等待资源被写者写完
		EnterCriticalSection(&RP_Write);
	}

	ReleaseMutex(h_Mutex);		//V操作

	printf("Reader thread %d begins to read file.\n", m_serial);
	Sleep(m_persist);			//持续时间

	//退出线程
	printf("Reader thread %d finishs reading file.\n", m_serial);
	
	//等待互斥信号，保证对reaadCount的访问、修改互斥
	wait_for_mutex = WaitForSingleObject(h_Mutex, -1);
	//读者书减少
	readCount--;

	if (readCount == 0)
	{
		//如果读者全部读完，唤醒写者
		LeaveCriticalSection(&RP_Write);
	}

	ReleaseMutex(h_Mutex);		//V操作

}


/***********************
*  读者优先-写者进程  *
*infoPtr:写者线程信息 *
***********************/
void ReadPriority_WThread(ThreadInfo *infoPtr)
{
	DWORD m_delay;				//延迟时间
	DWORD m_persist;			//持续时间
	int m_serial;				//线程序号

	//从参数中获取信息
	m_serial = infoPtr->serial;
	m_delay = infoPtr->delay*INTE_PER_SEC;
	m_persist = infoPtr->persist*INTE_PER_SEC;
	Sleep(m_delay);				//延迟等待

	printf("Writer thread %d sends the writing require.\n",m_serial);
	//等待临界资源
	EnterCriticalSection(&RP_Write);

	//开始写文件
	printf("Writer thread %d begins to write to the file.\n",m_serial);
	Sleep(m_persist);

	//退出程序
	printf("Writer thread %d finishs writing to the file.\n", m_serial);

	//释放临界资源
	LeaveCriticalSection(&RP_Write);
}

/********************************
*  读者优先函数                 *
*  fileName:文件名(初始化文件)  *
*********************************/
void ReaderPriority(char *fileName)
{
	DWORD n_thread = 0;				//线程数目
	DWORD serial_thread;			//线程序号
	DWORD wait_for_all;				//等待所有线程结束

	//互斥对象
	HANDLE h_Mutex;
	h_Mutex = CreateMutex(NULL, false, "mutex_for_readCount");

	//线程对象的数组
	HANDLE h_Thread[MAX_THREAD_NUM];
	ThreadInfo thread_info[MAX_THREAD_NUM];

	readCount = 0;					//初始化readCount
	InitializeCriticalSection(&RP_Write);		//初始化临界资源
	
	ifstream inFile;

	inFile.open(fileName);
	if (!inFile.is_open())
	{
		cout << "Failed to open the " << fileName << endl;
		return;
	}

	cout << "---------------------------Reader Priority---------------------------" << endl;

	while (!inFile.eof())
	{
		//读入读者或写者初始信息
		inFile >> thread_info[n_thread].serial;
		inFile >> thread_info[n_thread].type;
		inFile >> thread_info[n_thread].delay;
		inFile >> thread_info[n_thread].persist;

		//下一个读者或写者
		n_thread++;

		//读取回车换行符
		inFile.get();
	}

	for (int i = 0; i < (int)n_thread; ++i)
	{
		if (thread_info[i].type == READER || thread_info[i].type == 'r')
		{
			//创建读者进程
			h_Thread[i] = CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)ReadPriority_RThread,
				&thread_info[i],
				0, &serial_thread);
		}
		else
		{
			//创建写者进程
			h_Thread[i] = CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)ReadPriority_WThread,
				&thread_info[i],
				0, &serial_thread);
		}
	}

	//等待所有线程结束
	wait_for_all = WaitForMultipleObjects(n_thread, h_Thread, true, -1);
	cout << endl << "All reader and writer have finished operating." << endl;
}


/***********************
*  写者优先-读者线程  *
*infoPtr:读者线程信息 *
***********************/
void WritePriority_RThread(ThreadInfo *infoPtr)
{
	//互斥变量
	HANDLE h_mutex1;					//用于访问cs_Read临界区
	h_mutex1 = OpenMutex(MUTEX_ALL_ACCESS, false, "mutex1");
	HANDLE h_mutex2;					//用于readCount
	h_mutex2 = OpenMutex(MUTANT_ALL_ACCESS, false, "mutex2");

	DWORD wait_for_mutex1;				//等待互斥变量所有权
	DWORD wait_for_mutex2;				//用于readCount

	DWORD m_delay;						//延迟时间
	DWORD m_persist;					//读操作持续时间
	int m_serial;						//线程序号

	//从参数中获取线程信息
	m_serial = infoPtr->serial;
	m_delay = infoPtr->delay*INTE_PER_SEC;
	m_persist = infoPtr->persist*INTE_PER_SEC;

	Sleep(m_delay);						//延迟等待

	printf("Reader thread %d sends the reading require.\n", m_serial);

	wait_for_mutex1 = WaitForSingleObject(h_mutex1, -1);	//P操作

	//进入读者临界区
	EnterCriticalSection(&cs_Read);		//P操作

	//阻塞互斥对象，保证对readCount的访问、修改互斥
	wait_for_mutex2 = WaitForSingleObject(h_mutex2, -1);	//P操作
	//修改读者数目
	readCount++;

	if (readCount == 1)
	{
		//如果是第一个读者，等待写者写完
		EnterCriticalSection(&cs_Write);
	}

	ReleaseMutex(h_mutex2);				//V操作

	LeaveCriticalSection(&cs_Read);		//让其它读者进入临界区

	ReleaseMutex(h_mutex1);				//V操作

	//开始读操作
	printf("Reader thread %d begins to read file.\n", m_serial);
	Sleep(m_persist);					//读持续时间

	//退出线程
	printf("Reader thread %d finishs reading file.\n", m_serial);
	//阻塞互斥对象mutex2,保证对readCount的访问、修改互斥
	wait_for_mutex2 = WaitForSingleObject(h_mutex2, -1);	//P操作
	readCount--;
	if (readCount == 0)
	{
		//如果所有读者读完，唤醒写者
		LeaveCriticalSection(&cs_Write);
	}
	ReleaseMutex(h_mutex2);				//V操作
}


/***********************
*  写者优先-写者线程  *
*infoPtr:写者线程信息 *
***********************/
void WritePriority_WThread(ThreadInfo* infoPtr)
{
	DWORD wait_for_mutex3;				//用于writeCount
	DWORD m_delay;						//延迟时间
	DWORD m_persist;					//写文件持续时间
	int m_serial;						//线程序号

	//互斥对象
	HANDLE h_mutex3;
	h_mutex3 = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "mutex3");

	//从参数中获得信息
	m_serial = infoPtr->serial;
	m_delay = infoPtr->delay*INTE_PER_SEC;
	m_persist = infoPtr->persist *INTE_PER_SEC;

	Sleep(m_delay);//延迟等待

	printf("Writer thread %d sends the writing require.\n", m_serial);

	//阻塞互斥对象mutex3,保证对writecount的访问、修改互斥
	wait_for_mutex3 = WaitForSingleObject(h_mutex3, -1);//P操作
	//修改写者数目
	writeCount++;
	if (writeCount == 1)
	{
		//第一个写者，等待读者读完
		EnterCriticalSection(&cs_Read);
	}
	ReleaseMutex(h_mutex3);			//V操作

	//进入写者临界区
	EnterCriticalSection(&cs_Write);

	//开始写操作
	printf("Writer thread %d begins to write to the file.\n", m_serial);
	Sleep(m_persist);				//写操作持续时间

	//退出线程
	printf("Writer thread %d finished writing to the file.\n", m_serial);
	//离开临界区 
	LeaveCriticalSection(&cs_Write);

	//阻塞互斥对象mutex3,保证对writecount的访问、修改互斥
	wait_for_mutex3 = WaitForSingleObject(h_mutex3, -1);//P操作
	writeCount--;

	if (writeCount == 0)
	{
		//写者写完，读者可以读
		LeaveCriticalSection(&cs_Read);
	}

	ReleaseMutex(h_mutex3);			//V操作
}


/********************************
*  写者优先函数                 *
*  fileName:文件名(初始化文件)  *
*********************************/
void WriterPriority(char *fileName)
{
	DWORD n_thread = 0;						//线程数目
	DWORD serial_thread;						//线程ID
	DWORD wait_for_all;						//等待所有线程结束

	//创建互斥对象
	HANDLE h_Mutex1;						//用于cs_Read临界区状态修改
	h_Mutex1 = CreateMutex(NULL, FALSE, "mutex1");
	HANDLE h_Mutex2;						//用于readCount互斥修改
	h_Mutex2 = CreateMutex(NULL, FALSE, "mutex2");
	HANDLE h_Mutex3;						//用于writeCount互斥修改
	h_Mutex3 = CreateMutex(NULL, FALSE, "mutex3");

	//线程对象
	HANDLE h_Thread[MAX_THREAD_NUM];
	ThreadInfo thread_info[MAX_THREAD_NUM];

	readCount = 0;							//初始化readCount
	writeCount = 0;							//初始化writeCount
	InitializeCriticalSection(&cs_Write);	//初始化临界区
	InitializeCriticalSection(&cs_Read);

	ifstream inFile;
	inFile.open(fileName);

	if (!inFile.is_open())
	{
		cout << "Failed to open the " << fileName << endl;
		return;
	}

	cout << "---------------------------Writer Priority---------------------------" << endl;

	while (!inFile.eof())
	{
		//读入读者或写者初始信息
		inFile >> thread_info[n_thread].serial;
		inFile >> thread_info[n_thread].type;
		inFile >> thread_info[n_thread].delay;
		inFile >> thread_info[n_thread].persist;

		//下一个读者或写者
		n_thread++;

		//读取回车换行符
		inFile.get();
	}

	for (int i = 0; i < (int)n_thread; ++i)
	{
		if (thread_info[i].type == READER || thread_info[i].type == 'r')
		{
			//创建读者进程
			h_Thread[i] = CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)WritePriority_RThread,
				&thread_info[i],
				0, &serial_thread);
		}
		else
		{
			//创建写者进程
			h_Thread[i] = CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)WritePriority_WThread,
				&thread_info[i],
				0, &serial_thread);
		}
	}

	//等待所有线程结束
	wait_for_all = WaitForMultipleObjects(n_thread, h_Thread, true, -1);
	cout << endl << "All reader and writer have finished operating." << endl;

}



int main()
{
	char ch;

	while (true)
	{
		printf("****************************************************\n");
		printf("                 1:Reader Priority\n");
		printf("                 2:Writer Priority\n");
		printf("                 3:Exit to Windows \n");
		printf("****************************************************\n");
		printf("Enter your choice( 1, 2 or 3 ):");

		do
		{
			scanf_s("%c", &ch);
			getchar();
		} while (ch != '1' && ch != '2' && ch != '3');

		system("cls");

		if (ch == '1')
		{
			//读者优先
			ReaderPriority("Reader_Writer.txt");
		}
		else if (ch == '2')
		{
			//写者优先
			WriterPriority("Reader_Writer.txt");
		}
		else
		{
			cout << "GOOD BYE" << endl;
			system("pause");
			return 0;				//退出
		}

		//结束
		cout << "Press Any Key To Continue";
		getchar();
		system("cls");
	}

	system("pause");
	return 0;
}