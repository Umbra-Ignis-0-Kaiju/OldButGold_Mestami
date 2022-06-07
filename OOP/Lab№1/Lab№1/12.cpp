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
	char lock;
	float p;
	SetConsoleOutputCP(CP_UTF8);
	cout << "Введите количество  десятичных фунтов: ";
	cin >> f >> lock >> p;
	p = ceil(p * 240 / 100);
	s = p / 12;
	p = p - s * 12;
	cout << "\nЭквивалентная сумма в старой форме записи: " << "£" << f << "." << s << "." << p;
}