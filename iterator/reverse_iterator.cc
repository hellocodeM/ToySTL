#include <predef.hpp>

template <class Iterator>
class reverse_iterator {
    /* constructor */
    public:
        using value_type = typename std::iterator_traits<Iterator>::value_type;
        using difference_type = typename std::iterator_traits<Iterator>::difference_type;
        using pointer = typename std::iterator_traits<Iterator>::pointer;
        using reference= typename std::iterator_traits<Iterator>::reference;
        using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;
        using iterator = reverse_iterator<Iterator>;

        /* construct */
        explicit reverse_iterator(Iterator i): iter_(--i) {
        }

        /* copy construct */
        reverse_iterator(const reverse_iterator& rhs) = default;
        
        reverse_iterator& operator=(const reverse_iterator& rhs) = default;

        /* reference and dereference */
        Iterator base() const {
            Iterator res(iter_);
            ++res;
            return res;
        }

        reference operator* () {
            return *iter_;
        }

        Iterator operator ->() {
            return iter_;
        }

        /* iterate operation */
        reverse_iterator& operator++() {
            --iter_;
            return *this;
        }

        reverse_iterator& operator++(int) {
            iterator tmp(*this);
            --iter_;
            return tmp;
        }

        reverse_iterator& operator --() {
            ++iter_;
            return *this;
        }

        reverse_iterator& operator --(int) {
            iterator tmp(*this);
            ++iter_;
            return tmp;
        }

        /* comparation */
        friend bool operator == (const iterator& lhs, const iterator& rhs) {
            return lhs.iter_ == rhs.iter_;
        }

        friend bool operator !=(const iterator& lhs, const iterator& rhs) {
            return lhs.iter_ != rhs.iter_;
        }
        

    private:
    Iterator iter_;
};


template <class Iterator>
::reverse_iterator<Iterator>
make_reverse_iterator(Iterator i) {
    return ::reverse_iterator<Iterator>(i);
}

int main() {
    std::string s = "shit";
    
    auto rbegin = ::make_reverse_iterator(s.end());
    auto rend = ::make_reverse_iterator(s.begin());

    for (; rbegin != rend; ++rbegin) {
        ming::print(*rbegin);
    }
    return 0;
}
