#include <predef.hpp>

template <class Iter, 
         class T = typename std::iterator_traits<Iter>::value_type, 
         class Cmp = std::less<T>>
constexpr Iter max_element(Iter first, Iter last, Cmp cmp = Cmp()) {
    Iter max_iter = first;
    for (++first; first != last; ++first) {
        if (cmp(*max_iter, *first))
            max_iter = first;
    }
    return max_iter;
}


int main() {
    std::array<int, 4> xs{1, 2, 3, 4};
    assert(*std::max_element(xs.begin(), xs.end()) == 4);
    return 0;
}
