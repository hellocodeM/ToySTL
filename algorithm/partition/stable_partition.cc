#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

#include <ming/all.hpp>

template <class Iter, class Pred>
Iter stable_partition(Iter first, Iter last, Pred pred) {
    using value_type = typename std::iterator_traits<Iter>::value_type;
    std::vector<value_type> v1, v2;
    for (auto iter = first; iter != last; ++iter) {
        if (pred(*iter))
            v1.push_back(*iter);
        else
            v2.push_back(*iter);
    }
    auto res = std::copy(v1.begin(), v1.end(), first);
    std::copy(v2.begin(), v2.end(), res);
    return res;
}

int main() {
    std::vector<int> vec = {0, 0, 2, 0, 3, 0, 5 };
    ::stable_partition(vec.begin(), vec.end(), [](int x) { return x > 0; });
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
