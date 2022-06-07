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
	cout << "Введите границы интеграла a и b: ";
	cin >> a >> b;
	h = (b - a) / 10;
	// 10 шагов
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "Ручной подсчёт: 15.568736474";
	cout << "\n\nПри 10 шагах";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 20;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 20 шагов";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 50;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 50 шагов";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 100;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 100 шагов";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 200;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 200 шагов";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 500;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 500 шагов";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 1000;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 1000 шагов";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	simp = 0;
	count = 0;
	h = (b - a) / 5000;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 5000 шагов";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

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
	cout << "\n\n\nПри 10000 шагов";
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);
}