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
	int f1, s1, p1, f2, s2, p2;
	char t;
	do
	{
		cout << "\nВведите первое количество £ ";
		cin >> f1 >> s1 >> p1;
		cout << "\nВведите второе количество £ ";
		cin >> f2 >> s2 >> p2;
		f1 = f1 + f2 + (s1 + s2 + (p1 + p2) / 12) / 20;
		s1 = (s1 + s2 + (p1 + p2) / 12) % 20;
		p1 = (p1 + p2) % 12;
		cout << "\nВсего £ " << f1 << '.' << s1 << '.' << p1 << "\n\nПродолжить? (y/n)   ";
		cin >> t;
	} while (t == 'y');
}