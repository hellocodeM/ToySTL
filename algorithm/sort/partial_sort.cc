#include <predef.hpp>

template <class Iter,
         class T = typename std::iterator_traits<Iter>::value_type,
         class Cmp = std::less<T>>
void partial_sort(Iter first, Iter middle, Iter last, Cmp cmp = Cmp()) {
    auto dis = std::distance(first, last);
    if (dis < 5) {
        for (; first != last; ++first)
           for (auto j = std::next(first); j != last; ++j)
                if (!cmp(*first, *j))
                    std::iter_swap(first, j);
    } else {
        auto median = [](T x, T y, T z) {
            return std::min(x, std::max(y, z));
        };
        auto pivot = median(*first, *std::prev(last), *(first + dis/2));
        auto i = std::partition(first, last, [=](T x) { return cmp(x, pivot); });
        std::sort(first, i, cmp);
        if (i < middle) 
            std::partial_sort(i, middle, last, cmp);
    }
}

int main() {
    std::array<int, 9> xs{5, 7, 4, 3, 6, 8, 1, 2, 0};
    ::partial_sort(xs.begin(), xs.begin() + 3, xs.end());
    for (int i : xs)
        std::cout << i << " ";
    std::cout << std::endl;
    {
        constexpr size_t size = 12345678;
        std::vector<int> xs(size);
        std::iota(xs.rbegin(), xs.rend(), 1);
        
        std::random_shuffle(xs.begin(), xs.end());
        ming::println(DurationTime((std::sort(xs.begin(), xs.end()))));

        std::random_shuffle(xs.begin(), xs.end());
        ming::println(DurationTime((std::partial_sort(xs.begin(), xs.begin()+100, xs.end()))));
        assert(std::is_sorted(xs.begin(), xs.begin()+100));

        std::random_shuffle(xs.begin(), xs.end());
        ming::println(DurationTime((::partial_sort(xs.begin(), xs.begin()+100, xs.end()))));
        assert(std::is_sorted(xs.begin(), xs.begin()+100));
    }
}
