#include <iostream>
#include "MyQueue.h"
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");

	int size, choice;
	double tmp;

	cout << "Введите размер очереди: ";
	cin >> size;
	TQueue<int> q(size);
	while (true) {
		cout << "Меню операций:\n"
			<< "1. Добавить в конец очереди\n"
			<< "2. Удалить первый элемент\n"
			<< "3. Вывести количество элементов\n"
			<< "4. Вывести размер очереди\n"
			<< "5. Вывести индекс начала очереди\n"
			<< "6. Вывести индекс конца очереди\n"
			<< "Выберите операцию: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			cout << "Введите элемент (int): ";
			cin >> tmp;
			q.Push(tmp);
			break;
		case 2:
			cout << "Удалённый элемент: " << q.Get() << endl;
			break;
		case 3:
			cout << "Количество элементов очереди: " << q.GetCount() << endl;
			break;
		case 4:
			cout << "Размер очереди: " << q.GetSize() << endl;
			break;
		case 5:
			cout << "Индекс начала очереди: "  << q.GetStart() << endl;
			break;
		case 6:
			cout << "Индекс конца очереди: " << q.GetEnd() << endl;
			break;
		default:
			break;
		}

		cout << "Состоние очереди: " << endl << q << endl;
	}
}
