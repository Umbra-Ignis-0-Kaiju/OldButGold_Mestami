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
	struct fraction
	{
		int chislitel;
		int znamenatel;
	};
	fraction one, two, sum;
	char sash = '/';
	setlocale(LC_ALL, "Rus");
	cout << "������� ������ �����: ";
	cin >> one.chislitel >> sash >> one.znamenatel;
	cout << "\n������� ������ �����: ";
	cin >> two.chislitel >> sash >> two.znamenatel;
	sum.chislitel = one.chislitel * two.znamenatel + two.chislitel * one.znamenatel;
	sum.znamenatel = one.znamenatel * two.znamenatel;
	cout << "\n\n����� �����: " << sum.chislitel << '/' << sum.znamenatel;
}