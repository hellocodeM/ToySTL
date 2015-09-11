#include <predef.hpp>

template <class Iter, class Pred>
Iter partition_point(Iter first, Iter last, Pred pred) {
    while (first != last && pred(*first))
        ++first;
    return first;
}
int main() {
    std::vector<int> vec = {4, 6, 8, 1, 2, 5, 7, 3 };
    
    std::partition(vec.begin(), vec.end(), [](int x) { return x < 5; });
    auto pivot = ::partition_point(vec.begin(), vec.end(), [](int x) { return x < 5; });

    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    ming::println(*pivot);
    return 0;
}
