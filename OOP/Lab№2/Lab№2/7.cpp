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
	double p, s;
	int y;
	cout << "��������� �����: ";
	cin >> s;
	cout << "\n����� ���: ";
	cin >> y;
	cout << "\n�������: ";
	cin >> p;
	p /= 100;
	for (int i = 0; i < y; i++)
		s += s * p;
	cout.precision();
	cout << endl << "����� " << y << " years �� �������� " << fixed << s;
}