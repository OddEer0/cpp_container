#ifndef S21_CONTAINERS_STACK_H_
#define S21_CONTAINERS_STACK_H_

#include <utility>
#include <cstddef>
#include <functional>
#include <optional>

#define RED 1
#define BLACK 0
#define START 0
#define PROCESS 1
#define END 2

namespace s21 {
    template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>>
    class RedBlackTree {
    public:
        using key_type = Key;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using key_compare = Compare;
        using allocator_type = Allocator;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;

        class Node {
        friend RedBlackTree;
        public:
            using node_type = Node*;

        private:
            Key *data_;
            bool color_;
            node_type parent_;
            node_type left_;
            node_type right_;

        public:
            Node() : color_(BLACK) {};
            Node(Key val) : data_(val), color_(RED), parent_(nullptr), left_(nullptr), right_(nullptr) {};
            key_type getKey() {
                return data_;
            };
            node_type getLeft() {
                return left_;
            }
            node_type getRight() {
                return right_;
            }
            node_type getParent() {
                return parent_;
            }
            bool isBlack() {
                return color_ == BLACK;
            }
            bool isRed() {
                return color_ == RED;
            }
            bool isLeftNode() {
                return parent_->left_ == this;
            }
            bool isRightNode() {
                return parent_->right_ == this;
            }
            int getChildrenCount() {
                int result = 0;
                if (right_ != nullptr) {
                    result++;
                }
                if (left_ != nullptr) {
                    result++;
                }
                return result;
            }
            node_type getChildOrNull() {
                if (left_ != nullptr) {
                    return left_;
                }
                if (right_ == nullptr) {
                    return new Node();
                }
                return right_;
            }
            bool isNotChild() {
                if (left_ == nullptr && right_ == nullptr) {
                    return true;
                }
                return false;
            }
        };

        using node_type = Node*;

        class Iterator {
        private:
            RedBlackTree<Key, Compare, Allocator> *tree_;
            node_type node_;
            int position_;
            bool is_reverse_;

        public:
            Iterator(RedBlackTree<Key, T, Compare, Allocator> *tree, node_type node, int position = START, bool isReverse = false)
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
            T& operator*();
            T* operator->();
            node_type getNode();

            void start();
            void end();
            Iterator first();
            Iterator last();
        };
    };

    #include "iterator.tpp"
}

#endif