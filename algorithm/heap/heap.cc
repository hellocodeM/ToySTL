#include <predef.hpp>

template <class Iter>
void make_heap(Iter first, Iter last) {

}

template <class Iter>
void push_heap(Iter first, Iter last) {
    --last;
    auto prev = last;
    prev = first + (last - first) / 2;
    while (last != first && *prev < *last) {
        std::iter_swap(prev, last);
        last = prev;
        prev = first + (std::distance(first, prev) - 1) / 2;
    }
}

template <class Iter>
void pop_heap(Iter first, Iter last) {
    if (std::distance(first, last) <= 1) return;
    --last;
    std::iter_swap(first, last);
    auto iter = first;
    while (iter < last) {
        auto succ = first + (std::distance(first, iter) + 1) * 2 - 1;
        if (succ >= last) break;
        auto right = succ+1;
        if (right < last && *succ < *right)
            succ = right;
        if (*iter < *succ)
            std::iter_swap(succ, iter);
        iter = succ;
    }
}

template <class Iter>
void sort_heap(Iter first, Iter last) {
    while (first != last)
        ::pop_heap(first, last--);
}

template <class Iter>
bool is_heap_impl(Iter first, Iter iter, Iter last) {
    auto left = first + (std::distance(first, iter) + 1) * 2 - 1;
    auto right = left + 1;
    bool heap_order = true;
    if (left < last)
        heap_order = heap_order && *iter > *left && is_heap_impl(first, left, last);
    if (right < last)
        heap_order = heap_order && *iter > *right && is_heap_impl(first, right, last);
    return heap_order;
}

template <class Iter>
bool is_heap(Iter first, Iter iter) {
    return is_heap_impl(first, first, iter);
}

int main() {
    std::vector<int> vec(5);
    std::iota(vec.begin(), vec.end(), 1);
    ming::println(vec);

    // make heap
    // 5, 4, 3, 1, 2
    std::make_heap(vec.begin(), vec.end());
    ming::println(vec);
    
    // heap push
    // 6, 4, 5, 1, 2, 3
    vec.push_back(6);
    ::push_heap(vec.begin(), vec.end());
    assert((vec == std::vector<int>{6, 4, 5, 1, 2, 3} && "push_heap"));
    ming::println(vec);

    // heap pop
    // 5, 4, 3, 1, 2, 6
    ::pop_heap(vec.begin(), vec.end());
    assert((vec == std::vector<int>{5, 4, 3, 1, 2, 6} && "pop_heap"));
    ming::println(vec);

    // is_heap
    ::push_heap(vec.begin(), vec.end());
    ming::println(vec);
    assert((::is_heap(vec.begin(), vec.end())));
    // sort heap
    // 1, 2, 3, 4, 5, 6
    ::sort_heap(vec.begin(), vec.end());
    ming::println(vec);
    assert((std::is_sorted(vec.begin(), vec.end())));
    return 0;
}
