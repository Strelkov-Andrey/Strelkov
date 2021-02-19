#include "convertor.h"

#include <gtest.h>


TEST(test_convertor, test_three)
{
	Convertor c;
	roman r("III");
	arabic v  = c.toArabic(r);
	EXPECT_EQ(v, 3);
}

TEST(test_convertor, test_eight)
{
	Convertor c;
	roman r("VIII");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 8);
}
TEST(test_convertor, test_fourteen)
{
	Convertor c;
	roman r("XIV");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 14);
}
TEST(test_convertor, test_nineteen)
{
	Convertor c;
	roman r("XIX");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 19);
}
TEST(test_convertor, test_thirty)
{
	Convertor c;
	roman r("XXX");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 30);
}
TEST(test_convertor, test_fourty)
{
	Convertor c;
	roman r("XL");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 40);
}
TEST(test_convertor, test_fifty)
{
	Convertor c;
	roman r("L");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 50);
}
TEST(test_convertor, test_seventy_two)
{
	Convertor c;
	roman r("LXXII");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 72);
}
TEST(test_convertor, test_ninety_four)
{
	Convertor c;
	roman r("XCIV");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 94);
}
TEST(test_convertor, test_one_hundred)
{
	Convertor c;
	roman r("C");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 100);
}
TEST(test_convertor, test_three_hundred_ninety)
{
	Convertor c;
	roman r("CCCXC");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 390);
}
TEST(test_convertor, test_four_hundred_forty_four)
{
	Convertor c;
	roman r("CDXLIV");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 444);
}
TEST(test_convertor, test_five_hundred)
{
	Convertor c;
	roman r("D");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 500);
}
TEST(test_convertor, test_nine_hundred)
{
	Convertor c;
	roman r("CM");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 900);
}
TEST(test_convertor, test_2017)
{
	Convertor c;
	roman r("MMXVII");
	arabic v = c.toArabic(r);
	EXPECT_EQ(v, 2017);
}

TEST(test_convertor, test_3)
{
	Convertor c;
	arabic v(3);
	roman r=c.toRoman(v);
	EXPECT_EQ(r, "III");
}

TEST(test_convertor, test_8)
{
	Convertor c;
	arabic v(8);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "VIII");
}
TEST(test_convertor, test_14)
{
	Convertor c;
	arabic v(14);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "XIV");
}
TEST(test_convertor, test_19)
{
	Convertor c;
	arabic v(19);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "XIX");
}
TEST(test_convertor, test_30)
{
	Convertor c;
	arabic v(30);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "XXX");
}
TEST(test_convertor, test_40)
{
	Convertor c;
	arabic v(40);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "XL");
}
TEST(test_convertor, test_50)
{
	Convertor c;
	arabic v(50);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "L");
}
TEST(test_convertor, test_72)
{
	Convertor c;
	arabic v(72);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "LXXII");
}
TEST(test_convertor, test_94)
{
	Convertor c;
	arabic v(94);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "XCIV");
}
TEST(test_convertor, test_100)
{
	Convertor c;
	arabic v(100);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "C");
}
TEST(test_convertor, test_390)
{
	Convertor c;
	arabic v(390);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "CCCXC");
}
TEST(test_convertor, test_444)
{
	Convertor c;
	arabic v(444);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "CDXLIV");
}
TEST(test_convertor, test_500)
{
	Convertor c;
	arabic v(500);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "D");
}
TEST(test_convertor, test_900)
{
	Convertor c;
	arabic v(900);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "CM");
}
TEST(test_convertor, test_3017)
{
	Convertor c;
	arabic v(3017);
	roman r = c.toRoman(v);
	EXPECT_EQ(r, "MMMXVII");
}
