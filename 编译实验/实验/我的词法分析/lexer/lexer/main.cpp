/**
*����ʹ����������Ϣ��
*���readme.txt�ļ�
*/

#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;

ifstream fptr("test.txt");//�ļ�������

const int bufferSize = 1000;//�����������С

typedef struct id {
	string name;		//��ʶ������
	int pos;			//��ʶ����ڵ�ַ
}ID;

typedef struct error {
	int lineNum;		//����������
	int kind;			//��������
	/**
	*kind=0;ʶ�𵽷Ƿ�����,��$��/��
	*kind=1;ʶ���޷������Ĵ���
	*kind=2;ʶ���ַ������Ĵ���
	*kind=3,ʶ���ַ��������Ĵ���
	*kind=4,ʶ��ע�Ϳ첻�հ��Ĵ���
	*/
	string err;			//�������
}ERROR;

int state = 0;				//�Զ���״̬,��ʼ̬
char C = ' ';					//��ǰ�����ַ�
int iskey;				//ֵΪ-1Ϊ�Զ����ʶ��,�����ǹؼ���
string token = "";			//��ǰ����ʶ��ĵ��ʣ���ʼΪ��
char *lexemebegin;		//�ַ�ָ��ָ�����뻺�����е�ǰ���ʵĿ�ʼλ��
char *forwardptr;		 //��ǰɨ��ָ��
char bufferL[bufferSize];//��Ի����������
char bufferR[bufferSize];//��Ի������Ұ���

int lineCur = 1;			//ͳ�Ƶ�ǰ��������ʼΪ0
int charSum = 0;			//�ַ����� 

int relopCount = 0;			//��ϵ���������
int assign_opCount = 0;		//��ֵ���������
int logic_opCount = 0;		//�߼����������
int bound_opCount = 0;		//���
int arith_opCount = 0;		//���������
int bitwise_opCount = 0;		//λ�����
int other_opCount = 0;		//���������

int keywordCount = 0;		//�ؼ��ָ���
int numCount = 0;			//��������
int stringCount = 0;		//�ַ�����������
int constcharCount = 0;		//�ַ������ַ�����
int idCount = 0;			//��ʶ������
int wordCount = 0;			//���ʸ���


vector<ID>	idTable;	//��ʶ����
vector<ERROR> errorTable;//������Ϣ��

//���ַ�����,ÿ����һ��,�����뻺�����ж�һ���ַ�,����ȫ�ֱ���C��,forwardָ����һ��ָ��
void get_char();

//����,���C�Ƿ�Ϊ���ַ�,���ǣ��򷴸����ã�ֱ��CΪ�ǿ��ַ�
void get_nbc();

//����,��C���ַ���token��������
void cat();

//��������,�ж�C�Ƿ�Ϊ��ĸ,�Ƿ���true
bool isletter();

//��������,�ж�C�Ƿ�Ϊ����,�Ƿ���true
bool isdigit();

//����,��ǰɨ��ָ��forward����һ���ַ�
void retract();

//��ؼ��ֱ�,���˺�������ֵΪ0,��ʾtoken�Ǳ�ʶ��,�����ǹؼ���
int reserve();

//����ʶ��������ű�,���ز���λ��
int idTable_insert();

//������
void error(int kind);

//�Զ����ʷ���������
void DFA();

//��ӡ����ʷ��������
void printRes();

int main()
{
	cout << "�ʷ�����������output.txt�ļ�" << endl;
	FILE *outfptr;
	freopen_s(&outfptr, "output.txt", "w", stdout);//��׼�������ض���output.txt�ļ���

	bufferL[bufferSize - 1] = -1;//��뻺����ĩβ�ڱ�
	bufferR[bufferSize - 1] = -1;//�Ұ뻺����ĩβ�ڱ�
	lexemebegin = bufferL;
	forwardptr = bufferL;

	if (!fptr.is_open())
	{//δ�ҵ��ļ�
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

	while (C != EOF)//���ļ�����
	{
		DFA();
	}

	printRes();//��ӡ����ʷ��������

	forwardptr=NULL;
	lexemebegin=NULL;
	fptr.close();
	system("pause");
	return 0;
}

//���ַ�����,ÿ����һ��,�����뻺�����ж�һ���ַ�,����ȫ�ֱ���C��,forwardָ����һ��ָ��
void get_char()
{
	if ((*forwardptr) == -1)
	{
		if ((forwardptr == bufferL + bufferSize - 1))
		{
			for (int i = 0; i < bufferSize - 1; ++i)
			{
				bufferR[i] = fptr.get();//�����Ұ뻺����
				charSum++;
				if (bufferR[i] == EOF)//�����ļ�β
					break;
			}
			forwardptr = bufferR;
		}
		else if (forwardptr == bufferR + bufferSize - 1)
		{
			for (int i = 0; i < bufferSize - 1; ++i)
			{
				bufferL[i] = fptr.get();//������뻺����
				charSum++;
				if (bufferL[i] == EOF)//�����ļ�β
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

//����,���C�Ƿ�Ϊ���ַ�,���ǣ��򷴸����ã�ֱ��CΪ�ǿ��ַ�
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

//����,��C���ַ���token��������
void cat()
{
	token = token + C;
}

//��������,�ж�C�Ƿ�Ϊ��ĸ,�Ƿ���true
bool isletter()
{
	if ((C >= 'A'&&C <= 'Z') || (C >= 'a'&&C <= 'z'))
		return true;
	else
		return false;
}

//��������,�ж�C�Ƿ�Ϊ����,�Ƿ���true
bool isdigit()
{
	if (C >= '0'&&C <= '9')
		return true;
	else
		return false;
}

//����,��ǰɨ��ָ��forward����һ���ַ�
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

//��ؼ��ֱ�,���˺�������ֵΪ0,��ʾtoken�Ǳ�ʶ��,�����ǹؼ���
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

//����ʶ��������ű�,���ز���λ��
int idTable_insert()
{
	int len = idTable.size();
	for (int i = 0; i < len; ++i)
	{
		if (idTable[i].name == token)
		{
			return i;					//���ر�ʶ����ڵ�ַ
		}
	}
	ID newId;
	newId.name = token;
	newId.pos = len;
	idTable.push_back(newId);
	return len;
}

//������
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
			case 0:					//��һ�ִ�������г��ַǷ��ַ�����$��\��
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  Invalid character" << endl;
				break;
			case 1:					//�ڶ��ִ����ļ�����ĩβ��������ע��δ�պ�
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  The last line is wrong." << endl;
				break;
			case 2:					//�����ִ����޷���������E����û�����ֻ�+��-�ţ���+��-�ź���û������
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  The const num is wrong." << endl;
				break;
			case 3:					//�����ִ����ַ�������������һ���ַ�����ת���ַ�����
				cout << errorTable[i].lineNum << '\t' << "[Error]" << errorTable[i].err << "  The const char is wrong!" << endl;
				break;
			case 4:					//�����ִ��󣬿�ע�ͷ��Ų��հ������
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
		if (isletter() || C == '_')		//��ʶ��
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
						error(1);			//�ļ����һ�г��ִ���
					}
				}	
				else    //�����ַ�
				{
					cat();
					error(0);			//�Ƿ��ַ�$��\��
				}

				state = 0;
				break;
			}
		}
		break;

	case 1:				//#Ԥ����
		cat();
		get_char();
		if (C == '\n'|| C==EOF)
		{
			state = 0;
			cout << token << '\t' << '<' << "Ԥ��������" << ',' << '-' << '>' << endl;
			lineCur++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else
		{
			state = 1;
		}
		break;

	case 2:			//��ʶ��
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
				int loc = idTable_insert();//��ò����ʶ����
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
			error(2);			//�޷���������E
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
			error(2);			//�޷���������+/-
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
			state = 11;			//ת���ַ�
		}
		else
		{
			state = 10;			//�����ַ�
		}
		break;

	case 10:
		cat();
		get_char();
		if (C == '\'')			//�ַ��������ַ�������2
		{
			cat();
			state = 0;
			cout << token << '\t' << '<' << "CONST CHAR" << ',' << token << '>' << endl;
			constcharCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else			//�ַ���������
		{
			cat();
			get_char();
			while (C != '\''&&C!='\n')	
			{
				cat();
				get_char();
			}
			if (C == '\'')			//�ַ������в�ֻ��һ���ַ�����'az'
			{
				cat();
				error(3);
				state = 0;
				token.clear();
			}
			if (C == '\n')         //�ַ�������û�е����űպϣ���'a;
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
		else					//�Ƿ�ת���ַ���\w��\m
		{
			cat();
			get_char();
			while (C != '\''&&C != '\n')
			{
				cat();
				get_char();
			}
			if (C == '\'')			//�Ƿ�ת���ַ�\w��\m��
			{
				cat();
				error(3);
				state = 0;
				token.clear();
			}
			if (C == '\n')         //�ַ�������û�е����űպϣ���'\z;
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
		if (C == '\\')    //ת���ַ�
		{
			state = 13;
		}
		else if (C == '\n')
		{
			error(4);			//�ַ����м任�и���
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
			lexemebegin = forwardptr;//������
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

			error(6);			//�ַ����м�ת���ַ�����
			state = 0;
			token.clear();
		}

		break;

	case 14:			//ע�ͻ��������
		cat();
		get_char();
		if (C == '/')			//����ע��
		{
			state = 15;
		}
		else if (C == '*')		//������ע��
		{
			state = 16;
		}
		else if (C == '=')		//��ֵ�����
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
				error(1);//	ע�͵���ĩβ
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
		if (C == '=')	//���
		{
			state = 0;
			cout << "^=" << '\t' << '<' << "assign_op" << ',' << "^=" << '>' << endl;
			assign_opCount++;
			token.clear();
			lexemebegin = forwardptr;
		}
		else			//���
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
		else			//%ȡģ
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
