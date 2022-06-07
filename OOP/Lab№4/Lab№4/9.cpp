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
void swap(times& x, times& y)
{
	times t;
	t = x;
	x = y;
	y = t;
}
int main()
{
	char space;
	setlocale(LC_ALL, "Rus");
	
	times one;
	cout << "¬ведите one врем€ в формате 12:59:59 : ";
	cin >> one.hours >> space >> one.minutes >> space >> one.seconds;
	
	
	times two;
	cout << "\n\n¬ведите two врем€ в формате 12:59:59 : ";
	cin >> two.hours >> space >> two.minutes >> space >> two.seconds;
	swap(one, two);
	cout << "\nOne: " << setw(2) << setfill('0') << one.hours << space << setw(2) << setfill('0') << one.minutes << space << setw(2) << setfill('0') << one.seconds;
	cout << "\nTwo: " << setw(2) << setfill('0') << two.hours << space << setw(2) << setfill('0') << two.minutes << space << setw(2) << setfill('0') << two.seconds;
}