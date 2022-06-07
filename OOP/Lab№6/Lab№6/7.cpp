#include<iostream>
#include<math.h>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<STDLIB.h>
#include<iomanip>
using namespace std;

class money
{
private:
	
public:
	long double  bax;
	string num;
	void mstold(string start)
	{
		for (int i = 0; i < start.length(); i++)
		{
			if (start[i] >= '0' && start[i] <= '9')
			{
				num += start[i];
			}
		}
		num += ",";
		char wow;
		wow = num[num.length() - 1];
		num[num.length() - 1] = num[num.length() - 2];
		num[num.length() - 2] = num[num.length() - 3];
		num[num.length() - 3] = wow;
		bax = stold(num);
	}
	void rebind(string start)
	{
		num = start;
		num[num.length() - 3] = ',';
	}
	void out()
	{
		cout.precision();
		cout << "Хранимое в строке: " << num << endl << "Хранимое в числе: " << fixed << bax << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	string start;
	money wat;
	char e;
	do
	{
		cout << "Введите денежное значение: ";
		cin >> start;
		wat.mstold(start);
		wat.rebind(start);
		wat.out();
		cout << endl << "Продолжить? (y/n)   ";
		cin >> e;
		cout << endl;
	} while (e != 'n');
}