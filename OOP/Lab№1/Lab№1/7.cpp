#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
using namespace std;

int main()
{
	float T;
	setlocale(LC_ALL, "Rus");
	cout << "По Цельсию: ";
	cin >> T;
	cout.precision(2);
	cout << endl << "По Фаренгейту: " << fixed << T * (9 / 5) + 32;
}