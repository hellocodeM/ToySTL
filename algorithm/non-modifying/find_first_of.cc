#include <predef.hpp>

template <class Iter1, class Iter2>
Iter1 find_first_of(
        Iter1 first1, Iter1 last1,
        Iter2 first2, Iter2 last2) {
    for (; first1 != last1; ++first1) {
        auto pos = std::find(first2, last2, *first1);
        if (pos != last2) 
            return first1;
    }
    return last1;
}

int main() {
    std::vector<int> xs1{1, 2, 3, 4, 5};
    std::vector<int> xs2{2, 4, 6};

    assert(::find_first_of(
                xs1.begin(), xs1.end(),
                xs2.begin(), xs2.end()) == xs1.begin() + 1);
    return 0;
}
