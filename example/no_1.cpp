#include "main.h"

// void run() {
//     s21::vector<int*> cn;
//     auto val = new int;
//     *val = 2;
//     cn.push_back(val);
// }

// ------------------------

// void run() {
//     s21::vector<int*> cn;
//     auto val = new int;
//     *val = 2;
//     cn.push_back(val);
//     // clear
//     delete val;
//     val = nullptr;
// }

// ------------------------

template<typename T>
class MyAllocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    MyAllocator() noexcept {}

    template<typename U>
    MyAllocator(const MyAllocator<U>&) noexcept {}

    pointer allocate(size_type n) {
        std::cout << "Allocating memory for " << n << " elements" << std::endl;
        return static_cast<pointer>(::operator new(n * sizeof(T)));
    }

    void deallocate(pointer p, size_type n) noexcept {
        std::cout << "Deallocating memory for " << n << " elements" << std::endl;
        ::operator delete(p);
    }

    pointer address(reference x) const noexcept {
        return std::addressof(x);
    }

    const_pointer address(const_reference x) const noexcept {
        return std::addressof(x);
    }

    size_type max_size() const noexcept {
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    void construct(pointer p, const T& val) {
        new(static_cast<void*>(p)) T(val);
    }

    void destroy(pointer p) {
        p->~T();
    }
};


void run() {
    s21::vector<int*> cn;
    auto val = new int;
    *val = 2;
    cn.push_back(val);
}