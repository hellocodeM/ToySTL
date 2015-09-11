#include <predef.hpp>


template <class Iter, class T>
Iter remove(Iter first, Iter last, const T& value) {
    for (auto iter = first; iter != last; ++iter) {
        if (*iter != value)
            *first++ = *iter;
    }
    return first;
}

int main() {
    std::string str = "hey, *****.";
    
    assert(std::string(
                str.begin(), ::remove(str.begin(), str.end(), '*'))
            == "hey, .");
    return 0;
}
