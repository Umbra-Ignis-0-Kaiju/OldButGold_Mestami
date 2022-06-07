#include<iostream>
#include<vector>
#include<cmath>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
char sash;
class fraction
{
private:
	
public:
	int chislitel;
	int znamenatel;
	void in()
	{
		cout << "Введите дробь: ";
		cin >> chislitel >> sash >> znamenatel;
	}
	void out()
	{
		cout << "Итог: " << chislitel << "/" << znamenatel;
	}
	void fadd(fraction d1, fraction d2)
	{
		chislitel = d1.chislitel * d2.znamenatel + d2.chislitel * d1.znamenatel;
		znamenatel = d1.znamenatel * d2.znamenatel;
	}
	void fsub(fraction d1, fraction d2)
	{
		chislitel = d1.chislitel * d2.znamenatel - d2.chislitel * d1.znamenatel;
		znamenatel = d1.znamenatel * d2.znamenatel;
	}
	void fmul(fraction d1, fraction d2)
	{
		chislitel = d1.chislitel * d2.chislitel;
		znamenatel = d1.znamenatel * d2.znamenatel;
	}
	void fdiv(fraction d1, fraction d2)
	{
		chislitel = d1.chislitel * d2.znamenatel;
		znamenatel = d1.znamenatel * d2.chislitel;
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
		cout << "Введите операцию: ";
		cin >> t;
		d2.in();
		if (t == '+')
		{
			di.fadd(d1, d2);
		}
		else if (t == '-')
		{
			di.fsub(d1, d2);
		}
		else if (t == '*')
		{
			di.fmul(d1, d2);
		}
		else
		{
			di.fdiv(d1, d2);
		}
		di.lowterms();
		di.out();
		cout << "\n\nПродолжить? (y/n)   ";
		cin >> t;
	} while (t == 'y');
	return 0;
}