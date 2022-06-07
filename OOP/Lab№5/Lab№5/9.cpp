#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<iomanip>
using namespace std;
char sash;
class fraction
{
private:
	int chislitel;
	int znamenatel;
public:
	void sum(fraction z)
	{
		chislitel = z.chislitel * znamenatel + chislitel * z.znamenatel;
		znamenatel = znamenatel * z.znamenatel;
	}
	void in()
	{
		cout << "Введите дробь: ";
		cin >> chislitel >> sash >> znamenatel;
	}
	void out()
	{
		cout << "\n\nСумма равна: " << chislitel << '/' << znamenatel;
	}
};
int main()
{

	fraction one, two;
	bool n = 1;
	char z;
	setlocale(LC_ALL, "Rus");
	while (n != 0)
	{
		one.in();
		two.in();
		one.sum(two);
		one.out();
		cout << "\nПовторить цикл ещё раз? (y/n)    ";
		cin >> z;
		if (z == 'n')
			n = 0;
	}
}