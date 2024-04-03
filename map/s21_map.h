#ifndef S21_CONTAINERS_MAP_H_
#define S21_CONTAINERS_MAP_H_

#include <utility>
#include <cstddef>
#include <functional>
#include <optional>
#include "../redblacktree/redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>>>
    class map {
    // USING TYPESREDBLACKTREE
    public:
        using key_type = Key;
        using mapped_value = T;
        using value_type = std::pair<const Key, T>;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using key_compare = Compare;
        using allocator_type = Allocator;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
        using piterator = typename RedBlackTree<Key, T, Compare, Allocator>::piterator;
        using iterator = typename RedBlackTree<Key, T, Compare, Allocator>::iterator;
        using const_iterator = typename RedBlackTree<Key, T, Compare, Allocator>::const_iterator;
        using reverse_iterator = iterator;
        using const_reverse_iterator = const_iterator;
        using node_type = typename RedBlackTree<Key, T, Compare, Allocator>::node_type;

    private:
        RedBlackTree<Key, T, Compare, Allocator> tree_;

    public:
        map() {
            tree_ = RedBlackTree<Key, T, Compare, Allocator>();
        }
        map(std::initializer_list<value_type> const &items) {
            tree_ = RedBlackTree<Key, T, Compare, Allocator>(items);
        }

        // PRINT MAP
        std::string string() {
            return tree_.string();
        }

        // CAPACITY
        bool empty() {
            return tree_.empty();
        }
        size_type size() {
            return tree_.size();
        }
        size_type max_size() {
            return tree_.max_size();
        }

        // ELEMENT ACCESS
        mapped_value &at(key_type key) {
            return tree_.at(key);
        }
        mapped_value operator[](key_type key) {
            return tree_[key];
        }

        // ITERATOR
        node_type right() {
            return tree_.right();
        }
        node_type left() {
            return tree_.left();
        }
        iterator begin() {
            return tree_.begin();
        }
        iterator end() {
            return tree_.end();
        }
        const_iterator cbegin() {
            return tree_.cbegin();
        }
        const_iterator cend() {
            return tree_.cend();
        }
        reverse_iterator rbegin() {
            return tree_.rbegin();
        }
        reverse_iterator rend() {
            return tree_.rend();
        }
        const_reverse_iterator crbegin() {
            return tree_.crbegin();
        }
        const_reverse_iterator crend() {
            return tree_.crend();
        }

        // MODIFIER
        // Вствка элемента
        std::pair<node_type, bool> insert(value_type pair) {
            return tree_.insert(pair);
        }

        // Вставка элемента, или перезапись значения. Если элемент с заданным ключем уже существует
        std::pair<node_type, bool> insert_or_assign(value_type pair) {
            return tree_.insert_or_assign(pair);
        }

        // Вставка элементов по итератору
        template <class InputIt>
        void insert_range(InputIt first, InputIt last) {
            tree_.insert_range(first, last);
        }

        // Удаление по ключу. возвращает кол-во удаленных элементов
        int erase(key_type key) {
            return tree_.erase(key);
        }

        // Удвление по ключу. Возвращает пару ключ значение при успешном удалений. Если же элемента не существует возвращает std::nullopt
        std::optional<value_type> extract(key_type key) {
            return tree_.extract(key);
        }

        void clear() {
            tree_.clear();
        }

        // Обмен содержимым двух деревьев
        // void swap(RedBlackTree& other);

        // Слияние двух деревьев
        // void merge(RedBlackTree& other);

        // LOOKUP
        // Поиск элемента с заданным ключом
        // iterator find(const key_type& key);
        // const_iterator find(const key_type& key) const;
        // bool contains(key_type key);

        // // Возвращает диапазон элементов с заданным ключом
        // std::pair<iterator, iterator> equal_range(const key_type& key);
        // std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const;

        // // Возвращает итератор на первый элемент не меньше заданного ключа
        // iterator lower_bound(const key_type& key);
        // const_iterator lower_bound(const key_type& key) const;

        // // Возвращает итератор на первый элемент больше заданного ключа
        // iterator upper_bound(const key_type& key);
        // const_iterator upper_bound(const key_type& key) const;

        // OBSERVERS (getters and setters)
        // Возвращает функцию компаратор
        key_compare key_comp() {
            return tree_.key_comp();
        }

        // Возвращает функцию компаратор. По сути идентичен key_comp нахера эта функция нужна не ясно. Наверное этот метод нахер удалю. Не тестить
        key_compare value_comp() {
            return tree_.value_comp();
        }

        // Возвращает аллокатор
        allocator_type get_allocator() {
            return tree_.get_allocator();
        }
    };
}

#endif
