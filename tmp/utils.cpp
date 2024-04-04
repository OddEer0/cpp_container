#include "redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::node_type RedBlackTree<Key, T, Compare, Allocator>::left() {
        if t.length == 0 {
		    return nullptr;
	    }
        node_type current = root;
        while(current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::node_type RedBlackTree<Key, T, Compare, Allocator>::right() {
        if t.length == 0 {
		    return nullptr;
	    }
        node_type current = root;
        while(current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::node_type RedBlackTree<Key, T, Compare, Allocator>::get_node(key_type& key) {
        node_type current = t.root;
	    while (current != nullptr) {
            if (current->key() == key) {
                return current;
            }
            if (cmp(key, current->key())) {
                current = current->left();
            } else {
                current = current->right();
            }
	    }

	    return nullptr
    }
}