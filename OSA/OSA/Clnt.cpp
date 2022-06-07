#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <locale.h>
#include <vector>
using namespace std;

class ClntN
{
private:
public:
	vector <int> num;
	char zn;
	ClntN()
	{
		zn = '+';
	}
	ClntN(int N)
	{
		vector <int> temp(N);
		num = temp;
		zn = '+';
	}
	~ClntN()
	{
		num.clear();
		zn = NULL;
	}
	ClntN operator = (ClntN v)
	{
		num = v.num;
		zn = v.zn;
		return *this;
	}
};
bool more(ClntN v1, ClntN v2)
{
	if (v1.zn == '-' && v2.zn ==  '+')
		return 0;
	for (int i = 0; i < v1.num.size(); i++)
		if (v1.num[i] < v2.num[i])
			return 0;
		else if (v1.num[i] > v2.num[i])
			return 1;
	return 1;
}
ClntN operator - (ClntN v1, ClntN v2);
ClntN operator + (ClntN v1, ClntN v2)
{
	ClntN t1, t2;
	t1 = v1;
	t2 = v2;
	t1.zn = '+';
	t2.zn = '+';
	int temp = 0;
	while (v1.num.size() != v2.num.size())
		if (v1.num.size() > v2.num.size())
			v2.num.insert(v2.num.begin(), 0);
		else
			v1.num.insert(v1.num.begin(), 0);
	ClntN v3(v1.num.size());
	if (v1.zn == '+' && v2.zn == '+')
	{
		for (int i = v1.num.size() - 1; i >= 0; i--)
		{
			if (i != v1.num.size() - 1)
				if (v3.num[i + 1] >= 10)
				{
					v3.num[i + 1] = v3.num[i + 1] % 10;
					temp = 1;
				}
				else
					temp = 0;
			v3.num[i] = v1.num[i] + v2.num[i] + temp;
		}
		if (v3.num[0] >= 10)
		{
			v3.num.insert(v3.num.begin(), 1);
			v3.num[1] = v3.num[1] % 10;
		}
		return v3;
	}
	else if (v1.zn == '-' && v2.zn == '-')
	{
		for (int i = v1.num.size() - 1; i >= 0; i--)
		{
			if (i != v1.num.size() - 1)
				if (v3.num[i + 1] >= 10)
				{
					v3.num[i + 1] = v3.num[i + 1] % 10;
					temp = 1;
				}
				else
					temp = 0;
			v3.num[i] = v1.num[i] + v2.num[i] + temp;
		}
		if (v3.num[0] >= 10)
		{
			v3.num.insert(v3.num.begin(), 1);
			v3.num[1] = v3.num[1] % 10;
		}
		v3.zn = '-';
		return v3;
	}
	else if (v1.zn == '-' && v2.zn == '+')
		v3 = t2 - t1;
	else if (v1.zn == '+' && v2.zn == '-')
	{
		v3 = t2 - t1;
		v3.zn = '-';
	}
	return v3;
}
ClntN operator - (ClntN v1, ClntN v2)
{
	ClntN t1, t2;
	t1 = v1;
	t2 = v2;
	t1.zn = '+';
	t2.zn = '+';
	while (v1.num.size() != v2.num.size())
		if (v1.num.size() > v2.num.size())
			v2.num.insert(v2.num.begin(), 0);
		else
			v1.num.insert(v1.num.begin(), 0);
	ClntN v3(v1.num.size());
	if (!more(v1, v2))
	{
		if (v1.zn == '+' && v2.zn == '+')
		{
			v3 = t2 - t1;
			v3.zn = '-';
		}
		else if (v1.zn == '-' && v2.zn == '-')
		{
			v3 = t2 - t1;
		}
		else if (v1.zn == '+' && v2.zn == '-')
			v3 = t1 + t2;
		else if (v1.zn == '-' && v2.zn == '+')
		{
			v3 = t1 + t2;
			v3.zn = '-';
		}
			return v3;
	}
	else
		if (v1.zn == '+' && v2.zn == '+')
		{
			for (int i = 0; i < v1.num.size(); i++)
			{
				v3.num[i] = v1.num[i] - v2.num[i];
				if (v3.num[i] < 0)
				{
					v3.num[i] = (10 - v3.num[i]) % 10;
					v3.num[i - 1]--;
				}
			}
			if (v3.num[0] >= 10)
			{
				v3.num.insert(v3.num.begin(), 1);
				v3.num[1] = v3.num[1] % 10;
			}
		}
		else if (v1.zn == '-' && v2.zn == '-')
		{
			for (int i = 0; i < v1.num.size(); i++)
			{
				v3.num[i] = v1.num[i] - v2.num[i];
				if (v3.num[i] < 0)
				{
					v3.num[i] = 10 - v3.num[i];
					v3.num[i - 1]--;
				}
			}
			if (v3.num[0] >= 10)
			{
				v3.num.insert(v3.num.begin(), 1);
				v3.num[1] = v3.num[1] % 10;
			}
			v3.zn = '-';
		}
		else if (v1.zn == '+' && v2.zn == '-')
			v3 = t1 + t2;
		else if (v1.zn == '-' && v2.zn == '+')
		{
			v3 = t1 + t2;
			v3.zn = '-';
		}
	while (1)
	{
		if (v3.num[0] == 0 && v3.num.size() != 1)
			v3.num.erase(v3.num.begin());
		else if (v3.num.size() == 1 && v3.num[0] == 0)
		{
			v3.zn = '+';
			break;
		}
		else break;
	}
	return v3;
};
void print(ClntN v)
{
	//if (v.zn == '-')
		cout << v.zn;
	for (int i = 0; i < v.num.size(); i++)
		cout << " " << v.num[i];
	cout << endl;
}
ClntN write(int N)
{
	ClntN v(N);
	v.zn = '0';
	cout << "Введите знак числа: (+/-)   ";
	while (1)
	{
		cin >> v.zn;
		if (v.zn == '+' || v.zn == '-')
			break;
		else
			cout << endl << "Ещё попытку? :   ";
	}
	cout << "Введите всё число поциферно (любой ввод >10 отбросит всё кроме последней цифры) :   ";
	for (int i = 0; i < v.num.size(); i++)
	{
		cin >> N;
		if (N >= 10)
			N = N % 10;
		v.num[i] = N;
	}
	return v;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	ClntN v1, v2, t;
	ClntN v3(1);
	int N;
	char end = 'y';
	cout << "Введите размер первого числа: ";
	cin >> N;
	v1 = write(N);
	cout << "\nВведите размер второго числа: ";
	cin >> N;
	v2 = write(N);
	while (end == 'y')
	{
		cout << "\nКакой функцией хотите воспользоваться?:"
			<< "\n1 - Перезаписать первое число"
			<< "\n2 - Перезаписать второе число"
			<< "\n3 - Вывести первое число"
			<< "\n4 - Вывести второе число"
			<< "\n5 - Вывести третье число (результат сложения/вычитания)"
			<< "\n6 - Поменять первое и второе числа местами"
			<< "\n7 - Приравнять первое число к третьему"
			<< "\n8 - Приравнять второе число к третьему"
			<< "\n9 - Вывести все три числа"
			<< "\n10 - Ч3 = Ч1 + Ч2"
			<< "\n11 - Ч3 = Ч1 - Ч2\n";
		cin >> N;
		switch (N)
		{
		case 1:
			cout << "\nВведите размер первого числа: ";
			cin >> N;
			v1 = write(N);
			break;
		case 2:
			cout << "\nВведите размер второго числа: ";
			cin >> N;
			v2 = write(N);
			break;
		case 3:
			cout << "\nПервое число: ";
			print(v1);
			break;
		case 4:
			cout << "\nВторое число: ";
			print(v2);
			break;
		case 5:
			cout << "\nТретье число: ";
			print(v3);
			break;
		case 6:
			t = v1;
			v1 = v2;
			v2 = t;
			break;
		case 7:
			v1 = v3;
			v3.zn = '+';
			v3.num.clear();
			v3.num.push_back(0);
			break;
		case 8:
			v2 = v3;
			v3.zn = '+';
			v3.num.clear();
			v3.num.push_back(0);
			break;
		case 9:
			cout << "\nПервое число: ";
			print(v1);
			cout << "Второе число: ";
			print(v2);
			cout << "Третье число: ";
			print(v3);
			break;
		case 10:
			v3 = v1 + v2;
			break;
		case 11:
			v3 = v1 - v2;
			break;
		}
		cout << "\n\n}{отите продолжить работу с программой? (y/n)   ";
		cin >> end;
	}
}