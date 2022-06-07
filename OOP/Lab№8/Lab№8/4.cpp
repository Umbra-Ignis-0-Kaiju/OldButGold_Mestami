#include <iostream>
#include <string> 
using namespace std;

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

class sales
{
private:
	float sales_sum[3];
public:
	void getdata()
	{
		cout << " ������� ������� �� ������ �� 3 ������ (����� ������): ";
		wcin >> sales_sum[0] >> sales_sum[1] >> sales_sum[2];
	}
	void putdata() const
	{
		cout << " ������� �� ������ �� ��������� 3 ������: "
			<< sales_sum[0] << " " << sales_sum[1] << " " << sales_sum[2] << endl;
	}
};
class book : public publication, public sales
{
private:
	int pages;
public:
	void getdata()
	{
		publication::getdata();
		cout << " ������� ���������� ������� � �����: "; wcin >> pages;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << " ���������� ������� � �����: " << pages << endl;
		sales::putdata();
	}
};

class tape : public publication, public sales
{
private:
	float playing_time;
public:
	void getdata()
	{
		publication::getdata();
		cout << " ������� ����� ������������ ���������� � �������: "; wcin >> playing_time;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << " ����� ������������ ���������� � �������: " << playing_time << endl;
		sales::putdata();
	}
};

class disk : public publication, public sales
{
private:
	enum disk_type_enum { CD, DVD };
	disk_type_enum disk_type;
public:
	void getdata()
	{
		publication::getdata();
		wchar_t ch;
		cout << " ������� ��� ����������� ����� (������� ����� '�' ��� CD, '�' ��� DVD): "; wcin >> ch;
		switch (ch)
		{
		case '�': disk_type = CD; break;
		case '�': disk_type = DVD; break;
		default: disk_type = CD;
		}
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << " ��� ����������� �����: " << ((disk_type == CD) ? "CD" : "DVD") << endl;
		sales::putdata();
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	book b1;
	tape t1;
	disk d1;

	cout << "���� ������ �������������� �������� �����"; b1.getdata();
	cout << "\n���� ������ �������������� ����������"; t1.getdata();
	cout << "\n���� ������ �����, �������������� �� ���������� �����"; d1.getdata();

	cout << "\n������ �������������� �������� �����"; b1.putdata();
	cout << "\n������ �������������� ����������"; t1.putdata();
	cout << "\n������ �����, �������������� �� ���������� �����"; d1.putdata();

	return 0;
}
