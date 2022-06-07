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
	cout << "Введите границы интеграла a и b: ";
	cin >> a >> b;
	cout << "\n\nПри 1 шаге";
	cout << "\nЛевых прямоугольников: " << fixed << f(1) * 99;
	cout << "\nЦентральных прямоугольников: " << fixed << f(50.5) * 99;
	cout << "\nПравых прямоугольнико: " << fixed << f(100) * 99;
	h = (b - a) / 10;
	// 10 шагов
	for (double i = a; i < b; i += h)
		suml += f(i);
	for (double i = a; i < b; i += h)
		sumr += f(i + h);
	for (double i = a; i < b; i += h)
		sumc += f(i + h/2);
	cout.precision();
	cout << "\n\nПри 10 шагах";
	cout << "\nЛевых прямоугольников: " << fixed <<  suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr *h;

	suml = 0;
	sumr = 0;
	sumc = 0;
	h = (b - a) / 100;
	// 100 шагов
	for (double i = a; i < b; i += h)
		suml += f(i);
	for (double i = a; i < b; i += h)
		sumr += f(i + h);
	for (double i = a; i < b; i += h)
		sumc += f(i + h/2);
	cout.precision();
	cout << "\n\nПри 100 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;

	suml = 0;
	sumr = 0;
	sumc = 0;
	h = (b - a) / 10000;
	// 10000 шагов
	for (double i = a; i < b; i += h)
		suml += f(i); 
	for (double i = a; i < b; i += h)
		sumr += f(i + h);
	for (double i = a; i < b; i += h)
		sumc += f(i + h/2);
	cout.precision();
	cout << "\n\nПри 10000 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
}