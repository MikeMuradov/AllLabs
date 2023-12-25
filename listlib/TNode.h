#pragma once

// Звено списка
template<class T>
struct TNode
{
	T value; // Значение
	TNode<T>* pNext; // Следующее звено
};

//int arr[5];
// int* arr = new int(5);
// arr[1] = 1
//