#pragma once
#include <iostream>


template <class T>
class TStack {
protected:
	int size; // Размер стека
	int top; // Количество элементов и индекс для нового элемента 
	T* mas; 
public:
	TStack(int n = 0) {//В конструкторе происходит инициализация стека размером n с нулевым верхним индексом и выделение памяти под массив mas размером sizе
		if (n <= 0)
			throw - 1;
		 
		top = 0;
		size = n;
		mas = new T[size]();
	}
	TStack(TStack<T>& stack) {//конструктор копирования
		top = stack.top; // В конструкторе копирования происходит копирование элементов стека stack в новый стек.
		size = stack.size;

		mas = new T[size]();
		for (int i = 0; i < size; i++)
			mas[i] = stack.mas[i];
	}
	~TStack() {
		if (mas != nullptr)
			delete[] mas;

		top = 0;
		size = 0;
	}
	void Push(T a) {//Метод Push(T a) позволяет добавить новый элемент a на верхушку стека, если стек не заполнен
		if (IsFull()) {
			throw - 1;
		}
		mas[top] = a;
		top++;
	}
	T Get() {//Метод Get() возвращает и удаляет элемент, находящийся на вершине стека, если стек не пуст.
		if (IsEmpty()) {
			throw - 1;
		}
		top--;
		return mas[top];
	}
	T TopView() { return mas[top - 1]; }// элем в начале стека

	int GetSize() 
	{
		return size;
	}
	int GetTop() // Возвращает количество элементов стека
	{
		return top;
	}


	bool IsFull() // Если top == size, значит количество элементов достигло размера стека
	{
		return top == size;
	}

	bool IsEmpty()
	{
		return top == 0;
	}

	TStack& operator=(TStack<T>& stack) //копирование одного стека в другой с освобождением памяти
	{
		if (this == &stack)//проверка не явл ли объект самим собой, если явл то возвращает this просто чтобы не делать лишних операций
			return *this;

		if (mas != nullptr)
			delete[] mas;

		size = stack.size;
		mas = new T[size];


		top = stack.top;

		for (int i = 0; i < size; i++)
			mas[i] = stack.mas[i];

		return *this;
	}

	//операторы вводы и выводы
	friend std::ostream& operator<<(std::ostream & ostr, const TStack<T>& s) noexcept {//вывод
		ostr << "Количество элементов: " << s.top << endl;//вывод масива стека s  на поток ostr с новой строчки
		for (int i = 0; i < s.top; i++) {
			ostr << s.mas[i] << endl;
		}
		return ostr;
	}
	friend std::istream& operator>>(std::istream & istr, const TStack<T>&s) noexcept {//ввод
		for (int i = 0; i < s.size; i++) {
			istr >> s.mas[i];
		}
		return istr;
	}
};




