#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <typeinfo>
#include <unistd.h>

#include <iostream>

namespace ft {
template<class T, class Alloc = std::allocator<T> >
class vector
{
	//-----------------------Typedef-----------------------//
private:
    typedef std::__vector_base<T, Alloc>           	__base;
public:
    // typedef vector                                   __self;
    typedef T                                     	value_type;
    typedef Alloc		                           	allocator_type;
    typedef std::allocator<allocator_type>    		__alloc;
    typedef value_type&                            	reference;
    typedef const value_type&                      	const_reference;
    typedef typename __alloc::size_type       		size_type;
    typedef typename __alloc::difference_type 		difference_type;
    typedef typename __alloc::pointer         		pointer;
    typedef typename __alloc::const_pointer   		const_pointer;
    typedef pointer                                	iterator;
    typedef const_pointer                          	const_iterator;
    typedef _VSTD::reverse_iterator<iterator>      	reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>	const_reverse_iterator;

	//-----------------------Param-----------------------//
private:
    T*		_array;
    size_t  _size;
    size_t  _capacity;
    Alloc   alloc;

    pointer                                         __begin_;
    pointer                                         __end_;
    // __compressed_pair<pointer, allocator_type> 		__end_cap_;

	//-----------------------Constructor-----------------------//
private:
	template <class InputIterator>
	void	my_constructor_helper(InputIterator first, InputIterator last)
	{
		size_t lenght = last - first;
		this->_capacity = lenght * 2;
		this->_size = lenght;
		// if (length > this->_capacity)
			// this->reserve(length);
		this->_array = (this->alloc).allocate(lenght * 2);
		for (size_t i = 0; first != last; first++, i++)
			(this->alloc).construct(_array + i, *first);
	}

	void	my_constructor_helper(int first, int last)
	{
		size_t lenght = static_cast<size_t>(first);
		this->_capacity = lenght * 2;
		this->_size = lenght;
		// if (length > this->_capacity)
			// this->reserve(length);
		this->_array = (this->alloc).allocate(lenght * 2);
		for (size_t i = 0; i < lenght; ++i)
			(this->alloc).construct(_array + i, static_cast<value_type&>(last));
	}

public:
	explicit vector (const allocator_type& alloc = allocator_type()): 
			_array(nullptr), _size(0), _capacity(0)	{ (void)alloc; }

    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		(void)alloc;
		this->_capacity = n * 2;
		this->_size = n;
		this->_array = (this->alloc).allocate(n * 2);
		for (size_t i = 0; i < n; i++)
			(this->alloc).construct(_array + i, val);
	}

    template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	{
		this->my_constructor_helper(first, last);
		(void)alloc;
	}

    vector (const vector& x)
	{
		this->clear();
		if (this->_capacity < x._capacity)
		{
			if (this->_array != nullptr)
				(this->alloc).deallocate (_array, this->_capacity);
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->_array = (this->alloc).allocate(x._capacity);
		}
		for (size_t i = 0; i < x._size; i++)
			(this->alloc).construct(_array + i, *(x._array + i));
	}

	virtual ~vector()
	{
		if (_array == nullptr)
			return ;
		for (size_t i = 0; i < this->_size; i++)
			(this->alloc).destroy (_array + i);
		(this->alloc).deallocate (_array, this->_capacity);
	}

	vector& 		operator=(const vector& x)
	{
		this->clear();
		if (this->_capacity < x._capacity)
		{
			(this->alloc).deallocate (_array, this->_capacity);
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->_array = (this->alloc).allocate(x._capacity);
		}
		for (size_t i = 0; i < x._size; i++)
			(this->alloc).construct(_array + i, *(x._array + i));
		return (*this);
	}

	//-----------------------Iterators-----------------------//


	//-----------------------Capacity-----------------------//

	size_type size() const
	{
		return (this->_size);
	}

	size_type max_size() const
	{
		return std::numeric_limits<T>::max() / sizeof(T);
	}

	void resize (size_type n, value_type val = value_type())
	{
		T* new_array;

		if (this->_size > n)
		{
			for (size_t i = _size; i > n; i--)
				(this->alloc).destroy (_array + i);
			this->_size = n;
		}
		else if (this->_size < n && this->_capacity > n)
		{
			for (size_t i = this->_size; i < n; i++)
				(this->alloc).construct(_array + i, val);
			this->_size = n;
		}
		else if (this->_capacity < n)
		{
			new_array = (this->alloc).allocate(n * 2);
			for (size_t i = 0; i < this->_size; i++)
				(this->alloc).construct(new_array + i, *(this->_array + i));
			for (size_t i = this->_size; i < n; i++)
				(this->alloc).construct(new_array + i, val);
			for (size_t i = 0; i < this->_size; i++)
				(this->alloc).destroy (_array + i);
			(this->alloc).deallocate (_array, this->_capacity);
			this->_array = new_array;
			this->_size = n;
			this->_capacity = n * 2;
		}
	}

	size_type capacity() const
	{
		return (this->_capacity);
	}

	bool empty() const
	{
		if (this->_size > 0)
			return (true);
		else
			return (false);
	}

	void reserve (size_type n)
	{
		T* new_array;

		if (this->_capacity < n)
		{
			new_array = (this->alloc).allocate(n + 20);
			for (size_t i = 0; i < this->_size; i++)
				(this->alloc).construct(new_array + i, *(this->_array + i));
			for (size_t i = 0; i < this->_size; i++)
				(this->alloc).destroy (_array + i);
			(this->alloc).deallocate (_array, this->_capacity);
			this->_array = new_array;
			this->_capacity = n + 20;
		}
	}

	//-----------------------Element access-----------------------//

    reference       operator[](size_type n)
	{
		if (n < size())
			return (this->_array[n]);
		else
			throw vector::LimitingArgumentsException();
	}

    const_reference operator[](size_type n) const
	{
		if (n < size())
			return (this->_array[n]);
		else
			throw vector::LimitingArgumentsException();
	}

	//-----------------------Modifiers-----------------------//

    // void    push_back(const T& val) // не факт что работает
	// {
	// 	if (this->_size < this->_capacity)
	// 	{
	// 		(this->alloc).construct(Alloc, array + _size, x);
	// 		_size++;
	// 	}
	// 	else
	// 	{
	// 		T* new_arr = (this->alloc).allocate(Alloc, this->_capacity * 2);
	// 		for (int i = 0; i < this->_capacity; i++)
	// 			(this->alloc).construct(Alloc, new_arr + i, array[i]);
	// 		for (int i = 0; i < this->_capacity; i++)
	// 			(this->alloc).destroy(Alloc, array + i);
	// 		(this->alloc).deallocate(Alloc, this->_capacity);
	// 		this->_capacity *= 2;
	// 		array = new_arr;
	// 	}
	// }
	
	void clear(void)
	{
		for (size_t i = 0; i < this->_size; i++)
			(this->alloc).destroy (_array + i);
		this->_size = 0;
	}

	//-----------------------Exception-----------------------//

	class LimitingArgumentsException : public std::exception {
		virtual const char* what() const throw() {
			return "LimitingArgumentsException: ft::vector there is no <n> argument";
		}
	};
};
// #include "vector.ipp"
}

// Цветной консольный вывод
namespace ansi
{
	template < class CharT, class Traits >
	std::basic_ostream< CharT, Traits > & reset( std::basic_ostream< CharT, Traits > &os )
	{
		return os << "\033[0m";
	}

	template < class CharT, class Traits >
	std::basic_ostream< CharT, Traits > & foreground_black( std::basic_ostream< CharT, Traits > &os )
	{
		return os << "\033[30m";
	}

	template < class CharT, class Traits >
	std::basic_ostream< CharT, Traits > & foreground_red( std::basic_ostream< CharT, Traits > &os )
	{
		return os << "\033[31m";
	}

	template < class CharT, class Traits >
	std::basic_ostream< CharT, Traits > & foreground_green( std::basic_ostream< CharT, Traits > &os )
	{
		return os << "\033[32m";
	}

	template < class CharT, class Traits >
	std::basic_ostream< CharT, Traits > & foreground_yellow( std::basic_ostream< CharT, Traits > &os )
	{
		return os << "\033[33m";
	}

	template < class CharT, class Traits >
	std::basic_ostream< CharT, Traits > & foreground_blue( std::basic_ostream< CharT, Traits > &os )
	{
		return os << "\033[34m";
	}

	template < class CharT, class Traits >
	std::basic_ostream< CharT, Traits > & foreground_purple( std::basic_ostream< CharT, Traits > &os )
	{
		return os << "\033[35m";
	}

	template < class CharT, class Traits >
	std::basic_ostream< CharT, Traits > & foreground_cyan( std::basic_ostream< CharT, Traits > &os )
	{
		return os << "\033[36m";
	};
} // ansi

#endif