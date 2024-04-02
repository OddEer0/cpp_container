#ifndef S21_CONTAINERS_REDBLACKTREE_H_
#define S21_CONTAINERS_REDBLACKTREE_H_

#include <utility>
#include <cstddef>
#include <functional>
#include <optional>

#define RED 1
#define BLACK 0
#define START 0
#define PROCESS 1
#define END 2

namespace s21 {
    template <class Key, class T>
    class RedBlackTreeNode {
    private:
        Key key;
        T value;
        bool color;
        RedBlackTreeNode<Key, T> *left_;
        RedBlackTreeNode<Key, T> *right_;
        RedBlackTreeNode<Key, T> *parent_;

    public:
        Key key();
        T& value();
        RedBlackTreeNode* left();
        RedBlackTreeNode* right();
        RedBlackTreeNode* parent();
        bool isBlack();
        bool isRed();
        bool isLeftNode();
        bool isRightNode();
        int getChildrenCount();
        RedBlackTreeNode* getChildOrNull();
    };



    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>>>
    class RedBlackTreeIterator {
        private:
            RedBlackTree<Key, T, Compare, Allocator> *tree;
            RedBlackTreeNode<Key, T> *node_;
            int position;
            bool is_reverse;

            RedBlackTreeIterator& next();
            RedBlackTreeIterator& prev();

        public:
            RedBlackTreeIterator(RedBlackTree<Key, T, Compare, Allocator> *tree, RedBlackTreeNode<Key, T> *node, int position = START, bool isReverse = false)
                : tree(tree), node(node), position(position), is_reverse(isReverse) {}
            ~RedBlackTreeIterator() {}
            RedBlackTreeIterator(const RedBlackTreeIterator& other) = default;
            RedBlackTreeIterator& operator=(const RedBlackTreeIterator& other) = default;
            bool operator==(const RedBlackTreeIterator& other) const {
                return tree == other.tree && node.key() == other.node.key();
            }
            bool operator!=(const RedBlackTreeIterator& other) const {
                return node.key() != other.node.key();
            }

            RedBlackTreeIterator& operator++();
            RedBlackTreeIterator& operator--();
            T& operator*();
            T* operator->();

            RedBlackTreeNode<Key, T>* node();
            void start();
            void end();
            RedBlackTreeIterator& first();
            RedBlackTreeIterator& last();
    };



    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>>>
    class RedBlackTree {
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
        using iterator = RedBlackTreeIterator<Key, T, Compare, Allocator>&;
        using const_iterator = const RedBlackTreeIterator<Key, T, Compare, Allocator>*;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;
        using node_type = RedBlackTreeNode<Key, T>*;

    private:
        node_type root;
        size_type length;
        key_compare cmp;
        allocator_type allocator;

        node_type get_node(key_type &key);

        // Balance tree
        void balance_insert(node_type new_node);
        void left_rotate(node_type node);
        void right_rotate(node_type node);
        void swap_node(node_type to, node_type from);
        void balance_remove(node_type node);
        node_type getRightSwappedNode(node_type node);

    public:
        RedBlackTree();
        RedBlackTree(std::initializer_list<value_type> const &items);
        RedBlackTree(const RedBlackTree &m);
        RedBlackTree(RedBlackTree &&m);
        ~RedBlackTree();
        RedBlackTree& operator=(RedBlackTree &&m);
        RedBlackTree& operator=(const RedBlackTree &m);

        // CAPACITY
        bool empty();
        size_type size();
        size_type max_size();

        // ELEMENT ACCESS
        mapped_value &at(const key_type &key);
        mapped_value &operator[](const key_type &key);

        // ITERATOR
        node_type right();
        node_type left();
        iterator begin();
        iterator end();
        const_iterator cbegin();
        const_iterator cend();
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator crbegin();
        const_reverse_iterator crend();

        // MODIFIER
        // Вставка элемента
        void insert(const key_type &key, const mapped_value &value);

        // Вставка элемента или замена, если ключ уже существует
        void insert_or_assign(const key_type &key, const mapped_value &value);

        // Вставка по итератору
        template <class InputIt>
        void insert_range(InputIt first, InputIt last); 

        // Вставка элемента в дерево возвращая пару (итератор, успешность вставки)
        std::pair<iterator, bool> emplace(const key_type& key, const mapped_value& value);

        // Попытка вставки элемента с использованием подсказки
        iterator emplace_hint(const_iterator hint, const key_type& key, const mapped_value& value);

        // Попытка вставки элемента или его замены, если ключ уже существует
        std::pair<iterator, bool> try_emplace(const key_type& key, const mapped_value& value);

        // Удаление элемента по ключу
        void erase(const key_type& key);

        // Извлечение элемента по ключу
        std::optional<value_type> extract(const key_type& key);

        // Очистка контейнера
        void clear();

        // Обмен содержимым двух деревьев
        void swap(RedBlackTree& other);

        // Слияние двух деревьев
        void merge(RedBlackTree& other);

        // LOOKUP
        size_type count(const key_type& key) const;

        // Поиск элемента с заданным ключом
        iterator find(const key_type& key);
        const_iterator find(const key_type& key) const;

        // Проверка наличия элемента с заданным ключом
        bool contains(const key_type& key) const; // C++20

        // Возвращает диапазон элементов с заданным ключом
        std::pair<iterator, iterator> equal_range(const key_type& key);
        std::pair<const_iterator, const_iterator> equal_range(const key_type& key) const;

        // Возвращает итератор на первый элемент не меньше заданного ключа
        iterator lower_bound(const key_type& key);
        const_iterator lower_bound(const key_type& key) const;

        // Возвращает итератор на первый элемент больше заданного ключа
        iterator upper_bound(const key_type& key);
        const_iterator upper_bound(const key_type& key) const;

        // OBSERVERS (getters and setters)
        key_compare key_comp();
        key_compare value_comp();
        allocator_type get_allocator();
    };
}

#endif