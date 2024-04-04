#include "redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::iterator RedBlackTree<Key, T, Compare, Allocator>::begin() {
        iterator it = RedBlackTreeIterator<Key, T, Compare, Allocator>(this, nullptr, START);
        it.first();
        return it;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::iterator RedBlackTree<Key, T, Compare, Allocator>::end() {
        iterator it = RedBlackTreeIterator<Key, T, Compare, Allocator>(this, nullptr, START);
        it.end();
        return it;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::const_iterator RedBlackTree<Key, T, Compare, Allocator>::cbegin() {
        const_iterator it = RedBlackTreeIterator<Key, T, Compare, Allocator>(this, nullptr, START);
        it.first();
        return it;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::const_iterator RedBlackTree<Key, T, Compare, Allocator>::cend() {
        const_iterator it = RedBlackTreeIterator<Key, T, Compare, Allocator>(this, nullptr, START);
        it.end();
        return it;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::reverse_iterator RedBlackTree<Key, T, Compare, Allocator>::rbegin() {
        reverse_iterator it = RedBlackTreeIterator<Key, T, Compare, Allocator>(this, nullptr, START, true);
        it.last();
        return it;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::reverse_iterator RedBlackTree<Key, T, Compare, Allocator>::rend() {
        reverse_iterator it = RedBlackTreeIterator<Key, T, Compare, Allocator>(this, nullptr, START, true);
        it.start();
        return it;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::const_reverse_iterator RedBlackTree<Key, T, Compare, Allocator>::crbegin() {
        const_reverse_iterator it = RedBlackTreeIterator<Key, T, Compare, Allocator>(this, nullptr, START);
        it.last();
        return it;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTree<Key, T, Compare, Allocator>::const_reverse_iterator RedBlackTree<Key, T, Compare, Allocator>::crend() {
        const_reverse_iterator it = RedBlackTreeIterator<Key, T, Compare, Allocator>(this, nullptr, START);
        it.start();
        return it;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTreeIterator<Key, T, Compare, Allocator>& RedBlackTreeIterator<Key, T, Compare, Allocator>::operator++() {
        if (!is_reverse) {
            return next();
        } else {
            return prev();
        }
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTreeIterator<Key, T, Compare, Allocator>& RedBlackTreeIterator<Key, T, Compare, Allocator>::next() {
        if (position == END) {
            return *this;
        }
        if (position == START) {
            if (tree->size() == 0) {
                return *this;
            }
            node = tree->left();
            position = PROCESS;
            return *this;
        }
        if (node->right != nullptr) {
            node = node->right;
            while (node->left != nullptr) {
                node = node->left;
            }
            return *this;
        }
        while (node->parent != nullptr) {
            RedBlackTreeNode<Key, T> *tmp_node = node;
            node = node->parent;
            if (tmp_node == node->left) {
                return *this;
            }
        }
        node = nullptr;
        position = END;
        return *this;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTreeIterator<Key, T, Compare, Allocator>& RedBlackTreeIterator<Key, T, Compare, Allocator>::operator--() {
        if (!is_reverse) {
            return prev();
        } else {
            return next();
        }
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTreeIterator<Key, T, Compare, Allocator>& RedBlackTreeIterator<Key, T, Compare, Allocator>::prev() {
        if (position == START) {
            return *this;
        }
        if (position == END) {
            if (tree->size() == 0) {
                return nullptr;
            }
            node = tree->right();
            position = PROCESS;
            return *this;
        }
        if (node->left != nullptr) {
            node = node->left;
            while (node->right != nullptr) {
                node = node->right;
            }
            return *this
        }
        while (node->parent != nullptr) {
            RedBlackTreeNode<Key, T> *tmp_node = node;
            node = node.parent;
            if (tmp_node == node.right) {
                return *this;
            }
        }

        node = nullptr;
        position = START;
        return *this;
    }

    template <class Key, class T, class Compare, class Allocator>
    T& RedBlackTreeIterator<Key, T, Compare, Allocator>::operator*() {
        return node->value;
    }

    template <class Key, class T, class Compare, class Allocator>
    T* RedBlackTreeIterator<Key, T, Compare, Allocator>::operator->() {
        return &(node->value);
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTreeNode<Key, T>* RedBlackTreeIterator<Key, T, Compare, Allocator>::node() {
        return node;
    }

    template <class Key, class T, class Compare, class Allocator>
    void RedBlackTreeIterator<Key, T, Compare, Allocator>::start() {
        node = nullptr;
        position = START;
    }

    template <class Key, class T, class Compare, class Allocator>
    void RedBlackTreeIterator<Key, T, Compare, Allocator>::end() {
        node = nullptr;
        position = END;
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTreeIterator<Key, T, Compare, Allocator>& RedBlackTreeIterator<Key, T, Compare, Allocator>::first() {
        start();
        return ++(*this);
    }

    template <class Key, class T, class Compare, class Allocator>
    RedBlackTreeIterator<Key, T, Compare, Allocator>& RedBlackTreeIterator<Key, T, Compare, Allocator>::last() {
        end();
        return --(*this);
    }
}