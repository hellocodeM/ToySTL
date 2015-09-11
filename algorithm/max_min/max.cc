#include <predef.hpp>

template <class T, class Cmp = std::less<T>>
constexpr const T& max(const T& lhs, const T& rhs, Cmp cmp = Cmp()) {
    return cmp(lhs, rhs) ? rhs : lhs;
}

template <class T, class Cmp = std::less<T>>
constexpr T max(std::initializer_list<T> ilist, Cmp cmp = Cmp()) {
    return *std::max_element(ilist.begin(), ilist.end(), cmp);
}

int main() {
    int x = 1, y = 2;
    assert(::max(x, y) == 2);
    assert(::max({1, 2, 3, 4}) == 4);
    
    return 0;
}
