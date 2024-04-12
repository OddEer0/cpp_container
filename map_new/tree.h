#ifndef S21_CONTAINERS_REDBLACKTREE_H_
#define S21_CONTAINERS_REDBLACKTREE_H_

#include <utility>
#include <cstddef>
#include <functional>
#include <optional>

#define RED 1
#define BLACK 0
#define START 0
#define PROCESS 1
#define END 2

namespace s21_test {
    template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>>
    class RedBlackTree {
    public:
        using key_type = Key;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using key_compare = Compare;
        using allocator_type = Allocator;
        using reference = key_type&;
        using const_reference = const key_type&;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;

        class Node {
        friend RedBlackTree;
        public:
            using node_type = Node*;

        private:
            key_type* data_;
            bool color_;
            node_type parent_;
            node_type left_;
            node_type right_;

        public:
            Node() : color_(BLACK) {};
            Node(Key val) : data_(val), color_(RED), parent_(nullptr), left_(nullptr), right_(nullptr) {};
            key_type getKey();
            node_type getLeft();
            node_type getRight();
            node_type getParent();
            bool isBlack();
            bool isRed();
            bool isLeftNode();
            bool isRightNode();
            int getChildrenCount();
            node_type getChildOrNull();
            bool isNotChild();
        };

        using node_type = Node*;

        class Iterator {
        private:
            RedBlackTree<Key, Compare, Allocator> *tree_;
            node_type node_;
            int position_;
            bool is_reverse_;

        public:
            Iterator(RedBlackTree<Key, Compare, Allocator> *tree, node_type node, int position = START, bool isReverse = false)
                : tree_(tree), node_(node), position_(position), is_reverse_(isReverse) {}
            ~Iterator() {};
            Iterator(const Iterator& other) = default;
            Iterator& operator=(const Iterator& other) = default;
            bool operator==(const Iterator& other);
            bool operator!=(const Iterator& other);
            Iterator next();
            Iterator prev();
            Iterator operator++();
            Iterator operator--();
            key_type operator*();
            key_type* operator->();
            node_type getNode();
            void start();
            void end();
            Iterator first();
            Iterator last();
        };

        using piterator = Iterator*;
        using iterator = Iterator;
        using const_iterator = const Iterator;
        using reverse_iterator = iterator;
        using const_reverse_iterator = const_iterator;

    private:
        node_type root_;
        size_type length_;
        key_compare cmp_;
        allocator_type allocator_;

        // Utils
        void clearRecursive(node_type node);

        // Balance tree
        void balanceInsert(node_type new_node);
        void leftRotate(node_type node);
        void rightRotate(node_type node);
        void swapNode(node_type to, node_type from, bool isNull);
        void balanceRemove(node_type node, bool isLeftNode);
        node_type getRightSwappedNode(node_type node);
        bool getColor(node_type node);

    public:
        // CONSTRUCTORS
        RedBlackTree();
        RedBlackTree(std::initializer_list<key_type> const &items);
        // На самом деле если скопировать по итератору. Она идентичной не будет по структуре. Для этого нужно делать специальный метод для копирования
        RedBlackTree(RedBlackTree &other);
        // Конструктор перемещение
        RedBlackTree(RedBlackTree&& other);
        // Деструктор
        ~RedBlackTree();
        // Оператор присваивания
        RedBlackTree& operator=(RedBlackTree &&other);
        // Оператор присваивания перемещения
        RedBlackTree& operator=(RedBlackTree &other);

        // PRINT
        std::string string();
        void output(node_type node, std::string prefix, bool isTail, std::string* str);

        // CAPACITY
        bool empty();
        size_type size();
        size_type max_size();

        // ELEMENT ACCESS
        node_type getNode(key_type &key);
        reference at(const_reference key);
        reference operator[](const_reference key);

        // ITERATOR
        node_type right();
        node_type left();
        iterator begin();
        iterator end();
        const_iterator cbegin();
        const_iterator cend();
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator crbegin();
        const_reverse_iterator crend();

        // MODIFIER
        void clear() {
            clearRecursive(root_);
            root_ = nullptr;
            length_ = 0;
        }
        std::pair<iterator, bool> insert( const key_type& value );
        template< class P >
        std::pair<iterator, bool> insert( P&& value );
        std::pair<iterator, bool> insert( key_type&& value );
        iterator insert( iterator pos, const key_type& value );
        template< class P >
        iterator insert( const_iterator pos, P&& value );
        iterator insert( const_iterator pos, key_type&& value );
        template< class InputIt >
        void insert( InputIt first, InputIt last );
        void insert( std::initializer_list<key_type> ilist );
        // insert_return_type insert( node_type&& nh );
        iterator insert( const_iterator pos, node_type&& nh );
        template<class R>
        void insert_range( R&& rg );
        template< class M >
        std::pair<iterator, bool> insert_or_assign( const Key& k, M&& obj );
        template< class M >
        std::pair<iterator, bool> insert_or_assign( Key&& k, M&& obj );
        template< class K, class M >
        std::pair<iterator, bool> insert_or_assign( K&& k, M&& obj );
        template< class M >
        iterator insert_or_assign( const_iterator hint, const Key& k, M&& obj );
        template< class M >
        iterator insert_or_assign( const_iterator hint, Key&& k, M&& obj );
        template< class K, class M >
        iterator insert_or_assign( const_iterator hint, K&& k, M&& obj );
        iterator erase( iterator pos );
        iterator erase( iterator first, iterator last );
        size_type erase( const Key& key );
        template< class K >
        size_type erase( K&& x );
        void swap( class other );
        node_type extract( const_iterator position );
        node_type extract( const Key& k );
        template< class K >
        node_type extract( K&& x );
        template< class C2 >

        // LOOKUP
        iterator find( const Key& key );
        const_iterator find( const Key& key ) const;
        template< class K >
        iterator find( const K& x );
        template< class K >
        const_iterator find( const K& x ) const;
        bool contains( const Key& key ) const;
        template< class K >
        bool contains( const K& x ) const;
        std::pair<iterator, iterator> equal_range( const Key& key );
        std::pair<const_iterator, const_iterator> equal_range( const Key& key ) const;
        template< class K >
        std::pair<iterator, iterator> equal_range( const K& x );
        template< class K >
        std::pair<const_iterator, const_iterator> equal_range( const K& x ) const;
        iterator lower_bound( const Key& key );
        const_iterator lower_bound( const Key& key ) const;
        template< class K >
        iterator lower_bound( const K& x );
        template< class K >
        const_iterator lower_bound( const K& x ) const;
        iterator upper_bound( const Key& key );
        const_iterator upper_bound( const Key& key ) const;
        template< class K >
        iterator upper_bound( const K& x );
        template< class K >
        const_iterator upper_bound( const K& x ) const;

        // OBSERVERS
        key_compare key_comp();
        allocator_type get_allocator();
    };

    #include "constructor.tpp"
    #include "balance.tpp"
    #include "node.tpp"
    #include "utils.tpp"
    #include "iterator.tpp"
    #include "observer.tpp"
    #include "print.tpp"
    #include "element_access.tpp"
    #include "capacity.tpp"
}

#endif