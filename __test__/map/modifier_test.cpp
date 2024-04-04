#include "../main.h"

TEST(MapModifierTest, insert_value) {
    s21::map<int, int> data;
    ASSERT_TRUE(data.empty()); // Контейнер пустой

    auto ret = data.insert(std::make_pair(1000, 2000)); // Вставка элемента

    ASSERT_TRUE(ret.second); // Успешная вставка возвращает вторым аршументом в паре bool значение true. false если вставка не удалась
    ASSERT_EQ(ret.first->getKey(), 1000); // первая пара возвращает ссылку на node класс у него есть свои классы. Конкретно возвращает указатель не элемент который был вставлен
    ASSERT_EQ(ret.first->getValue(), 2000);

    ASSERT_EQ(data.size(), 1); // Ну логично что размер теперь 1
    ASSERT_FALSE(data.empty()); // Контейнер уже не пустой

    ret = data.insert(std::make_pair(2000, 4000));
    ASSERT_EQ(ret.first->getKey(), 2000); // первая пара возвращает ссылку на node класс у него есть свои классы. Конкретно возвращает указатель не элемент который был вставлен
    ASSERT_EQ(ret.first->getValue(), 4000);
    ASSERT_EQ(data.size(), 2);
    ret = data.insert(std::make_pair(3000, 6000));
    ASSERT_EQ(ret.first->getKey(), 3000); // первая пара возвращает ссылку на node класс у него есть свои классы. Конкретно возвращает указатель не элемент который был вставлен
    ASSERT_EQ(ret.first->getValue(), 6000);
    ASSERT_EQ(data.size(), 3);
}

TEST(MapModifierTest, clear_value) {
    s21::map<int, int> data = initMap();
    ASSERT_EQ(data.size(), 13);
    data.clear();
    ASSERT_EQ(data.size(), 0);
    ASSERT_TRUE(data.empty());
}