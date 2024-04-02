#include "redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::RedBlackTree()
        : root(nullptr), length(0), cmp(Compare()), allocator(Allocator()) {}

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::RedBlackTree(RedBlackTree &&m)
        : root(m.root), length(m.length), cmp(std::move(m.cmp)), allocator(std::move(m.allocator)) {
        m.root = nullptr;
        m.length = 0;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::RedBlackTree(std::initializer_list<value_type> const &items)
        : root(nullptr), length(0), cmp(Compare()), allocator(Allocator()) {
        for (const auto& item : items) {
            insert(item.first, item.second);
        }
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::RedBlackTree(const RedBlackTree &m)
        : root(nullptr), length(m.length), cmp(m.cmp), allocator(m.allocator) {
        // Копирование дерева m
        // Например: this->copyTree(m.root);
    }

     template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::~RedBlackTree() {
        clear();
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>& RedBlackTree<Key, T, Compare, Allocator>::operator=(RedBlackTree &&m) {
        if (this != &m) {
            clear();

            root = m.root;
            length = m.length;
            cmp = std::move(m.cmp);
            allocator = std::move(m.allocator);

            m.root = nullptr;
            m.length = 0;
        }
        return *this;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>& RedBlackTree<Key, T, Compare, Allocator>::operator=(const RedBlackTree &m) {
        if (this != &m) {
            clear();

            // Копирование данных из m в текущее дерево
            // Например: this->copyTree(m.root);
            length = m.length;
            cmp = m.cmp;
            allocator = m.allocator;
        }
        return *this;
    }
}