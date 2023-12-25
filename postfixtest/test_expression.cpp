#include "Postfix.h"
#include <gtest.h>

TEST(TArithmeticExpression, can_get_infix)
{
	string expr = "a+b";
	TArithmeticExpression expression(expr);

	string str = "a+b";

	ASSERT_EQ(str, expression.GetInfix());
}
TEST(TArithmeticExpression, can_get_postfix)
{
	string expr = "a+b";
	TArithmeticExpression expression(expr);

	string str = "a b + ";

	ASSERT_EQ(str, expression.GetPostfix());
}
TEST(TArithmeticExpression, can_calculate)
{
	string expr = "1+1";
	TArithmeticExpression expression(expr);

	ASSERT_EQ(2, expression.Calculate());
}
TEST(TArithmeticExpression, example)
{
	string expr = "(4+11-8/2*(7*3+4-7))*3";
	TArithmeticExpression expression(expr);

	EXPECT_EQ(-171.0, expression.Calculate());
}
TEST(TArithmeticExpression, priority)
{
	string expr = "2+2*2/2";
	TArithmeticExpression expression(expr);

	EXPECT_EQ(4, expression.Calculate());
}