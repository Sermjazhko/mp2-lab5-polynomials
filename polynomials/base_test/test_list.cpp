#include "List.h"
#include <gtest.h>

TEST(List, can_create_elem)
{
  ASSERT_NO_THROW(List st);
}

TEST(List, throws_when_empty_tasks)
{
  List st;
  EXPECT_EQ(true, st.empty());
}

TEST(List, can_add_element)
{
  List st;
  st.add_elem(1,1);
  EXPECT_EQ(1, st.get_size());
}

TEST(List, can_return_degree_of_element)
{
  List st;
  st.add_elem(1, 1);
  EXPECT_EQ(1, st.get_elem_deg(0));
}

TEST(List, can_return_element_constanst)
{
  List st;
  st.add_elem(1, 1);
  EXPECT_EQ(1, st.get_elem_con(0));
}
TEST(List, can_delete_beginning_of_list)
{
  List st;
  st.add_elem(1, 1);
  st.add_elem(2, 1);
  st.delete_elem(0);
  EXPECT_EQ(1, st.get_size());
}
TEST(List, can_delete_middle_of_list)
{
  List st;
  st.add_elem(1, 1);
  st.add_elem(2, 1);
  st.add_elem(2, 1);
  st.delete_elem(1);
  EXPECT_EQ(2, st.get_size());
}
TEST(List, can_delete_end_of_list)
{
  List st;
  st.add_elem(1, 1);
  st.add_elem(2, 1);
  st.delete_elem(1);
  EXPECT_EQ(1, st.get_size());
}
TEST(List, can_sort_list)
{
  List st;
  st.add_elem(1, 1);
  st.add_elem(1, -1);
  st.sorting();
  EXPECT_EQ(0, st.get_size());
}