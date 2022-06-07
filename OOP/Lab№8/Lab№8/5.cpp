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
		cout << "\n ������� �������: "; wcin >> name;
		cout << " ������� �����: "; wcin >> number;
	}
	void putdata() const
	{
		cout << "\n �������: " << name;
		cout << "\n �����: " << number;
	}
};
class employee2 : public employee
{
private:
	enum period_type { ���������, ������������, ����������� };
	period_type period;
	double compensation;
public:
	void getdata()
	{
		employee::getdata();
		cout << " ������� ������ ������ ('�' ���������, '�' ������������, '�' �����������): ";
		wchar_t ch; wcin >> ch;
		switch (ch)
		{
		case '�': period = ���������; break;
		case '�': period = ������������; break;
		case '�': period = �����������; break;
		default: period = ���������;
		}
		cout << " ������� ����� ��������������: "; wcin >> compensation;
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n ������ ������: ";
		switch (period)
		{
		case ���������: cout << "���������"; break;
		case ������������: cout << "������������"; break;
		case �����������: cout << "�����������"; break;
		}
		cout << "\n ����� ��������������: " << compensation;
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
		cout << " ������� ���������: "; wcin >> title;
		cout << " ������� ����� ������� � �����-����: "; wcin >> dues;
	}
	void putdata() const
	{
		employee2::putdata();
		cout << "\n ���������: " << title;
		cout << "\n ����� ������� � �����-����: " << dues;
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
		cout << " ������� ���������� ����������: "; wcin >> pubs;
	}
	void putdata() const
	{
		employee2::putdata();
		cout << "\n ���������� ����������: " << pubs;
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

	cout << "���� ���������� � ������ ����������";   m1.getdata();
	cout << "\n���� ���������� � ������ ����������"; m2.getdata();
	cout << "\n���� ���������� � ������ ������";     s1.getdata();
	cout << "\n���� ���������� � ������ �������";    l1.getdata();

	cout << "\n���������� � ������ ����������"; m1.putdata();
	cout << "\n���������� � ������ ����������"; m2.putdata();
	cout << "\n���������� � ������ ������";     s1.putdata();
	cout << "\n���������� � ������ �������";    l1.putdata();
	cout << endl;

	return 0;
}
