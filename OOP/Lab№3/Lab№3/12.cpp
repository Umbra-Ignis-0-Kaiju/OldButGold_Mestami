#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	struct fraction
	{
		int chislitel;
		int znamenatel;
	};
	fraction d1, d2, di;
	char t, space;
	do
	{
		cout << "\nВведите первый операнд, операцию, а затем второй операнд: ";
		cin >> d1.chislitel >> space >> d1.znamenatel >> t >> d2.chislitel >> space >> d2.znamenatel;
		if (t == '+')
		{
			di.chislitel = d1.chislitel * d2.znamenatel + d2.chislitel * d1.znamenatel;
			di.znamenatel = d1.znamenatel * d2.znamenatel;
		}
		else if (t == '-')
		{
			di.chislitel = d1.chislitel * d2.znamenatel - d2.chislitel * d1.znamenatel;
			di.znamenatel = d1.znamenatel * d2.znamenatel;
		}
		else if (t == '*')
		{
			di.chislitel = d1.chislitel * d2.chislitel;
			di.znamenatel = d1.znamenatel * d2.znamenatel;
		}
		else
		{
			di.chislitel = d1.chislitel * d2.znamenatel;
			di.znamenatel = d1.znamenatel * d2.chislitel;
		}
		cout << "Результат работы: " << di.chislitel << space << di.znamenatel << "\n\nПродолжить? (y/n)   ";
		cin >> t;
	} while (t == 'y');
}