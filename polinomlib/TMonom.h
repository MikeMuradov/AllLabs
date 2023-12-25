#pragma once
#include <string>
using namespace std;
struct TMonom
{
    double coef; // коэффициент монома
    int index; // индекс (свертка степеней)

	int precision = 10000; // Количество знаков после запятой (10^n)

	TMonom();

	TMonom(double coef1, int degX, int degY, int degZ);

	void SetCoef(int cval) { 
		coef = cval;
	}
	int GetCoef(void) {
		return coef;
	}

	void SetIndex(int ival) { 
		index = ival;
	}
	int GetIndex(void) { 
		return index;
	}


	bool operator==(const TMonom& other);
	
	bool operator>(const TMonom& other);

	bool operator<(const TMonom& other);

	friend std::ostream& operator<<(std::ostream& ostr, TMonom poly);

};

TMonom::TMonom() {
	coef = 0;
	index = 0;
}

TMonom::TMonom(double coef1, int degX, int degY, int degZ) {
	index = degX * 100 + degY * 10 + degZ; // Для x^5*y^6*z^7 -> 567
	coef = coef1;
}

bool TMonom::operator==(const TMonom& other) {
	if (index != other.index)
		return false;
	if (coef != other.coef)
		return false;
	return true;
}

bool TMonom::TMonom::operator>(const TMonom & other) {
	return index >= other.index || coef > other.coef;
}

bool TMonom::operator<(const TMonom& other) {
	return index <= other.index || coef < other.coef;
}

std::ostream& operator<<(std::ostream& ostr, TMonom poly) {
	int degX = poly.index / 100;
	int degY = poly.index / 10 % 10;
	int degZ = poly.index % 10;

	ostr << to_string(round(poly.coef * poly.precision) / poly.precision);//работа с нулями
	if (degX != 0) {
		ostr << "*X";
		if (degX != 1)
			ostr << "^" + to_string(degX);
	}
	if (degY != 0) {
		ostr << "*Y";
		if (degY != 1)
			ostr << "^" + to_string(degY);
	}
	if (degZ != 0) {
		ostr << "*Z";
		if (degZ != 1)
			ostr << "^" + to_string(degZ);
	}

	return ostr;
}