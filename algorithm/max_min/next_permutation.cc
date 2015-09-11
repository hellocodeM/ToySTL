#include <predef.hpp>

template <class Iter>
bool next_permutation(Iter first, Iter last) {
    Iter i = last;
    --i;
    while (true) {
        Iter next, j;
        next = i;
        --i;
        if (*i < *next) {
            j = last;
            while (!(*i < *--j))
                ;
            std::iter_swap(i, j);
            std::reverse(next, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

int main() {
    std::array<int, 4> xs;
    std::iota(xs.begin(), xs.end(), 1);
    
    do {
        ming::println(xs);
    } while (::next_permutation(xs.begin(), xs.end()));
    return 0;
}
