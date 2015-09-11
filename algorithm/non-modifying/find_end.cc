#include <predef.hpp>

template <class Input1, class Input2>
Input1 search_end(
        Input1 first1, Input1 last1,
        Input2 first2, Input2 last2) {
    Input1 res = last1;
    for (; first1 != last1; ++first1) {
        Input1 pos = std::search(
                first1, last1, first2, last2);
        if (pos == last1)
            break;
        else 
            res = pos;
    }
    return res;
}

int main() {
    std::string s = "how, now, now, how";
    std::string dst = "how";
    
    assert(std::search(
                s.begin(), s.end(),
                dst.begin(), dst.end()) == s.begin());
    assert(*::search_end(
                s.begin(), s.end(), 
                dst.begin(), dst.end()) == 'h');
    return 0;
}
