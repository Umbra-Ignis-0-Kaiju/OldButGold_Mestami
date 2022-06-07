#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<windows.h>
#include<iomanip>
using namespace std;

int main()
{
	int f, s;
	float p;
	SetConsoleOutputCP(CP_UTF8);
	cout << "Введите количество фунтов: ";
	cin >> f;
	cout << "\nВведите количество шиллингов: ";
	cin >> s;
	cout << "\nВведите количество пенсов: ";
	cin >> p;
	p = abs((p + s * 12 - 1) / 240 * 100);
	cout.precision(0);
	cout << "\nКоличество десятичных фунтов: " << "£" << f << "." << fixed << p;
}