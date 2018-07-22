#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

#define READER 'R'				//����
#define WRITER 'W'				//д��
#define INTE_PER_SEC 1000		//ÿ��ʱ���ж���Ŀ
#define MAX_THREAD_NUM 64		//����߳���
#define MAX_FILE_NUM 32			//��������ļ���Ŀ
#define MAX_STR_LEN 32			//�ַ�������

int readCount = 0;				//������Ŀ
int writeCount = 0;				//д����Ŀ

CRITICAL_SECTION RP_Write;		//�ٽ���
CRITICAL_SECTION cs_Write;
CRITICAL_SECTION cs_Read;

typedef struct threadInfo
{
	int serial;					//�߳����
	char type;					//�߳����(RΪ���ߣ�WΪд��
	double delay;				//�̴߳�������ʱʱ��
	double persist;				//�̳߳���ʱ��
}ThreadInfo;

/***********************
 *  ��������-���߽���  *
 *infoPtr:�����߳���Ϣ *	
 ***********************/	
void ReadPriority_RThread(ThreadInfo *infoPtr)
{
	HANDLE h_Mutex;				//�������
	h_Mutex = OpenMutex(MUTEX_ALL_ACCESS, false, "mutex_for_readCount");

	DWORD wait_for_mutex;		//�ȴ������������Ȩ
	DWORD m_delay;				//�ӳ�ʱ��
	DWORD m_persist;			//���ļ�����ʱ��
	int m_serial;				//�߳����

	//�Ӳ����л�ȡ��Ϣ
	m_serial = infoPtr->serial;
	m_delay = infoPtr->delay*INTE_PER_SEC;
	m_persist = infoPtr->persist*INTE_PER_SEC;
	Sleep(m_delay);				//��ʱ�����ӳ�ʱ���ʱ��

	printf("Reader thread %d sends the reading require.\n", m_serial);
	

	//�ȴ������źţ���֤��readcount�ķ��ʡ��޸ġ�����
	wait_for_mutex = WaitForSingleObject(h_Mutex, -1);		//P����
															//������Ŀ����
	readCount++;
	

	if (readCount == 1)
	{
		//����ǵ�һ�����ߣ��ȴ���Դ��д��д��
		EnterCriticalSection(&RP_Write);
	}

	ReleaseMutex(h_Mutex);		//V����

	printf("Reader thread %d begins to read file.\n", m_serial);
	Sleep(m_persist);			//����ʱ��

	//�˳��߳�
	printf("Reader thread %d finishs reading file.\n", m_serial);
	
	//�ȴ������źţ���֤��reaadCount�ķ��ʡ��޸Ļ���
	wait_for_mutex = WaitForSingleObject(h_Mutex, -1);
	//���������
	readCount--;

	if (readCount == 0)
	{
		//�������ȫ�����꣬����д��
		LeaveCriticalSection(&RP_Write);
	}

	ReleaseMutex(h_Mutex);		//V����

}


/***********************
*  ��������-д�߽���  *
*infoPtr:д���߳���Ϣ *
***********************/
void ReadPriority_WThread(ThreadInfo *infoPtr)
{
	DWORD m_delay;				//�ӳ�ʱ��
	DWORD m_persist;			//����ʱ��
	int m_serial;				//�߳����

	//�Ӳ����л�ȡ��Ϣ
	m_serial = infoPtr->serial;
	m_delay = infoPtr->delay*INTE_PER_SEC;
	m_persist = infoPtr->persist*INTE_PER_SEC;
	Sleep(m_delay);				//�ӳٵȴ�

	printf("Writer thread %d sends the writing require.\n",m_serial);
	//�ȴ��ٽ���Դ
	EnterCriticalSection(&RP_Write);

	//��ʼд�ļ�
	printf("Writer thread %d begins to write to the file.\n",m_serial);
	Sleep(m_persist);

	//�˳�����
	printf("Writer thread %d finishs writing to the file.\n", m_serial);

	//�ͷ��ٽ���Դ
	LeaveCriticalSection(&RP_Write);
}

/********************************
*  �������Ⱥ���                 *
*  fileName:�ļ���(��ʼ���ļ�)  *
*********************************/
void ReaderPriority(char *fileName)
{
	DWORD n_thread = 0;				//�߳���Ŀ
	DWORD serial_thread;			//�߳����
	DWORD wait_for_all;				//�ȴ������߳̽���

	//�������
	HANDLE h_Mutex;
	h_Mutex = CreateMutex(NULL, false, "mutex_for_readCount");

	//�̶߳��������
	HANDLE h_Thread[MAX_THREAD_NUM];
	ThreadInfo thread_info[MAX_THREAD_NUM];

	readCount = 0;					//��ʼ��readCount
	InitializeCriticalSection(&RP_Write);		//��ʼ���ٽ���Դ
	
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
		//������߻�д�߳�ʼ��Ϣ
		inFile >> thread_info[n_thread].serial;
		inFile >> thread_info[n_thread].type;
		inFile >> thread_info[n_thread].delay;
		inFile >> thread_info[n_thread].persist;

		//��һ�����߻�д��
		n_thread++;

		//��ȡ�س����з�
		inFile.get();
	}

	for (int i = 0; i < (int)n_thread; ++i)
	{
		if (thread_info[i].type == READER || thread_info[i].type == 'r')
		{
			//�������߽���
			h_Thread[i] = CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)ReadPriority_RThread,
				&thread_info[i],
				0, &serial_thread);
		}
		else
		{
			//����д�߽���
			h_Thread[i] = CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)ReadPriority_WThread,
				&thread_info[i],
				0, &serial_thread);
		}
	}

	//�ȴ������߳̽���
	wait_for_all = WaitForMultipleObjects(n_thread, h_Thread, true, -1);
	cout << endl << "All reader and writer have finished operating." << endl;
}


/***********************
*  д������-�����߳�  *
*infoPtr:�����߳���Ϣ *
***********************/
void WritePriority_RThread(ThreadInfo *infoPtr)
{
	//�������
	HANDLE h_mutex1;					//���ڷ���cs_Read�ٽ���
	h_mutex1 = OpenMutex(MUTEX_ALL_ACCESS, false, "mutex1");
	HANDLE h_mutex2;					//����readCount
	h_mutex2 = OpenMutex(MUTANT_ALL_ACCESS, false, "mutex2");

	DWORD wait_for_mutex1;				//�ȴ������������Ȩ
	DWORD wait_for_mutex2;				//����readCount

	DWORD m_delay;						//�ӳ�ʱ��
	DWORD m_persist;					//����������ʱ��
	int m_serial;						//�߳����

	//�Ӳ����л�ȡ�߳���Ϣ
	m_serial = infoPtr->serial;
	m_delay = infoPtr->delay*INTE_PER_SEC;
	m_persist = infoPtr->persist*INTE_PER_SEC;

	Sleep(m_delay);						//�ӳٵȴ�

	printf("Reader thread %d sends the reading require.\n", m_serial);

	wait_for_mutex1 = WaitForSingleObject(h_mutex1, -1);	//P����

	//��������ٽ���
	EnterCriticalSection(&cs_Read);		//P����

	//����������󣬱�֤��readCount�ķ��ʡ��޸Ļ���
	wait_for_mutex2 = WaitForSingleObject(h_mutex2, -1);	//P����
	//�޸Ķ�����Ŀ
	readCount++;

	if (readCount == 1)
	{
		//����ǵ�һ�����ߣ��ȴ�д��д��
		EnterCriticalSection(&cs_Write);
	}

	ReleaseMutex(h_mutex2);				//V����

	LeaveCriticalSection(&cs_Read);		//���������߽����ٽ���

	ReleaseMutex(h_mutex1);				//V����

	//��ʼ������
	printf("Reader thread %d begins to read file.\n", m_serial);
	Sleep(m_persist);					//������ʱ��

	//�˳��߳�
	printf("Reader thread %d finishs reading file.\n", m_serial);
	//�����������mutex2,��֤��readCount�ķ��ʡ��޸Ļ���
	wait_for_mutex2 = WaitForSingleObject(h_mutex2, -1);	//P����
	readCount--;
	if (readCount == 0)
	{
		//������ж��߶��꣬����д��
		LeaveCriticalSection(&cs_Write);
	}
	ReleaseMutex(h_mutex2);				//V����
}


/***********************
*  д������-д���߳�  *
*infoPtr:д���߳���Ϣ *
***********************/
void WritePriority_WThread(ThreadInfo* infoPtr)
{
	DWORD wait_for_mutex3;				//����writeCount
	DWORD m_delay;						//�ӳ�ʱ��
	DWORD m_persist;					//д�ļ�����ʱ��
	int m_serial;						//�߳����

	//�������
	HANDLE h_mutex3;
	h_mutex3 = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "mutex3");

	//�Ӳ����л����Ϣ
	m_serial = infoPtr->serial;
	m_delay = infoPtr->delay*INTE_PER_SEC;
	m_persist = infoPtr->persist *INTE_PER_SEC;

	Sleep(m_delay);//�ӳٵȴ�

	printf("Writer thread %d sends the writing require.\n", m_serial);

	//�����������mutex3,��֤��writecount�ķ��ʡ��޸Ļ���
	wait_for_mutex3 = WaitForSingleObject(h_mutex3, -1);//P����
	//�޸�д����Ŀ
	writeCount++;
	if (writeCount == 1)
	{
		//��һ��д�ߣ��ȴ����߶���
		EnterCriticalSection(&cs_Read);
	}
	ReleaseMutex(h_mutex3);			//V����

	//����д���ٽ���
	EnterCriticalSection(&cs_Write);

	//��ʼд����
	printf("Writer thread %d begins to write to the file.\n", m_serial);
	Sleep(m_persist);				//д��������ʱ��

	//�˳��߳�
	printf("Writer thread %d finished writing to the file.\n", m_serial);
	//�뿪�ٽ��� 
	LeaveCriticalSection(&cs_Write);

	//�����������mutex3,��֤��writecount�ķ��ʡ��޸Ļ���
	wait_for_mutex3 = WaitForSingleObject(h_mutex3, -1);//P����
	writeCount--;

	if (writeCount == 0)
	{
		//д��д�꣬���߿��Զ�
		LeaveCriticalSection(&cs_Read);
	}

	ReleaseMutex(h_mutex3);			//V����
}


/********************************
*  д�����Ⱥ���                 *
*  fileName:�ļ���(��ʼ���ļ�)  *
*********************************/
void WriterPriority(char *fileName)
{
	DWORD n_thread = 0;						//�߳���Ŀ
	DWORD serial_thread;						//�߳�ID
	DWORD wait_for_all;						//�ȴ������߳̽���

	//�����������
	HANDLE h_Mutex1;						//����cs_Read�ٽ���״̬�޸�
	h_Mutex1 = CreateMutex(NULL, FALSE, "mutex1");
	HANDLE h_Mutex2;						//����readCount�����޸�
	h_Mutex2 = CreateMutex(NULL, FALSE, "mutex2");
	HANDLE h_Mutex3;						//����writeCount�����޸�
	h_Mutex3 = CreateMutex(NULL, FALSE, "mutex3");

	//�̶߳���
	HANDLE h_Thread[MAX_THREAD_NUM];
	ThreadInfo thread_info[MAX_THREAD_NUM];

	readCount = 0;							//��ʼ��readCount
	writeCount = 0;							//��ʼ��writeCount
	InitializeCriticalSection(&cs_Write);	//��ʼ���ٽ���
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
		//������߻�д�߳�ʼ��Ϣ
		inFile >> thread_info[n_thread].serial;
		inFile >> thread_info[n_thread].type;
		inFile >> thread_info[n_thread].delay;
		inFile >> thread_info[n_thread].persist;

		//��һ�����߻�д��
		n_thread++;

		//��ȡ�س����з�
		inFile.get();
	}

	for (int i = 0; i < (int)n_thread; ++i)
	{
		if (thread_info[i].type == READER || thread_info[i].type == 'r')
		{
			//�������߽���
			h_Thread[i] = CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)WritePriority_RThread,
				&thread_info[i],
				0, &serial_thread);
		}
		else
		{
			//����д�߽���
			h_Thread[i] = CreateThread(NULL, 0,
				(LPTHREAD_START_ROUTINE)WritePriority_WThread,
				&thread_info[i],
				0, &serial_thread);
		}
	}

	//�ȴ������߳̽���
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
			//��������
			ReaderPriority("Reader_Writer.txt");
		}
		else if (ch == '2')
		{
			//д������
			WriterPriority("Reader_Writer.txt");
		}
		else
		{
			cout << "GOOD BYE" << endl;
			system("pause");
			return 0;				//�˳�
		}

		//����
		cout << "Press Any Key To Continue";
		getchar();
		system("cls");
	}

	system("pause");
	return 0;
}