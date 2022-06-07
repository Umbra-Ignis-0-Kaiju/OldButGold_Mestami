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
	int a, b, c, d;
	char sash = '/';
	setlocale(LC_ALL, "Rus");
	cout << "¬ведите первую дробь: ";
	cin >> a >> sash >> b;
	cout << "\n¬ведите вторую дробь: ";
	cin >> c >> sash >> d;
	cout << "—умма равна: " << (a * d + c * b) << '/' << d * b;
}