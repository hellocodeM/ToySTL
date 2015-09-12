#include <predef.hpp>

template <class Forward>
auto distance_impl(Forward first, Forward last, std::forward_iterator_tag) {
    typename std::iterator_traits<Forward>::difference_type dis(0);
    for (; first != last; ++first)
        ++dis;
    return dis;
}

template <class Random>
auto distance_impl(Random first, Random last, std::random_access_iterator_tag) {
    return last - first;
}

template <class Iter>
auto distance(Iter first, Iter last) {
    return ::distance_impl(first, last, typename std::iterator_traits<Iter>::iterator_category());
}


int main() {
    std::string s = "shit";
    std::list<int> list{1, 2, 3, 4};

    assert(::distance(s.begin(), s.end()) == 4);
    assert(::distance(list.begin(), list.end()) == 4);
    return 0;
}
