//27.	�������� ��������� � ����������� ��������, ����������� ������������ ���� ��������� ������������ ����� n
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
	cout << "������� ����� n:" << endl;
	cin >> n;

	cout << "������������ ���� ��������� ������������ ����� n �����:" << MULTIPLICATION(n) << endl;
	return 0;
}