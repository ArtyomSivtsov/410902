/*
��������� ���������� ���-������� ����������� �� ����� ���������������� �++ ���������, ������� ������ ��������� ��������� �������:
-	��������� ���-�������;
-	��������� �������� � ���-�������;
-	������������� ���-�������;
-	������ �������� � ���-�������;
-	������� �������� �� ���-�������.
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct hashTable {
	list<string>* table = nullptr;
	int capacity;
	hashTable() {}
	hashTable(int size) : capacity(size) {
		table = new list<string>[capacity];
	}

	int hashFunction(string key) {
		int hash = 0;
		for (char c : key) {
			hash += static_cast<int>(c);
		}
		hash = hash * hash;
		hash = hash / 100;
		hash = deleteFirstTwoNums(hash);

		while (hash > 2000) {
			hash = hash % 2000;
		}

		return hash % capacity;
	}

	void insert(string key) {
		int index = hashFunction(key);
		table[index].push_back(key);
	}

	void display() {
		for (int i = 0; i < capacity; i++) {
			cout << "Index " << i << ": ";
			for (string& value : table[i]) {
				cout << value << " ";
			}
			cout << endl;
		}
	}

	void search(string key) {
		int index = hashFunction(key);
		for (string value : table[index]) {
			if (value == key) {
				cout << "������� " << key << " ������ �� ������� " << index << endl;
			}
		}
	}

	void remove(string key) {
		int index = hashFunction(key);
		table[index].remove(key);
	}

	int deleteFirstTwoNums(int a) {
		int p = 1;
		while (a / p > 99) p *= 10;
		int y = a % p;
		return y;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	int cmd;
	hashTable* container = nullptr;
	string key;
	do {
		cout << "1 - ������� ���-�������" << endl;
		cout << "2 - �������� �������" << endl;
		cout << "3 - ����������� ���-�������" << endl;
		cout << "4 - ����� �������" << endl;
		cout << "5 - ������� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "������� �������: " << endl;
		cin >> cmd;
		switch (cmd) {
		case 0: {

			break;
		}
		case 1: {
			cout << "������� ������ �������: " << endl;
			int size;
			cin >> size;
			container = new hashTable(size);
			cout << "���-������� ������� �������!" << endl;
			break;
		}
		case 2: {
			cout << "������� ������: " << endl;
			cin.ignore();
			getline(cin, key);
			container->insert(key);
			break;
		}
		case 3: {
			container->display();
			break;
		}
		case 4: {
			cout << "������� ������: " << endl;
			cin.ignore();
			getline(cin, key);
			container->search(key);
			break;
		}
		case 5: {
			cout << "������� ������: " << endl;
			cin.ignore();
			getline(cin, key);
			container->remove(key);
			break;
		}
		default: {
			cout << "����������� �������! ���������� �����." << endl;
			break;
		}
		}
	} while (cmd != 0);
	delete[] container;
	return 0;
}