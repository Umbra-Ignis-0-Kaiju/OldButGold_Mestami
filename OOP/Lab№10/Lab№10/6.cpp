#include <iostream>
#include <iomanip> 
#include <sstream> 
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
		cout << "Введите денежную сумму (пример: '$1,234,567.99'):\n";
		wcin >> tms;
		mstold(tms);
	}
	void putmoney()
	{
		wchar_t tms[80];
		ldtoms(tms);
		cout << tms;
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
};

int main()
{
	setlocale(LC_ALL, "Russian");

	wchar_t ans;
	bMoney m1, m2, mres;
	long double n, res;
	do {
		cout << "1. "; m1.getmoney();
		cout << "2. "; m2.getmoney();
		cout << "3. Введите вещественное число: "; wcin >> n; cout << endl;

		mres = m1 + m2; cout << "1. m1 + m2 = "; mres.putmoney(); cout << endl;
		mres = m1 - m2; cout << "2. m1 - m2 = "; mres.putmoney(); cout << endl;
		mres = m1 * n;  cout << "3. m1 * n  = "; mres.putmoney(); cout << endl;
		res = m1 / m2; cout << "4. m1 / m2 = " << res << endl;
		mres = m1 / n;  cout << "5. m1 / n  = "; mres.putmoney(); cout << endl;

		mres = n * m1;  cout << "6. n * m1  = "; mres.putmoney(); cout << endl;

		res = n / m1;   cout << "7. n / m1 = " << res << endl << endl;

		cout << "Попробовать с другими исходными данными (д/н)? "; wcin >> ans; cout << endl;
	} while (ans != 'н');

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
long double bMoney::mstold(const wchar_t str[])
{
	wchar_t temp[80];
	int j = 0;
	for (int i = 0; i < wcslen(str); i++)
	{
		wchar_t ch = str[i];
		if ((ch >= '0') && (ch <= '9'))
			temp[j++] = ch;
		else if (ch == '.')
			temp[j++] = ch;
	}
	temp[j] = '\0';

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
	wchar_t delim3 = ',';

	str[i++] = '$';

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
	str[i] = '\0';
}
