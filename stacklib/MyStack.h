#pragma once
#include <iostream>


template <class T>
class TStack {
protected:
	int size; // ������ �����
	int top; // ���������� ��������� � ������ ��� ������ �������� 
	T* mas; 
public:
	TStack(int n = 0) {//� ������������ ���������� ������������� ����� �������� n � ������� ������� �������� � ��������� ������ ��� ������ mas �������� siz�
		if (n <= 0)
			throw - 1;
		 
		top = 0;
		size = n;
		mas = new T[size]();
	}
	TStack(TStack<T>& stack) {//����������� �����������
		top = stack.top; // � ������������ ����������� ���������� ����������� ��������� ����� stack � ����� ����.
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
	void Push(T a) {//����� Push(T a) ��������� �������� ����� ������� a �� �������� �����, ���� ���� �� ��������
		if (IsFull()) {
			throw - 1;
		}
		mas[top] = a;
		top++;
	}
	T Get() {//����� Get() ���������� � ������� �������, ����������� �� ������� �����, ���� ���� �� ����.
		if (IsEmpty()) {
			throw - 1;
		}
		top--;
		return mas[top];
	}
	T TopView() { return mas[top - 1]; }// ���� � ������ �����

	int GetSize() 
	{
		return size;
	}
	int GetTop() // ���������� ���������� ��������� �����
	{
		return top;
	}


	bool IsFull() // ���� top == size, ������ ���������� ��������� �������� ������� �����
	{
		return top == size;
	}

	bool IsEmpty()
	{
		return top == 0;
	}

	TStack& operator=(TStack<T>& stack) //����������� ������ ����� � ������ � ������������� ������
	{
		if (this == &stack)//�������� �� ��� �� ������ ����� �����, ���� ��� �� ���������� this ������ ����� �� ������ ������ ��������
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

	//��������� ����� � ������
	friend std::ostream& operator<<(std::ostream & ostr, const TStack<T>& s) noexcept {//�����
		ostr << "���������� ���������: " << s.top << endl;//����� ������ ����� s  �� ����� ostr � ����� �������
		for (int i = 0; i < s.top; i++) {
			ostr << s.mas[i] << endl;
		}
		return ostr;
	}
	friend std::istream& operator>>(std::istream & istr, const TStack<T>&s) noexcept {//����
		for (int i = 0; i < s.size; i++) {
			istr >> s.mas[i];
		}
		return istr;
	}
};




