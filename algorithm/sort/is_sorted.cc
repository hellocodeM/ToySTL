#include <predef.hpp>

template <class Iter, class T = typename std::iterator_traits<Iter>::value_type,
         class Cmp = std::less<T>>
bool is_sorted(Iter first, Iter last, Cmp cmp = Cmp()) {
    --last;
    for (; first != last; ++first) {
        if (!cmp(*first, *(first + 1)))
            return false;
    }
    return true;
}

int main() {
    std::vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 1);
    
    assert(::is_sorted(vec.begin(), vec.end()));
    std::reverse(vec.begin(), vec.end());
    assert(::is_sorted(vec.rbegin(), vec.rend()));
    return 0;
}
