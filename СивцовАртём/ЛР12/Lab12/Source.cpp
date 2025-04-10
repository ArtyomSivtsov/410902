/*
2. Разработайте программу,
с помощью которой можно определить наибольший допустимый размер очереди с вещественным информационным полем.
Найдите этот размер (число элементов в очереди).
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
		cout << "Максимальный размер очереди: " << i << " элементов" << endl;
	}

	return 0;
}