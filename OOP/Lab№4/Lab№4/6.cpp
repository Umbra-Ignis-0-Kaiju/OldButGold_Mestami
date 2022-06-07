#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
struct times
{
	int hours;
	int minutes;
	int seconds;
};
times secs_to_time(int secs)
{
	times F;
	F.hours = secs / 3600;
	secs = secs % 3600;
	F.minutes = secs / 60;
	secs = secs % 60;
	F.seconds = secs;
	return F;
}
long times_to_secs(times time)
{
	return time.hours * 3600 + time.seconds + time.minutes * 60;
}
int main()
{
	char space;
	setlocale(LC_ALL, "Rus");
	long totalsecs_t1;
	times t1;
	cout << "Введите первое время в формате 12:59:59 : ";
	cin >> t1.hours >> space >> t1.minutes >> space >> t1.seconds;
	totalsecs_t1 = times_to_secs(t1);
	long totalsecs_t2;
	times t2;
	cout << "\n\nВведите второе время в формате 12:59:59 : ";
	cin >> t2.hours >> space >> t2.minutes >> space >> t2.seconds;
	totalsecs_t2 = times_to_secs(t2);
	times t3;
	long totalsecs_t3 = (totalsecs_t1 + totalsecs_t2) % 46800;
	t3 = secs_to_time(totalsecs_t3);
	cout << "\nИтоговое время: " << setw(2) << setfill('0') << t3.hours << space << setw(2) << setfill('0') << t3.minutes << space << setw(2) << setfill('0') << t3.seconds;
}