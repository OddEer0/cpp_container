#include "../main.h"

TEST(MapIteratorTesting, left_right_elem_in_tree) {
    s21::map<int, int> data;
    auto left = data.left();
    auto right = data.right();
    ASSERT_EQ(left, nullptr);
    ASSERT_EQ(right, nullptr);
    data.insert(std::make_pair(1000, 1000));
    left = data.left();
    right = data.right();
    ASSERT_FALSE(left == nullptr);
    ASSERT_FALSE(right == nullptr);
    ASSERT_EQ(left->getValue(), 1000);
    ASSERT_EQ(right->getValue(), 1000);

    data = initMap();
    left = data.left();
    right = data.right();
    ASSERT_FALSE(left == nullptr);
    ASSERT_FALSE(right == nullptr);
    ASSERT_EQ(left->getValue(), 600);
    ASSERT_EQ(right->getValue(), 1250);
}