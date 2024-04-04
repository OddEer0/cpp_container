#include "redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare, class Allocator>
    bool RedBlackTree<Key, T, Compare, Allocator>::empty() {
        return length == 0;
    }

    template <class Key, class T, class Compare, class Allocator>
    typename RedBlackTree<Key, T, Compare, Allocator>::size_type RedBlackTree<Key, T, Compare, Allocator>::size() {
        return length;
    }

    template <class Key, class T, class Compare, class Allocator>
    typename RedBlackTree<Key, T, Compare, Allocator>::size_type RedBlackTree<Key, T, Compare, Allocator>::max_size() {
        return std::allocator_traits<Allocator>::max_size(allocator);
    }
}
