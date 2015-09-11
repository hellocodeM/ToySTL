#include <predef.hpp>

template <class Iter1, class Iter2>
bool includes(Iter1 first1, Iter1 last1,
            Iter2 first2, Iter2 last2) {
    for (; first2 != last2; ++first2) {
        first1 = std::lower_bound(first1, last1, *first2);
        if (*first1 != *first2 || first1 == last1) return false;
    }
    return true;
}

int main() {
    std::array<int, 5> xs1{1, 2, 3, 4, 5};
    std::array<int, 4> xs2{1, 2, 3, 4};

    assert(::includes(xs1.begin(), xs1.end(), 
                xs2.begin(), xs2.end()));
    return 0;
}
