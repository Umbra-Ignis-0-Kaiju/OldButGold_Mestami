#include <iostream>
using namespace std;

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
	Token* atoken[100];
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

int main()
{
	setlocale(LC_ALL, "Russian");

	Stack s;
	Number n1(6.02f), n2(3.333f), n3(75.25f), n4(2.0f), n5(3.14159f);
	Operator plus('+'), mult('*'), minus('-'), div('/');
	s.push(&n1); s.push(&plus); s.push(&n2);
	s.push(&mult); s.push(&n3); s.push(&plus);
	s.push(&n4); s.push(&div); s.push(&n5);

	while (s.gettop() > 0)
	{
		if (s.isNumber())
			cout << s.pop()->getNumber();
		else
			cout << s.pop()->getOperator();
		if (s.gettop() > 0) cout << ' ';
	}
	cout << endl;

	return 0;
}
