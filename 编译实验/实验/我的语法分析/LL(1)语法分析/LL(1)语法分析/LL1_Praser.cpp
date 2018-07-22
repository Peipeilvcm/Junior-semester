/**
*LL1_Praser.cpp文件内容
*作者:裴子祥
*时间:2017.11.20
*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<iomanip>

using namespace std;

const int VnSize = 5;							//非终结符个数
const int VtSize = 8;							//终结符个数
const int ProductionSize = 10;					//产生式个数

char Vn[VnSize] = { 'E','A','T','B','F' };		//非终结符
char Vt[VtSize] = { 'n','+','-','*','/','(',')','$' };//终结符
vector<char> FIRST[VnSize];						//FIRST集
vector<char> FOLLOW[VnSize];					//FOLLOW集
stack<char> AnalyseStack;						//分析栈
string AnalyseTable[VnSize][VtSize];			//预测分析表
string Production[ProductionSize];				//文法产生式
string inputBuffer;								//输入缓冲区
int ip;											//输入缓冲区指针


int mapVn(char c);								//非终结符与数字对应

int mapVt(char c);								//终结符与数字对应

void Initial();									//产生式、FIRST、FOLLOW初始化

void createAnalyseTable();						//创建预测分析表，算法4.2

string outStack();								//输出栈内容字符串

void error1();									//第一种错误，栈顶终结符与当前输入符不匹配
void error2(char X, char a);					//第二种错误，表项空白
void error3(char X, char a);					//第三种错误，表项为"synch"

void LL1_analyse(string w);						//算法4.1,非递归预测分析方法

string inStringChange(string w);				//输入数字转化为非终结符'n'

void TablePrint();								//输出预测分析表


int main()//主函数
{
	string s;
	cout << "输入待分析算术表达式(形如*7*2+-7):";
	cin >> s;
	string w = inStringChange(s);
	Initial();
	createAnalyseTable();
	TablePrint();
	LL1_analyse(w);

	system("pause");
	return 0;
}

int mapVn(char c)//非终结符与数字对应
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
int mapVt(char c)//终结符与数字对应
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
	//消除左递归、提取左公因式后的产生式
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

	//FIRST集
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

	//FOLLOW集
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
			AnalyseTable[i][j] = "";//预测分析表项置空
		}
	}
}

void createAnalyseTable()//创建预测分析表，算法4.2
{
	for (int i = 0; i < ProductionSize; ++i)
	{
		int row = -1, col = -1, row2 = -1;//分析表横纵坐标
		char RightHead = Production[i][3];
		row = mapVn(Production[i][0]);
		if (RightHead == 'n' || RightHead == '+' || RightHead == '-'
			|| RightHead == '*' || RightHead == '/' || RightHead == '('
			|| RightHead == ')' || RightHead == '$')//为终结符时
		{
			col = mapVt(RightHead);
			AnalyseTable[row][col] = Production[i];
		}
		else if (RightHead == 'E' || RightHead == 'A' || RightHead == 'T'
			|| RightHead == 'B' || RightHead == 'F')//非终结符
		{
			int row2 = mapVn(RightHead);//非终结符
			for (int j = 0; j < FIRST[row2].size(); ++j)
			{
				if (FIRST[row2][j] != 'e')//不是A->ε
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
		else//A->ε
		{
			for (int k = 0; k < FOLLOW[row].size(); ++k)
			{
				col = mapVt(FOLLOW[row][k]);
				AnalyseTable[row][col] = Production[i];
			}
		}
	}

	for (int i = 0; i < VnSize; ++i)//对非终结符遍历
	{
		int col = -1;
		for (int j = 0; j < FOLLOW[i].size(); ++j)
		{
			col = mapVt(FOLLOW[i][j]);//b∈FOLLOW(A)
			if (AnalyseTable[i][col].empty())
			{//若M[A,b]为空，填入"synch"
				AnalyseTable[i][col] = "synch";
			}
		}
	}
		
}

string outStack()//输出站内容
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


void error1()//第一种错误，栈顶终结符与当前输入符不匹配
{
	AnalyseStack.pop();//弹出栈顶
	cout << "ERROR,X!=a,终结符不匹配" << endl;
}
void error2(char X, char a)//第二种错误，表项空白
{
	ip++;//空白，错误，跳过a
	cout << "ERROR,M[" << X << ',' << a << "]空白，跳过" << a << endl;
}
void error3(char X, char a)//第三种错误，表项为"synch"
{
	AnalyseStack.pop();//弹出栈顶
	cout << "ERROR,M[" << X << ',' << a << "]=synch，弹出" << X << endl;
}


void LL1_analyse(string w)//算法4.1,非递归预测分析方法
{
	char X;//指向栈顶文法符号
	char a;//ip所指向的输入符号
	ip = 0;//w$指针，初始指向第一个符号
	int step = 0;//记录步骤
	inputBuffer = w;
	AnalyseStack.push('$');
	AnalyseStack.push('E');
	cout << "                            分析过程" << endl;
	cout << left << setw(10) << "Step" << left << setw(20) << "Stack" << left << setw(20) << "Input" << left << setw(20) << "Output" << endl;

	do
	{
		X = AnalyseStack.top();
		a = inputBuffer[ip];
		++step;
		cout << left << setw(10) << step << left << setw(20) << outStack() << left << setw(20) << inputBuffer.substr(ip);

		if (X == 'n' || X == '+' || X == '-' || X == '*'
			|| X == '/' || X == '(' || X == ')' || X == '$')//终结符或$
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
					cout << "分析结束" << endl;
				}
					
				cout << endl;
			}
			else
			{
				error1();//第一种错误
			}
		}
		else//非终结符
		{
			int rowVn = mapVn(X);
			int colVt = mapVt(a);
			if (rowVn == -1 || colVt == -1)
			{
				cout << "输入含有错误文法符号" << endl;
				exit(0);
			}
			if (AnalyseTable[rowVn][colVt].empty()) 
			{
				error2(X, a);//第二种错误,空白
			}
			else if (AnalyseTable[rowVn][colVt] == "synch")
			{
				error3(X, a);//第三种错误synch
			}
			else//正常情况
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
		{//是数字
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


void TablePrint()//输出预测分析表
{
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "                            预测分析表M" << endl;
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