//ќтсортировать элементы квадратной вещественной матрицы размерности n, сто€щие на побочной диагонали, применив сортировку бинарным включением.
#include <iostream>

using namespace  std;

void sort(int arr[], int size)
{
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		while (j>=0 && arr[j] > arr[j + 1])
		{
			swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	const int n = 5;
	const int m = 5;
	int a[n][m];
	int b[n];
	cout << "¬ведите матрицу" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		b[i] = a[i][n - i - 1];
	}

	cout << '\n';
	cout << "Ёлементы побочной диагонали:" << endl;

	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}

	cout << '\n';
	sort(b, 5);
	cout << "–езультат сортировки:" << endl;
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}


	return 0;
}