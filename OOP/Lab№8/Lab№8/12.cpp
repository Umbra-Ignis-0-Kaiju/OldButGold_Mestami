#include <iostream>
#include <iomanip> 
using namespace std;

class sterling
{
protected:
	long pounds;
	int shillings;
	int pences;
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
		wchar_t separator;
		cout << "Введите сумму (фунты, шиллинги и пенсы через точку): ";
		wcin >> pounds >> separator >> shillings >> separator >> pences;
	}
	void putSterling() const
	{
		cout << "Pounds " << pounds << "." << shillings << "." << pences;
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
class sterfrac : public sterling
{
private:
	int eighths;
	// возможные значения:
	// 0                                    (0/8 пенни)
	// 1 — полуфартинг                      (1/8 пенни)
	// 2 — фартинг                          (2/8 пенни или 1/4 пенни)
	// 3 — фартинг и полуфартинг            (3/8 пенни)
	// 4 — полупенни                        (4/8 пенни или 1/2 пенни)
	// 5 — полупенни и полуфартинг          (5/8 пенни)
	// 6 — полупенни и фартинг              (6/8 пенни или 3/4 пенни)
	// 7 — полупенни, фартинг и полуфартинг (7/8 пенни)
public:
	sterfrac() : sterling(), eighths(0)
	{ }
	sterfrac(double df)
	{
		pounds = df;
		shillings = (df - pounds) * 20;
		pences = ((df - pounds) * 20 - shillings) * 12;
		eighths = round((((df - pounds) * 20 - shillings) * 12 - pences) * 8);
	}
	sterfrac(long ps, int s, int p, int e) : sterling(ps, s, p), eighths(e)
	{ }
	void getSterling()
	{
		wchar_t separator;
		int num, den;
		cout << "Введите сумму в формате '9.19.11-1/4': ";
		wcin >> pounds >> separator >> shillings >> separator >> pences
			>> separator >> num >> separator >> den;
		if (den == 2) num = num * 4;
		if (den == 4) num = num * 2;
		eighths = num;
	}
	void putSterling() const
	{
		sterling::putSterling();
		cout << "-";
		switch (eighths)
		{
		case 2: cout << "1/4"; break;
		case 4: cout << "1/2"; break;
		case 6: cout << "3/4"; break;
		default: cout << eighths << "/8";
		}
	}
	operator double() const
	{
		return (sterling::operator double() + eighths / 1920.0);
	}
	sterfrac operator+ (sterfrac s) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) + double(s));
	}
	sterfrac operator- (sterfrac s) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) - double(s));
	}
	sterfrac operator* (double n) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) * n);
	}
	double operator/ (sterfrac s) const
	{
		return (double(sterfrac(pounds, shillings, pences, eighths)) / double(s));
	}
	sterfrac operator/ (double n) const
	{
		return sterfrac(double(sterfrac(pounds, shillings, pences, eighths)) / n);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	sterfrac s1, s2, s;
	double n;
	cout << "1. "; s1.getSterling();
	cout << "2. "; s2.getSterling(); cout << endl;

	cout << "1. В десятичных фунтах: " << fixed << setprecision(2) << double(s1) << endl;
	cout << "2. В десятичных фунтах: " << fixed << setprecision(2) << double(s2) << endl << endl;

	s = s1 + s2;
	cout << "Результат сложения этих сумм: "; s.putSterling(); cout << endl;

	s = s1 - s2;
	cout << "Разность этих сумм: "; s.putSterling(); cout << endl;

	s = s1 * 1.05;
	cout << "Произведение первой суммы и числа 1,05: "; s.putSterling(); cout << endl;

	n = s1 / s2;
	cout << "Частное от деления первой суммы на вторую: " << n << endl;

	s = s1 / 3.5;
	cout << "Частное от деления первой суммы на число 3,5: "; s.putSterling(); cout << endl;

	return 0;
}
