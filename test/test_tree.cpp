/*#include "polynomials.h"
#include <gtest.h>

TEST(test_monomial, CAN_CREATE_MONOMIAL)
{
	ASSERT_NO_THROW(monomial m);
}

TEST(test_monomial, CAN_CREATE_MONOMIAL2)
{
	ASSERT_NO_THROW(monomial m(10, 3, 4, 2));
}

TEST(test_monomial, CANT_CREATE_MONOMIAL_WITH_TOO_LARGE_DEGREE)
{
	ASSERT_ANY_THROW(monomial m(2, 0, 6, 15));
}

TEST(test_monomial, CANT_CREATE_MONOMIAL_WITH_NEGATIVE_DEGREE)
{
	ASSERT_ANY_THROW(monomial m(5,-1,0,4));
}

TEST(test_monomial, CAN_GET_DEGREE)
{
	monomial m(3,5,1,7);
	ASSERT_NO_THROW(m.getDegree());
}

TEST(test_monomial, RIGHT_GET_DEGREE)
{
	monomial m(3, 5, 1, 7);
	EXPECT_EQ(m.getDegree(),517);
}

TEST(test_monomial, CAN_ASSIGN)
{
	monomial m(3, 5, 1, 7);
	monomial m1;
	ASSERT_NO_THROW(m1=m);
}

TEST(test_monomial, CAN_ASSIGN_RIGHT)
{
	monomial m(3, 5, 1, 7);
	monomial m1 = m;
	EXPECT_EQ(m1, m);
}

TEST(test_monomial, UNARY_MINUS)
{
	monomial m(3, 5, 1, 7);
	monomial m1(-3, 5, 1, 7);
	EXPECT_EQ(m1, -m);
}

TEST(test_monomial, CAN_ADD_MONOMIALS)
{
	monomial m(3, 5, 1, 7);
	monomial m1(4, 5, 1, 7);
	monomial res(7, 5, 1, 7);
	EXPECT_EQ(res, m1 + m);
}

TEST(test_monomial, CAN_SUB_MONOMIALS)
{
	monomial m(3, 5, 1, 7);
	monomial m1(4, 5, 1, 7);
	monomial res(1, 5, 1, 7);
	EXPECT_EQ(res, m1 - m);
}

TEST(test_monomial, CAN_MUL_MONOMIALS)
{
	monomial m(3, 4, 1, 7);
	monomial m1(4, 5, 1, 1);
	monomial res(12, 9, 2, 8);
	EXPECT_EQ(res, m1 * m);
}

TEST(test_monomial, CANT_ADD_MONOMIALS_WITH_DIFF_DEGREES)
{
	monomial m(3, 0, 1, 7);
	monomial m1(4, 5, 1, 7);
	ASSERT_ANY_THROW(m1 + m);
}

TEST(test_monomial, CANT_SUB_MONOMIALS_WITH_DIFF_DEGREES)
{
	monomial m(3, 0, 1, 7);
	monomial m1(4, 5, 1, 7);
	ASSERT_ANY_THROW(m1 - m);
}

TEST(test_monomial, CANT_MULL_MONOMIALS_WITH_TOOLARGE_DEGREES)
{
	monomial m(3, 0, 1, 7);
	monomial m1(4, 5, 1, 7);
	ASSERT_ANY_THROW(m1 * m);
}
*/