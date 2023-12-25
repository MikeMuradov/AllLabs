#pragma once 
#include <string>
#include "MyStack.h"
using namespace std;


class TPostfix
{
private:
	string infix;
	string postfix;

	int GetPrioritet(char op); // Получить приоритет для операции
public:
	TPostfix(string inf);
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	double Calc(); // Вычислить выражение в постфиксной форме
	
};
