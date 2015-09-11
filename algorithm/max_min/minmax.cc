#include <predef.hpp>

template <class T, class Cmp = std::less<T>>
constexpr std::pair<const T&, const T&>
minmax(const T& lhs, const T& rhs, Cmp cmp = Cmp()) {
    if (cmp(lhs, rhs))
        return std::make_pair(lhs, rhs);
    return std::make_pair(rhs, lhs);
}

int main() {
    int x = 1, y = 2;
    auto min_max = std::minmax(x, y);
    assert(min_max.first == 1);
    assert(min_max.second == 2);
    return 0;
}
