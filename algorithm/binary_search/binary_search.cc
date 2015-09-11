#include <predef.hpp>

template <class Iter, class T>
bool binary_search(Iter first, Iter last, T value) {
    while (first != last) {
        auto median = first + std::distance(first, last) / 2;
        if (*median == value)
            return true;
        else if (*median < value)
            first = median + 1;
        else 
            last = median - 1;
    }
    return false;
}

int main() {
    std::array<int, 8> xs{1, 2, 3, 5, 7, 8, 9, 10};
    assert(::binary_search(xs.begin(), xs.end(), 7));
    assert(!::binary_search(xs.begin(), xs.end(), 6));
    assert(::binary_search(xs.begin(), xs.end(), 10));
    assert(!::binary_search(xs.begin(), xs.end(), 12));
    return 0;
}
