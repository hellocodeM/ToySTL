#include <predef.hpp>

template <class Iter>
bool prev_permutation(Iter first, Iter last) {
    Iter i = last;
    --i;
    while (true) {
        Iter next = i;
        --i;
        if (*i > *next) {
            Iter j = last;
            while (!(*i > *--j))
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
    std::vector<int> xs(4);
    std::iota(xs.rbegin(), xs.rend(), 1);
    do {
        ming::println(xs);
    } while (::prev_permutation(xs.begin(), xs.end()));
    return 0;
}
