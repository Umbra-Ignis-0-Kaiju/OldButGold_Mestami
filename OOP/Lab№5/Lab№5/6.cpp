#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<windows.h>
#include<iomanip>
using namespace std;
class date
{
private:
	int day;
	int month;
	int year;
public:
	void getdate()
	{
		char space;
		cout << "������ ������� ���� � ������� dd/mm/yyyy: ";
		cin >> day >> space >> month >> space >> year;
	}
	void showdate()
	{
		cout << "\n���� ����� �� ������: " << setw(2) << setfill('0') << day << '/' << setw(2) << setfill('0') << month << '/' << setw(4) << setfill('0') << year;
	}
};
enum etype { laborer, secretary, manager, accountant, executive, researcher };
class employee
{
private:
	int number;
	float money;
	date priem;
	etype work;
public:
	void pri()
	{
		priem.getdate();
	}
	void show()
	{
		priem.showdate();
	}
	void set()
	{
		cout << "������� ����� � ������� ����������: ";
		cin >> number >> money;
	}
	void info()
	{
		cout << "\n��������� �" << number << " �������� ������� � �������: " << money;
	}
	void getemploy()
	{
		char a;
		cout << "� ������ ������� ������ ����� ��������� (laborer, secretary, manager, accountant, executive, researcher): ";
		cin >> a;
		switch (a)
		{
		case 'l':
		{
			work = laborer;
			break;
		}
		case 's':
		{
			work = secretary;
			break;
		}
		case 'm':
		{
			work = manager;
			break;
		}
		case 'a':
		{
			work = accountant;
			break;
		}
		case 'e':
		{
			work = executive;
			break;
		}
		case 'r':
		{
			work = researcher;
			break;
		}
		}
	}
	void putemploy()
	{
		switch (work)
		{
		case 0:
		{
			cout << "\n���������� ���������: laborer";
			break;
		}
		case 1:
		{
			cout << "\n���������� ���������: secretary";
			break;
		}
		case 2:
		{
			cout << "\n���������� ���������: manager";
			break;
		}
		case 3:
		{
			cout << "\n���������� ���������: accountant";
			break;
		}
		case 4:
		{
			cout << "\n���������� ���������: executive";
			break;
		}
		case 5:
		{
			cout << "\n���������� ���������: researcher";
			break;
		}
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	employee one, two, three;
	one.set();
	one.getemploy();
	one.pri();
	two.set();
	two.getemploy();
	two.pri();
	three.set();
	three.getemploy();
	three.pri();
	one.info();
	one.putemploy();
	one.show();
	two.info();
	two.putemploy();
	two.show();
	three.info();
	three.putemploy();
	three.show();
}