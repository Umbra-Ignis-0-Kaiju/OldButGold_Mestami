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

const double RATE = 50.0;
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
		cout << "Введите сумму (фунты, шиллинги и пенсы через точку): £";
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

class bMoney
{
private:
	long double sum;
public:
	bMoney()
	{
		sum = 0.0L;
	}
	explicit bMoney(long double n) : sum(n)
	{ }
	bMoney(const wchar_t s[])
	{
		mstold(s);
	}
	long double mstold(const wchar_t[]);
	void ldtoms(wchar_t[]);
	void getmoney()
	{
		wchar_t tms[80];
		cout << "Введите денежную сумму (пример: '$1,234,567.99'):\n";
		wcin >> tms;
		mstold(tms);
	}
	void putmoney()
	{
		wchar_t tms[80];
		ldtoms(tms);
		wcout << tms;
	}
	bMoney operator+ (bMoney m) const

	{
		return bMoney(sum + m.sum);
	}
	bMoney operator- (bMoney m) const
	{
		return bMoney(sum - m.sum);
	}
	bMoney operator* (long double n) const
	{
		return bMoney(sum * n);
	}
	long double operator/ (bMoney m) const
	{
		return sum / m.sum;
	}
	bMoney operator/ (long double n) const
	{
		return bMoney(sum / n);
	}
	bMoney(sterling s)
	{
		sum = double(s) * RATE;
	}
	operator sterling()
	{
		return sterling(sum / RATE);
	}
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	wchar_t ans;
	int currency;
	bMoney sd;
	sterling sf;
	do {

		cout << "Введите номер валюты (1 — доллар, 2 — фунт): ";
		wcin >> currency;

		if (currency == 1)
		{
			sd.getmoney();
			sf = sd;

			cout << "В старой английской системе: "; sf.putSterling();
		}
		else if (currency == 2)
		{
			sf.getSterling();
			sd = sf;
			cout << "В долларах: "; sd.putmoney();
		}
		else
			cout << "Ошибка, вы ввели не 1 и не 2!";
		wcout << endl;

		cout << "Попробовать ещё (1/0)? "; wcin >> ans; cout << endl;
	} while (ans != L'0');

	return 0;
}

long double bMoney::mstold(const wchar_t str[])
{
	wchar_t temp[80];
	int j = 0;
	for (int i = 0; i < wcslen(str); i++)
	{
		wchar_t ch = str[i];

		if ((ch >= L'0') && (ch <= L'9'))
			temp[j++] = ch;
		else if (ch == L'.')
			temp[j++] = ch;
	}
	temp[j] = L'\0';

	wchar_t* stop;
	sum = wcstold(temp, &stop);
	return sum;
}
void bMoney::ldtoms(wchar_t str[])
{
	wchar_t ustring[80];
	wstringstream woss;
	woss << setiosflags(ios::fixed) << setprecision(2) << sum;

	woss >> ustring;

	int i = 0, n = 0, j;
	int len = wcslen(ustring);
	wchar_t delim3 = L',';

	str[i++] = L'$';
	if (len > 6)
	{
		if ((len - 3) % 3 == 2)
		{
			str[i++] = ustring[n++];
			str[i++] = ustring[n++];
			str[i++] = delim3;
		}
		else if ((len - 3) % 3 == 1)
		{
			str[i++] = ustring[n++];
			str[i++] = delim3;
		}
	}

	for (j = n; j < len - 3; j++)
	{
		str[i++] = ustring[j];
		if (((j - n + 1) % 3 == 0) && (j != len - 3 - 1))
			str[i++] = delim3;
	}

	str[i++] = ustring[j++];
	str[i++] = ustring[j++];
	str[i++] = ustring[j];
	str[i] = L'\0';
}
