#include <fstream>
#include <iostream>
using namespace std;

const int N = 8; // ���������� ������ � �����

int arr[N][N] = // ������ (�������) ���������

{ {0,1,1,0,0,1,1,1},

{1,0,0,0,0,0,0,1},

{1,0,0,0,0,0,0,1},

{0,0,0,0,1,1,0,0},

{0,0,0,1,0,1,1,1},

{1,0,0,1,1,0,0,0},

{1,0,0,0,1,0,0,0},

{1,1,1,0,1,0,0,0} };

bool visited[N]; // ������ ���������� ������

int ways[N]; // ������ ������������ ������ (VON_PUNKT)

struct item { // ��������� ��������

	int data;

	item* next;

	item* prev;

};

class queue {

private:

	item* first; // ����� ������� �������� � ������

	item* last; // ����� ���������� �������� � ������

	int count; // ���������� ��������� � ������

	int VON_PUNKT[N];

	int k;

public:

	queue() {

		last = NULL;

		first = NULL;

		count = 0;

	}

	void add(int a) { // ���������� �������� � ����� ������ (push_fifo)

		item* newitem = new item;

		newitem->data = a;

		if (first == NULL) {

			first = newitem;

		}

		newitem->next = NULL;

		newitem->prev = last;

		if (last != NULL) {

			last->next = newitem;

		}

		last = newitem;

		count++;

	}

	void del_first() { // �������� �������� �� ������ ������� (pop_fifo)

		item* place = first;

		if (place != last) { // ���� ������� ������, �� �� ���������

			place->next->prev = NULL;

			first = place->next;

		}

		else { // ���� ������� ������ � ���������

			first = NULL;

			last = NULL;

		}

		delete place;

		count--;

	}

	bool empty() { // ���������� true ���� ������� ������ � false ���� ���

		bool empt;

		if (first == NULL) {

			empt = true;

		}

		else empt = false;

		return empt;

	}

	int first_data() { //���������� �������� �� ������ �������

		return first->data;

	}

	void search_in_width() {

		int start = 0;

		for (int i = 0; i < N; i++) {

			visited[i] = 0;

		}

		cout << "�� ����� ������� ���������� ����? ";

		cin >> start;

		add(start); // ������� � ������� ��������� �������

		visited[start] = 1; // �������� �������, ��� ����������

		ways[start] = -1; // ���������� ������ �������� �� ��������� ������� � ��������

		while (!empty()) { // ���� ������� �� �����

			int unit = first_data(); // ��������� 1�� ������� �� �������

			del_first(); // ������� 1�� ������� �� �������

			for (int i = 0; i < N; i++) { // ��� �� ���� �������� �����

				if ((visited[i] == 0) && (arr[unit][i] == 1)) { // ���� ������� �� �������� � ������� �����

					add(i); // ��������� � ������� ������� i

					ways[i] = unit; // ����������, �� ����� ������� �� ������

					visited[i] = 1; // �������� ������� i, ��� ����������

				}

			}

		}

		int end;

		cout << "�� ����� ����� ���������� �������? ";

		cin >> end; // ���������� �������� �������

		int dne = end; // ���������� �������� �������

		int count = 0; // ������� �������

		do { // ������, ���� �� ����� � ������ ��������

			count++; // ����������� ������� �� 1

			dne = ways[dne]; // ���������� �������� ������� �� ��������

		} while (dne != ways[start]);

		k = count;

		int* rev = new int[count];

		int i = 0;

		rev[i] = end; // � ������ ������� ������ �������� �������

		i++;

		do { // ������, ���� �������� ������� �� ����� ����� ���������

			rev[i] = ways[end]; // ���������� �������

			i++;

			end = ways[end]; // ���������� �������� ������� �� ����������

		} while (end != start);

		cout << "����: ";

		while (i >= 0) {

			cout << rev[i] << " "; // ������� ����������� ����

			i--;

		}

	cout << '\n';

	for (int i = 0; i < k; i++) {

		VON_PUNKT[i] = rev[i];

	}

	}

	void write_in_file() {

		ofstream file("c:\\search", ofstream::app);

		file << "������� ���������:" << endl;

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {

				file << arr[i][j] << " ";

			}

			file << endl;

		}

		file << "�������: " << endl;

		for (int i = k - 1; i >= 0; i--) {

			file << VON_PUNKT[i] << " ";

		}

		file.close();

	}

};

int main() {

	setlocale(LC_ALL, "Russian");

	queue Que;

	Que.search_in_width();

	Que.write_in_file();

	return 0;

}