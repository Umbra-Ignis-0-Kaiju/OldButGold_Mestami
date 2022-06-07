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
	void out()
	{
		cout.precision(2);
		cout << "Хранимое в строке: " << num << endl << "Хранимое в числе: " << fixed << bax << endl;
	}
	void ldtoms()
	{
		ostringstream temp;
		int count = 0;
		string ustring, t = num;
		temp.precision(0);
		temp << fixed << bax;
		ustring = temp.str();
		num.clear();
		num += t[t.length() - 3]; num += t[t.length() - 2]; num += t[t.length() - 1];
		for (int i = ustring.length() - 1; i >= 0; i--)
		{
			num = ustring[i] + num;
			if (count % 3 == 2 && i != 0)
				num = " " + num;
			count++;
		}
		num = '$' + num;
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
		wat.num.clear();
		cout << "Введите денежное значение: ";
		cin >> start;
		wat.mstold(start);
		wat.ldtoms();
		wat.out();
		cout << endl << "Продолжить? (y/n)   ";
		cin >> e;
		cout << endl;
	} while (e != 'n');
}