#include <predef.hpp>

template <class Iter1, class Iter2>
bool is_permutation(
        Iter1 first1, Iter1 last1, 
        Iter2 first2, Iter2 last2) {
    for (; first1 != last1; ++first1) {
        if (std::count(first1, last1, *first1) != 
            std::count(first2, last2, *first1))
            return false;
    }
    return true;
}

int main() {
    std::array<int, 4> xs{1, 2, 2, 3};
    
    
    std::random_shuffle(xs.begin(), xs.end());
    assert(std::is_permutation(xs.begin(), xs.end(), xs.begin()));
    return 0;
}
