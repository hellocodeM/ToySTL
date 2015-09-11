#include <predef.hpp>

template <class Iter, class Pred>
Iter adjacent_find(Iter first, Iter last, Pred pred) {
    if (first == last) return last;
    for (auto next = first+1; next != last; ++first, ++next) {
        if (pred(*first, *next))
            return first;
    }
    return last;
}

int main() {
    std::string s = "123467";
    auto mis = ::adjacent_find(
            s.begin(), s.end(), 
            [](char l, char r) { return r - l != 1; });
    assert(*mis == '4');
    return 0;
}
