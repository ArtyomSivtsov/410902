/*
2. ������������ ���������,
� ������� ������� ����� ���������� ���������� ���������� ������ ������� � ������������ �������������� �����.
������� ���� ������ (����� ��������� � �������).
*/
#include <iostream>
#include <queue>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	queue <int> q;
	int a = 1;
	int i = 0;
	int max = 500;
	try
	{
		while (true) {
			q.push(a);
			i++;
			if (i == max) throw "Error";
		}
	}

	catch (...)
	{
		cout << "������������ ������ �������: " << i << " ���������" << endl;
	}

	return 0;
}