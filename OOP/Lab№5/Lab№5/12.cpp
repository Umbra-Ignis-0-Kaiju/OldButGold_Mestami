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
	fraction(int ch, int zn) : chislitel(ch), znamenatel(zn) {}
	void in()
	{
		cout << "Введите дробь: ";
		cin >> chislitel >> sash >> znamenatel;
	}
	void out()
	{
		cout << chislitel << "/" << znamenatel;
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
    int num;
	cin >> num;
	fraction di(0, 0);
	for (int j = 1; j < num; ++j)
	{
		di.fmul(fraction(1, num), fraction(j, 1));
		di.lowterms();
		di.out();
		cout << " ";
	}
	cout << endl << "-----------------------------------" << endl;
    for (int i = 1; i < num; ++i) 
	{
		di.fmul(fraction(i, num), fraction(num, num));
		di.lowterms();
		di.out();
		cout << " ";
        for (int j = 1; j < num; ++j) 
		{
			di.fmul(fraction(i, num), fraction(j, num));
			di.lowterms();
			di.out();
            cout << " ";
        }
        cout << endl;
    }
}