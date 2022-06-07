#include <io.h> 
#include <iostream>
using namespace std;

struct link
{
	int data;
	link* next;
};

class linklist
{
private:
	link* first;
public:
	linklist()
	{
		first = NULL;
	}
	linklist(linklist&);
	~linklist();
	void additem(int d);
	void display();
	linklist& operator= (linklist&);
};

linklist::linklist(linklist& li)
{
	first = NULL;

	link* current = li.first;
	while (current)
	{
		additem(current->data);
		current = current->next;
	}
}

void linklist::additem(int d)
{
	link* newlink = new link;
	newlink->data = d;
	newlink->next = first;

	first = newlink;
}

void linklist::display()
{
	link* current = first;
	while (current)
	{
		cout << current->data << ' ';
		current = current->next;
	}
	cout << endl;
}
linklist::~linklist()
{
	link* current = first;
	while (current)
	{
		first = current->next;
		delete current;
		cout << "Элемент списка удалён." << endl;
		current = first;
	}
}

linklist& linklist::operator= (linklist& li)
{
	if (this == &li) return *this;
	link* current = first;
	while (current)
	{
		first = current->next;
		delete current;
		current = first;
	}
	current = li.first;
	while (current)
	{
		additem(current->data);
		current = current->next;
	}
	return *this;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	linklist* list1 = new linklist;
	list1->additem(25);
	list1->additem(36);
	list1->additem(49);
	list1->additem(64);
	cout << "list1 = "; list1->display();

	linklist list2(*list1);

	linklist list3;
	list3 = *list1;
	delete list1;
	cout << "list2 = "; list2.display();
	cout << "list3 = "; list3.display();
	return 0;
}
