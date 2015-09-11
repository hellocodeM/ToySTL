#include <predef.hpp>

template <class Iter, class Pred>
bool all_of(Iter first, Iter last, Pred pred) {
    for (; first != last; ++first)
        if (!pred(*first))
            return false;
    return true;
}

int main() {
    std::array<int, 4> xs{1, 3, 5, 7};
    auto is_even = [](int x) { return (x & 0x1) == 1; };

    assert(::all_of(xs.begin(), xs.end(), is_even));
    return 0;
}
