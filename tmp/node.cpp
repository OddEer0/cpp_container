#include "redblacktree.h"

namespace s21 {
    template <class Key, class T>
    Key RedBlackTreeNode<Key, T>::key() {
        return key;
    }

    template <class Key, class T>
    T& RedBlackTreeNode<Key, T>::value() {
        return value;
    }

    template <class Key, class T>
    RedBlackTreeNode<Key, T>* RedBlackTreeNode<Key, T>::left() {
        return left;
    }

    template <class Key, class T>
    RedBlackTreeNode<Key, T>* RedBlackTreeNode<Key, T>::right() {
        return right;
    }

    template <class Key, class T>
    RedBlackTreeNode<Key, T>* RedBlackTreeNode<Key, T>::parent() {
        return parent;
    }

    template <class Key, class T>
    bool RedBlackTreeNode<Key, T>::isBlack() {
        return color == BLACK;
    }

    template <class Key, class T>
    bool RedBlackTreeNode<Key, T>::isRed() {
        return color == RED;
    }

    template <class Key, class T>
    bool RedBlackTreeNode<Key, T>::isLeftNode() {
        if (parent == nullptr) {
            return false;
        }
        return parent.left == this;
    }

    template <class Key, class T>
    bool RedBlackTreeNode<Key, T>::isRightNode() {
        if (parent == nullptr) {
            return false;
        }
        return parent.right == this;
    }

    template <class Key, class T>
    int RedBlackTreeNode<Key, T>::getChildrenCount() {
        int result = 0;

        if (left != nullptr) {
            result++;
        }
        if (right != nullptr) {
            result++;
        }

	    return result;
    }

    template <class Key, class T>
    RedBlackTreeNode<Key, T>* RedBlackTreeNode<Key, T>::getChildOrNull() {
        if (left != nullptr) {
            return left;
        }
        return right;
    }
}