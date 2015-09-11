#include <predef.hpp>

template <class Iter>
void reverse(Iter first, Iter last) {
    if (last - first <= 1)
        return;
    for (--last; first < last; ++first, --last)
        std::iter_swap(first, last);
}

int main() {
    std::string str = "no";
    ::reverse(str.begin(), str.end());

    assert(str == "on");
    return 0;
}
