#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<iomanip>
using namespace std;

long hms_to_secs(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}

int main()
{
	int h, m, s;
	char space;
	setlocale(LC_ALL, "Rus");
	while (1)
	{
		cout << "Введите время: ";
		cin >> h >> space >> m >> space >> s;
		cout << "Количество секунд в введённом времени: " << hms_to_secs(h, m, s) << endl << endl;
	}
}