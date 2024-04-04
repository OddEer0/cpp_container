#include "main.h"

// TEST(MapBaseSuite, default_init) {
//     s21::map<int, int> data;
//     ASSERT_EQ(data.size(), 0);
// }

// TEST(MapBaseSuite, correct_insert) {
//     s21::map<int, int> data;
//     ASSERT_TRUE(data.empty()); // Контейнер пустой

//     auto ret = data.insert(std::make_pair(1000, 2000)); // Вставка элемента

//     ASSERT_TRUE(ret.second); // Успешная вставка возвращает вторым аршументом в паре bool значение true. false если вставка не удалась
//     ASSERT_EQ(ret.first->getKey(), 1000); // первая пара возвращает ссылку на node класс у него есть свои классы. Конкретно возвращает указатель не элемент который был вставлен
//     ASSERT_EQ(ret.first->getValue(), 2000);

//     ASSERT_EQ(data.size(), 1); // Ну логично что размер теперь 1
//     ASSERT_FALSE(data.empty()); // Контейнер уже не пустой
// }

// TEST(MapBaseSuite, list_init) {
//     s21::map<int, int> data = {
//         {1000, 2000},
//         {2000, 4000},
//         {3000, 6000},
//     }; // Инициализация по списку
//     ASSERT_EQ(data.size(), 3); // Логично что 3
//     // И тд
// }

// TEST(MapBaseSuite, copy_init) {
//     s21::map<int, int> data = {
//         {1000, 2000},
//         {2000, 4000},
//         {3000, 6000},
//     };
//     s21::map<int, int> copy(data);
//     copy.insert(std::make_pair(4000, 8000));
//     ASSERT_EQ(data.size(), 3);
//     ASSERT_EQ(copy.size(), 4);
// }

// TEST(MapBaseSuite, print_string_method) {
//     s21::map<int, int> data = {
//         {2000, 5000},
//         {1000, 2000},
//         {3000, 6000},
//     };

//     // Метод string возвращает отрисовку дерева. Можно сделать свою ожидаемую строку отрисовку и тестировать в след тестах
//     std::string str = "RedBlackTree\n│   ┌── Color: RED, Key: 3000, Value: 6000\n└── Color: BLACK, Key: 2000, Value: 5000\n    └── Color: RED, Key: 1000, Value: 2000\n";

//     ASSERT_EQ(data.string(), str);
// }

// TEST(MapBaseSuite, at_correct_test) {

// }

// TEST(MapBaseSuite, operator_correct_test) {
//     // Оператор data[index(0, 2 ну кароче получение по индексу)]
// }

// TEST(MapBaseSuite, left_correct) {

// }

// TEST(MapBaseSuite, right_correct) {

// }

// TEST(MapBaseSuite, all_iterator_correct) {

// }

// TEST(MapBaseSuite, all_reverse_iteratir_correct) {

// }

// // Вставка, если элемент уже существует то меняет значение
// TEST(MapBaseSuite, insert_or_assign) {

// }

// // Вставка по итератору
// TEST(MapBaseSuite, insert_range_correct) {

// }

// // Удаление элемента с возвращением опцианального типа
// TEST(MapBaseSuite, extract_correct) {

// }

// // Удаление элемента с возвращением кол-во удаленных элементов 1 или 0 по очевидным причинам. Это больше полезно при multiset
// TEST(MapBaseSuite, erase_correct) {

// }

// // Очиска всего контейнера
// TEST(MapBaseSuite, clear_correct) {

// }

// // Проверка на наличие элемента с таким ключем
// TEST(MapBaseSuite, contains_correct) {

// }