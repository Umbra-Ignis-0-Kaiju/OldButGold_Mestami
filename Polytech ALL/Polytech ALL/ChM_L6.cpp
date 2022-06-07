#include<iostream>
#include<cmath>
#include<assert.h>
#include<algorithm>
#include<string>
using namespace std;

double f(double x)
{
	return sqrt(1 + 5 * log(x)) / x;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double suml = 0, sumr = 0, sumc = 0, a, b, h;
	cout << "������� ������� ��������� a � b: ";
	cin >> a >> b;
	cout << "\n\n��� 1 ����";
	cout << "\n����� ���������������: " << fixed << f(1) * 99;
	cout << "\n����������� ���������������: " << fixed << f(50.5) * 99;
	cout << "\n������ ��������������: " << fixed << f(100) * 99;
	h = (b - a) / 10;
	// 10 �����
	for (double i = a; i < b; i += h)
		suml += f(i);
	for (double i = a; i < b; i += h)
		sumr += f(i + h);
	for (double i = a; i < b; i += h)
		sumc += f(i + h/2);
	cout.precision();
	cout << "\n\n��� 10 �����";
	cout << "\n����� ���������������: " << fixed <<  suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr *h;

	suml = 0;
	sumr = 0;
	sumc = 0;
	h = (b - a) / 100;
	// 100 �����
	for (double i = a; i < b; i += h)
		suml += f(i);
	for (double i = a; i < b; i += h)
		sumr += f(i + h);
	for (double i = a; i < b; i += h)
		sumc += f(i + h/2);
	cout.precision();
	cout << "\n\n��� 100 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;

	suml = 0;
	sumr = 0;
	sumc = 0;
	h = (b - a) / 10000;
	// 10000 �����
	for (double i = a; i < b; i += h)
		suml += f(i); 
	for (double i = a; i < b; i += h)
		sumr += f(i + h);
	for (double i = a; i < b; i += h)
		sumc += f(i + h/2);
	cout.precision();
	cout << "\n\n��� 10000 �����";
	cout << "\n����� ���������������: " << fixed << suml * h;
	cout << "\n����������� ���������������: " << fixed << sumc * h;
	cout << "\n������ ��������������: " << fixed << sumr * h;
}