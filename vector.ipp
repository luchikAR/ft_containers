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
//     if (this->size_use < this->capacity)
//     {
//         std::allocator_traits<Alloc>::construct(Alloc, array + size_use, x);
//         size_use++;
//     }
//     else
//     {
//         T* new_arr = allocator_traits<Alloc>::allocate(Alloc, this->capacity * 2);
//         for (int i = 0; i < this->capacity; i++)
//             std::allocator_traits<Alloc>::construct(Alloc, new_arr + i, array[i]);
//         for (int i = 0; i < this->capacity; i++)
//             std::allocator_traits<Alloc>::destroy(Alloc, array + i);
//         std::allocator_traits<Alloc>::deallocate(Alloc, this->capacity);
//         this->capacity *= 2;
//         array = new_arr;
//     }
// }
// }