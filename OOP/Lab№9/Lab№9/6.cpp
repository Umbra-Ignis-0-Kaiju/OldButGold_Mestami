#include <iostream>
using namespace std;

int compwcs(const wchar_t*, const wchar_t*);

int main()
{
	setlocale(LC_ALL, "Russian");
	const wchar_t* str1, * str2;
	str1 = "Сидоров"; str2 = "Петровский";
	cout << L'"' << str1 << "\", \"" << str2 << "\", результат: " << compwcs(str1, str2) << endl;

	str1 = "Петровский"; str2 = "Сидоров";
	cout << L'"' << str1 << "\", \"" << str2 << "\", результат: " << compwcs(str1, str2) << endl;

	str1 = "Петров"; str2 = "Петров";
	cout << L'"' << str1 << "\", \"" << str2 << "\", результат: " << compwcs(str1, str2) << endl;

	str1 = "Петров"; str2 = "Петровский";
	cout << L'"' << str1 << "\", \"" << str2 << "\", результат: " << compwcs(str1, str2) << endl;

	str1 = "Петровcкий"; str2 = "Петров";
	cout << L'"' << str1 << "\", \"" << str2 << "\", результат: " << compwcs(str1, str2) << endl;


	str1 = "сидоров"; str2 = "Яковлев";
	cout << L'"' << str1 << "\", \"" << str2 << "\", результат: " << compwcs(str1, str2) << endl;


	str1 = "Petrov"; str2 = "Архангельский";
	cout << L'"' << str1 << "\", \"" << str2 << "\", результат: " << compwcs(str1, str2) << endl;

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