#include "Polynomials.h"
#include <gtest.h>

TEST(Polynomials, can_create_object_with_positive_length)
{
  ASSERT_NO_THROW(Polynomials, st("xyz"));
}

TEST(Polynomials, can_add1_polynomials)
{
  Polynomials st("xyz-xy");
  EXPECT_EQ("xyz", st.add("xy"));
}
TEST(Polynomials, can_add2_polynomials)
{
  Polynomials st("2x2");
  EXPECT_EQ("3.00x2", st.add("x2"));
}
TEST(Polynomials, can_multiply1_by_constant)
{
  Polynomials st("x2y2");
  EXPECT_EQ("2.00x2y2", st.mult_const(2));
}
TEST(Polynomials, can_multiply2_by_constant)
{
  Polynomials st("x2y2");
  EXPECT_EQ("0", st.mult_const(0));
}

TEST(Polynomials, can_multiply_polynomials)
{
  Polynomials st("x2y2");
  EXPECT_EQ("x2y2z2", st.mult("z2"));
}

TEST(Polynomials, can_get_size)
{
  Polynomials st("x2+y2+z2");
  EXPECT_EQ(3, st.get_size());
}

TEST(Polynomials, can_calculate1_value_at_point)
{
  Polynomials st("x2+y2+z2");
  EXPECT_EQ(3, st.point_calcul(1,1,1));
}
TEST(Polynomials, can_calculate2_value_at_point)
{
  Polynomials st("5xyz");
  EXPECT_EQ(5, st.point_calcul(1, 1, 1));
}
TEST(Polynomials, can_calculate3_value_at_point)
{
  Polynomials st("x2-y2-z3");
  EXPECT_EQ(2, st.point_calcul(2, 1, 1));
}

TEST(Polynomials, can_return_degree_of_element)
{
  Polynomials st("z2");
  EXPECT_EQ(2, st.get_monom_deg(0));
}

TEST(Polynomials, can_return_element_constanst)
{
  Polynomials st("z2");
  EXPECT_EQ(1, st.get_monom_con(0));
}