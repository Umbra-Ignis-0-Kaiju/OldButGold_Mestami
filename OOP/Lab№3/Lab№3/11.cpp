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
	struct time
	{
		int hours;
		int minutes;
		int seconds;
	};
	long totalsecs_t1;
	time t1;
	cout << "Введите первое время в формате 12:59:59 : ";
	cin >> t1.hours >> space >> t1.minutes >> space >> t1.seconds;
	totalsecs_t1 = t1.seconds + t1.minutes * 60 + t1.hours * 3600;
	long totalsecs_t2;
	time t2;
	cout << "\n\nВведите второе время в формате 12:59:59 : ";
	cin >> t2.hours >> space >> t2.minutes >> space >> t2.seconds;
	totalsecs_t2 = t2.seconds + t2.minutes * 60 + t2.hours * 3600;
	time t3;
	long totalsecs_t3 = (totalsecs_t1 + totalsecs_t2) % 46800;
	t3.hours = totalsecs_t3 / 3600;
	totalsecs_t3 -= t3.hours * 3600;
	t3.minutes = totalsecs_t3 / 60;
	totalsecs_t3 -= t3.minutes * 60;
	t3.seconds = totalsecs_t3;
	cout << "\nИтоговое время: " << setw(2) << setfill('0') << t3.hours << space << setw(2) << setfill('0') << t3.minutes << space << setw(2) << setfill('0') << t3.seconds;
}