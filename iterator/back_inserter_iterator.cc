#include <predef.hpp>

template <class Container>
class back_inserter_iterator: 
    public std::iterator<std::output_iterator_tag, typename Container::value_type> {
    public:
        using iterator = back_inserter_iterator<Container>;
        using value_type = typename Container::value_type;
        
        explicit back_inserter_iterator(Container& rhs) {
            container_ = &rhs;
        }

        back_inserter_iterator(const iterator& rhs) {
            container_ = rhs.container_;
        }

        iterator& operator= (const iterator& rhs) {
            container_ = rhs.container_;
            return *this;
        }

        iterator& operator=(const value_type& value) {
            container_->push_back(value);
            return *this;
        }

        iterator& operator=(value_type&& value) {
            container_->push_back(std::move(value));
            return *this;
        }

        iterator& operator* () {
            return *this;
        }

        iterator& operator++() {
            return *this;
        }

        iterator& operator++(int) {
            return *this;
        }
    private:
        
        Container* container_;
};

template <class Container>
::back_inserter_iterator<Container>
back_inserter(Container& con) {
    return ::back_inserter_iterator<Container>(con);
}

int main() {
    std::vector<int> xs1{1, 2, 3};
    std::vector<int> xs2;
    std::copy(xs1.begin(), xs1.end(), ::back_inserter(xs2));
    assert((xs2 == std::vector<int>{1, 2, 3}));
    return 0;
}
