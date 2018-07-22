/**
*LL1_Praser.cpp�ļ�����
*����:������
*ʱ��:2017.11.20
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<iomanip>

using namespace std;

const int VnSize = 5;							//���ս������
const int VtSize = 8;							//�ս������
const int ProductionSize = 10;					//����ʽ����

char Vn[VnSize] = { 'E','A','T','B','F' };		//���ս��
char Vt[VtSize] = { 'n','+','-','*','/','(',')','$' };//�ս��
vector<char> FIRST[VnSize];						//FIRST��
vector<char> FOLLOW[VnSize];					//FOLLOW��
stack<char> AnalyseStack;						//����ջ
string AnalyseTable[VnSize][VtSize];			//Ԥ�������
string Production[ProductionSize];				//�ķ�����ʽ
string inputBuffer;								//���뻺����
int ip;											//���뻺����ָ��


int mapVn(char c);								//���ս�������ֶ�Ӧ

int mapVt(char c);								//�ս�������ֶ�Ӧ

void Initial();									//����ʽ��FIRST��FOLLOW��ʼ��

void createAnalyseTable();						//����Ԥ��������㷨4.2

string outStack();								//���ջ�����ַ���

void error1();									//��һ�ִ���ջ���ս���뵱ǰ�������ƥ��
void error2(char X, char a);					//�ڶ��ִ��󣬱���հ�
void error3(char X, char a);					//�����ִ��󣬱���Ϊ"synch"

void LL1_analyse(string w);						//�㷨4.1,�ǵݹ�Ԥ���������

string inStringChange(string w);				//��������ת��Ϊ���ս��'n'

void TablePrint();								//���Ԥ�������


int main()//������
{
	string s;
	cout << "����������������ʽ(����*7*2+-7):";
	cin >> s;
	string w = inStringChange(s);
	Initial();
	createAnalyseTable();
	TablePrint();
	LL1_analyse(w);

	system("pause");
	return 0;
}

int mapVn(char c)//���ս�������ֶ�Ӧ
{
	switch (c)
	{
	case 'E':
		return 0;
		break;
	case 'A':
		return 1;
		break;
	case 'T':
		return 2;
		break;
	case 'B':
		return 3;
		break;
	case 'F':
		return 4;
		break;
	default:
		return -1;
		break;
	}
}
int mapVt(char c)//�ս�������ֶ�Ӧ
{
	switch (c)
	{
	case 'n':
		return 0;
		break;
	case '+':
		return 1;
		break;
	case '-':
		return 2;
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 4;
		break;
	case '(':
		return 5;
		break;
	case ')':
		return 6;
		break;
	case '$':
		return 7;
		break;
	default:
		return -1;
		break;
	}
}


void Initial()
{
	//������ݹ顢��ȡ����ʽ��Ĳ���ʽ
	Production[0] = "E->TA";
	Production[1] = "A->+TA";
	Production[2] = "A->-TA";
	Production[3] = "A->e";
	Production[4] = "T->FB";
	Production[5] = "B->*FB";
	Production[6] = "B->/FB";
	Production[7] = "B->e";
	Production[8] = "F->(E)";
	Production[9] = "F->n";

	//FIRST��
	FIRST[0].push_back('(');
	FIRST[0].push_back('n');
	FIRST[1].push_back('+');
	FIRST[1].push_back('-');
	FIRST[1].push_back('e');
	FIRST[2].push_back('(');
	FIRST[2].push_back('n');
	FIRST[3].push_back('*');
	FIRST[3].push_back('/');
	FIRST[3].push_back('e');
	FIRST[4].push_back('(');
	FIRST[4].push_back('n');

	//FOLLOW��
	FOLLOW[0].push_back('$');
	FOLLOW[0].push_back(')');
	FOLLOW[1].push_back('$');
	FOLLOW[1].push_back(')');
	FOLLOW[2].push_back('$');
	FOLLOW[2].push_back('+');
	FOLLOW[2].push_back('-');
	FOLLOW[2].push_back(')');
	FOLLOW[3].push_back('$');
	FOLLOW[3].push_back('+');
	FOLLOW[3].push_back('-');
	FOLLOW[3].push_back(')');
	FOLLOW[4].push_back('$');
	FOLLOW[4].push_back('+');
	FOLLOW[4].push_back('-');
	FOLLOW[4].push_back(')');
	FOLLOW[4].push_back('*');
	FOLLOW[4].push_back('/');

	for (int i = 0; i < VnSize; ++i)
	{
		for (int j = 0; j < VtSize; ++j)
		{
			AnalyseTable[i][j] = "";//Ԥ����������ÿ�
		}
	}
}

void createAnalyseTable()//����Ԥ��������㷨4.2
{
	for (int i = 0; i < ProductionSize; ++i)
	{
		int row = -1, col = -1, row2 = -1;//�������������
		char RightHead = Production[i][3];
		row = mapVn(Production[i][0]);
		if (RightHead == 'n' || RightHead == '+' || RightHead == '-'
			|| RightHead == '*' || RightHead == '/' || RightHead == '('
			|| RightHead == ')' || RightHead == '$')//Ϊ�ս��ʱ
		{
			col = mapVt(RightHead);
			AnalyseTable[row][col] = Production[i];
		}
		else if (RightHead == 'E' || RightHead == 'A' || RightHead == 'T'
			|| RightHead == 'B' || RightHead == 'F')//���ս��
		{
			int row2 = mapVn(RightHead);//���ս��
			for (int j = 0; j < FIRST[row2].size(); ++j)
			{
				if (FIRST[row2][j] != 'e')//����A->��
				{
					col = mapVt(FIRST[row2][j]);
					AnalyseTable[row][col] = Production[i];
				}
				else
				{
					for (int k = 0; k < FOLLOW[row].size(); ++k)
					{
						col = mapVt(FOLLOW[row][k]);
						AnalyseTable[row][col] = Production[i];
					}
				}
			}
		}
		else//A->��
		{
			for (int k = 0; k < FOLLOW[row].size(); ++k)
			{
				col = mapVt(FOLLOW[row][k]);
				AnalyseTable[row][col] = Production[i];
			}
		}
	}

	for (int i = 0; i < VnSize; ++i)//�Է��ս������
	{
		int col = -1;
		for (int j = 0; j < FOLLOW[i].size(); ++j)
		{
			col = mapVt(FOLLOW[i][j]);//b��FOLLOW(A)
			if (AnalyseTable[i][col].empty())
			{//��M[A,b]Ϊ�գ�����"synch"
				AnalyseTable[i][col] = "synch";
			}
		}
	}
		
}

string outStack()//���վ����
{
	string s = "";
	char ctemp;
	stack<char> stemp;
	while (!AnalyseStack.empty())
	{
		ctemp = AnalyseStack.top();
		AnalyseStack.pop();
		stemp.push(ctemp);
	}
	while (!stemp.empty())
	{
		ctemp = stemp.top();
		s += ctemp;
		AnalyseStack.push(ctemp);
		stemp.pop();
	}
	return s;
}


void error1()//��һ�ִ���ջ���ս���뵱ǰ�������ƥ��
{
	AnalyseStack.pop();//����ջ��
	cout << "ERROR,X!=a,�ս����ƥ��" << endl;
}
void error2(char X, char a)//�ڶ��ִ��󣬱���հ�
{
	ip++;//�հף���������a
	cout << "ERROR,M[" << X << ',' << a << "]�հף�����" << a << endl;
}
void error3(char X, char a)//�����ִ��󣬱���Ϊ"synch"
{
	AnalyseStack.pop();//����ջ��
	cout << "ERROR,M[" << X << ',' << a << "]=synch������" << X << endl;
}


void LL1_analyse(string w)//�㷨4.1,�ǵݹ�Ԥ���������
{
	char X;//ָ��ջ���ķ�����
	char a;//ip��ָ����������
	ip = 0;//w$ָ�룬��ʼָ���һ������
	int step = 0;//��¼����
	inputBuffer = w;
	AnalyseStack.push('$');
	AnalyseStack.push('E');
	cout << "                            ��������" << endl;
	cout << left << setw(10) << "Step" << left << setw(20) << "Stack" << left << setw(20) << "Input" << left << setw(20) << "Output" << endl;

	do
	{
		X = AnalyseStack.top();
		a = inputBuffer[ip];
		++step;
		cout << left << setw(10) << step << left << setw(20) << outStack() << left << setw(20) << inputBuffer.substr(ip);

		if (X == 'n' || X == '+' || X == '-' || X == '*'
			|| X == '/' || X == '(' || X == ')' || X == '$')//�ս����$
		{
			if (X == a)
			{
				AnalyseStack.pop();
				ip++;
				if (X == '$')
				{
					cout << "ACC";
					cout << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					cout << "��������" << endl;
				}
					
				cout << endl;
			}
			else
			{
				error1();//��һ�ִ���
			}
		}
		else//���ս��
		{
			int rowVn = mapVn(X);
			int colVt = mapVt(a);
			if (rowVn == -1 || colVt == -1)
			{
				cout << "���뺬�д����ķ�����" << endl;
				exit(0);
			}
			if (AnalyseTable[rowVn][colVt].empty()) 
			{
				error2(X, a);//�ڶ��ִ���,�հ�
			}
			else if (AnalyseTable[rowVn][colVt] == "synch")
			{
				error3(X, a);//�����ִ���synch
			}
			else//�������
			{
				if (AnalyseTable[rowVn][colVt][3] == 'e')
				{
					AnalyseStack.pop();
					cout << AnalyseTable[rowVn][colVt] << endl;
				}
				else
				{
					AnalyseStack.pop();
					for (int i = AnalyseTable[rowVn][colVt].length() - 1; i >= 3; --i)
					{
						AnalyseStack.push(AnalyseTable[rowVn][colVt][i]);
					}
					cout << AnalyseTable[rowVn][colVt] << endl;
				}
			}
		}

	} while (X != '$');

}


string inStringChange(string w)
{
	string temp = "";
	for (int i = 0; i < w.length(); ++i)
	{
		//cout << w[i] << endl;
		if (w[i] >= '0'&&w[i] <= '9'&&i < w.length())
		{//������
			++i;
			while (w[i] >= '0'&&w[i] <= '9'&&i < w.length())
			{
				++i;
			}
			temp += 'n';
			--i;
		}
		else
		{
			temp += w[i];
		}
	}
	temp += '$';
	return temp;
}


void TablePrint()//���Ԥ�������
{
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "                            Ԥ�������M" << endl;
	for (int j = 0; j < VtSize; j++) {
		cout << "\t" << Vt[j];
	}
	cout << endl;
	for (int i = 0; i < VnSize; i++) {
		cout << Vn[i] << "\t";
		for (int j = 0; j < VtSize; j++) {
			cout << AnalyseTable[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "----------------------------------------------------------------------------" << endl;
}