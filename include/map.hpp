#ifndef MAP_HPP
# define MAP_HPP

#include <memory>       // std::allocator
#include <unistd.h>
#include <stdexcept>    // std::exeption
#include <iterator>     // std::iterator

#include <functional>   // std::less
#include "pair.hpp"     // ft::pair  ft::make_pair

#include <iostream>

namespace ft {

template<typename T, typename N>
class MapIterator
{
public:
	typedef T                   value_type;
	typedef N                   node_type;
    typedef std::size_t         size_type;
    typedef value_type*         pointer;
    typedef value_type const*   const_pointer;
    typedef value_type&         reference;
    typedef value_type const&   const_reference;
	typedef node_type*          node_pointer;
    typedef std::ptrdiff_t      difference_type;
protected:
	node_pointer p;

	void previous() {
		if (this->p->left) {
			this->p = this->p->left;
			while (this->p->right)
				this->p = this->p->right;
		} else
			this->p = this->p->parent;
	}
	void next() {
		if (this->p->right) {
			this->p = this->p->right;
			while (this->p->left)
				this->p = this->p->left;
		} else {
			node_pointer tmp = this->p;
			this->p = this->p->parent;
			while ( (this->p && this->p->left) && this->p->left != tmp)
			{
				tmp = this->p;
				this->p = this->p->parent;
			}
		}
	}
public:
	MapIterator(): p(nullptr) {}
	MapIterator(node_pointer p): p(p) {}
	MapIterator(MapIterator const &other): p(other.p) {}
	virtual ~MapIterator() {}

	node_pointer as_node(void) const {
		return (this->p);
	}

	MapIterator &operator=(MapIterator const &other) {
		this->p = other.p;
		return (*this);
	}

	reference operator*() {
		return (this->p->pair);
	}
	const_reference operator*() const {
		return (this->p->pair);
	}
	pointer operator->() {
		return (&this->p->pair);
	}
	const_pointer operator->() const {
		return (&this->p->pair);
	}

	MapIterator operator++(int) {
		MapIterator tmp(*this);
		this->next();
		return (tmp);
	}
	MapIterator &operator++() {
		this->next();
		return (*this);
	}
	MapIterator operator--(int) {
		MapIterator tmp(*this);
		this->previous();
		return (tmp);
	}
	MapIterator &operator--() {
		this->previous();
		return (*this);
	}

	MapIterator &operator+=(int value) {
		if (value > 0) {
			for (int i = 0; i < value; i++)
				this->next();
		} else {
			for (int i = value; i > 0; i--)
				this->previous();
		}
		return (*this);
	}
	MapIterator operator+(int value) const {
		MapIterator tmp(*this);
		return (tmp += value);
	}
	MapIterator &operator-=(int value) {
		operator+=(-value);
		return (*this);
	}
	MapIterator operator-(int value) const {
		MapIterator tmp(*this);
		return (tmp -= value);
	}

	bool operator==(MapIterator const &other) const {
		return (this->p == other.p);
	}
	bool operator!=(MapIterator const &other) const {
		return (this->p != other.p);
	}
	bool operator<(MapIterator const &other) const {
		return (this->p < other.p);
	}
	bool operator<=(MapIterator const &other) const {
		return (this->p <= other.p);
	}
	bool operator>(MapIterator const &other) const {
		return (this->p > other.p);
	}
	bool operator>=(MapIterator const &other) const {
		return (this->p >= other.p);
	}
};

template < class Key,                                           // map::key_type
           class T,                                             // map::mapped_type
           class Compare = std::less<Key>,                          // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > 
class map
{
public:
    struct Node {
        bool	color; // false - black, true - red
        Node*	parent;
        Node*	left;
        Node*	right;
        ft::pair<const Key, T> pair;
    };

	//-----------------------Typedef-----------------------//
    typedef Key                                      key_type;
    typedef T                                        mapped_type;
    typedef ft::pair<const key_type, mapped_type>    value_type;
    typedef Compare                                  key_compare;
    typedef Alloc                                    allocator_type;
    typedef std::allocator<Node>                     AllocNode;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;

    typedef MapIterator<value_type, Node>               iterator; // полная фигня, надо делать свой
	typedef MapIterator<value_type const, Node const>   const_iterator;
	typedef ReverseIterator<iterator>                   reverse_iterator;
	typedef ReverseIterator<const_iterator>             const_reverse_iterator;
	
    //-----------------------Param-----------------------//
private:
	// struct ft::Node
    Node *p;
    Node *m_begin;
    Node *m_end;
	// функция для сравнения
    key_compare _compare;
	// std::allocator
    Alloc allocPair;
    AllocNode allocNode;
	// Пустая ли map сейчас
	bool empty_map;
	//-----------------------Constructor-----------------------//
public:
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
        _compare(comp)
    {
        p = allocNode.allocate(1);
		this->empty_map = true;
        // (this->allocPair).construct(&p->pair, ft::pair<const Key, T>());
		m_begin = p;
		//end
		m_end->left = nullptr;
		m_end->right = nullptr;
		m_end->parent = nullptr;
		//
		p->parent = nullptr;
		p->right = m_end;
		p->left = m_end;
        p->color = false; // black
        (void)alloc;
    }
    template <class InputIterator>
    map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    {
        // insert(first, last);
        (void)first;
        (void)last;
        (void)alloc;
        (void)comp;
    }
    map(const map& x);
    // : __tree_(__m.__tree_)
    // {
        // insert(__m.begin(), __m.end());
    // }
	virtual ~map()
    { }

	map& operator= (const map& x);
	//-----------------------Iterators-----------------------//
    iterator begin() {
		return (iterator(m_begin)); }
    const_iterator begin() const {
		return (const_iterator(m_begin)); }
    iterator end() {
		return (iterator(m_end)); }	
    const_iterator end() const {
		return (const_iterator(m_end)); }
    // reverse_iterator rbegin();
    // const_reverse_iterator rbegin() const;
    // reverse_iterator rend();
    // const_reverse_iterator rend() const;
	//-----------------------Capacity-----------------------//
    // bool empty() const;
    // size_type size() const;
    // size_type max_size() const;
	//---------------------Element access---------------------//
    mapped_type& operator[] (const key_type& k)
    {
		iterator it = this->find(k);
		if (it != this->end())
			return (it->second);
		else
			return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
    }
	//-----------------------Modifiers-----------------------//
    pair<iterator,bool> insert (const value_type& val)
	{
		iterator it = this->find(val.first);
		Node *it_node = this->m_begin;
        if (it != this->end())
			return (make_pair<iterator,bool>(it,false));
		if (empty_map == true)
		{
        	(this->allocPair).construct(&p->pair, val);
			this->empty_map = false;
			this->m_end = this->p->left;
			return (make_pair<iterator,bool>(iterator(p),true));
		}
		while ((it_node->left != nullptr && val.first < it_node->pair.first)
				|| (it_node->right != nullptr && !(val.first < it_node->pair.first) ))
		{
			while (val.first < it_node->pair.first && it_node->left)
				it_node = it_node->left;
			while (!(val.first < it_node->pair.first) && it_node->right)
				it_node = it_node->right;
		}
		if (it_node->left == nullptr && val.first < it_node->pair.first)
		{
	        it_node->left = allocNode.allocate(1);
        	(this->allocPair).construct(&it_node->left->pair, val);
			it_node->left->parent = it_node;
			it_node = it_node->left;
			it_node->left = nullptr;
			it_node->right = nullptr;
			// it_node->left->color = 
		}
		else if (it_node->right == nullptr && !(val.first < it_node->pair.first))
		{
	        it_node->right = allocNode.allocate(1);
        	(this->allocPair).construct(&it_node->right->pair, val);
			it_node->right->parent = it_node;
			it_node = it_node->right;
			it_node->left = nullptr;
			it_node->right = nullptr;
			// it_node->right->color = 
		}
		this->m_end->parent = it_node;
		this->m_end->left = nullptr;
		this->m_end->right = nullptr;
		it_node->left = m_end;
		it_node->right = m_end;
		return (make_pair<iterator,bool>(iterator(it_node),true));
	}
    iterator insert (iterator position, const value_type& val);
    template <class InputIterator>
        void insert (InputIterator first, InputIterator last);
    // void erase (iterator position);
    // size_type erase (const key_type& k);
    // void erase (iterator first, iterator last);
    // void swap (map& x);
    // void clear();
	//-----------------------Observers-----------------------//
    // key_compare key_comp() const;
    // value_compare value_comp() const;
	//-----------------------Operations-----------------------//
    iterator find (const key_type& k) {
		iterator it = this->begin();
		while (it != this->end() && it->first != k)
			it++;
		return (it);
	}
    const_iterator find (const key_type& k) const {
		const_iterator it = this->begin();
		while (it != this->end() && it->first != k)
			it++;
		return (it);
	}
    // size_type count (const key_type& k) const;
    // iterator lower_bound (const key_type& k);
    // const_iterator lower_bound (const key_type& k) const;
    // iterator upper_bound (const key_type& k);
    // const_iterator upper_bound (const key_type& k) const;
    // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
    // pair<iterator,iterator>             equal_range (const key_type& k);
	//-----------------------Allocator-----------------------//
    allocator_type get_allocator() const;
};
}

#endif