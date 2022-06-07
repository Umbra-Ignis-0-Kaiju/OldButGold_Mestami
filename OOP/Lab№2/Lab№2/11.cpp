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
	SetConsoleOutputCP(CP_UTF8);
	long int f1, s1, p1, f2, s2, p2;
	char t;
	do
	{
		cout << "\nВведите первый операнд, операцию, а затем второй операнд: ";
		cin >> f1 >> s1 >> p1 >> t;
		if (t == '-' || t == '+')
		{
			cin >> f2 >> s2 >> p2;
			p1 = p1 + s1 * 12 + f1 * 20 * 12;
			p2 = p2 + s2 * 12 + f2 * 20 * 12;
			if (t == '-')
				p1 = p1 - p2;
			else
				p1 = p1 + p2;
		}
		else
		{
			cin >> f2;
			p1 = p1 + s1 * 12 + f1 * 12 * 20;
			p1 = p1 * f2;
		}
		s1 = p1 / 12;
		f1 = s1 / 20;
		s1 -= f1 * 20;
		p1 -= (f1 * 240 + s1 * 12);
		cout << "\nРезультат работы: " << f1 << '.' << abs(s1) << '.' << abs(p1) << "\n\nПродолжить? (y/n)   ";
		cin >> t;
	} while (t == 'y');
}