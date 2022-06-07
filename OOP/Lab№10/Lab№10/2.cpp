#include <iostream>
#include <string> 
using namespace std;
class publication
{
private:
	wstring title;
	float price;
public:
	virtual void getdata()
	{
		cout << "\n ������� �������� �������: "; getline(ws(wcin), title);
		cout << " ������� ���� ���������� �������: "; wcin >> price;
	}
	virtual void putdata() const
	{
		cout << "\n �������� �������: " << title;
		cout << "\n ���� ���������� �������: " << price << endl;
	}
};
class book : public publication
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << " ������� ���������� ������� � �����: "; wcin >> pages;
	}
	void putdata() const
	{
		publication::putdata();
		cout << " ���������� ������� � �����: " << pages << endl;
	}
};
class tape : public publication
{
private:
	float playing_time;
public:
	void getdata()
	{
		publication::getdata();
		cout << " ������� ����� ������������ ���������� � �������: "; wcin >> playing_time;
	}
	void putdata() const
	{
		publication::putdata();
		cout << " ����� ������������ ���������� � �������: " << playing_time << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	publication* pubPtr[100];
	int n = 0;
	wchar_t choice;
	do {
		cout << "������ �������� ��� ����������? (p/a): "; wcin >> choice;
		if (choice == 'p')
			pubPtr[n] = new book;
		else
			pubPtr[n] = new tape;
		cout << "���� ������ ������� " << n + 1 << ":";
		pubPtr[n++]->getdata();
		cout << "\n������ ��������� �������? (1/0): "; wcin >> choice; cout << endl;
	} while (choice == '1');
	for (int j = 0; j < n; j++)
	{
		cout << "������ ������� " << j + 1 << ":";
		pubPtr[j]->putdata();
	}

	return 0;
}