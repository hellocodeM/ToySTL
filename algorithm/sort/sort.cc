#include <predef.hpp>

template <class Iter,
         class T = typename std::iterator_traits<Iter>::value_type,
         class Cmp = std::less<T>>
void sort(Iter first, Iter last, Cmp cmp = Cmp()) {
    auto dis = std::distance(first, last);
    if (dis < 10) {
        for (; first != last && first+1 != last; ++first) {
            auto min = std::min_element(first+1, last, cmp);
            if (cmp(*min, *first))
                std::iter_swap(min, first);
        }
    } else { 
        auto median = [](T x, T y, T z) {
            return std::min(x, std::max(y, z));
        };
        auto pivot = median(*first, *(prev(last)), *(first + dis / 2));
        auto i = std::partition(first, last, [=](T x) { return cmp(x, pivot); });
        ::sort(first, i, cmp);
        ::sort(i+1, last, cmp);
    }
}
int main() {
    {
        std::vector<int> vec = { 5, 4, 3, 2, 1};
        
        ::sort(vec.begin(), vec.end());
        assert(std::is_sorted(vec.begin(), vec.end()));
    }
    {
        constexpr size_t size = 12345;
        std::vector<int> v(size);
        std::iota(v.rbegin(), v.rend(), 1);
        ming::println(DurationTime((std::sort(v.begin(), v.end()))));
        std::iota(v.rbegin(), v.rend(), 1);
        ming::println(DurationTime((::sort(v.begin(), v.end()))));
    }
    return 0;
}
