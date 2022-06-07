#include <iostream>
using namespace std;

const int LEN = 80;

class student
{
private:
	wchar_t school[LEN];
	wchar_t degree[LEN];
public:
	void getedu()
	{
		cout << " Введите название учебного заведения: "; wcin >> school;
		cout << " Введите уровень полученного образования\n";
		cout << " (неполное_высшее, бакалавр, магистр, кандидат_наук): "; wcin >> degree;
	}
	void putedu() const
	{
		cout << "\n Учебное заведение: " << school;
		cout << "\n Уровень полученного образования: " << degree;
	}
};

class employee
{
private:
	wchar_t name[LEN];
	unsigned long number;
public:
	void getdata()
	{
		cout << "\n Введите фамилию: "; wcin >> name;
		cout << " Введите номер: "; wcin >> number;
	}
	void putdata() const
	{
		cout << "\n Фамилия: " << name;
		cout << "\n Номер: " << number;
	}
};

class manager : private employee, private student
{
private:
	wchar_t title[LEN];
	double dues;
public:
	void getdata()
	{
		employee::getdata();
		cout << " Введите должность: "; wcin >> title;
		cout << " Введите сумму взносов в гольф-клуб: "; wcin >> dues;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n Должность: " << title;
		cout << "\n Сумма взносов в гольф-клуб: " << dues;
		student::putedu();
	}
};
class executive : private manager
{
private:
	double yearly_bonus;
	unsigned long shares;
public:
	void getdata()
	{
		manager::getdata();
		cout << " Введите размер годовой премии: "; wcin >> yearly_bonus;
		cout << " Введите количество акций: "; wcin >> shares;
	}
	void putdata() const
	{
		manager::putdata();
		cout << "\n Размер годовой премии: " << yearly_bonus;
		cout << "\n Количество акций: " << shares;
	}
};

class scientist : private employee, private student
{
private:
	int pubs;
public:
	void getdata()
	{
		employee::getdata();
		cout << " Введите количество публикаций: "; wcin >> pubs;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n Количество публикаций: " << pubs;
		student::putedu();
	}
};

class laborer : public employee
{ };

int main()
{
	setlocale(LC_ALL, "Russian");

	executive e1;
	manager m1;
	scientist s1;
	laborer l1;
	cout << "Ввод информации об управленце высшего звена"; e1.getdata();
	cout << "\nВвод информации об управленце";             m1.getdata();
	cout << "\nВвод информации об ученом";                 s1.getdata();
	cout << "\nВвод информации о рабочем";                 l1.getdata();

	cout << "\nИнформация об управленце высшего звена"; e1.putdata();
	cout << "\nИнформация об управленце";               m1.putdata();
	cout << "\nИнформация об ученом";                   s1.putdata();
	cout << "\nИнформация о рабочем";                   l1.putdata();
	cout << endl;

	return 0;
}
