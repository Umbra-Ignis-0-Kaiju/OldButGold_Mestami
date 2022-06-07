#include <iostream>
#include <fstream>
using namespace std;

FILE* fp;
void read(int** mas, int size)
{
	fopen_s(&fp, "Graff.txt", "r");
	if (fp == NULL)
		cout << "Cannot open file";
	else
	{
		fscanf_s(fp, "%d", &size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				fscanf_s(fp, "%d", &mas[i][j]);
	}
	fclose(fp);
}


struct item 
{
	int data;
	item* next;
	item* prev;
};

class queue 
{
private:
	item* first;
	item* last;
	int count;
	int* VON_PUNKT;
	int k;
public:
	queue(int N) 
	{
		last = NULL;
		first = NULL;
		count = 0;
		VON_PUNKT = new int[N];
	}

	void add(int a) 
	{
		item* newitem = new item;
		newitem->data = a;
		if (first == NULL) 
		{
			first = newitem;
		}

		newitem->next = NULL;
		newitem->prev = last;

		if (last != NULL) 
		{
			last->next = newitem;
		}
		last = newitem;
		count++;
	}

	void del_first() 
	{
		item* place = first;

		if (place != last) 
		{
			place->next->prev = NULL;
			first = place->next;
		}
		else 
		{
			first = NULL;
			last = NULL;
		}
		delete place;
		count--;
	}

	bool empty() 
	{
		bool empt;
		if (first == NULL) 
		{
			empt = true;
		}
		else empt = false;
		return empt;
	}

	int first_data() 
	{
		return first->data;
	}

	void search_in_width(int** arr, int N) 
	{
		bool* visited = new bool[N];
		int* ways = new int[N];
		int start = 0;
		for (int i = 0; i < N; i++)
		{
			visited[i] = 0;
		}
		cout << "Из какой вершины начинается путь? ";
		cin >> start;
		start--;
		add(start);
		visited[start] = 1;
		ways[start] = -1;
		while (!empty())
		{
			int unit = first_data();
			del_first();
			for (int i = 0; i < N; i++)
			{
				if ((visited[i] == 0) && (arr[unit][i] == 1))
				{
					add(i);
					ways[i] = unit;
					visited[i] = 1;
				}
			}
		}
		int end;
		cout << "До какой точки рассчитать маршрут? ";
		cin >> end;
		end--;
		int dne = end;
		int count = 0;
		do
		{
			count++;
			dne = ways[dne];
		} while (dne != ways[start]);
		k = count;
		int* rev = new int[count];
		int i = 0;
		rev[i] = end;
		i++;
		do
		{
			rev[i] = ways[end];
			i++;
			end = ways[end];
		} while (end != start);
		cout << "Путь: ";
		i--;
		while (i >= 0)
		{
			if (i != 0)
				cout << rev[i] + 1 << " -> ";
			else
				cout << rev[i] + 1;
			i--;
		}
		cout << '\n';
		for (int i = 0; i < k; i++)
		{
			VON_PUNKT[i] = rev[i];
		}
		write_in_file(arr, N);
	}

	void write_in_file(int** arr, int N)
	{
		ofstream file("C:\\Users\\Kinjen\\source\\repos\\OSA\\OSA\\L7W.txt", ofstream::app);
		file << "Матрица смежности:" << endl;
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				file << arr[i][j] << " ";
			}
			file << endl;
		}
		file << "Путь: " << endl;
		for (int i = k - 1; i >= 0; i--) 
		{
			if (i != 0)
				file << VON_PUNKT[i] + 1 << " -> ";
			else
				file << VON_PUNKT[i] + 1;

		}
		file << endl << endl;
		file.close();
	}
};

int main() 
{
	setlocale(LC_ALL, "Rus");
	int size = 0;
	fopen_s(&fp, "Graff.txt", "r");
	if (fp == NULL)
		cout << "Cannot open file";
	else
		fscanf_s(fp, "%d", &size);
	fclose(fp);
	int** mas = new  int* [size];
	for (int i = 0; i < size; i++)
		mas[i] = new int[size];
	read(mas, size);
	cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}

	queue Q(size);
	Q.search_in_width(mas, size);
}