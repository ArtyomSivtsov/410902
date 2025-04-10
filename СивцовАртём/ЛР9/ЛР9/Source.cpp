//27.	Написать программу с рекурсивной функцией, вычисляющей произведение цифр заданного натурального числа n
#include <iostream>
#include <cmath>

using namespace std;

int MULTIPLICATION(int a) {
	if (a == 0)
		return 1;

	return (a % 10) * MULTIPLICATION(a / 10);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите число n:" << endl;
	cin >> n;

	cout << "Произведение цифр заданного натурального числа n равно:" << MULTIPLICATION(n) << endl;
	return 0;
}