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
	long unsigned int g, p, r = 1;
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество гостей и мест: ";
	cin >> g >> p;
	for (int i = g; i > (g - p); i--)
		r *= i;
	cout << "Возможных рассадок: " << r;
}