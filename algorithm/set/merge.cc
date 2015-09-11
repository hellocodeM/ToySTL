#include <predef.hpp>

template <class Input, class Output>
Output merge(Input first1, Input last1,
            Input first2, Input last2,
            Output d_first) {
    auto iter_min = [](auto& x, auto& y) -> Input& {
        if (*x < *y) return x;
        return y;
    };
    while (first1 != last1 || first2 != last2) {
        if (first1 == last1) 
            return std::copy(first2, last2, d_first);
        else if (first2 == last2) 
            return std::copy(first1, last1, d_first);
        else {
            Input& min = iter_min(first1, first2);
            *d_first++ = *min++;
        }
    }
    return d_first;
}
int main() {
    std::array<int, 4> xs1{1, 3, 5, 7};
    std::array<int, 4> xs2{2, 4, 6, 8};
    std::vector<int> xs3;
    std::vector<int> res{1, 2, 3, 4, 5, 6, 7, 8 };

    {
        ::merge(xs1.begin(), xs1.end(), xs2.begin(), xs2.end(), std::back_inserter(xs3));
        assert(xs3 == res);
    }
    return 0;
}
