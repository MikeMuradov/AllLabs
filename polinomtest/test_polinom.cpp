#include <gtest.h>
#include "TPolinom.h"
using namespace std;


TEST(Polinom, Created_polinom_is_empty) {
	TPolinom a;
	ASSERT_EQ(0, a.GetLength());
}

TEST(Polinom, Created_polinom_with_one_monom_is_not_empty) {
	TPolinom a;
	a.AddMonom(TMonom(1, 1, 1, 1));
	ASSERT_NE(0, a.GetLength());
}

TEST(Polinom, Coefficients_add_up_if_degrees_are_equal) {
	TPolinom a;
	a.AddMonom(TMonom(1, 1, 1, 1));
	a.AddMonom(TMonom(1, 1, 1, 1));
	ASSERT_EQ("2.000000X*Y*Z", a.ToString());
}

TEST(Polinom, Coefficients_dont_add_up_if_degrees_are_different) {
	TPolinom a;
	a.AddMonom(TMonom(1, 1, 1, 1));
	a.AddMonom(TMonom(1, 2, 1, 1));
	ASSERT_EQ("X^2*Y*Z + X*Y*Z", a.ToString());
}

TEST(Polinom, Monom_delete_if_coefficient_equal_zero) {
	TPolinom a; 
	a.AddMonom(TMonom(0, 1, 1, 1));
	ASSERT_EQ(0, a.GetLength());
}

TEST(Polinom, Correct_adding_operator) {
	TMonom m1(3, 5, 2, 5);
	TMonom m2(-5, 4, 3, 3);
	TMonom m3(7, 3, 5, 1);
	TMonom m4(4, 3, 2, 6);
	TMonom m5(0, 2, 7, 3);
	TMonom m6(-6, 2, 1, 8);

	TPolinom p1, p2, res;
	p1.AddMonom(m1);
	p1.AddMonom(m2);
	p1.AddMonom(m3);

	p2.AddMonom(m4);
	p2.AddMonom(m5);
	p2.AddMonom(m6);

	res.AddMonom(m1);
	res.AddMonom(m2);
	res.AddMonom(m3);
	res.AddMonom(m4);
	res.AddMonom(m5);
	res.AddMonom(m6);

	ASSERT_EQ(res.ToString(), (p1 + p2).ToString());
}

