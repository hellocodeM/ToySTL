template < class Category,
         class T,
         class Distance = std::ptrdiff_t,
         class Pointer = T*,
         class Reference = T&,
         >
struct iterator {
    using difference_type = Distance;
    using value_type = T;
    using pointer = Pointer;
    using reference = Reference;
    using iterator_category = Category;
};
