#ifndef S21_CONTAINERS_MAP_H_
#define S21_CONTAINERS_MAP_H_

#include <utility>
#include <cstddef>
#include <functional>
#include <optional>
#include "../tree/tree.h"

template <class A, class K>
struct CustomComparator {
    bool operator() (std::pair<A, K> a, std::pair<A, K> b) const {
        return a.first < b.first;
    }
};

namespace s21 {
    template <class Key, class T, class Compare = CustomComparator<Key, T>, class Allocator = std::allocator<std::pair<const Key, T>>>
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
        using iterator = typename RedBlackTree<Key, Compare, Allocator>::iterator;
        using const_iterator = typename RedBlackTree<Key, Compare, Allocator>::const_iterator;
        using reverse_iterator = iterator;
        using const_reverse_iterator = const_iterator;
        using node_type = typename RedBlackTree<Key, std::function<bool(value_type, value_type)>, Allocator>::node_type;

    private:
        RedBlackTree<value_type, Compare, Allocator> tree_;

    public:
        map() {
            tree_ = RedBlackTree<value_type, Compare, Allocator>();
        }
        map(std::initializer_list<value_type> const &items) {
            tree_ = RedBlackTree<value_type, Compare, Allocator>();
            for (auto item : items) {
                tree_.insert(item);
            }
        }
        map(map& other) {
            tree_ = RedBlackTree<value_type, Compare, Allocator>(other.tree_);
        }
        map(map&& other) {
            tree_ = RedBlackTree<value_type, Compare, Allocator>(std::move(other.tree_));
        }
        map& operator=(map &&other) {
            tree_ = std::move(other.tree_);
            return *this;
        }
        // Оператор присваивания перемещения
        map& operator=(map &other) {
            tree_ = other.tree_;
            return *this;
        }

        // PRINT MAP
        std::string string() {
            return tree_.stringWithCompare(std::function<std::string(value_type)>([](value_type val) {
                return "Key: " + std::to_string(val.first) + ", Value: " + std::to_string(val.second);
            }));
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
        iterator find(key_type key) {
            return tree_.find(key);
        }
        const_iterator find(key_type key) const {
            return tree_.find(key);
        };
        bool contains(key_type key) {
            return tree_.contains(key);
        }

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
        key_compare key_comp() {
            return tree_.key_comp();
        }

        allocator_type get_allocator() {
            return tree_.get_allocator();
        }

        mapped_value root() {
            return tree_.root();
        }
    };
}

#endif
