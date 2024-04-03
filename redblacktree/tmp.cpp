#include "redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare, class Allocator>
    bool RedBlackTree<Key, T, Compare, Allocator>::contains(key_type key) {
        node_type node = getNode(key);
        if (node == nullptr) {
            return false;
        }
        return true;
    }

    template <class Key, class T, class Compare, class Allocator>

}