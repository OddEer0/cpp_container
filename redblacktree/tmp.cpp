#include "redblacktree.h"

namespace s21 {
    template <class Key, class T, class Compare, class Allocator>
    void RedBlackTree<Key, T, Compare, Allocator>::clear() {
        clearRecursive(root_);
        root_ = nullptr;
        length_ = 0;
    }

    template <class Key, class T, class Compare, class Allocator>
    int RedBlackTree<Key, T, Compare, Allocator>::erase(key_type key) {
        std::optional<value_type> res = extract(key);
        if (res.has_value()) {
            return 1;
        }
        return 0;
    }

    template <class Key, class T, class Compare, class Allocator>
    std::optional<typename RedBlackTree<Key, T, Compare, Allocator>::value_type> RedBlackTree<Key, T, Compare, Allocator>::extract(key_type key) {
        node_type deletedNode = getNode(key);
        if (deletedNode == nullptr) {
            return std::nullopt;
        }
        key_type keyRes = deletedNode->data_->first;
        mapped_value valueRes = deletedNode->data_->second;

        node_type child = nullptr;
        bool removedColor = deletedNode->color_;
        if (deletedNode->getChildrenCount() < 2) {
            child = deletedNode->getChildOrNull();
            swapNode(deletedNode, child, deletedNode->isNotChild());
            allocator_.deallocate(deletedNode->data_, 1);
            delete deletedNode;
            deletedNode = nullptr;
        } else {
            node_type swappedRight = getRightSwappedNode(deletedNode->right_);
            const_cast<Key&>(deletedNode->data_->first) = swappedRight->data_->first;
            deletedNode->data_->second = swappedRight->data_->second;
            removedColor = swappedRight->color_;
            child = swappedRight->getChildOrNull();
            swapNode(swappedRight, child, swappedRight->isNotChild());
            allocator_.deallocate(swappedRight->data_, 1);
            delete swappedRight;
            swappedRight = nullptr;
        }

        if (removedColor == BLACK) {
            balanceRemove(child);
        }
        length_--;
        return std::make_pair(keyRes, valueRes);
    }
}