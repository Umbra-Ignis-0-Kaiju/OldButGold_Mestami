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
	long totalsecs;
	time plzno;
	cout << "Введите время в формате hh:mm:ss : ";
	cin >> plzno.hours >> space >> plzno.minutes >> space >> plzno.seconds;
	totalsecs = plzno.seconds + plzno.minutes * 60 + plzno.hours * 3600;
	cout << "\nТоталсекс = " << totalsecs;
}