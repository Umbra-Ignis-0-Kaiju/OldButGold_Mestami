#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

const int N = 10;
class queue
{
private:
	string* array;
	int tail;
	int size;
public:
	queue()
	{
		array = new string[N];
		size = N;
		tail = -1;
	}
	queue(int el)
	{
		array = new string[el];
		size = el;
		tail = -1;
	}
	~queue()
	{
		delete[] array;
	}
	void push(string n) // n - becous NEW
	{
		if (tail == size - 1)
			cout << "Queue is already FULL!";
		else
		{
			tail++;
			array[tail] = n;
		}
	}
	void pop()
	{
		if (tail != -1)
		{
			cout << "\n������ ���: " << array[0];
			for (int i = 0; i < tail; i++)
				array[i] = array[i + 1];
			tail--;
		}
		else
			cout << "\nQueue is already EMPTY!";
	}
	bool check(char temp)
	{
		if (temp == 'v')
		{
			if (tail == size - 1)
			{
				cout << "Queue is already FULL!";
				return 0;
			}
			else
				return 1;
		}
		else if (temp == 'p')
		{
			if (tail == -1)
			{
				cout << "\nQueue is already EMPTY!";
				return 0;
			}
			else
				return 1;
		}
		else
		{
			cout << "������������� ��������. ������ �1337";
			return 0;
		}
	}
};

class stack
{
private:
	string* array;
	int top;
	int size;
public:
	stack()
	{
		array = new string[N];
		size = N;
		top = -1;
	}
	stack(int el)
	{
		array = new string[el];
		size = el;
		top = -1;
	}
	~stack()
	{
		delete[] array;
	}
	void pop()
	{
		if (top == -1)
		{
			cout << "\nStack is alrady EMPTY!";
		}
		else
		{
			cout << "\n�� �������� �� ����� �������: " << array[top];
			//delete array;
			top--;
		}
	}
	void push(string n) // n - becous NEW
	{
		if (top == size - 1)
		{
			cout << "\nStack is already FULL!";
		}
		else
		{
			top++;
			array[top] = n;
		}
	}
	bool check(char temp)
	{
		if (temp == 'p')
		{
			if (top == size - 1)
			{
				cout << "Queue is already FULL!";
				return 0;
			}
			else
				return 1;
		}
		else if (temp == 'i')
		{
			if (top == -1)
			{
				cout << "\nQueue is already EMPTY!";
				return 0;
			}
			else
				return 1;
		}
		else
		{
			cout << "������������� ��������. ������ �1337";
			return 0;
		}
	}
};

int main()
{
	char o = 'd';
	string ws;
	setlocale(LC_ALL, "Rus");
	while (o != 'n')
	{
		cout << "\n� ��� �� ������ ��������: � ���������/� ���������? (stack/queue): ";
		cin >> ws;
		if (ws == "stack")
		{
			char t;
			cout << "\n������ ������ ������ ���������? (d/n): ";
			cin >> t;
			int z = N;
			if (t == 'd')
			{
				cout << "\n������ ���������: ";
				cin >> z;
			}
			stack inv(z);
			while (o != 'n')
			{
				cout << "\n������ �������� ��� ������ ������� �� ���������? (p/i): ";
				cin >> o;
				if (o == 'p')
				{
					if (inv.check(o))
					{
						cout << "\n����� ������� �� ������ �������� � ���������?: ";
						cin.get();
						getline(cin, ws);
						inv.push(ws);
					};
				}
				else if (o == 'i')
				{
					if (inv.check(o))
					{
						inv.pop();
					};
				}
				else
				{
					cout << "\n����������� �����.";
				}
				cout << "\n������ ���������� ������ �� ������? (d/n): ";
				cin >> o;
			}
		}
		else if (ws == "queue")
		{
			char t;
			cout << "\n������ ������ ������ ��������? (d/n): ";
			cin >> t;
			int z = N;
			if (t == 'd')
			{
				cout << "\n������ ��������: ";
				cin >> z;
			}
			queue auc(z);
			while (o != 'n')
			{
				cout << "\n������ ��������� ��� � ������� ��� ������� ��������� ��� �� ��������? (v/p): ";
				cin >> o;
				if (o == 'v')
				{
					if (auc.check(o))
					{
						cout << "\n����� ������� �� ������ ��������� � �������?: ";
						cin.get();
						getline(cin, ws);
						auc.push(ws);
					};
				}
				else if (o == 'p')
				{
					if (auc.check(o))
					{
						auc.pop();
					};
				}
				else
				{
					cout << "\n����������� �����.";
				}
				cout << "\n������ ���������� ������ � ��������? (d/n): ";
				cin >> o;
			}
		}
		else
		{
			cout << "\n����������� �����.";
		}
		cout << "\n������ ������ ����� ���� ������ � ����� �� ��������� ������������? (d/n): ";
		cin >> o;
	}
}