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
	cout << "�� �������: ";
	cin >> T;
	cout.precision(2);
	cout << endl << "�� ����������: " << fixed << T * (9 / 5) + 32;
}