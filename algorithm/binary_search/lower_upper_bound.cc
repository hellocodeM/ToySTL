#include <predef.hpp>

template <class Iter, class T>
Iter lower_bound(Iter first, Iter last, T dest) {
    while (first != last) {
        auto median = first + std::distance(first, last) / 2;
        if (*median < dest)
            first = median + 1;
        else
            last = median;
    }
    return first;
}

template <class Iter, class T>
Iter upper_bound(Iter first, Iter last, T dest) {
    while (first != last) {
        auto median = first + std::distance(first, last) / 2;
        if (*median <= dest)
            first = median + 1;
        else
            last = median;
    }
    return first;
}

int main() {
    std::array<int, 10> xs{1, 2, 3, 4, 4, 4, 6, 7, 8, 9};
    
    {
        auto lb = ::lower_bound(xs.begin(), xs.end(), 4);
        auto ub = ::upper_bound(xs.begin(), xs.end(), 4);
        assert(lb - xs.begin() == 3);
        assert(ub - xs.begin() == 6);
    }

    {
        auto lb = ::lower_bound(xs.begin(), xs.end(), 5);
        auto ub = ::upper_bound(xs.begin(), xs.end(), 5);
        assert(lb - xs.begin() == 6);
        assert(ub - xs.begin() == 6);
    }
    
    return 0;
}
