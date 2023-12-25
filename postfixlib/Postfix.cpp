#include "Postfix.h"

TPostfix::TPostfix(string inf)
{
	infix = inf; // Инфиксная запись

	TStack<char> stack(100); // Стек для операций
	char oper; // Операция из стека
	string n = ""; // По мере выполнения, здесь собирается число
	for (char chr : infix) {
		// Если (, кладём в любом случае в стек
		if (chr == '(') {
			if (n != "") { // Если в n что-то, есть это что-то будет отправлено в постфикс
				postfix += n + " ";
				n = "";
			}

			stack.Push(chr);
		}
		// Если ), то пока в стеке не (, достаём операторы
		else if (chr == ')') {
			if (n != "") {
				postfix += n + " ";
				n = "";
			}

			oper = stack.Get();
			while (oper != '(') {
				postfix += oper;
				postfix += " ";
				oper = stack.Get();
			}
		}
		// Встретился оператор +,-,*,/
		else if (chr == '+' || chr == '-' || chr == '*' || chr == '/') {
			if (n != "") {
				postfix += n + " ";
				n = "";
			}
			// Пока приритет операции в стеке больше или равен, чем chr, достаём операцию
			while (!stack.IsEmpty()) {
				oper = stack.Get();
				if (GetPrioritet(chr) <= GetPrioritet(oper)) {
					postfix += oper;
					postfix += " ";
				}
				else {
					stack.Push(oper);
					break;
				}
			}
			stack.Push(chr);
		}
		else { // Встретилась часть числа (цифра или точка)
			n += chr;
		}
	}

	if (n != "") {
		postfix += n + " ";
		n = "";
	}

	// Достаём все оставшиеся операторы
	while (!stack.IsEmpty()) {
		oper = stack.Get();
		postfix += oper;
		postfix += " ";
	}
}

double TPostfix::Calc() { // Вычислить выражение в постфиксной форме
	double left, right; // Левый и правый операнды
	TStack<double> stack(100); // Стек для чисел
	string n = ""; // По мере выполнения, здесь собирается число
	for (char chr : postfix)
	{	
		if (chr == ' ') { // Пропуск пробелов
			if (n != "") { // Если здесь что-то есть, что-то приводится к double и отправлется в стек
				stack.Push(stod(n)); // stod - string в double
				n = "";
			}
			continue;
		}
		// Встретился оператор +,-,*,/
		if (chr == '+' || chr == '-' || chr == '*' || chr == '/') {
			double res = 0; // Результат операции

			right = stack.Get();
			left = stack.Get();

			if (chr == '+') res = left + right;
			if (chr == '-') res = left - right;
			if (chr == '*') res = left * right;
			if (chr == '/') {
				if (right == 0) // Деление на ноль
					throw - 1;
				res = left / right;
			}
			stack.Push(res);
		}
		else { // Встретилась часть числа (цифра или точка)
			n += chr;
		}
	}
	return stack.TopView(); // В стеке остался один элемент - результат вычисления
}

int TPostfix::GetPrioritet(char op) { // Пролучить приоритет операции
	// Умножение и деление имеют наивысший приоритет (например, он равен 3)
	if (op == '/')
		return 3;
	if (op == '*')
		return 3;
	// Сложение и вычитание имеют меньший приоритет (например, 2)
	if (op == '+')
		return 2;
	if (op == '-')
		return 2;
	// Наименьший приоритет у открывающейся скобки(1)
	if (op == '(')
		return 1;
	if (op == ')')
		return 1;
	return 0;
}

