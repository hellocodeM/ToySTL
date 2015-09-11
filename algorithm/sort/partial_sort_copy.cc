#include <predef.hpp>

template <class Iter,
         class OutputIter,
         class T = typename std::iterator_traits<Iter>::value_type,
         class Cmp = std::less<T>>
void partial_sort_copy(Iter first, Iter last, OutputIter d_first, OutputIter d_last, Cmp cmp = Cmp()) {
    auto s_dis = std::distance(first, last);
    auto d_dis = std::distance(d_first, d_last);
    if (s_dis <= d_dis) {
        std::copy(first, last, d_first);
        std::sort(d_first, d_last);
    } else {
        std::vector<T> garbage;
        auto median = [](T x, T y, T z) {
            return std::min(x, std::max(y, z));
        };
        auto pivot = median(*first, *(std::prev(last)), *(first + s_dis / 2));
        auto i = std::partition_copy(first, last, d_first, std::back_inserter(garbage), [=](T x) { return cmp(x, pivot); });
        std::sort(d_first, i.first, cmp);
        ::partial_sort_copy(garbage.begin(), garbage.end(), i.first, d_last, cmp);
        std::sort(i.first, d_last, cmp);
    }
}

int main() {
    TestBlock {
        std::array<int, 8> xs{5, 3, 2, 1, 8, 6, 4, 7};
        std::array<int, 3> res;

        ::partial_sort_copy(xs.begin(), xs.end(), res.begin(), res.end());
        for (auto i : res)
            std::cout << i << " ";
        std::cout << " ";
        assert(std::is_sorted(res.begin(), res.end()));
    }
    return 0;
}
