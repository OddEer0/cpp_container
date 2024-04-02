template <class Key, class T, class Compare, class Allocator>
typename RedBlackTree<Key, T, Compare, Allocator>::node_type RedBlackTree<Key, T, Compare, Allocator>::getNode(key_type &key) {
    node_type current = root_;

    while(current != nullptr) {
        if (key == current->data_->first) {
            return current;
        }
        if (cmp_(key, current->data_->first)) {
            current = current->left_;
        } else {
            current = current->right_;
        }
    }

    return nullptr;
}