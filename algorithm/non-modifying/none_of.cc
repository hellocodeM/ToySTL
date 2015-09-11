#include <predef.hpp>

template <class Iter, class Pred>
bool none_of(Iter first, Iter last, Pred pred) {
    for (; first != last; ++first)
        if (pred(*first))
            return false;
    return true;
}

int main() {
    std::array<int, 4> xs{1, 3, 5, 7};
    auto is_odd = [](int x) { return (x & 0x1) == 2; };
    
    assert(::none_of(xs.begin(), xs.end(), is_odd));
    return 0;
}
