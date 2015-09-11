#include <predef.hpp>

template <class Iter>
void random_shuffle(Iter first, Iter last) {
    for (; first != last; ++first) {
        auto dis = last - first;
        std::swap(*first, first[std::rand() % dis]);
    }
}

int main() {
    std::array<int, 9> xs;
    std::iota(xs.begin(), xs.end(), 1);
    
    ::random_shuffle(xs.begin(), xs.end());
    ming::println(xs);
}
