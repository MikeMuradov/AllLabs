#pragma once

// ����� ������
template<class T>
struct TNode
{
	T value; // ��������
	TNode<T>* pNext; // ��������� �����
};

//int arr[5];
// int* arr = new int(5);
// arr[1] = 1
//