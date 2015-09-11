#include <predef.hpp>

template <class Iter, 
         class T = typename std::iterator_traits<Iter>::value_type,
         class Cmp = std::less<T>>
constexpr std::pair<Iter, Iter> minmax_element(Iter first, Iter last, Cmp cmp = Cmp()) {
    if (first == last)
        return std::make_pair(last, last);
    Iter min = first, max = first;
    for (++first; first != last; ++first) {
        if (*first < *min)
            min = first;
        if (*first > *max)
            max = first;
    }
    return std::make_pair(min, max);
}
int main() {
    std::array<int, 4> xs{1, 2, 3, 4};

    auto min_max = ::minmax_element(xs.begin(), xs.end());
    assert(*min_max.first == 1);
    assert(*min_max.second == 4);
    return 0;
}
