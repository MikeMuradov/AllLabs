#pragma once
#include <iostream>


template <class T>
class TQueue {
protected:
	int size; // Размер очереди
	int start; // Индекс начала очереди
	int end; // Индекс конца очереди
	int count; // Количество элементов
	T* mas;

public:
	TQueue(int n = 0) {
		if (n <= 0)
			throw - 1;

		size = n;
		end = size;
		start = 0;
		count = 0;

		mas = new T[size]();
	}
	TQueue(TQueue <T>& q) {
		start = q.start;
		size = q.size;
		count = q.count;
		end = q.end;

		mas = new T[size];

		for (int i = 0; i < size; i++)
			mas[i] = q.mas[i];
	}
	~TQueue() {
		if (mas == nullptr)
			delete[] mas;

		mas = nullptr;
	}

	void Push(T a) {
		if (IsFull())
			throw - 1;

		int i = (start + count) % size;
		mas[i] = a;
		end = (end + 1) % size;
		count++;
	}

	T Get() {
		if (IsEmpty())
			throw - 1;

		T tmp = mas[start]; // Сохраняем значение для возврата 
		mas[start] = T(); // Затираем значение в очереди
		
		start = (start + 1) % size;
		end = (end + 1) % size;
		count--;
		
		return tmp;
	}
	int GetSize() { 
		return size; 
	}
	
	bool IsFull() {
		return count == size;
	}
	
	bool IsEmpty() {
		return count == 0;
	}
	
	int GetStart() { 
		return start; 
	}

	int GetCount() {
		return count;
	}
	
	TQueue& operator=(const TQueue<T>& q) {
		if (this == &q)
			return *this;

		if (mas != nullptr)
			delete[] mas;

		count = q.count;
		start = q.start;
		end = q.end;
		size = q.size;

		mas = new T[size];
		for (int i = 0; i < size; i++)
			mas[i] = q.mas[i];

		return *this;
	}

	int GetEnd() { 
		return end; 
	}


	//операторы вводы и выводы
	friend std::ostream& operator<<(std::ostream& ostr, const TQueue<T>& q) noexcept {
		ostr << "Количество элементов: " << q.count << endl;
		for (int i = 0; i < q.size; i++) {
			ostr << q.mas[i] << endl;
		}
		return ostr;
	}
	friend std::istream& operator>>(std::istream& istr, const TQueue<T>& q) noexcept {
		for (int i = 0; i < q.size; i++) {
			istr >> q.mas[i];
		}
		return istr;
	}
};