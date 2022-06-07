#include<iostream>
#include<vector>
#include<assert.h>
#include<algorithm>
#include<string>
#include<clocale>
#include<iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	setiosflags(ios::left);
	cout << "Фамилия" << setw(9) << "Имя" << setw(15) << "Адрес" << setw(15) << "Город";
	cout << "\n\n" << "Петров" << setw(13) << "Василий" << setw(16) << "Кленовая 16" << setw(20) << "Санкт-Петербург";
	cout << endl << "Иванов" << setw(12) << "Сергей" << setw(17) << "Осиновая 3" << setw(12) << "Находка";
	cout << endl << "Сидоров" << setw(10) << "Иван" << setw(19) << "Берёзовая 21" << setw(15) << "Калининград";
}