#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead; // заголовок, pFirst - звено за pHead
public:
	THeadList() : TList<T>() // Делегация конструктору TList
	{
		pHead = new TNode<T>;
		pHead->pNext = this->pFirst;
		this->pStop->pNext = pHead;
	}
	~THeadList() { // Неявный вызов деструктора TList
		if (pHead != nullptr)
			delete pHead;
		pHead = nullptr;
	}
	void InsertFirst(T item) // вставка звена после pHead
	{
		TList<T>::InsertFirst(item); // Вызов InsertFirst родительского класса
		pHead->pNext = this->pFirst;
	}
	void DeleteFirst() { // удалить pFirst
		TList<T>::DeleteFirst(); // Вызов DeleteFirst родительского класса
		pHead->pNext = this->pFirst;
	}
};