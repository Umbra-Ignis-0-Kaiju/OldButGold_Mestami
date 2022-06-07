#include <iostream>
#include <fstream>
using namespace std;

FILE* fp;
void read(int** mas, int size)
{
	fopen_s(&fp, "Grafff.txt", "r");
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

class Stack
{
private:
	item* top;
	int count;
	int k;
	bool* visited;
	int* road;
	int* VON_PUNKT;
public:
	Stack(int N)
	{
		top = NULL;
		count = 0;
		visited = new bool[N];
		road = new int[N];
		VON_PUNKT = new int[N];
	}
	void push_lifo(int a)
	{
		item* temp = new item;
		temp->data = a;
		temp->next = top;
		top = temp;
		count++;
	}
	bool empty()
	{
		bool temp;
		if (top == NULL)
			temp = true;
		else
			temp = false;
		return temp;
	}
	void del()
	{
		item* place = top;
		if (place->next != NULL)
		{
			place->next->prev = NULL;
			top = place->next;
		}
		else top = NULL;
		delete place;
	}
	int pop_lifo()
	{
		int temp = top->data;
		del();
		return temp;
	}
	void out(int start, int end)
	{
		int temp = end;
		int count = 0;
		do
		{
			count++;
			temp = road[temp];
		} while (temp != road[start]);
		k = count;
		int* reverse = new int[count];
		int i = 0;
		reverse[i] = end;
		i++;
		do
		{
			reverse[i] = road[end];
			i++;
			end = road[end];
		} while (end != start);
		i--;
		cout << "Маршрут: ";
		while (i >= 0)
		{
			cout << reverse[i] + 1 << " ";
			i--;
		}
		cout << "\n";
		for (int i = 0; i < k; i++)
		{
			VON_PUNKT[i] = reverse[i];
		}
	}
	void search_in_depth(int** arr, int N)
	{
		int start, end;
		for (int i = 0; i < N; i++)
		{
			visited[i] = 0;
		}
		cout << "Из какой вершины начинается путь? ";
		cin >> start;
		start--;
		push_lifo(start);
		cout << "До какой точки рассчитать маршрут? ";
		cin >> end;
		end--;
		visited[start] = true;
		road[start] = -1;
		while (!empty())
		{
			int unit = pop_lifo();
			for (int i = N - 1; i >= 0; i--)
			{
				if ((visited[i] == 0) && (arr[unit][i] == 1))
				{
					push_lifo(i);
					road[i] = unit;
					visited[unit] = true;
				}
			}
		}
		out(start, end);
	}
	void write_in_file(int** arr, int N)
	{
		ofstream file("C:\\Users\\Kinjen\\source\\repos\\OSA\\OSA\\L8-1W.txt", ofstream::app);
		file << "Матрица смежности:" << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				file << arr[i][j] << " ";
			}
			file << endl;
		}
		file << "Маршрут: " << endl;
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

class rec {

private:
	bool* visited;
	int* road;
	int* VON_PUNKT;
	int k;
public:
	rec(int N)
	{
		visited = new bool[N];
		road = new int[N];
		VON_PUNKT = new int[N];
	}
	void func(int point, int** arr, int N)
	{
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && arr[point][i] == 1)
			{
				road[i] = point;
				visited[i] = true;
				func(i, arr, N);
			}
		}
	}
	void search(int** arr, int N)
	{
		int start;
		for (int i = 0; i < N; i++)
		{
			visited[i] = false;
		}
		cout << endl;
		cout << "\nВведите начальную точку: ";
		cin >> start;
		start--;
		visited[start] = true;
		road[start] = -1;
		int end;
		cout << "До какой точки рассчитать маршрут: ";
		cin >> end;
		end--;
			func(start, arr, N);
		int dne = end;
		int count = 0;
		do
		{
			count++;
			dne = road[dne];
		} while (dne != road[start]);
		k = count;
		int* reverse = new int[count];
		int i = 0;
		reverse[i] = end;
		i++;
		do
		{
			reverse[i] = road[end];
			i++;
			end = road[end];
		} while (end != start);
		i--;
		cout << "Маршрут: ";
		while (i >= 0)
		{
			cout << reverse[i] + 1 << " ";
			i--;
		}
		cout << '\n';
		for (int i = 0; i < k; i++)
		{
			VON_PUNKT[i] = reverse[i];
		}
	}
	void write_in_file(int** arr, int N)
	{
		ofstream file("C:\\Users\\Kinjen\\source\\repos\\OSA\\OSA\\L8-2W.txt", ofstream::app);
		file << "\nМаршрут: " << endl;
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
		file.close();
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int size = 0;
	fopen_s(&fp, "Grafff.txt", "r");
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
	Stack st(size);
	rec r(size);
	st.search_in_depth(mas, size);
	r.search(mas, size);
	st.write_in_file(mas, size);
	r.write_in_file(mas, size);
	return 0;
}