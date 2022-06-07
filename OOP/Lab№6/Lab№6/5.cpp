#include<iostream>
#include<vector>
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
	int N;
	cout << "Введите количество элементов массива: ";
	cin >> N;
	fraction* mas = new fraction[N];
	fraction sr;
	sr.chislitel = 0;
	sr.znamenatel = 1;
	cout << "Введите все элементы массива: \n";
	for (int i = 0; i < N; i++)
	{
		mas[i].in();
		sr.fadd(sr, mas[i]);
	}
	sr.chislitel = sr.chislitel / N;
	sr.lowterms();
	cout << "Среднее значение = " << sr.chislitel << "/" << sr.znamenatel;
}