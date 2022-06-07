#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double p, s1, s2;
	int y = 0;
	cout << "Начальный вклад: ";
	cin >> s1;
	cout << "\nПроцент: ";
	cin >> p;
	cout << "\nТребуемая сумма: ";
	cin >> s2;
	p /= 100;
	for (double i = s1; i < s2; i += i * p)
		y++;
	cout << endl << "Через " << y << " years";
}