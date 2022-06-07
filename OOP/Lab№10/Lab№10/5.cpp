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
	virtual bool isOversize() const = 0;
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
	bool isOversize() const
	{
		if (pages > 800)
			return true;
		else
			return false;
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
	bool isOversize() const
	{
		if (playing_time > 90)
			return true;
		else
			return false;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	publication* pubPtr[100];
	int n = 0;
	wchar_t choice;
	do {
		cout << "������ �������� ��� ����������? (�/�): "; wcin >> choice;
		if (choice == '�')
			pubPtr[n] = new book;
		else
			pubPtr[n] = new tape;
		cout << "���� ������ ������� " << n + 1 << ":";
		pubPtr[n++]->getdata();
		cout << "\n������ ��������� �������? (�/�): "; wcin >> choice; cout << endl;
	} while (choice == '�');
	for (int j = 0; j < n; j++)
	{
		cout << "������ ������� " << j + 1 << ":";
		pubPtr[j]->putdata();
		if (pubPtr[j]->isOversize()) cout << " (������� �������� �������!)\n";
	}

	return 0;
}