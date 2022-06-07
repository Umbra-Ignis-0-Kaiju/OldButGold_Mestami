#include <iostream>
#include <string>
using namespace std;

class date
{
private:
	int day;
	int month;
	int year;
public:
	void get()
	{
		wchar_t slash;
		cout << "������� ����, ����� � ��� ����� ����� ����� (/): ";
		wcin >> day >> slash >> month >> slash >> year;
	}
	void display() const
	{
		cout << day << "/" << month << "/" << year;
	}
};
class publication
{
private:
	wstring title;
	float price;
public:
	void getdata()
	{
		cout << "\n ������� �������� �������: "; getline(ws(wcin), title);
		cout << " ������� ���� ���������� �������: "; wcin >> price;
	}
	void putdata() const
	{
		cout << "\n �������� �������: " << title;
		cout << "\n ���� ���������� �������: " << price << endl;
	}
};
class publication2 : public publication
{
private:
	date pub_date;
public:
	void getdata()
	{
		publication::getdata();
		cout << " ������� ���� ���������� �������:\n  "; pub_date.get();
	}
	void putdata() const
	{
		publication::putdata();
		cout << " ���� ���������� �������: "; pub_date.display(); cout << endl;
	}
};

class book : public publication2
{
private:
	int pages;
public:
	void getdata()
	{
		publication2::getdata();
		cout << " ������� ���������� ������� � �����: "; wcin >> pages;
	}
	void putdata() const
	{
		publication2::putdata();
		cout << " ���������� ������� � �����: " << pages << endl;
	}
};
class tape : public publication2
{
private:
	float playing_time;
public:
	void getdata()
	{
		publication2::getdata();
		cout << " ������� ����� ������������ ���������� � �������: "; wcin >> playing_time;
	}
	void putdata() const
	{
		publication2::putdata();
		cout << " ����� ������������ ���������� � �������: " << playing_time << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	book b1;
	tape t1;
	cout << "���� ������ �������������� �������� �����"; b1.getdata();
	cout << "\n���� ������ �������������� ����������"; t1.getdata();
	cout << "\n������ �������������� �������� �����"; b1.putdata();
	cout << "\n������ �������������� ����������"; t1.putdata();

	return 0;
}
