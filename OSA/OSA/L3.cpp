#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <locale.h>
using namespace std;

struct train
{
	int num; 
	string point;
	int d_i_w;
	short int time_arrival;
	short int time_parking;

};
	bool operator == (train &one, train &two)
	{
		return (one.num == two.num && one.d_i_w == two.d_i_w && one.point == two.point && one.time_arrival == two.time_arrival && one.time_parking == two.time_parking);
	}
	bool operator != (train& one, train& two)
	{
		return !(one.num == two.num && one.d_i_w == two.d_i_w && one.point == two.point && one.time_arrival == two.time_arrival && one.time_parking == two.time_parking);
	}

train push()
{
	train t;
	cout << "\nВведите номер поезда: ";
	cin >> t.num;
	cout << "\nВведите пункт назначения: ";
	cin.get();
	getline(cin, t.point);
	cout << "\nВведите количество дней в пути: ";
	cin >> t.d_i_w;
	char pox;
	int h, m;
	cout << "\nВведите время прибытия: ";
	cin >> h >> pox >> m;
	t.time_arrival = h * 60 + m;
	cout << "\nВведите время стоянки: ";
	cin >> h >> pox >> m;
	t.time_parking = h * 60 + m;
	return t;
}

struct note 
{
    train sostav;
    note* next;

    note(train _sostav) : sostav(_sostav), next(nullptr) {}
};

struct list 
{
    note* first;
    note* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() 
    {
        return first == nullptr;
    }

    void push_back(train sostav) 
    {
        note* p = new note(sostav);
        if (is_empty()) 
		{
            first = p;
            last = p;
			return;
        }
        last->next = p;
        last = p;
    }

	void push_front(train sostav)
	{
		note* k;
		note* p = new note(sostav);
		if (is_empty())
		{
			first = p;
			last = p;
			return;
		}
		k = first;
		first = p;
		first->next = k;
	}

	void insert(note* t)
	{
		note* k;
		if (t == nullptr)
		{
			cout << "Не найдено\n";
			return;
		}
		note* p = new note(push());
		k = t->next;
		t->next = p;
		p->next = k;
		if (t == last)
			last = p;
	}

	void pop(note* t)
	{
		if (t == nullptr)
		{
			cout << "Не найдено\n";
			return;
		}
		note* p = first;
		if (t == last && t == first)
		{
			last = nullptr;
			first = nullptr;
			return;
		}
		while (1)
		{
			if (p->next != nullptr)
				if (p->next->sostav != t->sostav)
					p = p->next;
				else
					break;
			else
				break;
		}
		if (t == last)
		{
			last = p;
			p->next = nullptr;
		}
		else if (t == first)
			first = t->next;
		else
			p->next = t->next;
	}

	void remove_first() 
	{
		if (is_empty()) return;
		note* p = first;
		first = p->next;
		delete p;
	}

	void remove_last() 
	{
		if (is_empty()) return;
		if (first == last) 
		{
			remove_first();
			return;
		}
		note* p = first;
		while (p->next != last) p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}

	note* find() 
	{
		note* p = first;
		char tt;
		int k, t;
		cout << "По какому из эллементов искать?: \n"
			<< "1 - Поиск по номеру \n"
			<< "2 - Поиск по пункту назначения \n"
			<< "3 - Поиск по количеству дней в пути \n"
			<< "4 - Поиск по времени прибытия \n"
			<< "5 - Поиск по времени стоянки \n";
		cin >> k;
		string po;
		switch (k)
		{
		case 1:
			cin >> k;
			while (p && p->sostav.num != k) p = p->next;
			return (p && p->sostav.num == k) ? p : nullptr;
			break;
		case 2:
			cin >> po;
			while (p && p->sostav.point != po) p = p->next;
			return (p && p->sostav.point == po) ? p : nullptr;
			break;
		case 3:
			cin >> k;
			while (p && p->sostav.d_i_w != k) p = p->next;
			return (p && p->sostav.d_i_w == k) ? p : nullptr;
			break;
		case 4:
			cin >> k >> tt >> t;
			k = k * 60 + t;
			while (p && p->sostav.time_arrival != k) p = p->next;
			return (p && p->sostav.time_arrival == k) ? p : nullptr;
			break;
		case 5:
			cin >> k >> tt >> t;
			k = k * 60 + t;
			while (p && p->sostav.time_parking != k) p = p->next;
			return (p && p->sostav.time_parking == k) ? p : nullptr;
			break;
		}
		cout << "Элемент не найден\n";
		return nullptr;
	}

    void print() 
    {
        if (is_empty()) return;
        note* p = first;
        while (p) {
			cout << "\n\nНомер поезда: " << p->sostav.num;
			cout << "\nВведите пункт назначения: " << p->sostav.point;
			cout << "\nКоличество дней в пути: " << p->sostav.d_i_w;
			cout << "\nВремя прибытия: " << setfill('0') << setw(2) << p->sostav.time_arrival / 60 << ":" << setfill('0') << setw(2) << p->sostav.time_arrival % 60;
			cout << "\nВремя стоянки: " << setfill('0') << setw(2) << p->sostav.time_parking / 60 << ":" << setfill('0') << setw(2) << p->sostav.time_parking % 60;
            p = p->next;
        }
        cout << endl;
    }

	note* operator[] (const int index) {
		if (is_empty()) return nullptr;
		note* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
};

int main()
{
	setlocale(LC_ALL, "Ru");
	note* k = nullptr;
	list l;
	bool s = 1;
	int t;
	while (s != 0)
	{
		cout << "\nКакой функцией вы хотите воспользоваться?:\n"
			<< "1 - Добавление элемента в конце списка \n"
			<< "2 - Добавление элемента в начало списка \n"
			<< "3 - Удаление конечного элемента \n"
			<< "4 - Удаление первого элемента \n"
			<< "5 - Поиск элемента по заданному значению поля \n"
			<< "6 - Добавление элемента после найденного \n"
			<< "7 - Удаление найденного элемента \n"
			<< "8 - Вывести весь список\n";
		cin >> t;
		switch (t)
		{
		case 1:
			l.push_back(push());
			break;
		case 2:
			l.push_front(push());
			break;
		case 3:
			l.remove_last();
			break;
		case 4:
			l.remove_first();
			break;
		case 5:
			k = l.find();
			if (k == nullptr) cout << "Элемент не был найден\n";
			break;
		case 6:
			l.insert(k);
			break;
		case 7:
			l.pop(k);
			break;
		case 8:
			l.print();
			break;
		}
		cout << "\nПродолжить работу с программой?: (0/1)   ";
		cin >> s;
	}
    return 0;
}