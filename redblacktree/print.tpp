template <class Key, class T, class Compare, class Allocator>
std::string RedBlackTree<Key, T, Compare, Allocator>::string() {
    std::string str = "RedBlackTree\n";
    if (!empty()) {
        output(root_, "", true, &str);
    }

    return str;
}

template <class Key, class T, class Compare, class Allocator>
void RedBlackTree<Key, T, Compare, Allocator>::output(node_type node, std::string prefix, bool isTail, std::string* str) {
    if (node->right_ != nullptr) {
        std::string newPrefix = prefix;
        if (isTail) {
            newPrefix += "│   ";
        } else {
            newPrefix += "    ";
        }
        output(node->right_, newPrefix, false, str);
    }
    *str += prefix;
    if (isTail) {
        *str += "└── ";
    } else {
        *str += "┌── ";
    }
    if (node->data_ != nullptr) {
        *str += "Color: " + std::string(node->color_ == BLACK ? "BLACK" : "RED") + ", Key: " + std::to_string(node->data_->first) + ", Value: " + std::to_string(node->data_->second) + "\n";
    } else {
        *str += "NULL\n";
    }
    if (node->left_ != nullptr) {
        std::string newPrefix = prefix;
        if (isTail) {
            newPrefix += "    ";
        } else {
            newPrefix += "│   ";
        }
        output(node->left_, newPrefix, true, str);
    }
}