template <class Key, class T, class Compare, class Allocator>
typename RedBlackTree<Key, T, Compare, Allocator>::key_compare RedBlackTree<Key, T, Compare, Allocator>::key_comp() {
    return cmp_;
}

template <class Key, class T, class Compare, class Allocator>
typename RedBlackTree<Key, T, Compare, Allocator>::key_compare RedBlackTree<Key, T, Compare, Allocator>::value_comp() {
    return cmp_;
}

template <class Key, class T, class Compare, class Allocator>
typename RedBlackTree<Key, T, Compare, Allocator>::allocator_type RedBlackTree<Key, T, Compare, Allocator>::get_allocator() {
    return allocator_;
}