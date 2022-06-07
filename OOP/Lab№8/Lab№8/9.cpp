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
		cout << "¬ведите день, мес€ц и год через косую черту (/): ";
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
		cout << "\n введите название издани€: "; getline(ws(wcin), title);
		cout << " введите цену экземпл€ра издани€: "; wcin >> price;
	}
	void putdata() const
	{
		cout << "\n название издани€: " << title;
		cout << "\n цена экземпл€ра издани€: " << price << endl;
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
		cout << " введите дату публикации издани€:\n  "; pub_date.get();
	}
	void putdata() const
	{
		publication::putdata();
		cout << " дата публикации издани€: "; pub_date.display(); cout << endl;
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
		cout << " введите количество страниц в книге: "; wcin >> pages;
	}
	void putdata() const
	{
		publication2::putdata();
		cout << " количество страниц в книге: " << pages << endl;
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
		cout << " введите врем€ проигрывани€ аудиокниги в минутах: "; wcin >> playing_time;
	}
	void putdata() const
	{
		publication2::putdata();
		cout << " врем€ проигрывани€ аудиокниги в минутах: " << playing_time << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	book b1;
	tape t1;
	cout << "¬вод данных опубликованной бумажной книги"; b1.getdata();
	cout << "\n¬вод данных опубликованной аудиокниги"; t1.getdata();
	cout << "\nƒанные опубликованной бумажной книги"; b1.putdata();
	cout << "\nƒанные опубликованной аудиокниги"; t1.putdata();

	return 0;
}
