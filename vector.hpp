#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <typeinfo>

namespace ft {
template<class T, class Alloc = std::allocator<T> >
class vector
{
private:
    typedef std::__vector_base<T, Alloc>           	__base;
    typedef std::allocator<T>                       __default_allocator_type;
public:
    // typedef vector                                   __self;
    typedef T                                     	 value_type;
    typedef Alloc		                             allocator_type;
    typedef std::allocator_traits<allocator_type>    __alloc_traits;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    typedef typename __alloc_traits::size_type       size_type;
    typedef typename __alloc_traits::difference_type difference_type;
    typedef typename __alloc_traits::pointer         pointer;
    typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef pointer                                  iterator;
    typedef const_pointer                            const_iterator;
    typedef _VSTD::reverse_iterator<iterator>        reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>  const_reverse_iterator;

private:
    T*      _array;
    size_t  size_use;
    size_t  capacity;
    Alloc   alloc;

    pointer                                         __begin_;
    pointer                                         __end_;
    // __compressed_pair<pointer, allocator_type> 		__end_cap_;
public:
	explicit vector (const allocator_type& alloc = allocator_type()): 
			_array(nullptr), size_use(0), capacity(0)	{ (void)alloc; }
    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		this->capacity = n * 2;
		this->size_use = n;
		this->_array = __alloc_traits::allocate(alloc, n * 2);
		for (int i = 0; i < n; i++)
			__alloc_traits::construct(alloc, _array + i, val);
	}
    template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{
			// if (typeid(value_type) == typeid(InputIterator))
			// {
			// 	this->capacity = first * 2;
			// 	this->size_use = first;
			// 	this->_array = __alloc_traits::allocate(alloc, static_cast<size_t>(first) * 2);
			// 	for (int i = 0; i < first; i++)
			// 		__alloc_traits::construct(alloc, _array + i, static_cast<size_t>(last));
			// }
			(void)first;
			(void)last;
			(void)alloc;
		}
    vector (const vector& x)
	{
		(void)x;
	}
	virtual ~vector()
	{
		// if (_array == nullptr)
		// 	return ;
		// for (size_t i = 0; i < this->size_use; i++)
		// 	alloc.destroy(_array + i);
		// alloc.deallocate(_array, this->capacity);
	}

	vector& 		operator=(const vector& x);
    reference       operator[](size_type n)
	{
		if (n < size())
    		return this->__begin_[n];
		else
			return (nullptr);	//exeption; "vector[] index out of bounds"
	}
    const_reference operator[](size_type n) const
	{
		if (n < size())
    		return this->__begin_[n];
		else
			return (nullptr);	//exeption; "vector[] index out of bounds"
	}

    void    push_back(const T& val);
	size_type size() const
	{
		return (this->size_use);
	}
};
// #include "vector.ipp"
}

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