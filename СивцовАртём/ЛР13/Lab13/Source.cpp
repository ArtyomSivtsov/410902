/*
2. Описать функции, которая вычисляет значение заданного выражения.
Входные данные.В первой строке содержит обратную польскую запись арифметического выражения.Все операнды целые положительные числа.
Выходные данные.Вывести результат вычисления ОПЗ.
Технические требования.Используются знаки операций : +, -, *, / .
*/
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(string c) {
	return(c == "+" || c == "-" || c == "*" || c == "/");
}

double evaluatePostfix(string postfix) {
	stack <int> operands;
	string c;
	istringstream iss(postfix);
	while (iss>>c) {
		if (isOperator(c)) {
			int operand2 = operands.top();
			operands.pop();
			int operand1 = operands.top();
			operands.pop();
			if (c == "+") operands.push(operand1 + operand2);
			if (c == "-") operands.push(operand1 - operand2);
			if (c == "*") operands.push(operand1 * operand2);
			if (c == "/") operands.push(operand1 / operand2);
			if (c == " ") continue;
		}
		else{
			int n = stoi(c);
			operands.push(n);
		}
	}
	return operands.top();
}

int main() {
	setlocale(LC_ALL, "Russian");
	string exprPol;
	double res;
	cout << "Введите вашу ОПЗ:" << endl;
	getline(cin, exprPol);
	res = evaluatePostfix(exprPol);
	cout << "Результат вычисления: " << res << endl;
	return 0;
}
