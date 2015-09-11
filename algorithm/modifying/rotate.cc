#include <predef.hpp>

template <class Iter>
void rotate(Iter first1, Iter first2, Iter last1) {
    Iter next = first2;
    while (first1 != next) {
        std::iter_swap(first1++, next++);
        if (next == last1)
            next = first2;
        else if (first1 == first2)
            first2 = next;
    }
}

int main() {
    std::string str = "shit, fuck";
    ::rotate(str.begin(), str.begin()+6, str.end());
    assert(str == "fuckshit, ");
    return 0;
}
