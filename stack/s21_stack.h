#ifndef S21_CONTAINERS_STACK_H_
#define S21_CONTAINERS_STACK_H_

#include "../list/s21_list.h"

namespace s21 {
    template <class T, class Container = s21::list<T>>
    class stack {
    public:
        using reference = Container::reference;
        using const_reference = Container::const_reference;
        using size_type = Container::size_type;
        using value_type = Container::value_type;

    private:
        Container container_;

    public:
        stack();
        ~stack();

        reference top();
        const_reference top();

        bool empty();
        size_type size();

        void push(const value_type& value);
        void push(value_type&& value);
        void pop();
        template<class R>
        void push_range(R&& rg);
        void swap (stack & Other);
    };
}

#endif