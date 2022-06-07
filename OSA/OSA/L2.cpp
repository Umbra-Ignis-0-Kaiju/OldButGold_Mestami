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
	cout << "\n������� ����� ������: ";
	cin >> mas[i].num;
	cout << "\n������� ����� ����������: ";
	cin.get();
	getline(cin, mas[i].point);
	cout << "\n������� ���������� ���� � ����: ";
	cin >> mas[i].d_i_w;
	char pox;
	int h, m;
	cout << "\n������� ����� ��������: ";
	cin >>  h >> pox >> m;
	mas[i].time_arrival = h*60 + m;
	cout << "\n������� ����� �������: ";
	cin >> h >> pox >> m;
	mas[i].time_parking = h * 60 + m;
}
void pop(train mas[], int i)
{
	if (mas[i].full == 0)
	{
		cout << "������� ��� �������� " << i << " ����.";
	}
	else
	{
		cout << "\n����� ������: " << mas[i].num;
		cout << "\n������� ����� ����������: " << mas[i].point;
		cout << "\n���������� ���� � ����: " << mas[i].d_i_w;
		cout << "\n����� ��������: " << setfill('0') << setw(2) << mas[i].time_arrival / 60 << ":" << setfill('0') << setw(2) << mas[i].time_arrival % 60;
		cout << "\n����� �������: " << setfill('0') << setw(2) << mas[i].time_parking / 60 << ":" << setfill('0') << setw(2) << mas[i].time_parking % 60;
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
			cout << "\n������ � ���� ������: " << i;
			cout << "\n����� ������: " << mas[i].num;
			cout << "\n������� ����� ����������:" << mas[i].point << ".";
			cout << "\n���������� ���� � ����: " << mas[i].d_i_w;
			cout << "\n����� ��������: " << setfill('0') << setw(2) << mas[i].time_arrival / 60 << ":" << setfill('0') << setw(2) << mas[i].time_arrival % 60;
			cout << "\n����� �������: " << setfill('0') << setw(2) << mas[i].time_parking / 60 << ":" << setfill('0') << setw(2) << mas[i].time_parking % 60 << endl;
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
	int temp = 2147483646, tempi = -1;
	switch (num_polya)
	{
	case(0):
		cout << "ERROR";
		return -1;
		break;
	case(1):
		for (int i = 1; i < size; i++)
			if (mas[i].num < temp && mas[i].full == 1)
			{
				temp = mas[i].num;
				tempi = i;
			}
		break;
	case(2):
		cout << "ERROR";
		return -1;
		break;
	case(3):
		for (int i = 1; i < size; i++)
			if (mas[i].d_i_w < temp && mas[i].full == 1)
			{
				temp = mas[i].d_i_w;
				tempi = i;
			}
		break;
	case(4):
		for (int i = 1; i < size; i++)
			if (mas[i].time_arrival < temp && mas[i].full == 1)
			{
				temp = mas[i].time_arrival;
				tempi = i;
			}
		break;
	case(5):
		for (int i = 1; i < size; i++)
			if (mas[i].time_parking < temp && mas[i].full == 1)
			{
				temp = mas[i].time_parking;
				tempi = i;
			}
		break;
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
		break;
	case(1):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].num < mas[i - 1].num)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
		break;
	case(2):
		cout << "ERROR";
		break;
	case(3):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].d_i_w < mas[i - 1].d_i_w)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
		break;
	case(4):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].time_arrival < mas[i - 1].time_arrival)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
		break;
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
		break;
	case(1):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].num > mas[i - 1].num)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
		break;
	case(2):
		cout << "ERROR";
		break;
	case(3):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].d_i_w > mas[i - 1].d_i_w)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
		break;
	case(4):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].time_arrival > mas[i - 1].time_arrival)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
		break;
	case(5):
		for (int j = 0; j < size; j++)
			for (int i = 1; i < size; i++)
				if (mas[i].time_parking > mas[i - 1].time_parking)
				{
					temp = mas[i];
					mas[i] = mas[i - 1];
					mas[i - 1] = temp;
				}
		break;
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
		cout << "\n����� �� 11 ������� �� ������ �� ������������?: ";
		cin >> fun;
		switch (fun)
		{
		case 1:
			cout << "\n����� �� 13 ��������� �� ������ ��������? [0...12]: ";
			cin >> any;
			clear(base, any);
			break;
		case 2:
			any = findfull(base, size);
			if (any != -1)
				cout << "\n������ ��������� ������� ����: " << any;
			else
				cout << "\n��� �������� ���� ���������.";
			break;
		case 3:
			cout << "\n����� �� 13 ��������� �� ������ ������? [0...12]: ";
			cin >> any;
			push(base, any);
			break;
		case 4:
			cout << "\n����� �� 13 ��������� �� ������ �������? [0...12]: ";
			cin >> any;
			pop(base, any);
			break;
		case 5:
			popall(base, size);
			break;
		case 6:
			cout << "\n������ ������ �� ������ ������ �/��� ������ ����������? (n/p/np): ";
			cin.get();
			getline(cin, point);
			if (point == "n")
			{
				point = "-0";
				cout << "\n������� ����� �������� ������: ";
				cin >> any;
			}
			else if (point == "p")
			{
				cout << "\n������� ����� ���������� �������� ������: ";
				getline(cin, point);
				any = -1;
			}
			else if (point == "np")
			{
				cout << "\n������� ����� ���������� � ����� �������� ������ � ��� �� �������: ";
				getline(cin, point);
				cin >> any;
			}
			cout << "\n������ ����� �� ������ ������� �" << find(base, size, point, any);
			break;
		case 7:
			cout << "\n����������� �������� ������ ���� �� �� ������ �����? (����� - 1, ����� ���������� - 2 (�� �������), ���� � ���� - 3, ����� �������� - 4, ����� ������� - 5): ";
			cin >> any;
			cout << "������ ������������ ��������: " << findmin(base, size, any);
			break;
		case 8:
			cout << "\n�� ������������ ����� ������� ������������� ����? (����� - 1, ����� ���������� - 2 (�� �������), ���� � ���� - 3, ����� �������� - 4, ����� ������� - 5): ";
			cin >> any;
			sortplus(base, size, any);
			break;
		case 9:
			cout << "\n�� �������� ����� ������� ������������� ����? (����� - 1, ����� ���������� - 2 (�� �������), ���� � ���� - 3, ����� �������� - 4, ����� ������� - 5): ";
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
		cout << "\n������ ���������� ������ � ����� ������? (0/1): ";
		cin >> why;
	}
	return 0;
}