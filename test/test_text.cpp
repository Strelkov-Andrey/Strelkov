#include<tree.h>

#include<gtest.h>

TEST(Text, can_create_text)
{
	ASSERT_NO_THROW(Text t);
}

TEST(Text, can_add_new_string_to_the_current_level)
{
	Text t;
	t.addNext("key", "Next");
	string key =t.getKey();
	string val = t.getVal();
	EXPECT_EQ("Next", val);
	EXPECT_EQ("key", key);
}

TEST(Text, can_add_new_string_to_the_sublevel)
{
	Text t;
	t.addNext("key", "Next");
	t.addDown("key1", "Down");
	t.down();
	string key = t.getKey();
	string val = t.getVal();
	EXPECT_EQ("Down", val);
	EXPECT_EQ("key1", key);
}

TEST(Text, cant_get_current_key_if_text_is_empty)
{
	Text t;
	ASSERT_ANY_THROW(t.getKey());
}

TEST(Text, can_delete_current_value)
{
	Text t;
	t.addNext("key", "Next");
	t.addNext("key1", "This");
	ASSERT_NO_THROW(t.delCurr());
	
}

TEST(Text, can_delete_sublevel_from_current_string)
{
	Text t;
	t.addNext("key", "Next");
	t.addDown("key1", "Down");
	t.delDown();
	ASSERT_ANY_THROW(t.down());
}

TEST(Text, text_is_empty)
{
	Text t;
	EXPECT_EQ(true, t.empty());
}

TEST(Text, text_is_not_empty)
{
	Text t;
	EXPECT_EQ(true, t.empty());
}

TEST(Text, can_go_to_next)
{
	Text t;
	t.addNext("key", "Next");
	t.addNext("key1", "This");
	t.next();
	EXPECT_EQ("This", t.getVal());
}

TEST(Text, can_go_back)
{
	Text t;
	t.addNext("key", "Next");
	t.addNext("key1", "This");
	t.next();
	t.top();
	EXPECT_EQ("Next", t.getVal());
}

TEST(Text, can_go_down)
{
	Text t;
	t.addNext("key", "Next");
	t.addDown("key1", "This");
	t.down();
	EXPECT_EQ("This",t.getVal());
}

TEST(Text, can_check_isDown)
{
	Text t;
	t.addNext("key", "Next");
	t.addDown("key1", "Down");
	EXPECT_EQ(true, t.isDown());
}

TEST(Text, can_check_isTop_true)
{
	Text t;
	t.addNext("key", "Next");
	t.addDown("key1", "Down");
	t.down();
	EXPECT_EQ(true, t.isTop());
}
