template <class Key, class T, class Compare, class Allocator>
RedBlackTree<Key, T, Compare, Allocator>::RedBlackTree()
    : root_(nullptr), length_(0), cmp_(Compare()), allocator_(Allocator()) {}

template <class Key, class T, class Compare, class Allocator>
RedBlackTree<Key, T, Compare, Allocator>::RedBlackTree(std::initializer_list<value_type> const &items) 
    : root_(nullptr), length_(0), cmp_(Compare()), allocator_(Allocator()) {
    for (value_type item : items) {
        insert(item);
    }
}