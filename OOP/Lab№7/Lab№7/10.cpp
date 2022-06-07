#include<iostream>
#include<io.h>
#include<iomanip>
#include<windows.h>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<sstream>
#include<iomanip>
using namespace std;

class sterling
{
private:
	long pounds;   // фунты (1 фунт = 20 шиллингов = 240 пенсов)
	int shillings; // шиллинги (1 шиллинг = 12 пенсов)
	int pences;    // пенсы
public:

	sterling() : pounds(0), shillings(0), pences(0)
	{ }
	sterling(double df)
	{
		pounds = df;
		shillings = (df - pounds) * 20;
		pences = round(((df - pounds) * 20 - shillings) * 12);
	}
	sterling(long ps, int s, int p) : pounds(ps), shillings(s), pences(p)
	{ }
	void getSterling()
	{
		char separator;
		cout << "Введите сумму (фунты, шиллинги и пенсы через точку): ";
		cin >> pounds >> separator >> shillings >> separator >> pences;
	}
	void putSterling() const
	{
		cout << "£" << pounds << "." << shillings << "." << pences;
	}
	operator double() const
	{
		return (pounds + shillings / 20.0 + pences / 240.0);
	}
	sterling operator+ (sterling s) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) + double(s));
	}
	sterling operator- (sterling s) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) - double(s));
	}
	sterling operator* (double n) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) * n);
	}
	double operator/ (sterling s) const
	{
		return (double(sterling(pounds, shillings, pences)) / double(s));
	}
	sterling operator/ (double n) const
	{
		return sterling(double(sterling(pounds, shillings, pences)) / n);
	}
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	sterling s1, s2, s;
	double n;

	cout << "1. "; s1.getSterling();
	cout << "2. "; s2.getSterling(); wcout << endl;


	cout << "1. В десятичных фунтах: " << fixed << setprecision(2) << double(s1) << endl;
	cout << "2. В десятичных фунтах: " << fixed << setprecision(2) << double(s2) << endl << endl;

	s = s1 + s2;
	cout << "Результат сложения этих сумм: "; s.putSterling(); wcout << endl;

	s = s1 - s2;
	cout << "Разность этих сумм: "; s.putSterling(); wcout << endl;

	s = s1 * 1.05;
	cout << "Произведение первой суммы и числа 1,05: "; s.putSterling(); wcout << endl;

	n = s1 / s2;
	cout << "Частное от деления первой суммы на вторую: " << n << endl;

	s = s1 / 3.5;
	cout << "Частное от деления первой суммы на число 3,5: "; s.putSterling(); wcout << endl;

	return 0;
}
