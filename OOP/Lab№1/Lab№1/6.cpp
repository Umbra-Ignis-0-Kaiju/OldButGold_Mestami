#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
using namespace std;

int main()
{
	float M;
	setlocale(LC_ALL, "Rus");
	cout << "��������: ";
	cin >> M;
	cout.precision(2);
	cout << endl << "� ������ ����������: " << fixed << M / 1.487;
	cout << endl << "� �������: " << fixed << M / 0.172;
	cout << endl << "� �������� ������: " << fixed << M / 0.584;
	cout << endl << "� �������� �����: " << fixed << M / 0.00955;
}