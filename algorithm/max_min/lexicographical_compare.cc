#include <predef.hpp>

template <class Input1, class Input2>
constexpr bool lexicographical_compare(
        Input1 first1, Input1 last1,
        Input2 first2, Input2 last2) {
    for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
        if (*first1 < *first2) return true;
        if (*first2 < *first1) return false;
    }
    return first1 == last1 && first2 != last2;
}

int main() {
    std::string x = "shit";
    std::string y = "shitfuck";
    
    assert(::lexicographical_compare(
                x.begin(), x.end(),
                y.begin(), y.end()));
    return 0;
}
