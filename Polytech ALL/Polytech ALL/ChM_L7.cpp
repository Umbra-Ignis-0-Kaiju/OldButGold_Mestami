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
	double suml = 0, sumr = 0, sumc = 0, sumt = 0, simp = 0, a, b, h;
	int count = 0;
	cout << "Введите границы интеграла a и b: ";
	cin >> a >> b;
	/*cout << "\n\nПри 1 шаге";
	cout << "\nЛевых прямоугольников: " << fixed << f(1) * 99;
	cout << "\nЦентральных прямоугольников: " << fixed << f(50.5) * 99;
	cout << "\nПравых прямоугольнико: " << fixed << f(100) * 99;*/
	h = (b - a) / 10;
	// 10 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}	
	cout.precision();
	cout << "Ручной подсчёт: 15.568736474";
	cout << "\n\nПри 10 шагах";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 20;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 20 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 50;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 50 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 100;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 100 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 200;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 200 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 500;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 500 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 1000;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 1000 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	count = 0;
	h = (b - a) / 5000;
	// 100 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 5000 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);

	suml = 0;
	sumr = 0;
	sumc = 0;
	sumt = 0;
	simp = 0;
	h = (b - a) / 10000;
	count = 0;
	// 10000 шагов
	for (double i = a; i < b; i += h)
	{
		suml += f(i);

		sumr += f(i + h);

		sumc += f(i + h / 2);

		sumt += (f(i) + f(i + h)) / 2;

		/*if (count == 0 || count == 100)
			simp += f(i);
		else */if (count % 2 == 1)
			simp += f(i - h) + 4 * f(i) + f(i + h);
		
		count++;
	}
	cout.precision();
	cout << "\n\n\nПри 10000 шагов";
	cout << "\nЛевых прямоугольников: " << fixed << suml * h;
	cout << "\nЦентральных прямоугольников: " << fixed << sumc * h;
	cout << "\nПравых прямоугольнико: " << fixed << sumr * h;
	cout << "\n\nТрапеций: " << fixed << sumt * h;
	cout << "\n\nСимпсона: " << fixed << simp * (h / 3);
}