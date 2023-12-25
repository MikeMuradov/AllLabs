#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>
#include <sstream>


const int nonDisplayedZeros = 4; 
// Количество неотображаемых нулей при выводе коэффициента полинома
// Кол-во символов после запятой = 6 - nonDisplayedZeros


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& other);
	TPolinom(string str);
	TPolinom& operator=(const TPolinom& other); 

    void AddMonom(TMonom newMonom); // добавление монома
    TPolinom AddPolinom(TPolinom& other); // добавление полинома
    friend std::ostream& operator<<(std::ostream& ostr, TPolinom poly);
};

TPolinom::TPolinom() : THeadList<TMonom>::THeadList() // Делигация конструктора THeadList
{
    ;
}

TPolinom::TPolinom(TPolinom& other) : TPolinom()
{

    other.Reset();
    for (int i = 0; i < other.length; i++) {
        AddMonom(other.pCurrent->value);
        other.GoNext();
    }
    other.Reset();
}

TPolinom::TPolinom(string str)
{	
    stringstream stringstream1(str); // Превращаем строку в поток
    string s_monom; // Строковое представление монома
    while (getline(stringstream1, s_monom, '+')) { // Разбиваем str относительно "+"
        stringstream stringstream2(s_monom); 
        string comp;
        double coef;
        int degX = 0;
        int degY = 0;
        int degZ = 0;
        getline(stringstream2, comp, '*'); // Разбиваем s_monom относительно "*"
        coef = stod(comp); // Первым разбиением всегда будет коэффициент монома
        while(getline(stringstream2, comp, '*')) { // Примеры: "X^9", "Y"
            switch (comp[0])
            {
            case 'X':
                if (comp.size() == 3)
                    degX = comp[2] - '0'; // Символьные цифры в int
                else
                    degX = 1;
                break;
            case 'Y':
                if (comp.size() == 3)
                    degY = comp[2] - '0';
                else
                    degY = 1;
                break;
            case 'Z':
                if (comp.size() == 3)
                    degZ = comp[2] - '0';
                else
                    degZ = 1;
                break;
            }
        }
        AddMonom(TMonom(coef, degX, degY, degZ)); // Добавить моном в полином
    }
}

TPolinom& TPolinom::operator=(const TPolinom& other)
{
	if (this == &other)
		return *this;

    while (length > 0) { // Если полином не пуст, очистить
        DeleteFirst();
    }


    TNode<TMonom>* tmp = other.pFirst; 
    for (int i = 0; i < other.length; i++) {
        AddMonom(tmp->value);
        tmp = tmp->pNext;
    }
	
    return *this;
}

void TPolinom::AddMonom(TMonom m)
{
    if (m.GetCoef() == 0) // Если моном с нулевым коэффициентом, добавлять не нужно
        return;

    if (length == 0) // Если полином пуст, вставить первым
        InsertFirst(m);
    else {
        int i = 0;
        Reset();
        while (pCurrent->value.GetIndex() > m.GetIndex() && i <= length) // Поиск первого монома, которого степени меньше данного
        {
            i++;
            if (IsEnd()) { // Если дошли до конца, вставляем в конец
                InsertLast(m);
                return;
            }
            GoNext();
        }

        if (pCurrent->value.GetIndex() == m.GetIndex()) { // Если степени мономов равны, складываем
            double coef = pCurrent->value.GetCoef() + m.GetCoef();

            if (coef == 0) // Если моном занулился, удаляем его
                DeleteCurrent();
            else
                pCurrent->value.SetCoef(coef);
        }
        else {
            if (pCurrent == pFirst) { // Если мы всё ещё в начале, вставлем первым
                InsertFirst(m);
            }
            else { // Иначе смещаемся на 1 моном назад и вставляем
                pCurrent = pPrevious;
                pPrevious = nullptr;
                InsertCurrent(m); 
            }
        }
        Reset();
    }
}


TPolinom TPolinom::AddPolinom(TPolinom& other)
{
    TPolinom res(*this);
    other.Reset();
    for (int i = 0; i < other.length; i++) { 
        res.AddMonom(other.pCurrent->value);
        other.GoNext();
    }
    return res;
}

std::ostream& operator<<(std::ostream& ostr, TPolinom poly)
{
    if (poly.length == 0) 
        return ostr << "0";

    TNode<TMonom>* tmp = poly.pFirst;
    for (int i = 0; i < poly.length; i++)
    {
        if (i != 0)
            ostr << " + ";
        ostr << tmp->value;
        tmp = tmp->pNext;
    }
    return ostr;
}
