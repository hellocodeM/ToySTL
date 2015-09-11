#include <predef.hpp>

template <class Iter>
Iter unique(Iter first, Iter last) {
    for (Iter iter = first+1; iter != last; ++iter) {
        if (*iter != *first)
            *++first = *iter;
    }
    return ++first;
}

int main() {
    std::array<int, 8> xs{1, 2, 3, 3, 4, 5, 5,5};
    
    auto last = ::unique(xs.begin(), xs.end());
    std::copy(xs.begin(), last, std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
