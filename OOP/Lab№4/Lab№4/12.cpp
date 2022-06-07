#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;

	struct fraction
	{
		int chislitel;
		int znamenatel;
	};
	fraction fadd(fraction d1, fraction d2)
	{
		fraction di;
		di.chislitel = d1.chislitel * d2.znamenatel + d2.chislitel * d1.znamenatel;
		di.znamenatel = d1.znamenatel * d2.znamenatel;
		return di;
	}
	fraction fsub(fraction d1, fraction d2)
	{
		fraction di;
		di.chislitel = d1.chislitel * d2.znamenatel - d2.chislitel * d1.znamenatel;
		di.znamenatel = d1.znamenatel * d2.znamenatel;
		return di;
	}
	fraction fmul(fraction d1, fraction d2)
	{
		fraction di;
		di.chislitel = d1.chislitel * d2.chislitel;
		di.znamenatel = d1.znamenatel * d2.znamenatel;
		return di;
	}
	fraction fdiv(fraction d1, fraction d2)
	{
		fraction di;
		di.chislitel = d1.chislitel * d2.znamenatel;
		di.znamenatel = d1.znamenatel * d2.chislitel;
		return di;
	}
int main()
{
	setlocale(LC_ALL, "Rus");
	fraction d1, d2, di;
	char t, space;
	do
	{
		cout << "\nВведите первый операнд, операцию, а затем второй операнд: ";
		cin >> d1.chislitel >> space >> d1.znamenatel >> t >> d2.chislitel >> space >> d2.znamenatel;
		if (t == '+')
		{
			di = fadd(d1, d2);
		}
		else if (t == '-')
		{
			di = fsub(d1, d2);
		}
		else if (t == '*')
		{
			di = fmul(d1, d2);
		}
		else
		{
			di = fdiv(d1, d2);
		}
		cout << "Результат работы: " << di.chislitel << space << di.znamenatel << "\n\nПродолжить? (y/n)   ";
		cin >> t;
	} while (t == 'y');
}