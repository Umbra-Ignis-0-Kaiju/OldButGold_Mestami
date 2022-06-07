#include <iostream>
using namespace std;

int compwcs(const wchar_t*, const wchar_t*);

int main()
{
	setlocale(LC_ALL, "Russian");
	const wchar_t* str1, * str2;
	str1 = "�������"; str2 = "����������";
	cout << L'"' << str1 << "\", \"" << str2 << "\", ���������: " << compwcs(str1, str2) << endl;

	str1 = "����������"; str2 = "�������";
	cout << L'"' << str1 << "\", \"" << str2 << "\", ���������: " << compwcs(str1, str2) << endl;

	str1 = "������"; str2 = "������";
	cout << L'"' << str1 << "\", \"" << str2 << "\", ���������: " << compwcs(str1, str2) << endl;

	str1 = "������"; str2 = "����������";
	cout << L'"' << str1 << "\", \"" << str2 << "\", ���������: " << compwcs(str1, str2) << endl;

	str1 = "������c���"; str2 = "������";
	cout << L'"' << str1 << "\", \"" << str2 << "\", ���������: " << compwcs(str1, str2) << endl;


	str1 = "�������"; str2 = "�������";
	cout << L'"' << str1 << "\", \"" << str2 << "\", ���������: " << compwcs(str1, str2) << endl;


	str1 = "Petrov"; str2 = "�������������";
	cout << L'"' << str1 << "\", \"" << str2 << "\", ���������: " << compwcs(str1, str2) << endl;

	return 0;
}

int compwcs(const wchar_t* s1, const wchar_t* s2)
{
	while (*s1 && *s2)
	{
		if (*s1 > *s2)
			return 1;
		else if (*s1 < *s2)
			return -1;
		s1++; s2++;
	}

	if (!*s1 && !*s2)
		return 0;
	else if (!*s1)
		return -1;
	else
		return 1;
}