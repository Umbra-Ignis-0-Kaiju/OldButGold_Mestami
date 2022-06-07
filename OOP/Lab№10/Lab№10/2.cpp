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
		cout << "\n введите название издани€: "; getline(ws(wcin), title);
		cout << " введите цену экземпл€ра издани€: "; wcin >> price;
	}
	virtual void putdata() const
	{
		cout << "\n название издани€: " << title;
		cout << "\n цена экземпл€ра издани€: " << price << endl;
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
		cout << " введите количество страниц в книге: "; wcin >> pages;
	}
	void putdata() const
	{
		publication::putdata();
		cout << " количество страниц в книге: " << pages << endl;
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
		cout << " введите врем€ проигрывани€ аудиокниги в минутах: "; wcin >> playing_time;
	}
	void putdata() const
	{
		publication::putdata();
		cout << " врем€ проигрывани€ аудиокниги в минутах: " << playing_time << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	publication* pubPtr[100];
	int n = 0;
	wchar_t choice;
	do {
		cout << "¬водим бумажную или аудиокнигу? (p/a): "; wcin >> choice;
		if (choice == 'p')
			pubPtr[n] = new book;
		else
			pubPtr[n] = new tape;
		cout << "¬вод данных издани€ " << n + 1 << ":";
		pubPtr[n++]->getdata();
		cout << "\n¬вести следующее издание? (1/0): "; wcin >> choice; cout << endl;
	} while (choice == '1');
	for (int j = 0; j < n; j++)
	{
		cout << "ƒанные издани€ " << j + 1 << ":";
		pubPtr[j]->putdata();
	}

	return 0;
}