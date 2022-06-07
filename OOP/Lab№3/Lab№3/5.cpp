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
	char space;
	setlocale(LC_ALL, "Rus");
	struct date
	{
		int day;
		int month;
		int year;
	};
	date once;
	cout << "Введите дату в формате dd/mm/yyyy: ";
	cin >> once.day >> space >> once.month >> space >> once.year;
	cout << "\nВы ввели дату: " << setw(2) << setfill('0') << once.day << space << setw(2) << setfill('0') << once.month << space << setw(4) << setfill('0') << once.year;
}