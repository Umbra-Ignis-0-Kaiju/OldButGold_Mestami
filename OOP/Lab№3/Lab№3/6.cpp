#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	enum etype {laborer, secretary, manager, accountant, executive, researcher};
	char a;
	int z;
	cout << "������� ������ ����� ��������� (laborer, secretary, manager, accountant, executive, researcher): ";
	cin >> a;
	switch (a)
	{
	case 'l': 
	{
		z = laborer;
		break;
	}
	case 's':
	{
		z = secretary;
		break;
	}
	case 'm':
	{
		z = manager;
		break;
	}
	case 'a': 
	{
		z = accountant;
		break;
	}
	case 'e':
	{
		z = executive;
		break;
	}
	case 'r':
	{
		z = researcher;
		break;
	}
	}
	switch (z)
	{
	case 0:
	{
		cout << "\n������ �������� ���������: laborer";
		break;
	}
	case 1:
	{
		cout << "\n������ �������� ���������: secretary";
		break;
	}
	case 2:
	{
		cout << "\n������ �������� ���������: manager";
		break;
	}
	case 3:
	{
		cout << "\n������ �������� ���������: accountant";
		break;
	}
	case 4:
	{
		cout << "\n������ �������� ���������: executive";
		break;
	}
	case 5:
	{
		cout << "\n������ �������� ���������: researcher";
		break;
	}
	}
}