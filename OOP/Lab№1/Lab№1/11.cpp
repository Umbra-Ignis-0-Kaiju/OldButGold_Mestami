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
	cout << "�������" << setw(9) << "���" << setw(15) << "�����" << setw(15) << "�����";
	cout << "\n\n" << "������" << setw(13) << "�������" << setw(16) << "�������� 16" << setw(20) << "�����-���������";
	cout << endl << "������" << setw(12) << "������" << setw(17) << "�������� 3" << setw(12) << "�������";
	cout << endl << "�������" << setw(10) << "����" << setw(19) << "�������� 21" << setw(15) << "�����������";
}