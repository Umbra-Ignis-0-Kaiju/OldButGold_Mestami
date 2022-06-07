#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <locale.h>
#include <iterator>
#include <cstdlib>
#include <vector>
using namespace std;

struct leaf
{
	int data;
	struct leaf* left;
	struct leaf* right;
};

struct tree
{
	struct leaf* root;
	int count;
};

FILE* fp;
typedef struct tree Tree;
typedef struct leaf Leaf;
typedef vector<Leaf> Bag;

Tree* create()
{
	Tree* nt = (Tree*)malloc(sizeof * nt);
	if (nt == nullptr)
		return nullptr;
	nt->root = nullptr;
	nt->count = 0;
	return nt;
}

bool search(Tree* tree, int item)
{
	const Leaf* leaf;
	if (tree == nullptr)
	{
		return 0;
	}
	leaf = tree->root;
	while (1)
	{
		if (leaf == nullptr)
			return false;
		else if (item == leaf->data)
			return true;
		else if (item > leaf->data)
			leaf = leaf->right;
		else
			leaf = leaf->left;
	}
}

int insert(Tree* tree, int item)
{
	Leaf* leaf, ** lie;
	if (tree == nullptr)
	{
		return 0;
	}
	lie = &tree->root;
	leaf = tree->root;
	while (1)
	{
		if (leaf == nullptr)
		{
			*lie = (Leaf*)malloc(sizeof * leaf);
			leaf = *lie;
			if (leaf != nullptr)
			{
				leaf->data = item;
				leaf->left = leaf->right = nullptr;
				tree->count++;
				return 1;
			}
			else
				return 0;
		}
		else if (item == leaf->data)
			return 2;
		else if (item > leaf->data)
		{
			lie = &leaf->right;
			leaf = leaf->right;
		}
		else
		{
			lie = &leaf->left;
			leaf = leaf->left;
		}
	}
}


Tree* read()
{
	fopen_s(&fp, "Tree.dat", "rb");
	Tree* back = create();
	int wrs;
	fread(&wrs, sizeof(int), 1, fp);
	if (wrs != 0)
	{
		Leaf q;
		for (int i = 0; i < wrs; i++)
		{
			fread(&q, sizeof(Leaf), 1, fp);
			insert(back, q.data);
		}
	}
	fclose(fp);
	return back;
}

void write(Tree* tree)
{
	Bag wr;
	if (tree->root == nullptr)
		return;
	wr.push_back(*tree->root);
	for (int i = 0; i < wr.size(); i++)
	{
		if (wr[i].left != nullptr)
			wr.push_back(*wr[i].left);
		if (wr[i].right != nullptr)
			wr.push_back(*wr[i].right);
	}
	fopen_s(&fp, "Tree.dat", "wb");
	int wrs = wr.size();
	fwrite(&wrs, sizeof(int), 1, fp);
	for (int i = 0; i < wrs; i++)
		fwrite(&wr[i], sizeof(Leaf), 1, fp);
	fclose(fp);
}

void out(Tree* tree)
{
	Bag wr;
	if (tree == nullptr)
	{
		cout << "А нет элементов!";
		return;
	}
	if (tree->root == nullptr)
	{
		cout << "А нет элементов!";
		return;
	}
	wr.push_back(*tree->root);
	for (int i = 0; i < wr.size(); i++)
	{
		if (wr[i].left != nullptr)
			wr.push_back(*wr[i].left);
		if (wr[i].right != nullptr)
			wr.push_back(*wr[i].right);
	}
	for (int i = 0; i < tree->count; i++)
		cout << wr[i].data << " ";
}

Tree* del(Tree* tree, int item)
{
	Tree* back = create();
	if (tree == nullptr)
	{
		return back;
	}
	if (tree->root == nullptr)
	{
		return back;
	}
	Bag wr;
	wr.push_back(*tree->root);
	for (int i = 0; i < wr.size(); i++)
	{
		if (wr[i].left != nullptr)
			wr.push_back(*wr[i].left);
		if (wr[i].right != nullptr)
			wr.push_back(*wr[i].right);
	}
	auto iter = wr.cbegin();
	for (int i = 0; i < wr.size(); i++)
		if (wr[i].data == item)
			wr.erase(iter + i);
	for (int i = 0; i < wr.size(); i++)
		insert(back, wr[i].data);
	return back;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	int item;
	Tree* tree = nullptr;
	char end = 'y';
	while (end == 'y')
	{
		cout << "\nКакой функцией хотите воспользоваться?:"
			<< "\n1 - (Пере)Создать бинарное дерево"
			<< "\n2 - Проверка существования элемента со значением n"
			<< "\n3 - Добавление элемента со значением n"
			<< "\n4 - Сохранение дерева в файл"
			<< "\n5 - Чтение дерева из файла"
			<< "\n6 - Вывод дерева (от корня)"
			<< "\n7 - Удаление элемента со значением\n";
		cin >> item;
		switch (item)
		{
		case 1:
			tree = create();
			break;
		case 2:
			cout << "\nВведите значение искомого элемента n = ";
			cin >> item;
			if (search(tree, item))
				cout << "\nЭлемент найден!";
			else
				cout << "\nЭлемент не найден(";
			break;
		case 3:
			cout << "\nВведите значение вводимого элемента n = ";
			cin >> item;
			item = insert(tree, item);
			if (item == 2)
				cout << "\nЭлемент уже был добавлен ранее";
			else if (item == 1)
				cout << "\nЭлемент успешно добавлен";
			else
				cout << "\nЭлемент не может быть добавлен";
			break;
		case 4:
			write(tree);
			cout << "\nВыполнено!";
			break;
		case 5:
			tree = read();
			cout << "\nВыполнено!";
			break;
		case 6:
			cout << "\nЭлементы бинарного дерева: ";
			out(tree);
			break;
		case 7:
			cout << "\nЭлемент который хотите удалить: ";
			cin >> item;
			tree = del(tree, item);
			cout << endl << "Функция исполнена.";
			break;
		}

		cout << "\n\n}{отите продолжить работу с программой? (y/n)   ";
		cin >> end;
	}
}