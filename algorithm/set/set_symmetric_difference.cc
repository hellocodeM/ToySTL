#include <predef.hpp>

template <class Input1, class Input2, class Output, 
         class T = typename std::iterator_traits<Input1>::value_type>
Output set_symmetric_difference(
        Input1 first1, Input1 last1,
        Input2 first2, Input2 last2,
        Output out) {
    std::vector<T> intersect;
    std::set_intersection(first1, last1, first2, last2, std::back_inserter(intersect));
    for (; first1 != last1; ++first1) 
        if (!std::binary_search(intersect.begin(), intersect.end(), *first1))
            *out++ = *first1;
    for (; first2 != last2; ++first2)
        if (!std::binary_search(intersect.begin(), intersect.end(), *first2))
            *out++ = *first2;
    return out;
}
int main() {
    std::array<int, 5> xs1{1, 2, 3, 4, 5};
    std::array<int, 5> xs2{4, 5, 6, 7, 8};
    std::vector<int> ans{1, 2, 3, 6, 7, 8};
    std::vector<int> res;

    ::set_symmetric_difference(
            xs1.begin(), xs1.end(), 
            xs2.begin(), xs2.end(), 
            std::back_inserter(res));
    assert(res == ans);
    return 0;
}
