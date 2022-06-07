#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <iomanip> 
#include <sstream>
#include <windows.h>
using namespace std;

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
		wcout << L"Введите денежную сумму (пример: '$1,234,567.99'):\n";
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
	friend bMoney operator* (long double, bMoney);
	friend long double operator/ (long double, bMoney);
	friend bMoney round(bMoney);
};

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	bMoney mo1, mo2;
	mo1 = L"$1,234,567.23";
	mo1.putmoney(); wcout << L" -> ";
	mo2 = round(mo1);
	mo2.putmoney(); wcout << endl;

	mo1 = L"$1,234,567.50";
	mo1.putmoney(); wcout << L" -> ";
	mo2 = round(mo1);
	mo2.putmoney(); wcout << endl;

	return 0;
}

bMoney operator* (long double n, bMoney m)
{
	return bMoney(n * m.sum);
}

long double operator/ (long double n, bMoney m)
{
	return n / m.sum;
}
bMoney round(bMoney m)
{
	long double i, f;
	f = modfl(m.sum, &i);

	if (f < 0.50L)
		return bMoney(i);
	else
		return bMoney(i + 1.0L);
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
