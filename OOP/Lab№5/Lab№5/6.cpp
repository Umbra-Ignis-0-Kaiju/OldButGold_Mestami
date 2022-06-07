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
		cout << "Теперь введите дату в формате dd/mm/yyyy: ";
		cin >> day >> space >> month >> space >> year;
	}
	void showdate()
	{
		cout << "\nДата приёма на работу: " << setw(2) << setfill('0') << day << '/' << setw(2) << setfill('0') << month << '/' << setw(4) << setfill('0') << year;
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
		cout << "Введите номер и пособие сотрудника: ";
		cin >> number >> money;
	}
	void info()
	{
		cout << "\nСотрудник №" << number << " получает пособие в размере: " << money;
	}
	void getemploy()
	{
		char a;
		cout << "А теперь введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): ";
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
			cout << "\nЗанимаемая должность: laborer";
			break;
		}
		case 1:
		{
			cout << "\nЗанимаемая должность: secretary";
			break;
		}
		case 2:
		{
			cout << "\nЗанимаемая должность: manager";
			break;
		}
		case 3:
		{
			cout << "\nЗанимаемая должность: accountant";
			break;
		}
		case 4:
		{
			cout << "\nЗанимаемая должность: executive";
			break;
		}
		case 5:
		{
			cout << "\nЗанимаемая должность: researcher";
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