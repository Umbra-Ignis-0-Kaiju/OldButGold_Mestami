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
	cout << "¬ведите первую дробь: ";
	cin >> one.chislitel >> sash >> one.znamenatel;
	cout << "\n¬ведите вторую дробь: ";
	cin >> two.chislitel >> sash >> two.znamenatel;
	sum.chislitel = one.chislitel * two.znamenatel + two.chislitel * one.znamenatel;
	sum.znamenatel = one.znamenatel * two.znamenatel;
	cout << "\n\n—умма равна: " << sum.chislitel << '/' << sum.znamenatel;
}