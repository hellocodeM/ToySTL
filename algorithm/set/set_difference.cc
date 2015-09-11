#include <predef.hpp>


template <class Iter1, class Iter2, class Output>
Output set_difference(Iter1 first1, Iter1 last1,
                    Iter2 first2, Iter2 last2,
                    Output out) {
    for (; first1 != last1; ++first1) {
        first2 = std::lower_bound(first2, last2, *first1);
        if (first2 == last2)
            return std::copy(first1, last1, out);
        else if (*first2 == *first1)
            ++first2;
        else 
            *out = *first1;
    }
    return out;
}

int main() {
    std::array<int, 7> xs1{1, 2, 5, 5, 5, 7, 9};
    std::array<int, 3> xs2{1, 3, 5};
    std::vector<int> ans{2, 5, 5, 7, 9};
    std::vector<int> res;
    
    ::set_difference(xs1.begin(), xs1.end(), xs2.begin(), xs2.end(), std::back_inserter(res));
    assert(res == ans);

    return 0;
}
