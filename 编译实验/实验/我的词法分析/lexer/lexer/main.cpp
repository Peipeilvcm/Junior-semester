/**
*程序使用与其它信息，
*详见readme.txt文件
*/

#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;

ifstream fptr("test.txt");//文件输入流

const int bufferSize = 1000;//半个缓冲区大小

typedef struct id {
	string name;		//标识符名字
	int pos;			//标识符入口地址
}ID;

typedef struct error {
	int lineNum;		//错误发生行数
	int kind;			//错误类型
	/**
	*kind=0;识别到非法符号,如$、/等
	*kind=1;识别到无符号数的错误，
	*kind=2;识别字符常量的错误
	*kind=3,识别字符串常量的错误
	*kind=4,识别注释快不闭包的错误
	*/
	string err;			//错误输出
}ERROR;

int state = 0;				//自动机状态,初始态
char C = ' ';					//当前读入字符
int iskey;				//值为-1为自定义标识符,否则是关键字
string token = "";			//当前正在识别的单词，初始为空
char *lexemebegin;		//字符指针指向输入缓冲区中当前单词的开始位置
char *forwardptr;		 //向前扫描指针
char bufferL[bufferSize];//配对缓冲区左半区
char bufferR[bufferSize];//配对缓冲区右半区

int lineCur = 1;			//统计当前行数，初始为0
int charSum = 0;			//字符总数 

int relopCount = 0;			//关系运算符个数
int assign_opCount = 0;		//赋值运算符个数
int logic_opCount = 0;		//逻辑运算符个数
int bound_opCount = 0;		//界符
int arith_opCount = 0;		//算术运算符
int bitwise_opCount = 0;		//位运算符
int other_opCount = 0;		//其它运算符

int keywordCount = 0;		//关键字个数
int numCount = 0;			//常数个数
int stringCount = 0;		//字符串常量个数
int constcharCount = 0;		//字符常量字符个数
int idCount = 0;			//标识符个数
int wordCount = 0;			//单词个数


vector<ID>	idTable;	//标识符表
vector<ERROR> errorTable;//报错信息表

//读字符过程,每调用一次,从输入缓冲区中读一个字符,放入全局变量C中,forward指向下一个指针
void get_char();

//过程,检查C是否为空字符,若是，则反复调用，直到C为非空字符
void get_nbc();

//过程,把C中字符与token连接起来
void cat();

//布尔函数,判断C是否为字母,是返回true
bool isletter();

//布尔函数,判断C是否为数字,是返回true
bool isdigit();

//过程,向前扫描指针forward后退一个字符
void retract();

//查关键字表,若此函数返回值为0,表示token是标识符,否则是关键字
int reserve();

//将标识符插入符号表,返回插入位置
int idTable_insert();

//错误处理
void error(int kind);

//自动机词法分析主体
void DFA();

//打印输出词法分析结果
void printRes();

int main()
{
	cout << "词法分析结果详见output.txt文件" << endl;
	FILE *outfptr;
	freopen_s(&outfptr, "output.txt", "w", stdout);//标准输出输出重定向到output.txt文件中

	bufferL[bufferSize - 1] = -1;//左半缓冲区末尾哨兵
	bufferR[bufferSize - 1] = -1;//右半缓冲区末尾哨兵
	lexemebegin = bufferL;
	forwardptr = bufferL;

	if (!fptr.is_open())
	{//未找到文件
		cout << "ERROR OPENING THE SOURCR FILE";
		exit(-1);
	}

	for (int i = 0; i < bufferSize - 1; ++i)
	{
		bufferL[i] = fptr.get();
		charSum++;
		//cout << bufferL[i];
		if (bufferL[i] == EOF)
		{
			break;
		}
	}

	while (C != EOF)//到文件结束
	{
		DFA();
	}

	printRes();//打印输出词法分析结果

	forwardptr=NULL;
	lexemebegin=NULL;
	fptr.close();
	system("pause");
	return 0;
}

//读字符过程,每调用一次,从输入缓冲区中读一个字符,放入全局变量C中,forward指向下一个指针
void get_char()
{
	if ((*forwardptr) == -1)
	{
		if ((forwardptr == bufferL + bufferSize - 1))
		{
			for (int i = 0; i < bufferSize - 1; ++i)
			{
				bufferR[i] = fptr.get();//填入右半缓冲区
				charSum++;
				if (bufferR[i] == EOF)//读到文件尾
					break;
			}
			forwardptr = bufferR;
		}
		else if (forwardptr == bufferR + bufferSize - 1)
		{
			for (int i = 0; i < bufferSize - 1; ++i)
			{
				bufferL[i] = fptr.get();//填入左半缓冲区
				charSum++;
				if (bufferL[i] == EOF)//读到文件尾
					break;
			}
		}
		else
		{
			fptr.close();
		}
	}
	C = *forwardptr;
	forwardptr++;
}

//过程,检查C是否为空字符,若是，则反复调用，直到C为非空字符
void get_nbc()
{
	while (' ' == C || '\t' == C || '\n' == C)
	{
		if (C == '\n')
		{
			lineCur++;
		}
		get_char();
	}
}

//过程,把C中字符与token连接起来
void cat()
{
	token = token + C;
}

//布尔函数,判断C是否为字母,是返回true
bool isletter()
{
	if ((C >= 'A'&&C <= 'Z') || (C >= 'a'&&C <= 'z'))
		return true;
	else
		return false;
}

//布尔函数,判断C是否为数字,是返回true
bool isdigit()
{
	if (C >= '0'&&C <= '9')
		return true;
	else
		return false;
}

//过程,向前扫描指针forward后退一个字符
void retract()
{
	if (forwardptr == bufferL)
	{
		forwardptr = bufferR + bufferSize - 1;
	}
	else if (forwardptr == bufferR)
	{
		forwardptr = bufferL + bufferSize - 1;
	}
	else
	{
		forwardptr--;
	}
	//C = *forwardptr;
}

//查关键字表,若此函数返回值为0,表示token是标识符,否则是关键字
int reserve()
{
	if (token == "void" || token == "char" || token == "int" || token == "short"
		|| token == "float" || token == "double" || token == "long" || token == "signed"
		|| token == "unsigned" || token == "struct" || token == "union" || token == "enum"
		|| token == "typedef" || token == "sizeof" || token == "auto" || token == "static"
		|| token == "register" || token == "extern" || token == "const" || token == "volatile"
		|| token == "return" || token == "continue" || token == "break" || token == "goto"
		|| token == "if" || token == "else" || token == "switch" || token == "case"
		|| token == "default" || token == "for" || token == "do" || token == "while")
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

//将标识符插入符号表,返回插入位置
int idTable_insert()
{
	int len = idTable.size();
	for (int i = 0; i < len; ++i)
	{
		if (idTable[i].name == token)
		{
			return i;					//返回标识符入口地址
		}
	}
	ID newId;
	newId.name = token;
	newId.pos = len;
	idTable.push_back(newId);
	return len;
}

//错误处理
void error(int kind)
{
	ERROR newError;
	newError.lineNum = lineCur;
	newError.kind = kind;
	newError.err = token;
	errorTable.push_back(newError);
	lexemebegin = forwardptr;
}

void printRes()
{
	wordCount = idCount + keywordCount + stringCount + numCount + relopCount + assign_opCount + logic_opCount + arith_opCount + bitwise_opCount + other_opCount;
	cout << "-----------------------------\n- Statistics:" << endl;
	cout << "totoal line numbers: " << lineCur << endl;
	cout << "total char Sum:" << charSum << endl;
	cout << "total word Sum:" << wordCount << endl;
	cout << "---" << endl;
	cout << "relation operator: " << relopCount << endl;
	cout << "assign operator:" << assign_opCount << endl;
	cout << "logic operator:" << logic_opCount << endl;
	cout << "bound operator:" << bound_opCount << endl;
	cout << "arith operator:" << arith_opCount << endl;
	cout << "bitwise operator:" << bitwise_opCount << endl;
	cout << "other operator:" << other_opCount << endl;
	cout << "---" << endl;
	cout << "keyword Sum:" << keywordCount << endl;
	cout << "const numbers: " << numCount << endl;
	cout << "const strings: " << stringCount << endl;
	cout << "ids:" << idCount << endl;
	cout << "kinds of ids:" << idTable.size() << endl;
	

	if (errorTable.empty())
	{
		cout << "-----------------------------\n- Errors: 0" << endl;
	}
	else
	{
		cout << "-----------------------------\n- Errors:" << endl;
		cout << "line" << '\t' << "Error" << endl;
		int n = errorTable.size();
		for (int i = 0; i < n; ++i)
		{
			switch (errorTable[i].kind)
			{
			case 0:					//第一种错误，语句中出现非法字符，如$、\等
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  Invalid character" << endl;
				break;
			case 1:					//第二种错误，文件结束末尾出错，比如注释未闭合
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  The last line is wrong." << endl;
				break;
			case 2:					//第三种错误，无符号数出错，E后面没跟数字或+、-号，或+、-号后面没跟数字
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  The const num is wrong." << endl;
				break;
			case 3:					//第四种错误，字符常量出错，超过一个字符，或转义字符出错
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  The const char is wrong!" << endl;
				break;
			case 4:					//第五种错误，块注释符号不闭包的情况
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  The const string lose a \" wrongly!" << endl;
				break;
			default:
				cout << errorTable[i].lineNum << '\t' << "[Error]" << "Unknown Error!" << endl;
			}

		}
	}
}

void DFA()
{
	switch (state)
	{
	case 0:
		get_char();
		get_nbc();
		if (isletter() || C == '_')		//标识符
		{
			state = 2;
		}
		else if (isdigit())
		{
			state = 3;
		}
		else
		{
			switch (C)
			{
			case '#':
				state = 1;
				break;
			case '\'':
				state = 9;
				break;
			case '"':
				state = 12;
				break;
			case '/':
				state = 14;
				break;
			case '<':
				state = 19;
				break;
			case '>':
				state = 20;
				break;
			case '!':
				state = 21;
				break;
			case '&':
				state = 22;
				break;
			case '|':
				state = 23;
				break;
			case '~':
				state = 24;
				break;
			case '^':
				state = 25;
				break;
			case '%':
				state = 26;
				break;
			case '*':
				state = 27;
				break;
			case '+':
				state = 28;
				break;
			case '-':
				state = 29;
				break;
			case '=':
				state = 30;
				break;
			case '?':
				state = 0;
				cout << '?' << '\t' << '<' << "other_op" << ',' << '?' << '>' << endl;
				other_opCount++;
				lexemebegin = forwardptr;
				break;
			case ':':
				state = 0;
				cout << ':' << '\t' << '<' << "other_op" << ',' << ':' << '>' << endl;
				other_opCount++;
				lexemebegin = forwardptr;
				break;
			case '.':
				state = 0;
				cout << '.' << '\t' << '<' << "other_op" << ',' << '.' << '>' << endl;
				other_opCount++;
				lexemebegin = forwardptr;
				break;
			case '(':
				state = 0;
				cout << '(' << '\t' << '<' << "bound_op" << ',' << '(' << '>' << endl;
				bound_opCount++;
				lexemebegin = forwardptr;
				break;
			case ')':
				state = 0;
				cout << ')' << '\t' << '<' << "bound_op" << ',' << ')' << '>' << endl;
				bound_opCount++;
				lexemebegin = forwardptr;
				break;
			case '{':
				state = 0;
				cout << '{' << '\t' << '<' << "bound_op" << ',' << '{' << '>' << endl;
				bound_opCount++;
				lexemebegin = forwardptr;
				break;
			case '}':
				state = 0;
				cout << '}' << '\t' << '<' << "bound_op" << ',' << '}' << '>' << endl;
				bound_opCount++;
				lexemebegin = forwardptr;
				break;
			case '[':
				state = 0;
				cout << '[' << '\t' << '<' << "bound_op" << ',' << '[' << '>' << endl;
				bound_opCount++;
				lexemebegin = forwardptr;
				break;
			case ']':
				state = 0;
				cout << ']' << '\t' << '<' << "bound_op" << ',' << ']' << '>' << endl;
				bound_opCount++;
				lexemebegin = forwardptr;
				break;
			case ',':
				state = 0;
				cout << ',' << '\t' << '<' << "bound_op" << ',' << ',' << '>' << endl;
				bound_opCount++;
				lexemebegin = forwardptr;
				break;
			case ';':
				state = 0;
				cout << ';' << '\t' << '<' << "bound_op" << ',' << ';' << '>' << endl;
				bound_opCount++;
				lexemebegin = forwardptr;
				break;
			default:
				if (C == EOF)
				{
					cout << "END OF C_FILE";
					if (state != 0)
					{
						error(1);			//文件最后一行出现错误
					}
				}	
				else    //错误字符
				{
					cat();
					error(0);			//非法字符$、\等
				}

				state = 0;
				break;
			}
		}
		break;

	case 1:				//#预编译
		cat();
		get_char();
		if (C == '\n'|| C==EOF)
		{
			state = 0;
			cout << token << '\t' << '<' << "预编译命令" << ',' << '-' << '>' << endl;
			lineCur++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else
		{
			state = 1;
		}
		break;

	case 2:			//标识符
		cat();
		get_char();
		if (isletter() || isdigit() || C == '_')
		{
			state = 2;
		}
		else
		{
			//cout << *forwardptr;
			retract();
			//cout << *forwardptr;
			state = 0;
			iskey = reserve();
			if (iskey == 1)
			{
				cout << token << '\t' << '<' << token << ',' << '-' << '>' << endl;
				keywordCount++;
				token.clear();
				lexemebegin = forwardptr;

			}
			else
			{
				int loc = idTable_insert();//获得插入标识符表
				cout << token << '\t' << '<' << "ID" << ',' << loc << '>' << endl;
				idCount++;
				token.clear();
				lexemebegin = forwardptr;
			}
		}
		break;

	case 3:
		cat();
		get_char();
		if (isdigit())
		{
			state = 3;
		}
		else if (C == '.')
		{
			state = 4;
		}
		else if (C == 'E')
		{
			state = 6;
		}
		else
		{
			retract();
			state = 0;
			cout << token << '\t' << '<' << "NUM" << ',' << atoi(token.c_str()) << '>' << endl;
			numCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 4:
		cat();
		get_char();
		if (isdigit())
		{
			state = 5;

		}
		else
		{
			retract();
			state = 0;
			cout << token << '\t' << '<' << "NUM" << ',' << atof(token.c_str()) << '>' << endl;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 5:
		cat();
		get_char();
		if (isdigit())
		{
			state = 5;
		}
		else if (C == 'E')
		{
			state = 6;
		}
		else
		{
			retract();
			state = 0;
			cout << token << '\t' << '<' << "NUM" << ',' << atof(token.c_str()) << '>' << endl;
			numCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 6:
		cat();
		get_char();
		if (isdigit())
		{
			state = 8;
		}
		else if (C == '+' || C == '-')
		{
			state = 7;
		}
		else
		{
			retract();
			error(2);			//无符号数出错E
			state = 0;
			token.clear();
		}
		break;

	case 7:
		cat();
		get_char();
		if (isdigit())
		{
			state = 8;
		}
		else
		{
			retract();
			error(2);			//无符号数出错+/-
			state = 0;
			token.clear();
		}
		break;

	case 8:
		cat();
		get_char();
		if (isdigit())
		{
			state = 8;
		}
		else
		{
			retract();
			state = 0;
			cout << token << '\t' << '<' << "NUM" << ',' << atof(token.c_str()) << '>' << endl;
			numCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 9:
		cat();
		get_char();
		if (C == '\\')
		{
			state = 11;			//转义字符
		}
		else
		{
			state = 10;			//正常字符
		}
		break;

	case 10:
		cat();
		get_char();
		if (C == '\'')			//字符常量中字符数超过2
		{
			cat();
			state = 0;
			cout << token << '\t' << '<' << "CONST CHAR" << ',' << token << '>' << endl;
			constcharCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else			//字符常量错误
		{
			cat();
			get_char();
			while (C != '\''&&C!='\n')	
			{
				cat();
				get_char();
			}
			if (C == '\'')			//字符常量中不只有一个字符，如'az'
			{
				cat();
				error(3);
				state = 0;
				token.clear();
			}
			if (C == '\n')         //字符常量中没有单引号闭合，如'a;
			{
				retract();
				error(3);
				state = 0;
				token.clear();
			}
		}
		break;

	case 11:
		cat();
		get_char();
		if ('0' == C || 'n' == C || 'a' == C || 'b' == C || 'f' == C || 'r' == C
			|| 't' == C || 'v' == C || '\\' == C || '\'' == C )
		{
			state = 10;
		}
		else					//非法转移字符如\w、\m
		{
			cat();
			get_char();
			while (C != '\''&&C != '\n')
			{
				cat();
				get_char();
			}
			if (C == '\'')			//非法转义字符\w、\m等
			{
				cat();
				error(3);
				state = 0;
				token.clear();
			}
			if (C == '\n')         //字符常量中没有单引号闭合，如'\z;
			{
				retract();
				error(3);
				state = 0;
				token.clear();
			}
		}
		break;

	case 12:
		cat();
		get_char();
		if (C == '\\')    //转义字符
		{
			state = 13;
		}
		else if (C == '\n')
		{
			error(4);			//字符串中间换行隔断
			retract();
			state = 0;
			token.clear();
		}
		else if (C == '"')
		{
			cat();
			state = 0;
			cout << token << '\t' << '<' << "CONST STRING" << ',' << token << '>' << endl;
			stringCount++;
			token.clear();
			lexemebegin = forwardptr;//有问题
		}
		else
		{
			state = 12;
		}
		break;

	case 13:
		cat();
		get_char();
		if ('0' == C || 'n' == C || 'a' == C || 'b' == C || 'f' == C || 'r' == C
			|| 't' == C || 'v' == C || '\\' == C || '\'' == C)
		{
			state = 12;
		}
		else
		{

			error(6);			//字符串中间转义字符错误
			state = 0;
			token.clear();
		}

		break;

	case 14:			//注释或除法运算
		cat();
		get_char();
		if (C == '/')			//单行注释
		{
			state = 15;
		}
		else if (C == '*')		//跳到块注释
		{
			state = 16;
		}
		else if (C == '=')		//赋值运算符
		{
			state = 18;
		}
		else
		{
			retract();
			state = 0;
			cout << '/' << '\t' << '<' << "arith_op" << ',' << '/' << '>' << endl;
			arith_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 15:
		get_char();
		if (C == '\n' || C == EOF)
		{
			retract();
			state = 0;
			token.clear();
			lexemebegin = forwardptr;
		}
		else
		{
			state = 15;
		}
		break;

	case 16:
		get_char();
		if (C == '*')
		{
			state = 17;
		}
		else
		{
			if (C == '\n')
				lineCur++;
			if (C == EOF)
			{
				error(1);//	注释到了末尾
			}
			state = 16;
		}
		break;

	case 17:
		get_char();
		if (C == '/')
		{
			state = 0;
			token.clear();
			lexemebegin = forwardptr;
		}
		else
		{
			if (C == EOF)
			{
				error(1);
			}
			state = 16;
		}
		break;

	case 18:
		cat();
		state = 0;
		cout << token << '\t' << '<' << "assign_op" << ',' << '-' << '>' << endl;
		assign_opCount++;
		token.clear();
		lexemebegin = forwardptr;

		break;

	case 19:
		cat();
		get_char();
		if (C == '=')	// <=
		{
			state = 0;
			cout << "<=" << '\t' << '<' << "relop" << ',' << "LE" << '>' << endl;
			relopCount++;
			lexemebegin = forwardptr;
			token.clear();
		}
		else if (C == '<')	// <<
		{
			state = 0;
			cout << "<<" << '\t' << '<' << "bitwise_op" << ',' << "<<" << '>' << endl;
			bitwise_opCount++;
			lexemebegin = forwardptr;
			token.clear();
		}
		else
		{				// <
			retract();
			state = 0;
			cout << '<' << '\t' << '<' << "relop" << ',' << "LT" << '>' << endl;
			relopCount++;
			lexemebegin = forwardptr;
			token.clear();
		}
		break;

	case 20:				// >
		cat();
		get_char();
		if (C == '=')	// >=
		{
			state = 0;
			cout << ">=" << '\t' << '<' << "relop" << ',' << "GE" << '>' << endl;
			relopCount++;
			lexemebegin = forwardptr;
			token.clear();
		}
		else if (C == '>')	// >>
		{
			state = 0;
			cout << ">>" << '\t' << '<' << "bitwise_op" << ',' << ">>" << '>' << endl;
			bitwise_opCount++;
			lexemebegin = forwardptr;
			token.clear();
		}
		else
		{				// >
			retract();
			state = 0;
			cout << '<' << '\t' << '<' << "relop" << ',' << "GT" << '>' << endl;
			relopCount++;
			lexemebegin = forwardptr;
			token.clear();
		}
		break;

	case 21:			//!
		cat();
		get_char();
		if (C == '=')	//!=
		{
			state = 0;
			cout << "!=" << '\t' << '<' << "relop" << ',' << "NE" << '>' << endl;
			relopCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else			// !
		{
			retract();
			state = 0;
			cout << '!' << '\t' << '<' << "logic_op" << ',' << token << '>' << endl;
			logic_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 22:			//&
		cat();
		get_char();
		if (C == '&')
		{
			state = 0;
			cout << "&&" << '\t' << '<' << "logic_op" << ',' << "&&" << '>' << endl;
			logic_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else if (C == '=')
		{
			state = 0;
			cout << "&=" << '\t' << '<' << "assign_op" << ',' << "&=" << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else
		{
			retract();
			state = 0;
			cout << '&' << '\t' << '<' << "bitwise_op" << ',' << '&' << '>' << endl;
			bitwise_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 23:		//|
		cat();
		get_char();
		if (C == '|')
		{
			state = 0;
			cout << "||" << '\t' << '<' << "logic_op" << ',' << "||" << '>' << endl;
			logic_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else if (C == '=')
		{
			state = 0;
			cout << "|=" << '\t' << '<' << "assign_op" << ',' << "|=" << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else
		{
			retract();
			state = 0;
			cout << '|' << '\t' << '<' << "bitwise_op" << ',' << '|' << '>' << endl;
			bitwise_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 24:			//~
		state = 0;
		cout << '~' << '\t' << '<' << "bitwise_op" << ',' << '~' << '>' << endl;
		bitwise_opCount++;
		token.clear();
		lexemebegin = forwardptr;
		break;

	case 25:		//^
		cat();
		get_char();
		if (C == '=')	//异或
		{
			state = 0;
			cout << "^=" << '\t' << '<' << "assign_op" << ',' << "^=" << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else			//异或
		{
			retract();
			state = 0;
			cout << '^' << '\t' << '<' << "bitwise_op" << ',' << '^' << '>' << endl;
			bitwise_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 26:			//%
		cat();
		get_char();
		if (C == '=')	//%=
		{
			state = 0;
			cout << "%=" << '\t' << '<' << "assign_op" << ',' << "%=" << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else			//%取模
		{
			retract();
			state = 0;
			cout << '%' << '\t' << '<' << "arith_op" << ',' << '%' << '>' << endl;
			arith_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 27:			//*
		cat();
		get_char();
		if (C == '=')	//*=
		{
			state = 0;
			cout << "*=" << '\t' << '<' << "assign_op" << ',' << "*=" << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else			//*
		{
			retract();
			state = 0;
			cout << '*' << '\t' << '<' << "arith_op" << ',' << '*' << '>' << endl;
			arith_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 28:			//+
		cat();
		get_char();
		if (C == '+')	//++
		{
			state = 0;
			cout << "++" << '\t' << '<' << "arith_op" << ',' << "++" << '>' << endl;
			arith_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else if (C == '=')	//+=
		{
			state = 0;
			cout << "+=" << '\t' << '<' << "assign_op" << ',' << "+=" << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else				//+
		{
			retract();
			state = 0;
			cout << '+' << '\t' << '<' << "arith_op" << ',' << '+' << '>' << endl;
			arith_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 29:			//-
		cat();
		get_char();
		if (C == '-')	//--
		{
			state = 0;
			cout << "--" << '\t' << '<' << "arith_op" << ',' << "--" << '>' << endl;
			arith_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else if (C == '=')	//-=
		{
			state = 0;
			cout << "--" << '\t' << '<' << "assign_op" << ',' << "--" << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else if (C == '>')		//->
		{
			state = 0;
			cout << "->" << '\t' << '<' << "other_op" << ',' << "->" << '>' << endl;
			other_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else				//-
		{
			retract();
			state = 0;
			cout << '-' << '\t' << '<' << "arith_op" << ',' << '-' << '>' << endl;
			arith_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	case 30:			//=
		cat();
		get_char();
		if (C == '=')	//==
		{
			state = 0;
			cout << "==" << '\t' << '<' << "relop_op" << ',' << "EQ" << '>' << endl;
			relopCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else			//=
		{
			retract();
			state = 0;
			cout << '=' << '\t' << '<' << "assign_op" << ',' << '=' << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		break;

	default:
		cout << "unknow error" << endl;
		exit(0);
	}
}
