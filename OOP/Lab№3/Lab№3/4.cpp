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
	struct employee
	{
		int number;
		float money;
	};
	employee f, s, t;
	cout << "Введите номер и пособие первого сотрудника: ";
	cin >> f.number >> f.money;
	cout << "Введите номер и пособие второго сотрудника: ";
	cin >> s.number >> s.money;
	cout << "Введите номер и пособие третьего сотрудника: ";
	cin >> t.number >> t.money;
	cout << "\nСотрудник №" << f.number << " получает пособие в размере: " << f.money;
	cout << "\nСотрудник №" << s.number << " получает пособие в размере: " << s.money;
	cout << "\nСотрудник №" << t.number << " получает пособие в размере: " << t.money;
}