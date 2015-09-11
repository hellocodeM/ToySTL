#include <predef.hpp>

template <class Iter,
         class T = typename std::iterator_traits<Iter>::value_type,
         class Cmp = std::less<T>>
Iter is_sorted_until(Iter first, Iter last, Cmp cmp = Cmp()) {
    --last;
    for (; first != last; ++first) {
        auto next = std::next(first);
        if (!cmp(*first, *(next)))
            return next;
    }
    ++last;
    return last;
}

int main() {
    {
        std::vector<int> vec = { 1, 2, 3, 4, -1, 5 };
        auto i = ::is_sorted_until(vec.begin(), vec.end());
        assert(*i == -1);
    }

    {
        std::vector<int> vec = {1, 2, 3};
        auto i = ::is_sorted_until(vec.begin(), vec.end());
        assert(i == vec.end());
    }
    return 0;
}
