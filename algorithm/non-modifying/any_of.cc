#include <predef.hpp>

template <class Iter, class Pred>
bool any_of(Iter first, Iter last, Pred pred) {
    for (; first != last; ++first)
        if (pred(*first))
            return true;
    return false;
}

int main() {
    std::array<int, 4> xs{1, 2, 3, 5};
    auto is_odd = [](int x) { return (x & 0x1) == 0; };

    assert(::any_of(xs.begin(), xs.end(), is_odd));
    return 0;
}
