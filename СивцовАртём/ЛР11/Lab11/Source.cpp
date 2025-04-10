/*
6.Загрузить данные из исходного файла в двунаправленный список. 
Сохранить двунаправленный список в контрольный файл. 
Упорядочить исходные данные по  возрастанию.  
Перевести  данные  из  двунаправленного  списка  в  два кольцевых списка (один для четных чисел, другой для нечетных). 
Сохранить два кольцевых списка в два файла.
*/

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int _val) : val(_val), next(nullptr) {}
};

struct listloop {
	Node* first;
	Node* last;

	listloop() : first(nullptr), last(nullptr) {}

	bool is_empty() {
		return first == nullptr;
	}

	void push_back(int _val) {
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	Node* operator[] (const int index) {
		if (is_empty()) return nullptr;
		Node* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}


};

void sort(int arr[], int size)
{
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1])
		{
			swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	list<int> lst;
	const int size = 10;
	int b[size];
	fstream exod("exodus.txt");
	if (exod.is_open()) {
		int num;
		while (exod >> num) {
			lst.push_back(num);
		}
		exod.close();
	}
	else cout << "Ошибка!" << endl;

	
	cout << "Данные из исходного файла:" << endl;
	for (int num : lst) {
		cout << num << ' ';
	}

	cout << '\n';

	ofstream cont("control.txt");
	if (cont.is_open()) {
		for (int num : lst) {
			cont << num << ' ';
		}
		cont.close();
	}
	else cout << "Ошибка!" << endl;

	ifstream contr("control.txt");
	if (contr.is_open()) {
		int i = 0;
		while (contr >> b[i]) {
			i++;
		}
		contr.close();
	}
	else cout << "Ошибка!" << endl;
	
	sort(b, size);

	cout << "Сортировка по возрастанию:" << endl;
	for (int i = 0; i < size; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';
	
	listloop even;
	listloop odd;

	ofstream oddfile("oddfile.txt");
	ofstream evenfile("evenfile.txt");
	for (int i = 0; i < size; i++) {
		if (b[i] % 2 == 0) {
			if (oddfile.is_open()) {
				oddfile << b[i] << ' ';
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
		}
		else {

			
			if (evenfile.is_open()) {
				evenfile << b[i] << ' ';
			}
			else
			{
				cout << "Ошибка!" << endl;
			}
		}
	}
	oddfile.close();
	evenfile.close();
	
	for (int i = 0; i < size; i++) {
		if (b[i] % 2 == 0) {
			odd.push_back(b[i]);
		}
		else {
			even.push_back(b[i]);
		}
	}

	
	cout << "Кольцевой список нечётных\n";
	even.print();
	cout << "Кольцевой список чётных\n";
	odd.print();

	return 0;
}