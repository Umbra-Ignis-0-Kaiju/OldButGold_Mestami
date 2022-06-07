#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <windows.h>
using namespace std;

const int LEN = 80;
const int MAX = 40;

class Token
{
public:
	virtual float getNumber() const = 0;
	virtual wchar_t getOperator() const = 0;
};

class Operator : public Token
{
private:
	wchar_t oper;
public:
	Operator(wchar_t op) : oper(op)
	{ }
	wchar_t getOperator() const
	{
		return oper;
	}
	float getNumber() const
	{
		return 0.0f;
	}

};

class Number : public Token
{
private:
	float fnum;
public:
	Number(float n) : fnum(n)
	{ }
	float getNumber() const
	{
		return fnum;
	}
	wchar_t getOperator() const
	{
		return '0';
	}
};

class Stack
{
private:
	Token* atoken[MAX];
	int top;
public:
	Stack()
	{
		top = 0;
	}
	void push(Token* var)
	{
		atoken[++top] = var;
	}
	Token* pop()
	{
		return atoken[top--];
	}
	int gettop() const
	{
		return top;
	}
	bool isNumber() const
	{
		Number* pNum;
		if (pNum = dynamic_cast<Number*>(atoken[top]))
			return true;
		else
			return false;
	}
};

class express
{
private:
	Stack s;
	wchar_t* pStr;
	int len;
public:
	express(wchar_t* ptr)
	{
		pStr = ptr;
		len = wcslen(pStr);
	}
	void parse();
	float solve();
};
void express::parse()
{
	wchar_t ch;
	Token* lastval;
	Token* lastop;

	float ans;
	Number* ptrN;
	Operator* ptrO;
	wchar_t* pCurrent = pStr;

	while (pCurrent[0])
	{
		ch = pCurrent[0];

		if (ch >= '0' && ch <= '9')
		{
			ans = wcstof(pCurrent, &pCurrent);
			ptrN = new Number(ans);
			s.push(ptrN);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			if (s.gettop() == 1)
			{
				ptrO = new Operator(ch);
				s.push(ptrO);
			}
			else
			{
				lastval = s.pop();
				lastop = s.pop();
				if ((ch == '*' || ch == '/') &&
					(lastop->getOperator() == '+' || lastop->getOperator() == '-'))
				{
					s.push(lastop);
					s.push(lastval);
				}
				else
				{
					switch (lastop->getOperator())
					{
					case '+':
						ans = s.pop()->getNumber() + lastval->getNumber();
						ptrN = new Number(ans);
						s.push(ptrN);
						break;
					case '-':
						ans = s.pop()->getNumber() - lastval->getNumber();
						ptrN = new Number(ans);
						s.push(ptrN);
						break;
					case '*':
						ans = s.pop()->getNumber() * lastval->getNumber();
						ptrN = new Number(ans);
						s.push(ptrN);
						break;
					case '/':
						ans = s.pop()->getNumber() / lastval->getNumber();
						ptrN = new Number(ans);
						s.push(ptrN);
						break;
					default: cout << "\nНеизвестный знак операции\n"; exit(1);
					}
				}
				Operator* ptrO = new Operator(ch);
				s.push(ptrO);
			}
			pCurrent++;
		}
		else
		{
			cout << "\nНеразрешенный символ в арифметическом выражении\n"; exit(1);
		}
	}
}

float express::solve()
{
	Token* lastval;

	float ans;
	Number* ptrN;

	while (s.gettop() > 1)
	{
		lastval = s.pop();
		switch (s.pop()->getOperator())
		{
		case '+':
			ans = s.pop()->getNumber() + lastval->getNumber();
			ptrN = new Number(ans);
			s.push(ptrN);
			break;
		case '-':
			ans = s.pop()->getNumber() - lastval->getNumber();
			ptrN = new Number(ans);
			s.push(ptrN);
			break;
		case '*':
			ans = s.pop()->getNumber() * lastval->getNumber();
			ptrN = new Number(ans);
			s.push(ptrN);
			break;
		case '/':
			ans = s.pop()->getNumber() / lastval->getNumber();
			ptrN = new Number(ans);
			s.push(ptrN);
			break;
		default: cout << "\nНеизвестный знак операции\n"; exit(1);
		}
	}

	return s.pop()->getNumber();
}

int main()
{
	/*_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);*/
	SetConsoleOutputCP(CP_UTF8);

	wchar_t ans;
	wchar_t string[LEN];

	cout << "Введите арифметическое выражение, например: 2.5+3.0*4/3.148-2.84" << "\nЧисла могут быть вещественными и состоять из нескольких цифр." << "\nНе используйте пробелы и скобки.\n";

	do {
		cout << "\nВведите выражение: ";
		ws(wcin); wcin.get(string, LEN);

		express* eptr = new express(string);

		eptr->parse();

		cout << "Результат вычисления выражения: " << eptr->solve();
		delete eptr;

		cout << "\nЕще одно выражение (y/n)? "; wcin >> ans;
	} while (ans == 'y/n');

	return 0;
}
