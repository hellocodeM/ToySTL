#include <predef.hpp>

template <class Input1, class Input2>
Input1 search(
        Input1 first1, Input1 last1,
        Input2 first2, Input2 last2) {
    for (; first1 != last1; ++first1)
        if (std::equal(first1, last1, first2, last2))
            return first1;
    return last1;
}

template <class Input1, class Input2>
Input1 kmp_search(
        Input1 first1, Input1 last1,
        Input2 first2, Input2 last2) {
    
}

int main() {
    std::string s1 = "wow, how, now";
    std::string s2= "now";
    std::string s3 = "ri";
    assert(*::search(
                s1.begin(), s1.end(), 
                s2.begin(), s2.end()) == 'n');
    assert(::search(
                s1.begin(), s1.end(),
                s3.begin(), s3.end()) == s1.end());
    
    return 0;
}
