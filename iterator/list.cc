#include <predef.hpp>

template <class T>
class LinkedList {
    public:
        struct ListNode {
            T data_;
            ListNode<T>* next_ = nullptr;

            ListNode() {
            }
            
            ListNode(const T& data): data_(data) {
            }
        };

        struct iterator {
            ListNode<T>* node_ = nullptr;

            using difference_type = std::ptrdif_t;
            using value_type = T;
            using reference = T&;
            using pointer = T*;
            using iterator_category = std::forward_iterator_tag;

            iterator() {
            }

            iterator(ListNode<T>* node): node_(node) {
            }

            iterator(const iterator& rhs): node_(rhs.node_) {
            }

            ~iterator() {
            }

            iterator& operator = (const iterator& rhs) {
                node_ = rhs.node_;
            }

            iterator& operator++() {
                assert(node_->next != nullptr);
                node_ = node_->next;
                return *this;
            }

            iterator operator++(int) {
                iterator tmp(*this);
                ++tmp;
                return tmp;
            }

            reference operator*() const {
                return *this;
            }
            
            friend void swap(iterator& lhs, iterator& rhs) {
                std::swap(lhs.node_, rhs.node_);
            }

            pointer operator->() const {
                return node_;
            }
            
            friend bool operator==(const iterator& lhs, const iterator& rhs) {
                return node_ == rhs.node_;
            }

            friend bool operator!= (const iterator& lhs, const iterator& rhs) {
                return !(lhs == rhs);
            }
        };
        
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using difference_type = size_t;
        using iterator = iterator; 
        using const_iterator = std::const_iterator<iterator>;

        iterator begin() {
            return iterator(data_);
        }
        
        const_iterator begin() const {
            return const_iterator(data_);
        }

        const_iterator cbegin() {
            return const_iterator(data_);
        }

        iterator end() {
            return iterator();
        }

        const_iterator end() const {
            return const_iterator();
        }

        const_iterator cend() const {
            return const_iterator();
        }

        
    private:
        ListNode<T>* data_;
        
};
