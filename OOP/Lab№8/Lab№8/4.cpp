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
		cout << "\n введите название издани€: "; getline(ws(wcin), title);
		cout << " введите цену экземпл€ра издани€: "; wcin >> price;
	}
	void putdata() const
	{
		cout << "\n название издани€: " << title;
		cout << "\n цена экземпл€ра издани€: " << price << endl;
	}
};

class sales
{
private:
	float sales_sum[3];
public:
	void getdata()
	{
		cout << " введите выручку от продаж за 3 мес€ца (через пробел): ";
		wcin >> sales_sum[0] >> sales_sum[1] >> sales_sum[2];
	}
	void putdata() const
	{
		cout << " выручка от продаж за последние 3 мес€ца: "
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
		cout << " введите количество страниц в книге: "; wcin >> pages;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << " количество страниц в книге: " << pages << endl;
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
		cout << " введите врем€ проигрывани€ аудиокниги в минутах: "; wcin >> playing_time;
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << " врем€ проигрывани€ аудиокниги в минутах: " << playing_time << endl;
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
		cout << " введите тип оптического диска (русска€ буква 'к' дл€ CD, 'д' дл€ DVD): "; wcin >> ch;
		switch (ch)
		{
		case 'к': disk_type = CD; break;
		case 'д': disk_type = DVD; break;
		default: disk_type = CD;
		}
		sales::getdata();
	}
	void putdata() const
	{
		publication::putdata();
		cout << " тип оптического диска: " << ((disk_type == CD) ? "CD" : "DVD") << endl;
		sales::putdata();
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	book b1;
	tape t1;
	disk d1;

	cout << "¬вод данных опубликованной бумажной книги"; b1.getdata();
	cout << "\n¬вод данных опубликованной аудиокниги"; t1.getdata();
	cout << "\n¬вод данных книги, опубликованной на оптическом диске"; d1.getdata();

	cout << "\nƒанные опубликованной бумажной книги"; b1.putdata();
	cout << "\nƒанные опубликованной аудиокниги"; t1.putdata();
	cout << "\nƒанные книги, опубликованной на оптическом диске"; d1.putdata();

	return 0;
}
