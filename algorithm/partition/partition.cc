#include <predef.hpp>


template <class Iter, class Pred>
Iter partition(Iter first, Iter last, Pred pred) {
    --first;
    while (true) {
        while (first != last && pred(*++first));
        while (first != last && !pred(*--last));
        if (first == last) break;
        std::iter_swap(first, last);
    }
    return first;
}

template <class Iter, class Pred>
bool is_partitioned(Iter first, Iter last, Pred pred) {
    for (; first != last; ++first) 
        if (!pred(*first)) break;
    for (; first != last; ++first)
        if (pred(*first)) return false;
    return true;
}

template <class InputIterator, class OutputIterator, class Pred>
std::pair<OutputIterator, OutputIterator> 
    partition_copy(InputIterator first, InputIterator last, 
                    OutputIterator output_true, OutputIterator output_false, Pred pred) {
        
        for (; first != last; ++first) {
            if (pred(*first))
                *output_true++ = *first;
            else
                *output_false++ = *first;
        }
        return std::make_pair(output_true, output_false);
    }


template <class Iter, class T = typename std::iterator_traits<Iter>::value_type, class Pred = std::less<T>>
void sort(Iter first, Iter last, Pred pred = Pred()) {
    if (std::distance(first, last) <= 1) 
        return;
    auto delim = *first;
    auto pivot = std::partition(first, last, [=](auto x){ return pred(x, delim); });
    if (first < pivot)
        ::sort(first, pivot, pred);
    if (pivot + 1 < last)
        ::sort(std::next(pivot), last, pred);
}

int main() {
    std::vector<int> num = { 8, 7, 6, 5, 4, 3, 2, 1};
    
    auto pivot = ::partition(num.begin(), num.end(), [](int x) { return x < 5; });
    std::copy(num.begin(), pivot, std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::copy(pivot, num.end(), std::ostream_iterator<int>(std::cout, " "));

    ming::println(::is_partitioned(num.begin(), num.end(), [](int x ){ return x < 5; }));

    /* partition_copy */
    std::vector<int> v1, v2;
    ::partition_copy(
            num.begin(), num.end(), 
            std::back_inserter(v1),
            std::back_inserter(v2),
            [](int x) { return x < 7; });
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}

