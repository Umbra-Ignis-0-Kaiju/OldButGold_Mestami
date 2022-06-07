#include <iostream>
#include <stdio.h>
#include <string>
#include<iomanip>
#include <locale.h>
using namespace std;
FILE* fp;

struct train
{

	bool full = 0;
	int num;
	string point;
	int d_i_w;
	short int time_arrival;
	short int time_parking;
	
};

void clear(train mas[], int i)
{
	mas[i].full = 0;
}
int findfull(train mas[], int size)
{
	for (int i = 0; i < size; i++)
		if (mas[i].full == 0)
			return i;
	return -1;
}
void push(train mas[], int i)
{
	mas[i].full = 1;
	cout << "\nВведите номер поезда: ";
	cin >> mas[i].num;
	cout << "\nВведите пункт назначения: ";
	cin.get();
	getline(cin, mas[i].point);
	cout << "\nВведите количество дней в пути: ";
	cin >> mas[i].d_i_w;
	char pox;
	int h, m;
	cout << "\nВведите время прибытия: ";
	cin >>  h >> pox >> m;
	mas[i].time_arrival = h*60 + m;
	cout << "\nВведите время стоянки: ";
	cin >> h >> pox >> m;
	mas[i].time_parking = h * 60 + m;
}
void pop(train mas[], int i)
{
	if (mas[i].full == 0)
	{
		cout << "Элемент под индексом " << i << " пуст.";
	}
	else
	{
		cout << "\nНомер поезда: " << mas[i].num;
		cout << "\nВведите пункт назначения: " << mas[i].point;
		cout << "\nКоличество дней в пути: " << mas[i].d_i_w;
		cout << "\nВремя прибытия: " << setfill('0') << setw(2) << mas[i].time_arrival / 60 << ":" << setfill('0') << setw(2) << mas[i].time_arrival % 60;
		cout << "\nВремя стоянки: " << setfill('0') << setw(2) << mas[i].time_parking / 60 << ":" << setfill('0') << setw(2) << mas[i].time_parking % 60;
	}
}
void popall(train mas[], int size)
{
	for (int i = 0; i < size; i++)
		if (mas[i].full == 0)
		{
			continue;
		}
		else
		{
			cout << "\nНомер поезда: " << mas[i].num;
			cout << "\nВведите пункт назначения: " << mas[i].point;
			cout << "\nКоличество дней в пути: " << mas[i].d_i_w;
			cout << "\nВремя прибытия: " << setfill('0') << setw(2) << mas[i].time_arrival / 60 << ":" << setfill('0') << setw(2) << mas[i].time_arrival % 60;
			cout << "\nВремя стоянки: " << setfill('0') << setw(2) << mas[i].time_parking / 60 << ":" << setfill('0') << setw(2) << mas[i].time_parking % 60 << endl;
		}
}
int find(train mas[], int size, string point, int num)
{
	int t = 0, tt, ti = 0;
	if (point == "-0")
	{
		for (int i = 0; i < size; i++)
		{
			if (mas[i].num == num)
				return i;
			else
			{
				tt = abs(mas[i].num - num);
				if (t == 0 || tt < t)
				{
					t = tt;
					ti = i;
				}
			}
		}
		return ti;
	}
	else if (num == -1)
	{
		for (int i = 0; i < size; i++)
			if (mas[i].point == point)
				return i;
		return -1;
	}
	else
	{
		for (int i = 0; i < size; i++)
			if (mas[i].point == point && mas[i].num == num)
				return i;
		return -1;
	}
}
int findmin(train mas[], int size, int num_polya)
{
	int temp, tempi;
	switch (num_polya)
	{
	case(0):
		cout << "ERROR";
		return -1;
	case(1):
		temp = mas[0].num; tempi = 0;
		for (int i = 1; i < size; i++)
			if (mas[i].num < temp)
			{
				temp = mas[i].num;
				tempi = i;
			}
	case(2):
		cout << "ERROR";
		return -1;
	case(3):
		temp = mas[0].d_i_w; tempi = 0;
		for (int i = 1; i < size; i++)
			if (mas[i].d_i_w < temp)
			{
				temp = mas[i].d_i_w;
				tempi = i;
			}
	case(4):
		temp = mas[0].time_arrival; tempi = 0;
		for (int i = 1; i < size; i++)
			if (mas[i].time_arrival < temp)
			{
				temp = mas[i].time_arrival;
				tempi = i;
			}
	case(5):
		temp = mas[0].time_parking; tempi = 0;
		for (int i = 1; i < size; i++)
			if (mas[i].time_parking < temp)
			{
				temp = mas[i].time_parking;
				tempi = i;
			}
	}
	return tempi;
}
void sortplus(train mas[], int size, int num_polya)
{
	train temp;
	switch (num_polya)
	{
	case(0):
		cout << "ERROR";
	case(1):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].num < mas[i - 1].num)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
	case(2):
		cout << "ERROR";
	case(3):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].d_i_w < mas[i - 1].d_i_w)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
	case(4):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].time_arrival < mas[i - 1].time_arrival)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
	case(5):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].time_parking < mas[i - 1].time_parking)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
	}
}
void sortminus(train mas[], int size, int num_polya)
{
	train temp;
	switch (num_polya)
	{
	case(0):
		cout << "ERROR";
	case(1):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].num > mas[i - 1].num)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
	case(2):
		cout << "ERROR";
	case(3):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].d_i_w > mas[i - 1].d_i_w)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
	case(4):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].time_arrival > mas[i - 1].time_arrival)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
	case(5):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].time_parking > mas[i - 1].time_parking)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
	}
}
void read(train mas[], int size)
{
	fopen_s(&fp, "Base.dat", "rb");
	for (int i = 0; i < size; i++)
	{
		fread(&mas[i], sizeof(train), 1, fp);
	}
	fclose(fp);
}
void write(train mas[], int size)
{
	train zagl;
	zagl.full = 0;
	fopen_s(&fp, "Base.dat", "wb");
	for (int i = 0; i < size; i++)
	{
		if (mas[i].full == 0)
			fwrite(&zagl, sizeof(train), 1, fp);
		else
			fwrite(&mas[i], sizeof(train), 1, fp);
	}
	fclose(fp);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int size = 13;
	train base[13];
	bool why=1;
	int fun;
	while (why != 0)
	{
		string point;
		int any;
		cout << "\nКакую из 11 функций вы хотели бы использовать?: ";
		cin >> fun;
		switch (fun)
		{
		case 1:
			cout << "\nКакой из 13 элементов вы хотите очистить? [0...12]: ";
			cin >> any;
			clear(base, any);
			break;
		case 2:
			any = findfull(base, size);
			if (any != -1)
				cout << "\nПервый свободный элемент базы: " << any;
			else
				cout << "\nВсе элементы базы заполнены.";
			break;
		case 3:
			cout << "\nКакой из 13 элементов вы хотите ввести? [0...12]: ";
			cin >> any;
			push(base, any);
			break;
		case 4:
			cout << "\nКакой из 13 элементов вы хотите вывести? [0...12]: ";
			cin >> any;
			pop(base, any);
			break;
		case 5:
			popall(base, size);
			break;
		case 6:
			cout << "\nХотите искать по номеру поезда и/или пункту назначения? (n/p/np): ";
			cin.get();
			getline(cin, point);
			if (point == "n")
			{
				point = "-0";
				cout << "\nВведите номер искомого поезда: ";
				cin >> any;
			}
			else if (point == "p")
			{
				cout << "\nВведите пункт назначения искомого поезда: ";
				cin.get();
				getline(cin, point);
				any = -1;
			}
			else if (point == "np")
			{
				cout << "\nВведите пункт назначения и номер искомого поезда в том же порядке: ";
				cin.get();
				getline(cin, point);
				cin >> any;
			}
			cout << "\nСкорее всего вы искали элемент №" << find(base, size, point, any);
			break;
		case 7:
			cout << "\nМинимальное значение какого поля вы бы хотели найти? (Номер - 1, Пункт назначения - 2 (не советую), Дней в пути - 3, Время прибытия - 4, Время стоянки - 5): ";
			cin >> any;
			findmin(base, size, any);
			break;
		case 8:
			cout << "\nПо возорастанию какой позиции отсортировать базу? (Номер - 1, Пункт назначения - 2 (не советую), Дней в пути - 3, Время прибытия - 4, Время стоянки - 5): ";
			cin >> any;
			sortplus(base, size, any);
			break;
		case 9:
			cout << "\nПо убыванию какой позиции отсортировать базу? (Номер - 1, Пункт назначения - 2 (не советую), Дней в пути - 3, Время прибытия - 4, Время стоянки - 5): ";
			cin >> any;
			sortplus(base, size, any);
			break;
		case 10:
			read(base, size);
			break;
		case 11:
			write(base, size);
			break;
		}
		cout << "\nХотите продолжить работу с базой данных? (0/1): ";
		cin >> why;
	}
	return 0;
}