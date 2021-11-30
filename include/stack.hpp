#ifndef STACK_HPP
# define STACK_HPP

#include <memory>
#include <unistd.h>
#include <stdexcept>
#include <iterator>
#include <deque>

namespace ft {

template <class T, class Container = std::deque<T> >
class stack
{
public:
	//-----------------------Typedef-----------------------//
    typedef Container                                container_type;
    typedef T                                        value_type;
    typedef typename container_type::reference       reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type       size_type;
protected:
	//-----------------------Param-----------------------//
    container_type c;
public:
    //-----------------------Constructor-----------------------//
    explicit stack (const container_type& ctnr = container_type()): c(ctnr) {}
	stack(stack const &other): c(other.c) {}
	virtual ~stack() {}
	stack &operator=(stack const &other) {
		this->c = other.c;
		return (*this);
	}
    //-----------------------Member functions-----------------------//
    bool empty() const {
        return (this->c.empty());
    }
    size_type size() const {
        return (this->c.size());
    }
    value_type& top() {
        return (this->c.back());
    }
    const value_type& top() const {
        return (this->c.back());
    }
    void push (const value_type& val) {
        this->c.push_back(val);
    }
    void pop() {
        this->c.pop_back();
    }

	//-----------------------Relational operators-----------------------//

   	template<typename stack_type, typename container_type>
	friend bool operator==(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c == rhs.c);
	}
	template<typename stack_type, typename container_type>
	friend bool operator!=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c != rhs.c);
	}
	template<typename stack_type, typename container_type>
	friend bool operator<(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c < rhs.c);
	}
	template<typename stack_type, typename container_type>
	friend bool operator<=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c <= rhs.c);
	}
	template<typename stack_type, typename container_type>
	friend bool operator>(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c > rhs.c);
	}
	template<typename stack_type, typename container_type>
	friend bool operator>=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c >= rhs.c);
	}

};

}

#endif