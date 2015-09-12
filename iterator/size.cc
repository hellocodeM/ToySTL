#include <predef.hpp>

template <class Container>
constexpr auto size(const Container& c) {
    return c.size();
}

template <class T, size_t N>
constexpr size_t size(T (&array)[N]) {
    return N;
}

int main() {
    std::vector<int> xs1{1, 2, 3};
    int xs2[3];

    assert(::size(xs1) == 3);
    assert(::size(xs2) == 3);
    return 0;
}
