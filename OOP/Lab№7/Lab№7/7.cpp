#include<iostream>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<STDLIB.h>
#include<iomanip>
using namespace std;

char sash;
class fraction
{
private:

public:
	int chislitel;
	int znamenatel;
	fraction(int ch, int zn) : chislitel(ch), znamenatel(zn) {}
	fraction() : chislitel(0), znamenatel(0) {}
	void in()
	{
		cin >> chislitel >> sash >> znamenatel;
	}
	void out()
	{
		cout << chislitel << "/" << znamenatel;
	}
	fraction operator + (fraction d2)
	{
		int chis = chislitel * d2.znamenatel + d2.chislitel * znamenatel;
		int znam = znamenatel * d2.znamenatel;
		return fraction(chis, znam);
	}
	fraction operator - (fraction d2)
	{
		int chis = chislitel * d2.znamenatel - d2.chislitel * znamenatel;
		int znam = znamenatel * d2.znamenatel;
		return fraction(chis, znam);
	}
	fraction operator * (fraction d2)
	{
		int chis = chislitel * d2.chislitel;
		int znam = znamenatel * d2.znamenatel;
		return fraction(chis, znam);
	}
	fraction operator / (fraction d2)
	{
		int chis = chislitel * d2.znamenatel;
		int znam = znamenatel * d2.chislitel;
		return fraction(chis, znam);
	}
	bool operator == (fraction d2)
	{
		if (chislitel / d2.chislitel == znamenatel / d2.znamenatel)
			return true;
		else
			return false;
	}
	bool operator != (fraction d2)
	{
		if (chislitel / d2.chislitel == znamenatel / d2.znamenatel)
			return false;
		else
			return true;
	}
	void lowterms()
	{
		long tnum, tden, temp, gcd;
		tnum = labs(chislitel);
		tden = labs(znamenatel);
		if (tden == 0)
		{
			cout << "Недопустимый знаменатель";
			exit(1);
		}
		else if (tnum == 0)
		{
			chislitel = 0;
			znamenatel = 1;
			return;
		}
		while (tnum != 0)
		{
			if (tnum < tden)
			{
				temp = tnum;
				tnum = tden;
				tden = temp;
			}
			tnum = tnum - tden;
		}
		gcd = tden;
		chislitel = chislitel / gcd;
		znamenatel = znamenatel / gcd;
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	fraction d1, d2, di;
	char t;
	do
	{
		cout << endl;
		d1.in();
		cin >> t;
		d2.in();
		if (t == '+')
		{
			di = d1 + d2;
		}
		else if (t == '-')
		{
			di = d1 - d2;
		}
		else if (t == '*')
		{
			di = d1 * d2;
		}
		else
		{
			di = d1 / d2;
		}
		di.lowterms();
		di.out();
		cout << "\n\nПродолжить? (y/n)   ";
		cin >> t;
	} while (t == 'y');
	return 0;
}