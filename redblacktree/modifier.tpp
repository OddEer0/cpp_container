template <class Key, class T, class Compare, class Allocator>
std::pair<typename RedBlackTree<Key, T, Compare, Allocator>::iterator, bool> RedBlackTree<Key, T, Compare, Allocator>::insert(value_type pair) {
    node_type current = root_;
    node_type parent = nullptr;

    std::cout << pair.first << std::endl;


    while (current != nullptr) {
        parent = current;
        if (pair.first == current->data_->first) {
            iterator it = new Iterator(this, current, PROCESS);
            return std::make_pair(it, false);
        }
        if (cmp_(pair.first, current->data_->first)) {
            current = current->left_;
        } else {
            current = current->right_;
        }
    }



    std::pair<const key_type, mapped_value>* allocatedKV = allocator_.allocate(1);
    allocator_.construct(allocatedKV, pair);

    node_type newNode = new Node(allocatedKV);
    newNode->parent_ = parent;

    if (parent == nullptr) {
        root_ = newNode;
    } else if (cmp_(pair.first, parent->data_->first)) {
        parent->left_ = newNode;
    } else {
        parent->right_ = newNode;
    }

    balanceInsert(newNode);

    length_++;
    iterator it = new Iterator(this, current, PROCESS);
    return std::make_pair(it, true);
}

template <class Key, class T, class Compare, class Allocator>
std::pair<typename RedBlackTree<Key, T, Compare, Allocator>::iterator, bool> RedBlackTree<Key, T, Compare, Allocator>::insert_or_assign(value_type pair) {
    std::pair<iterator, bool> result = insert(pair);
    if (!result.second) {
        result.first->setValue(pair.second);
    }
    return result;
}