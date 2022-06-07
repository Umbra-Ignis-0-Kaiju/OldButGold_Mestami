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
	cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): ";
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
		cout << "\nПолное название должности: laborer";
		break;
	}
	case 1:
	{
		cout << "\nПолное название должности: secretary";
		break;
	}
	case 2:
	{
		cout << "\nПолное название должности: manager";
		break;
	}
	case 3:
	{
		cout << "\nПолное название должности: accountant";
		break;
	}
	case 4:
	{
		cout << "\nПолное название должности: executive";
		break;
	}
	case 5:
	{
		cout << "\nПолное название должности: researcher";
		break;
	}
	}
}