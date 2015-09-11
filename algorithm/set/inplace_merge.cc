#include <predef.hpp>

template <class Iter, class T = typename std::iterator_traits<Iter>::value_type>
void inplace_merge(Iter first, Iter middle, Iter last) {
    std::vector<T> buff(first, last);
    std::merge(first, middle, middle, last, buff.begin());
    std::copy(buff.begin(), buff.end(), first);
}


int main() {
    std::array<int, 8> xs{1, 3, 5, 7, 2, 4, 6, 8};

    ::inplace_merge(xs.begin(), xs.begin() + 4, xs.end());
    assert(std::is_sorted(xs.begin(), xs.end()));
    return 0;
}
