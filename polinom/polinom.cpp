#include "TPolinom.h"
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	TPolinom poly1,poly2;
	TMonom monom0(0, 2, 7, 3);
	poly1.AddMonom(monom0);
	TMonom monom1(-6, 6, 2, 4);
	poly1.AddMonom(monom1);
	TMonom monom2(9, 3, 5, 2);
	poly1.AddMonom(monom2);
	TMonom monom3(3, 6, 2, 4);
	poly2.AddMonom(monom3);
	TMonom monom4(5, 5, 4, 8);
	poly2.AddMonom(monom4);
	TMonom monom5(8, 3, 4, 8);
	poly2.AddMonom(monom5);

	cout << "Моном 0: " << monom0 << endl;
	cout << "Моном 1: " << monom1 << endl;
	cout << "Моном 2: " << monom2 << endl;
	cout << "Моном 3: " << monom3 << endl;
	cout << "Моном 4: " << monom4 << endl;
	cout << "Моном 5: " << monom5 << endl;
	cout << "Полином 1(monom0, monom1, monom2): " << poly1 << endl;
	cout << "Полином 2(monom3, monom4, monom5): " << poly2 << endl;
	cout  << "Сумма полиномов: " << poly1.AddPolinom(poly2) << endl;

}
