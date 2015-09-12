#include <predef.hpp>

template <class Container>
auto begin(Container& c) {
    return c.begin();
}

template <class T, size_t N>
T* begin(T (&array)[N]) {
    return &array[0];
}

int main() {
    std::vector<int> xs1{1, 2, 3, 4};
    int xs2[4];

    assert(::begin(xs1) == xs1.begin());
    assert(::begin(xs2) == xs2);
    return 0;
}
