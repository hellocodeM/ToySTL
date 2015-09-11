#include <predef.hpp>

template <class Iter, class T>
std::pair<Iter, Iter> equal_range(Iter first, Iter last, T value) {
    return std::make_pair(
            std::lower_bound(first, last, value),
            std::upper_bound(first, last, value));
}

int main() {
    std::array<int, 8> xs{1, 2, 3, 4, 4, 4, 5, 8};
    
    auto lower_upper = ::equal_range(xs.begin(), xs.end(), 4);
    assert(lower_upper.first - xs.begin() == 3);
    assert(lower_upper.second -xs.begin() == 6);
    return 0;
}
