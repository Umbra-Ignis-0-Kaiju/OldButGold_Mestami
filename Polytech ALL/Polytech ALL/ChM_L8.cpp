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
	double simp = 0, a, b, h;
	int count = 0;
	cout << "������� ������� ��������� a � b: ";
	cin >> a >> b;
	h = (b - a) / 10;
	// 10 �����
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "������ �������: 15.568736474";
	cout << "\n\n��� 10 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 20;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 20 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 50;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 50 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 100;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 100 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 200;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 200 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 500;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 500 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 1000;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 1000 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 5000;
	// 100 �����
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 5000 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);

	simp = 0;
	h = (b - a) / 10000;
	count = 0;
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\n��� 10000 �����";
	cout << "\n\n��������: " << fixed << simp * (h / 3);
}