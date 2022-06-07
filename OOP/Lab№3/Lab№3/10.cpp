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
	struct sterling
	{
		int pounds;
		int shillings;
		int pence;
	};
	sterling more;
	SetConsoleOutputCP(CP_UTF8);
	cout << "Введите количество  десятичных фунтов: ";
	cin >> p;
	more.pounds = floor(p);
	more.shillings = (p - more.pounds) * 240 / 12;
	more.pence = int((p - more.pounds) * 240) % 12;
	cout << "\nЭквивалентная сумма в старой форме записи: " << "£" << more.pounds << "." << more.shillings << "." << more.pence;
}