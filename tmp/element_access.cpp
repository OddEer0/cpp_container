#include "redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare, class Allocator>
    typename RedBlackTree<Key, T, Compare, Allocator>::mapped_value& RedBlackTree<Key, T, Compare, Allocator>::at(const key_type &key) {
        node_type node = get_node(key);
        if node != nullptr {
            return node->value();
        }
        throw std::out_of_range("Key not found in RedBlackTree");
    }

    template <class Key, class T, class Compare, class Allocator>
    typename RedBlackTree<Key, T, Compare, Allocator>::mapped_value& RedBlackTree<Key, T, Compare, Allocator>::operator[](const key_type &key) {
        node_type node = get_node(key);
        if node != nullptr {
            return node->value();
        }
        return mapped_value();
    }
}