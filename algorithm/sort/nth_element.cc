#include <predef.hpp>

template <class Iter,
         class T = typename std::iterator_traits<Iter>::value_type,
         class Cmp = std::less<T>>
void nth_element(Iter first, Iter middle, Iter last, Cmp cmp = Cmp()) {
    auto dis = std::distance(first, last);
    if (dis <= 1)
        return;
    auto pivot = *first;
    auto i = std::partition(first, last, [=](T x) { return cmp(x, pivot); });
    if (first < i && i < middle)
        ::nth_element(i, middle, last, cmp);
    else if (i < last){
        ::nth_element(first, middle, i, cmp);
    }
}

int main() {
    std::array<int, 8> xs{1, 2, 3, 4, 5, 6, 7};
    
    std::random_shuffle(xs.begin(), xs.end());
    ::nth_element(xs.begin(), xs.begin() + 3, xs.end());
    ming::println(*(xs.begin()+3));
    return 0;
}
