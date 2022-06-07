#include <iostream>
#include <string> 
using namespace std;

class person
{
protected:
	string name;
	float salary;
public:
	void setData()
	{
		cout << " введите имя: "; cin >> name;
		cout << " введите зарплату: "; wcin >> salary;
	}
	void printData() const
	{
		cout << endl << " имя: " << name;
		cout << endl << " зарплата: " << salary;
	}
	float getSalary() const
	{
		return salary;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	void salsort(person**, int);
	person* persPtr[100];
	int n = 0;
	wchar_t choice;

	do
	{
		persPtr[n] = new person;
		cout << "Субъект " << n << endl;
		persPtr[n]->setData();
		n++;
		cout << "Продолжаем ввод (1/0)? ";
		wcin >> choice;
	} while (choice == L'1');

	cout << "\nНеотсортированный список:";
	for (int j = 0; j < n; j++)
	{
		cout << endl << "Субъект " << j;
		(*(persPtr + j))->printData();
	}
	cout << endl;

	salsort(persPtr, n);

	cout << "\nОтсортированный список:";
	for (int j = 0; j < n; j++)
	{
		cout << endl << "Субъект " << j;
		(*(persPtr + j))->printData();
	}
	cout << endl;

	return 0;
}
void salsort(person** pp, int n)
{
	for (int j = 0; j < n - 1; j++)
		for (int k = j + 1; k < n; k++)
			if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary())
			{
				person* tempptr = *(pp + j);
				*(pp + j) = *(pp + k);
				*(pp + k) = tempptr;
			}
}
