#include <predef.hpp>

template <class Input1, class Input2>
std::pair<Input1, Input2>
mismatch(
        Input1 first1, Input1 last1,
        Input2 first2, Input2 last2) {
    while (first1 != last1 && first2 != last2 && 
            *first1 == *first2)
        ++first1, ++first2;
    return std::make_pair(first1, first2);
}

int main() {
    std::string s = "shiths";
    auto mis = ::mismatch(s.begin(), s.end(), s.rbegin(), s.rend());
    assert(*mis.first == 'i');
    assert(*mis.second == 't');
    return 0;
}
