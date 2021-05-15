/*#include "polynomials.h"
#include <gtest.h>

TEST(test_polynomial, CAN_CREATE)
{
	ASSERT_NO_THROW(polinomial p);
}

TEST(test_polynomial, CAN_ADD)
{
	polinomial p;
	monomial m(3, 1, 2, 3);
	ASSERT_NO_THROW(p.addmonom(m));
}

TEST(test_polynomial, ADD_MONOMIAL)
{
	polinomial p,p1;
	monomial m(3, 1, 2, 3);
	p.addmonom(m);
	p1 = p;
	EXPECT_EQ(p,p1);
}

TEST(test_polynomial, CAN_ADD_POLYNOMIALS)
{
	polinomial p, p1, p3;
	monomial m1(10, 2, 1, 1);
	monomial m2(10, 3, 1, 1);
	monomial m3(10, 1, 1, 5);
	monomial m4(6, 2, 1, 1);
	p.addmonom(m1);
	p.addmonom(m2);
	p1.addmonom(m3);
	p1.addmonom(m4);
	p3 = p3 + m1 + m2 + m3 + m4;
	EXPECT_EQ(p3, p + p1);
}

TEST(test_polynomial, CAN_SUB_POLYNOMIAL)
{
	polinomial p, p1, p3;
	monomial m1(10, 2, 1, 1);
	monomial m2(10, 3, 1, 1);
	monomial m3(10, 1, 1, 5);
	monomial m4(6, 2, 1, 1);
	p.addmonom(m1);
	p.addmonom(m2);
	p1.addmonom(m3);
	p1.addmonom(m4);
	p3 = p3 + m1 + m2 - m3 - m4;
	EXPECT_EQ(p3, p - p1);
}
*/