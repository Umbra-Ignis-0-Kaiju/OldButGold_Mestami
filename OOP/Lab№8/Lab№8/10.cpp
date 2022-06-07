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
		cout << " ������� �������� �������� ���������: "; wcin >> school;
		cout << " ������� ������� ����������� �����������\n";
		cout << " (��������_������, ��������, �������, ��������_����): "; wcin >> degree;
	}
	void putedu() const
	{
		cout << "\n ������� ���������: " << school;
		cout << "\n ������� ����������� �����������: " << degree;
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
		cout << "\n ������� �������: "; wcin >> name;
		cout << " ������� �����: "; wcin >> number;
	}
	void putdata() const
	{
		cout << "\n �������: " << name;
		cout << "\n �����: " << number;
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
		cout << " ������� ���������: "; wcin >> title;
		cout << " ������� ����� ������� � �����-����: "; wcin >> dues;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n ���������: " << title;
		cout << "\n ����� ������� � �����-����: " << dues;
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
		cout << " ������� ������ ������� ������: "; wcin >> yearly_bonus;
		cout << " ������� ���������� �����: "; wcin >> shares;
	}
	void putdata() const
	{
		manager::putdata();
		cout << "\n ������ ������� ������: " << yearly_bonus;
		cout << "\n ���������� �����: " << shares;
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
		cout << " ������� ���������� ����������: "; wcin >> pubs;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n ���������� ����������: " << pubs;
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
	cout << "���� ���������� �� ���������� ������� �����"; e1.getdata();
	cout << "\n���� ���������� �� ����������";             m1.getdata();
	cout << "\n���� ���������� �� ������";                 s1.getdata();
	cout << "\n���� ���������� � �������";                 l1.getdata();

	cout << "\n���������� �� ���������� ������� �����"; e1.putdata();
	cout << "\n���������� �� ����������";               m1.putdata();
	cout << "\n���������� �� ������";                   s1.putdata();
	cout << "\n���������� � �������";                   l1.putdata();
	cout << endl;

	return 0;
}
