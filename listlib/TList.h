#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst; // первое звено
	TNode<T>* pCurrent; // текущее звено
	TNode<T>* pPrevious; // звено перед текущим
	TNode<T>* pLast; // последнее звено
	TNode<T>* pStop; // значение указателя, означающего конец списка
	int length; // количество звеньев в списке

public:
	TList();
	~TList();
	int GetLength() { return length; } // Получить длину списка
	bool IsEmpty(); // список пуст ?
	// вставка звеньев
	void InsertFirst(T item); // перед первым
	void InsertCurrent(T item); // перед текущим
	void InsertLast(T item); // вставить последним

	// удаление звеньев
	void DeleteFirst(); // удалить первое звено
	void DeleteCurrent(); // удалить текущее звено

	void GoNext(); // сдвиг вправо текущего звена
	// (=1 после применения GoNext для последнего звена списка)

	void Reset(); // установить на начало списка
	bool IsEnd(); // список завершен ?

	T GetCurrentItem(); // Получить текущее значение
	void SetCurrentItem(T item) { pCurrent->value = item; } // Задать текущее значение
};

template <class T>
TList<T>::TList()
{
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pLast = nullptr;
	pStop = new TNode<T>;
	length = 0;
}

template <class T>
TList<T>::~TList()
{
	while (length > 0) {
		DeleteFirst();
	}

	if (pStop != nullptr) {
		delete pStop;
		pStop = nullptr;
	}
	
	pFirst = nullptr;
	pPrevious = nullptr;
	pCurrent = nullptr;
	pLast = nullptr;
	
}

template <class T>
bool TList<T>::IsEmpty()
{
	return length == 0; // Длина равна 0, только если список пуст
}

template <class T>
void TList<T>::InsertFirst(T item) // Встатвить элемент первым (перед pFirst)
{
	if (length == 0) {
		pFirst = new TNode<T>;
		pFirst->value = item;
		pFirst->pNext = pStop;
		pCurrent = pFirst;
		pLast = pFirst;
	}
	else {
		TNode<T>* tmp = pFirst;
		pFirst = new TNode<T>;
		pFirst->value = item;
		pFirst->pNext = tmp;
	}
	length++;
}

template <class T>
void TList<T>::InsertLast(T item) // Вставить звено в конец (перед pStop)
{
	if (length != 0) {
		length++;
		TNode<T>* tmp = pLast;
		pLast = new TNode<T>;
		pLast->pNext = pStop;
		pLast->value = item;
		tmp->pNext = pLast;
	}
	else {
		InsertFirst(item);
	}
}

template <class T>
void TList<T>::InsertCurrent(T item) // Вставить звено после текущего (pCurrent)
{
	if (length != 0) {
		length++;
		TNode<T>* pPrevios = pCurrent;
		pCurrent = new TNode<T>;
		pCurrent->pNext = pPrevios->pNext;
		pCurrent->value = item;
		pPrevios->pNext = pCurrent;
	}
	else {
		InsertFirst(item);
	}
}

template <class T>
void TList<T>::DeleteFirst() // Удалить первое звено (pFirst)
{
	if (length > 0) {
		length--;
	
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;

		if (pPrevious == tmp)
			pPrevious = nullptr;
		if (pCurrent == tmp)
			pCurrent = pFirst;
		if (pLast == tmp)
			pLast = pFirst;

		if (tmp != nullptr) {
			delete tmp;
			tmp = nullptr;
		}

	}
}

template <class T>
void TList<T>::DeleteCurrent() // Удалить текущее звено (pCurrent)
{
	if (length > 0) {
		length--;
		
		TNode<T>* tmp = pCurrent;
		pCurrent->pNext = tmp->pNext;
		pCurrent = pPrevious;
		
		if (tmp != nullptr)
			delete tmp;
		
		pPrevious = nullptr;
	}
}

template <class T>
T TList<T>::GetCurrentItem() 
{
	if (pCurrent == pStop)
		throw - 1;
	return pCurrent->value;
}

template <class T>
void TList<T>::Reset() // Сбросить текущую позицию до pFirst
{
	pPrevious = nullptr;
	pCurrent = pFirst;
}

template <class T>
void TList<T>::GoNext() // Переход к следующему звену
{
	if (pCurrent->pNext == nullptr)
		throw - 1;
	pPrevious = pCurrent;
	pCurrent = pCurrent->pNext;
}

template <class T>
bool TList<T>::IsEnd() // Если следующее звено - pStop, список кончился
{
	return pCurrent->pNext == pStop;
}