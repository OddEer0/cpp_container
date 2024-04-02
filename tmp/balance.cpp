#include "redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare, class Allocator>
    void RedBlackTree<Key, T, Compare, Allocator>::right_rotate(node_type node) {

    }

    template <class Key, class T, class Compare, class Allocator>
    void RedBlackTree<Key, T, Compare, Allocator>::left_rotate(node_type node) {

    }

    template <class Key, class T, class Compare, class Allocator>
    void RedBlackTree<Key, T, Compare, Allocator>::swap_node(node_type to, node_type from) {
        if (to == root) {
            root = from;
        } else if (to == to->parent()->left()) {
            to->parent()->left() = from;
        }
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::node_type RedBlackTree<Key, T, Compare, Allocator>::getRightSwappedNode(node_type node) {
        node_type current = node;
        while (current != nullptr) {
            int childrenCount = current->getChildrenCount();
            if (childrenCount == 0) {
                return current;
            }
            if (childrenCount == 2) {
                if (cmp(current->left()->key(), current->key())) {
                    current = current->left();
                } else {
                    current = current->right();
                }
            } else {
                if current->right() == nullptr {
                    if cmp(current->left()->key(), current->key()) {
                        current = current->left();
                    } else {
                        return current;
                    }
                } else {
                    if cmp(current->right()->key(), current->key()) {
                        current = current->right();
                    } else {
                        return current;
                    }
                }
            }
        }
    }
}
