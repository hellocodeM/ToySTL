#include <predef.hpp>

int main() {
    int a = 1, b = 2;
    int xs1[5] = {1, 3, 5, 7, 9};
    int xs2[5] = {2, 4, 6, 8, 10};

    std::swap(a, b);
    assert(a == 2);
    assert(b == 1);

    std::swap(xs1, xs2);
    return 0;
}
