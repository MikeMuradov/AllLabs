#include <iostream>
#include "Postfix.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string input;
	cout << "Введите выражение (дробная часть числа отделяется запятой): ";  // Запятая из-за русской локалки
	cin >> input;
	TPostfix expression(input);
	cout << "Префиксный вид: " << expression.GetPostfix() << endl
		<< "Посчитано: " << expression.Calc() << endl;
	
}
