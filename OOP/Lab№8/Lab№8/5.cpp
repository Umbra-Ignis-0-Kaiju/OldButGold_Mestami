#include <iostream>
using namespace std;

const int LEN = 80;
class employee
{
private:
	wchar_t name[LEN];
	unsigned long number;
public:
	void getdata()
	{
		cout << "\n ¬ведите фамилию: "; wcin >> name;
		cout << " ¬ведите номер: "; wcin >> number;
	}
	void putdata() const
	{
		cout << "\n ‘амили€: " << name;
		cout << "\n Ќомер: " << number;
	}
};
class employee2 : public employee
{
private:
	enum period_type { почасова€, еженедельна€, ежемес€чна€ };
	period_type period;
	double compensation;
public:
	void getdata()
	{
		employee::getdata();
		cout << " ¬ведите период выплат ('ч' почасова€, 'н' еженедельна€, 'м' ежемес€чна€): ";
		wchar_t ch; wcin >> ch;
		switch (ch)
		{
		case 'ч': period = почасова€; break;
		case 'н': period = еженедельна€; break;
		case 'м': period = ежемес€чна€; break;
		default: period = почасова€;
		}
		cout << " ¬ведите сумму вознаграждени€: "; wcin >> compensation;
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n ѕериод выплат: ";
		switch (period)
		{
		case почасова€: cout << "почасова€"; break;
		case еженедельна€: cout << "еженедельна€"; break;
		case ежемес€чна€: cout << "ежемес€чна€"; break;
		}
		cout << "\n —умма вознаграждени€: " << compensation;
	}
};
class manager : public employee2
{
private:
	wchar_t title[LEN];
	double dues;
public:
	void getdata()
	{
		employee2::getdata();
		cout << " ¬ведите должность: "; wcin >> title;
		cout << " ¬ведите сумму взносов в гольф-клуб: "; wcin >> dues;
	}
	void putdata() const
	{
		employee2::putdata();
		cout << "\n ƒолжность: " << title;
		cout << "\n —умма взносов в гольф-клуб: " << dues;
	}
};

class scientist : public employee2
{
private:
	int pubs;
public:
	void getdata()
	{
		employee2::getdata();
		cout << " ¬ведите количество публикаций: "; wcin >> pubs;
	}
	void putdata() const
	{
		employee2::putdata();
		cout << "\n  оличество публикаций: " << pubs;
	}
};

class laborer : public employee2
{ };

int main()
{
	setlocale(LC_ALL, "Russian");

	manager m1, m2;
	scientist s1;
	laborer l1;

	cout << "¬вод информации о первом управленце";   m1.getdata();
	cout << "\n¬вод информации о втором управленце"; m2.getdata();
	cout << "\n¬вод информации о первом ученом";     s1.getdata();
	cout << "\n¬вод информации о первом рабочем";    l1.getdata();

	cout << "\n»нформаци€ о первом управленце"; m1.putdata();
	cout << "\n»нформаци€ о втором управленце"; m2.putdata();
	cout << "\n»нформаци€ о первом ученом";     s1.putdata();
	cout << "\n»нформаци€ о первом рабочем";    l1.putdata();
	cout << endl;

	return 0;
}
