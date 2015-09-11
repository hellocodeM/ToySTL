#include <predef.hpp>

template <class Input1, class Input2, class Output>
Output set_union(
        Input1 first1, Input1 last1,
        Input2 first2, Input2 last2,
        Output out) {
    while (first1 != last1 || first2 != last2) {
        if (first1 == last1) 
            return std::copy(first2, last2, out);
        else if (first2 == last2)
            return std::copy(first1, last1, out);
        else if (*first1 == *first2) {
            *out++ = *first1++;
            ++first2;
        } else if (*first1 < *first2) 
            *out++ = *first1++;
        else
            *out++ = *first2++;
    }
    return out;
}

int main() {
    std::vector<int> xs1{1, 2, 3, 4, 5};
    std::vector<int> xs2{3, 4, 5, 6, 7};
    std::vector<int> ans{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> res;

    ::set_union(
            xs1.begin(), xs1.end(),
            xs2.begin(), xs2.end(),
            std::back_inserter(res));
    assert(res == ans);
    return 0;
}
