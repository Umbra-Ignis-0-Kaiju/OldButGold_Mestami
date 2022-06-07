#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include <windows.h>
using namespace std;

double f(double x) // Подсчёт значения y в точке x
{
	return x * x - 2 * cos(x) + 1;
}
double fp(double x)
{
	return 2 * x + 2 * sin(x);
}

int main()
{
	double a, b, E, x, count = 1, Z, A, B;
	SetConsoleOutputCP(CP_UTF8);
	cout << "Введите концы отрезка a и b, а так же точность E: ";
	cin >> a >> b >> E;
	A = a;
	B = b;
	
	double fppa = 2 * cos(a) + 2; // Вторая производная от f(x) = y
	double fppb = 2 * cos(b) + 2;
	cout << "\nМетод Ньютона:";

	if (fppa * f(a) > 0)
	{
		while (!((f(x + E) > 0 && f(x - E) < 0) || (f(x + E) < 0 && f(x - E) > 0)))
		{
			x = x - (f(x) / fp(x));
			count++;
		}
		cout << endl << x << " " << E << " " << count;
	}
	else if (fppb * f(b) > 0)
	{
		Z = b;
		x = Z - (f(b) / fp(b));
		/*while (abs(x - Z) > E)*/
		while (!((f(x + E) > 0 && f(x - E) < 0) || (f(x + E) < 0 && f(x - E) > 0)))
		{
			Z = x;
			x = x - (f(x) / fp(x));
			count++;
		}
		cout << endl << x << " " << E << " " << count;
	}
	else
		cout << endl << "Метод Ньютона неприменим с данными значениями.";
	a = A;
	b = B;
	count = 1;
	cout << "\n\nМетод хорд:\n";

	x = a - (f(a) / (f(b) - f(a))) * (b - a);
	/*while (abs(f(x) - f(B)) > E)*/
	while (!((f(x + E) > 0 && f(x - E) < 0) || (f(x + E) < 0 && f(x - E) > 0)))
	{
		if (f(a) * f(x) < 0)
		{
			A = a;
			B = x;
		}
		else if (f(b) * f(x) < 0)
		{
			A = b;
			B = x;
		}
		else
		{
			cout << "ERROR";
			return 0;
		}
		x = A - (f(A) / (f(B) - f(A))) * (B - A);
		count++;
	}
	cout << x << " " << E << " " << count;

}