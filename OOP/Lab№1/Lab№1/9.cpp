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
	cout << "������� ������ �����: ";
	cin >> a >> sash >> b;
	cout << "\n������� ������ �����: ";
	cin >> c >> sash >> d;
	cout << "����� �����: " << (a * d + c * b) << '/' << d * b;
}