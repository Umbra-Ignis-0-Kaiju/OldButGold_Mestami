#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
class date
{
private:
	int day;
	int month;
	int year;
public:
	void getdate()
	{
		char space;
		cout << "Введите дату в формате dd/mm/yyyy: ";
		cin >> day >> space >> month >> space >> year;
	}
	void showdate()
	{
		cout << "\nВы ввели дату: " << setw(2) << setfill('0') << day << '/' << setw(2) << setfill('0') << month << '/' << setw(4) << setfill('0') << year;
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	date wat;
	wat.getdate();
	wat.showdate();
}