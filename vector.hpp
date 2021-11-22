#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <typeinfo>
#include <iostream>

namespace ft {
template<class T, class Alloc = std::allocator<T> >
class vector
{
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

private:
    T*		_array;
    size_t  size_use;
    size_t  capacity;
    Alloc   alloc;

    pointer                                         __begin_;
    pointer                                         __end_;
    // __compressed_pair<pointer, allocator_type> 		__end_cap_;
private:
	template <class InputIterator>
	void	my_constructor_helper(InputIterator first, InputIterator last)
	{
		size_t lenght = last - first;
		this->capacity = lenght * 2;
		this->size_use = lenght;
		// if (length > this->capacity)
			// this->reserve(length);
		this->_array = (this->alloc).allocate(lenght * 2);
		for (size_t i = 0; first != last; first++, i++)
			(this->alloc).construct(_array + i, *first);
	}

	void	my_constructor_helper(int first, int last)
	{
		size_t lenght = static_cast<size_t>(first);
		this->capacity = lenght * 2;
		this->size_use = lenght;
		// if (length > this->capacity)
			// this->reserve(length);
		this->_array = (this->alloc).allocate(lenght * 2);
		for (size_t i = 0; i < lenght; ++i)
			(this->alloc).construct(_array + i, static_cast<value_type&>(last));
	}

public:
	explicit vector (const allocator_type& alloc = allocator_type()): 
			_array(nullptr), size_use(0), capacity(0)	{ (void)alloc; }
    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		(void)alloc;
		this->capacity = n * 2;
		this->size_use = n;
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
		(void)x;
	}
	virtual ~vector()
	{
		if (_array == nullptr)
			return ;
		for (size_t i = 0; i < this->size_use; i++)
			(this->alloc).destroy (_array + i);
		(this->alloc).deallocate (_array, this->capacity);
	}

	vector& 		operator=(const vector& x);
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

	class LimitingArgumentsException : public std::exception {
		virtual const char* what() const throw() {
			return "LimitingArgumentsException: ft::vector there is no <n> argument";
		}
	};

    void    push_back(const T& val);
	size_type size() const
	{
		return (this->size_use);
	}
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