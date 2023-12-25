#include <iostream>
#include "MyStack.h"
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");

	int choice, size;
	double tmp;

	cout << "Введите размер стека: ";
	cin >> size;
	TStack<double> stack(size);
	while (true) {
		cout << "Меню:\n"
			<< "1. Добавить в стек сверху\n"
			<< "2. Удалить верхний элемент\n"
			<< "3. Посмотреть верхний элемент\n"
			<< "4. Вывести количество элементов\n"
			<< "5. Вывести размер стека\n"
			<< "Выберите операцию: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			cout << "Введите новый элемент стека (double): ";
			cin >> tmp;
			stack.Push(tmp);
			break;
		case 2:
			cout << "Удаленный элемент: " << stack.Get() << endl;
			break;
		case 3:
			cout << "Верхний элемент стека: " << stack.TopView() << endl;
			break;
		case 4:
			cout << "Количество элементов: " << stack.GetTop() << endl;
			break;
		case 5:
			cout << "Размер стека: " << stack.GetSize() << endl;
			break;
		default:
			break;
		}

		cout << endl << "Состояние стека:" << endl << stack << endl;
	}
}
