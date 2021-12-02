#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <unistd.h>
#include <stdexcept>
#include <iterator>
#include <algorithm>

namespace ft {
template<typename T>
class VectorIterator: std::iterator_traits<T*>
{
	//-----------------------Typedef-----------------------//
public:
	typedef T 					value_type;
    typedef value_type* 		pointer;
    typedef value_type const* 	const_pointer;
    typedef value_type& 		reference;
    typedef value_type const& 	const_reference;
    typedef std::ptrdiff_t 		difference_type;
protected:
	pointer p;
public:
	VectorIterator(): p(nullptr) {}
	VectorIterator(pointer p): p(p) {}
	VectorIterator(VectorIterator const &other): p(other.p) {}
	virtual ~VectorIterator() {}

	VectorIterator &operator=(VectorIterator const &other) {
		this->p = other.p;
		return (*this);
	}

	reference operator*() {
		return (*this->p);
	}
	const_reference operator*() const {
		return (*this->p);
	}
	pointer operator->() {
		return (this->p);
	}
	const_pointer operator->() const {
		return (this->p);
	}
    reference operator[](int val) {
		return (*(this->p + val));
	}
    const_reference operator[](int val) const {
		return (*(this->p + val));
	}

	VectorIterator operator++(int) {
		VectorIterator tmp(*this);
		++this->p;
		return (tmp);
	}
	VectorIterator &operator++() {
		++this->p;
		return (*this);
	}
	VectorIterator operator--(int) {
		VectorIterator tmp(*this);
		--this->p;
		return (tmp);
	}
	VectorIterator &operator--() {
		--this->p;
		return (*this);
	}

	VectorIterator &operator+=(int value) {
		this->p += value;
		return (*this);
	}
	VectorIterator operator+(int value) const {
		VectorIterator tmp(*this);
		return (tmp += value);
	}
	VectorIterator &operator-=(int value) {
		this->p -= value;
		return (*this);
	}
	VectorIterator operator-(int value) const {
		VectorIterator tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(VectorIterator const &other) const {
		return (this->p - other.p);
	}

	bool operator==(VectorIterator const &other) const {
		return (this->p == other.p);
	}
	bool operator!=(VectorIterator const &other) const {
		return (this->p != other.p);
	}
	bool operator<(VectorIterator const &other) const {
		return (this->p < other.p);
	}
	bool operator<=(VectorIterator const &other) const {
		return (this->p <= other.p);
	}
	bool operator>(VectorIterator const &other) const {
		return (this->p > other.p);
	}
	bool operator>=(VectorIterator const &other) const {
		return (this->p >= other.p);
	}
};

template<typename It>
class ReverseIterator: public It
{
public:
	using typename It::value_type;
    using typename It::pointer;
    using typename It::const_pointer;
    using typename It::reference;
    using typename It::const_reference;
    using typename It::difference_type;
public:
	ReverseIterator(): It() {}
	ReverseIterator(It const &it): It(it) {}
	ReverseIterator(ReverseIterator const &other): It(other.p) {}
	ReverseIterator &operator=(ReverseIterator const &other) {
		this->p = other.p;
		return (*this);
	}

	reference operator*() {
		It tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const {
		It tmp(*this);
		return (*--tmp);
	}
	pointer operator->() {
		It tmp(*this);
		return (&*--tmp);
	}
	const_pointer operator->() const {
		It tmp(*this);
		return (&*--tmp);
	}
	ReverseIterator operator++(int) {
		ReverseIterator tmp(*this);
		operator++();
		return (tmp);
	}
	It &operator++() {
		return (this->It::operator--());
	}
	ReverseIterator operator--(int) {
		ReverseIterator tmp(*this);
		operator--();
		return (tmp);
	}
	It &operator--() {
		return (this->It::operator++());
	}
};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2) 
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template<class T, class Alloc = std::allocator<T> >
class vector
{
	//-----------------------Typedef-----------------------//
public:
    typedef T                                     	value_type;
    typedef Alloc		                           	allocator_type;
    typedef std::allocator<allocator_type>    		__alloc;
    typedef value_type&                            	reference;
    typedef const value_type&                      	const_reference;
	typedef unsigned long							size_type;
    typedef typename __alloc::difference_type 		difference_type;
    typedef typename __alloc::pointer         		pointer;
    typedef typename __alloc::const_pointer   		const_pointer;
	typedef VectorIterator<value_type> 				iterator;
	typedef VectorIterator<value_type const> 		const_iterator;
	typedef ReverseIterator<iterator> 				reverse_iterator;
	typedef ReverseIterator<const_iterator> 		const_reverse_iterator;

	//-----------------------Param-----------------------//
private:
    T*		_array;
    size_t  _size;
    size_t  _capacity;
    Alloc   alloc;

	//-----------------------Constructor-----------------------//
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
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):
		_array(nullptr), _size(0), _capacity(0)
	{
		this->assign(first, last);
		(void)alloc;
	}
    vector (const vector& x)
	{
		this->_capacity = x._capacity;
		this->_size = x._size;
		this->alloc = x.alloc;
		this->_array = (this->alloc).allocate(x._capacity);
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

    iterator begin()	{
		return (iterator(this->_array));
	}
	const_iterator begin() const	{
		return (const_iterator(this->_array));
	}
	iterator end()	{
		return (iterator(&(this->_array[this->_size])));
	}
	const_iterator end() const	{
		return (const_iterator(&(this->_array[this->_size])));
	}
	reverse_iterator rbegin(void)	{
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const	{
		return (const_reverse_iterator(this->end()));
	}
	reverse_iterator rend(void)	{
		return (reverse_iterator(this->begin()));
	}
	const_reverse_iterator rend(void) const	{
		return (const_reverse_iterator(this->begin()));
	}

	//-----------------------Capacity-----------------------//

	size_type size() const
	{
		return (this->_size);
	}
	size_type max_size() const
	{
		return (this->alloc.max_size());
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
		return (this->_size == 0);
	}
	void reserve (size_type n)
	{
		T* new_array;

		if (this->_capacity < n)
		{
			new_array = (this->alloc).allocate(n);
			for (size_t i = 0; i < this->_size; i++)
				(this->alloc).construct(new_array + i, *(this->_array + i));
			for (size_t i = 0; i < this->_size; i++)
				(this->alloc).destroy (_array + i);
			(this->alloc).deallocate (_array, this->_capacity);
			this->_array = new_array;
			this->_capacity = n;
		}
	}

	//-----------------------Element access-----------------------//

    reference       operator[](size_type n)
	{
		if (n >= this->_size || n < 0)
			throw vector::LimitingArgumentsException();
		return (this->_array[n]);
	}
    const_reference operator[](size_type n) const
	{
		if (n >= this->_size || n < 0)
			throw vector::LimitingArgumentsException();
		return (this->_array[n]);
	}
    reference at (size_type n)
	{
		if (n >= this->_size || n < 0)
			throw std::out_of_range("Vector index out of range");
		return (this->_array[n]);
	}
	const_reference at (size_type n) const
	{
		if (n >= this->_size || n < 0)
			throw std::out_of_range("Vector index out of range");
		return (this->_array[n]);
	}
    reference front()
	{
		return (this->_array[0]);
	}
	const_reference front() const
	{
		return (this->_array[0]);
	}
	reference back()
	{
		return (this->_array[this->_size - 1]);
	}
	const_reference back() const
	{
		return (this->_array[this->_size - 1]);
	}

	//-----------------------Modifiers-----------------------//

	// void assign (iterator first, iterator last)
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		this->clear();
		size_t lenght = last - first;
		this->_size = lenght;
		if (this->_capacity < lenght)
		{
			if (this->_array != nullptr)
				(this->alloc).deallocate (_array, this->_capacity);
			this->_capacity = lenght * 2;
			this->_array = (this->alloc).allocate(lenght * 2);
		}
		for (size_t i = 0; first != last; first++, i++)
			(this->alloc).construct(_array + i, *first);
	}

	// here should be void assign (size_type n, ...
	void assign (int n, const value_type& val)
	{
		this->clear();
		size_t lenght = static_cast<size_t>(n);
		this->_size = lenght;
		if (this->_capacity < lenght)
		{
			if (this->_array != nullptr)
				(this->alloc).deallocate (_array, this->_capacity);
			this->_capacity = lenght * 2;
			this->_array = (this->alloc).allocate(lenght * 2);
		}
		for (size_t i = 0; i < lenght; ++i)
			(this->alloc).construct(_array + i, val);
	}

    void push_back(const T& val)
	{
		size_t cap2;
		if (this->_capacity == 0)
			cap2 = 2;
		else
			cap2 = this->_capacity * 2;
		if (this->_size == this->_capacity)
		{
			T* new_array = (this->alloc).allocate(cap2);
			for (size_t i = 0; i < this->_capacity; i++)
				(this->alloc).construct(new_array + i, *(_array + i));
			for (size_t i = 0; i < this->_capacity; i++)
				(this->alloc).destroy(this->_array + i);
			(this->alloc).deallocate(_array, this->_capacity);
			this->_capacity = cap2;
			this->_array = new_array;
		}
		(this->alloc).construct(_array + this->_size, val);
		this->_size++;
	}
	void pop_back()
	{
		(this->alloc).destroy(this->_array + this->_size - 1);
		this->_size--;
	}
	iterator insert (iterator position, const value_type& val)
	{
		this->insert(position, 1, val);
		return (position);
	}

    // void insert (iterator position, size_type n, const value_type& val)
    void insert (iterator position, int n, const value_type& val)
	{
		iterator it_begin = this->begin();
		size_type n2 = n;
		int i_end = this->_size - 1;
		int pos	= 0;

		if (this->_capacity < this->_size + n)
			this->resize(this->_size + n);
		else
			this->_size += n;

		for ( ; it_begin != position; it_begin++)
			pos++;
		for ( ; i_end >= pos; i_end--)
		{
			(this->alloc).construct(_array + i_end + n, *(_array + i_end));
			(this->alloc).destroy(this->_array + i_end);
		}
		i_end++;
		for ( ; n2 > 0; n2--, i_end++)
			(this->alloc).construct(_array + i_end, val);
	}

	template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last)
	{
		iterator it_begin = this->begin();
		int i_end = this->_size - 1;
		int pos	= 0;
		size_type n, n2;
	
		n = n2 = last - first;
		if (this->_capacity < this->_size + n)
			this->resize(this->_size + n);
		else
			this->_size += n;

		for ( ; it_begin != position; it_begin++)
			pos++;
		for ( ; i_end >= pos; i_end--)
		{
			(this->alloc).construct(_array + i_end + n, *(_array + i_end));
			(this->alloc).destroy(this->_array + i_end);
		}
		i_end++;
		for ( ; n2 > 0; n2--, i_end++, first++)
			(this->alloc).construct(_array + i_end, *first);
	}
	iterator erase (iterator position)
	{
		iterator tmp(position);
		tmp++;
		return (this->erase(position, tmp));
	}
	iterator erase (iterator first, iterator last)
	{
		iterator it_begin = this->begin();
		iterator it_res;
		size_type count = last - first;
		size_type i_first, i_last, res;

		for (i_first = 0; it_begin != first; it_begin++, i_first++)
			(void)count;
		i_last = i_first;
		res = i_first;
		for ( ; count > 0; i_last++, count--)
			(this->alloc).destroy(this->_array + i_last);
		for ( ; i_last != this->_size; i_last++, i_first++)
		{
			(this->alloc).construct(_array + i_first, *(_array + i_last));
			(this->alloc).destroy(this->_array + i_last);
		}
		this->_size -= (last - first);
		it_res = this->begin() + res;
		return (it_res);
	}
	void swap (vector& x)
	{
		std::swap(this->_array, x._array);
		std::swap(this->_capacity, x._capacity);
		std::swap(this->_size, x._size);
	}
	void clear(void)
	{
		for (size_t i = 0; i < this->_size; i++)
			(this->alloc).destroy(this->_array + i);
		this->_size = 0;
	}

	//-----------------------Allocator-----------------------//

	allocator_type get_allocator() const {
		return (this->alloc);
	}

	//-----------------------Exception-----------------------//

	class LimitingArgumentsException : public std::exception {
		virtual const char* what() const throw() {
			return "LimitingArgumentsException: ft::vector there is no <n> argument";
		}
	};
};

	//-----------------------Relational operators-----------------------//

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
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