#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string.h> 

class String
{
protected:

	static const int SZ = 80;
	wchar_t str[SZ];
public:
	String()
	{
		str[0] = '\0';
	}
	String(const wchar_t s[])
	{
		wcscpy(str, s);
	}
	void display() const
	{
		cout << str;
	}
	operator wchar_t* ()
	{
		return str;
	}
};
class Pstring : public String
{
public:
	Pstring() : String()
	{ }
	Pstring(const wchar_t s[]) : String(test(s))
	{ }
private:
	const wchar_t* test(const wchar_t s[])
	{
		if (wcslen(s) >= SZ)
		{
			wchar_t ts[SZ];
			int i;
			for (i = 0; i < SZ - 1; i++)
				ts[i] = s[i];
			ts[i] = '\0';
			return ts;
		}
		else
			return s;
	}
};

class Pstring2 : public Pstring
{
public:
	Pstring2() : Pstring()
	{ }
	Pstring2(const wchar_t s[]) : Pstring(s)
	{ }
	Pstring2 left(Pstring2 source_str, unsigned int n)
	{
		int i;
		for (i = 0; i < n; i++)
			str[i] = source_str[i];
		str[i] = '\0';
		return Pstring2(str);
	}
	Pstring2 mid(Pstring2 source_str, unsigned int pos, unsigned int n)
	{
		int j = 0;
		for (int i = pos; i < pos + n; i++)
			str[j++] = source_str[i];
		str[j] = '\0';
		return Pstring2(str);
	}
	Pstring2 right(Pstring2 source_str, unsigned int n)
	{
		int j = 0;
		for (int i = wcslen(source_str) - n; i < wcslen(source_str); i++)
			str[j++] = source_str[i];
		str[j] = '\0';
		return Pstring2(str);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Pstring2 s1;

	wchar_t xstr[] = "Ура, товарищи! ";

	s1 = xstr;

	s1.display();

	Pstring2 s2 = "Мы победим!";
	cout << static_cast<wchar_t*>(s2);
	cout << endl;

	Pstring2 s3 = "Эта строка имеет очень большую длину и мы можем быть уверены, что она не "
		"уместится в отведенный буфер, что приведет к непредсказуемым последствиям.";

	s3.display();
	cout << endl;
	Pstring2 s4;

	cout << "Было:   s1 = "; s1.display(); cout << endl;
	cout << "        s2 = "; s2.display(); cout << endl;
	cout << "        s4 = "; s4.display(); cout << endl;

	s2.left(s1, 3);
	s4 = s2.left(s1, 3);

	cout << "Стало1: s1 = "; s1.display(); cout << endl;
	cout << "        s2 = "; s2.display(); cout << endl;
	cout << "        s4 = "; s4.display(); cout << endl;

	s2.mid(s1, 5, 5);
	s4 = s2.mid(s1, 5, 5);

	cout << "Стало2: s1 = "; s1.display(); cout << endl;
	cout << "        s2 = "; s2.display(); cout << endl;
	cout << "        s4 = "; s4.display(); cout << endl;

	s2.right(s1, 4);
	s4 = s2.right(s1, 4);

	cout << "Стало3: s1 = '"; s1.display(); cout << "'" << endl;
	cout << "        s2 = '"; s2.display(); cout << "'" << endl;
	cout << "        s4 = '"; s4.display(); cout << "'" << endl;

	return 0;
}
