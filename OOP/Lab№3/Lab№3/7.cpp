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
	char space;
	char post;
	string p;
	struct date
	{
		int day;
		int month;
		int year;
	};
	enum etype { laborer, secretary, manager, accountant, executive, researcher };
	struct employee
	{
		int number;
		float money;
		date adopted;
		etype post;
	};
	employee f, s, t;
	cout << "Введите номер, пособие, дату назначения на должность, а так же саму должность первого сотрудника: ";
	cin >> f.number >> f.money >> f.adopted.day >> space >> f.adopted.month >> space >> f.adopted.year >> p;
	post = p[0];
	switch (post)
	{
	case 'l':
	{
		f.post = laborer;
		break;
	}
	case 's':
	{
		f.post = secretary;
		break;
	}
	case 'm':
	{
		f.post = manager;
		break;
	}
	case 'a':
	{
		f.post = accountant;
		break;
	}
	case 'e':
	{
		f.post = executive;
		break;
	}
	case 'r':
	{
		f.post = researcher;
		break;
	}
	}
	cin.get();
	cout << "Введите номер, пособие, дату назначения на должность, а так же саму должность второго сотрудника: ";
	cin >> s.number >> s.money >> s.adopted.day >> space >> s.adopted.month >> space >> s.adopted.year >> p;
	post = p[0];
	switch (post)
	{
	case 'l':
	{
		s.post = laborer;
		break;
	}
	case 's':
	{
		s.post = secretary;
		break;
	}
	case 'm':
	{
		s.post = manager;
		break;
	}
	case 'a':
	{
		s.post = accountant;
		break;
	}
	case 'e':
	{
		s.post = executive;
		break;
	}
	case 'r':
	{
		s.post = researcher;
		break;
	}
	}
	cout << "Введите номер, пособие, дату назначения на должность, а так же саму должность третьего сотрудника: ";
	cin >> t.number >> t.money >> t.adopted.day >> space >> t.adopted.month >> space >> t.adopted.year >> p;
	post = p[0];
	switch (post)
	{
	case 'l':
	{
		t.post = laborer;
		break;
	}
	case 's':
	{
		t.post = secretary;
		break;
	}
	case 'm':
	{
		t.post = manager;
		break;
	}
	case 'a':
	{
		t.post = accountant;
		break;
	}
	case 'e':
	{
		t.post = executive;
		break;
	}
	case 'r':
	{
		t.post = researcher;
		break;
	}
	}
	switch (f.post)
	{
	case 0:
	{
		cout << "\nСотрудник №" << f.number << " получает пособие в размере: " << f.money << ", должность: laborer, дата приёма на должность: " << setw(2) << setfill('0') << f.adopted.day << space << setw(2) << setfill('0') << f.adopted.month << space << setw(4) << setfill('0') << f.adopted.year;
		break;
	}
	case 1:
	{
		cout << "\nСотрудник №" << f.number << " получает пособие в размере: " << f.money << ", должность: secretary, дата приёма на должность: " << setw(2) << setfill('0') << f.adopted.day << space << setw(2) << setfill('0') << f.adopted.month << space << setw(4) << setfill('0') << f.adopted.year;
		break;
	}
	case 2:
	{
		cout << "\nСотрудник №" << f.number << " получает пособие в размере: " << f.money << ", должность: manager, дата приёма на должность: " << setw(2) << setfill('0') << f.adopted.day << space << setw(2) << setfill('0') << f.adopted.month << space << setw(4) << setfill('0') << f.adopted.year;
		break;
	}
	case 3:
	{
		cout << "\nСотрудник №" << f.number << " получает пособие в размере: " << f.money << ", должность: accountant, дата приёма на должность: " << setw(2) << setfill('0') << f.adopted.day << space << setw(2) << setfill('0') << f.adopted.month << space << setw(4) << setfill('0') << f.adopted.year;
		break;
	}
	case 4:
	{
		cout << "\nСотрудник №" << f.number << " получает пособие в размере: " << f.money << ", должность: executive, дата приёма на должность: " << setw(2) << setfill('0') << f.adopted.day << space << setw(2) << setfill('0') << f.adopted.month << space << setw(4) << setfill('0') << f.adopted.year;
		break;
	}
	case 5:
	{
		cout << "\nСотрудник №" << f.number << " получает пособие в размере: " << f.money << ", должность: researcher, дата приёма на должность: " << setw(2) << setfill('0') << f.adopted.day << space << setw(2) << setfill('0') << f.adopted.month << space << setw(4) << setfill('0') << f.adopted.year;
		break;
	}
	}
	switch (s.post)
	{
	case 0:
	{
		cout << "\nСотрудник №" << s.number << " получает пособие в размере: " << s.money << ", должность: laborer, дата приёма на должность: " << setw(2) << setfill('0') << s.adopted.day << space << setw(2) << setfill('0') << s.adopted.month << space << setw(4) << setfill('0') << s.adopted.year;
		break;
	}
	case 1:
	{
		cout << "\nСотрудник №" << s.number << " получает пособие в размере: " << s.money << ", должность: secretary, дата приёма на должность: " << setw(2) << setfill('0') << s.adopted.day << space << setw(2) << setfill('0') << s.adopted.month << space << setw(4) << setfill('0') << s.adopted.year;
		break;
	}
	case 2:
	{
		cout << "\nСотрудник №" << s.number << " получает пособие в размере: " << s.money << ", должность: manager, дата приёма на должность: " << setw(2) << setfill('0') << s.adopted.day << space << setw(2) << setfill('0') << s.adopted.month << space << setw(4) << setfill('0') << s.adopted.year;
		break;
	}
	case 3:
	{
		cout << "\nСотрудник №" << s.number << " получает пособие в размере: " << s.money << ", должность: accountant, дата приёма на должность: " << setw(2) << setfill('0') << s.adopted.day << space << setw(2) << setfill('0') << s.adopted.month << space << setw(4) << setfill('0') << s.adopted.year;
		break;
	}
	case 4:
	{
		cout << "\nСотрудник №" << s.number << " получает пособие в размере: " << s.money << ", должность: executive, дата приёма на должность: " << setw(2) << setfill('0') << s.adopted.day << space << setw(2) << setfill('0') << s.adopted.month << space << setw(4) << setfill('0') << s.adopted.year;
		break;
	}
	case 5:
	{
		cout << "\nСотрудник №" << s.number << " получает пособие в размере: " << s.money << ", должность: researcher, дата приёма на должность: " << setw(2) << setfill('0') << s.adopted.day << space << setw(2) << setfill('0') << s.adopted.month << space << setw(4) << setfill('0') << s.adopted.year;
		break;
	}
	}
	switch (t.post)
	{
	case 0:
	{
		cout << "\nСотрудник №" << t.number << " получает пособие в размере: " << t.money << ", должность: laborer, дата приёма на должность: " << setw(2) << setfill('0') << t.adopted.day << space << setw(2) << setfill('0') << t.adopted.month << space << setw(4) << setfill('0') << t.adopted.year;
		break;
	}
	case 1:
	{
		cout << "\nСотрудник №" << t.number << " получает пособие в размере: " << t.money << ", должность: secretary, дата приёма на должность: " << setw(2) << setfill('0') << t.adopted.day << space << setw(2) << setfill('0') << t.adopted.month << space << setw(4) << setfill('0') << t.adopted.year;
		break;
	}
	case 2:
	{
		cout << "\nСотрудник №" << t.number << " получает пособие в размере: " << t.money << ", должность: manager, дата приёма на должность: " << setw(2) << setfill('0') << t.adopted.day << space << setw(2) << setfill('0') << t.adopted.month << space << setw(4) << setfill('0') << t.adopted.year;
		break;
	}
	case 3:
	{
		cout << "\nСотрудник №" << t.number << " получает пособие в размере: " << t.money << ", должность: accountant, дата приёма на должность: " << setw(2) << setfill('0') << t.adopted.day << space << setw(2) << setfill('0') << t.adopted.month << space << setw(4) << setfill('0') << t.adopted.year;
		break;
	}
	case 4:
	{
		cout << "\nСотрудник №" << t.number << " получает пособие в размере: " << t.money << ", должность: executive, дата приёма на должность: " << setw(2) << setfill('0') << t.adopted.day << space << setw(2) << setfill('0') << t.adopted.month << space << setw(4) << setfill('0') << t.adopted.year;
		break;
	}
	case 5:
	{
		cout << "\nСотрудник №" << t.number << " получает пособие в размере: " << t.money << ", должность: researcher, дата приёма на должность: " << setw(2) << setfill('0') << t.adopted.day << space << setw(2) << setfill('0') << t.adopted.month << space << setw(4) << setfill('0') << t.adopted.year;
		break;
	}
	}
}