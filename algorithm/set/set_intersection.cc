#include <predef.hpp>

template <class Input1, class Input2, class Output>
Output set_intersection(Input1 first1, Input1 last1, 
                        Input2 first2, Input2 last2,
                        Output out) {
    for (; first1 != last1; ++first1) {
        first2 = std::lower_bound(first2, last2, *first1);
        if (first2 == last2 || *first2 != *first1)
            ;
        else {
            *out++ = *first1;
            ++first2;
        }
    }
    return out;
}
int main() {
    std::array<int, 5> xs1{1, 2, 3, 3, 5};
    std::array<int, 3> xs2{2, 3, 4};
    std::vector<int> ans{2, 3};
    std::vector<int> res;

    ::set_intersection(xs1.begin(), xs1.end(), xs2.begin(), xs2.end(), std::back_inserter(res));
    assert(res == ans);
    return 0;
}
