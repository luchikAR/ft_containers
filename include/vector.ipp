// #include "vector.hpp"

// namespace ft{
// template<typename T, typename Alloc>
// vector::vector(const allocator_type& alloc = allocator_type()) {}

// template<typename T, typename Alloc>
// vector<T, Alloc>::vector(const vector& x) {}

// template<typename T, typename Alloc>
// vector<T, Alloc>::~vector() {}

// template<typename T, typename Alloc>
// vector& vector<T, Alloc>::operator=(const vector& x);
// {

// }

// template<typename T, typename Alloc>
// void vector<T, Alloc>::push_back(const T& val) {
//     if (this->_size < this->_capacity)
//     {
//         std::allocator_traits<Alloc>::construct(Alloc, array + _size, x);
//         _size++;
//     }
//     else
//     {
//         T* new_arr = allocator_traits<Alloc>::allocate(Alloc, this->_capacity * 2);
//         for (int i = 0; i < this->_capacity; i++)
//             std::allocator_traits<Alloc>::construct(Alloc, new_arr + i, array[i]);
//         for (int i = 0; i < this->_capacity; i++)
//             std::allocator_traits<Alloc>::destroy(Alloc, array + i);
//         std::allocator_traits<Alloc>::deallocate(Alloc, this->_capacity);
//         this->_capacity *= 2;
//         array = new_arr;
//     }
// }
// }