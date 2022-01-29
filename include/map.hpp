#ifndef MAP_HPP
# define MAP_HPP

#include <memory>       // std::allocator
#include <unistd.h>
#include <stdexcept>    // std::exeption
#include <iterator>     // std::iterator

#include <functional>   // std::less
#include "pair.hpp"     // ft::pair  ft::make_pair
#include "TreeIterator.hpp" // ft::iterator
#include "RBTree.hpp"

#include <iostream>

namespace ft {

template < class Key,                                           // map::key_type
           class T,                                             // map::mapped_type
           class Compare = std::less<Key>,                          // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > 
class map
{
public:
    //------------------------------Typedef------------------------------//
    typedef     Key                                                     key_type;
    typedef     T                                                       mapped_type;
    typedef     ft::pair<const key_type, mapped_type>                   value_type;
    typedef     Compare                                                 key_compare;
    typedef     Alloc                                                   allocator_type;
    typedef     typename allocator_type::reference                      reference;
    typedef     typename allocator_type::const_reference                const_reference;
    typedef     typename allocator_type::pointer                        pointer;
    typedef     typename allocator_type::const_pointer                  const_pointer;

    typedef     ft::rbtree<Key, T, key_compare, allocator_type>         tree_type;
    typedef     typename tree_type::iterator                            iterator;
    typedef     typename tree_type::const_iterator                      const_iterator;
    typedef     typename tree_type::reverse_iterator                    reverse_iterator;
    typedef     typename tree_type::const_reverse_iterator              const_reverse_iterator;
    typedef     std::ptrdiff_t                                          difference_type;
    typedef     std::size_t                                             size_type;

private:

        tree_type       _tree;
        allocator_type  _alloc; // возмоожно в дальнейшем не пригодится
        key_compare     _compare; // и это тоже

public:
    //----------------------------Constructor----------------------------//
    explicit map (const key_compare& comp = key_compare(),
                                            const allocator_type& alloc = allocator_type()) :
                    _tree(tree_type(comp, alloc)), _alloc(alloc), _compare(comp) {}

    template <class InputIterator>
    map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                                            const allocator_type &alloc = allocator_type()) :
                    _tree(tree_type(comp, alloc)), _alloc(alloc), _compare(comp)
    {
        this->rb.tree.insert(first, last);
    }
    map (const map& x) : _tree(tree_type(x._tree)) {}
    ~map(){}

	map& operator= (const map& x);
	//-----------------------Iterators-----------------------//
    iterator begin() {
		return ( _tree.begin() ); }
    const_iterator begin() const {
		return ( _tree.begin() ); }
    iterator end() {
		return ( _tree.end() ); }	
    const_iterator end() const {
		return ( _tree.end() ); }
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
		iterator it = _tree.find(k);
		if (it != this->end())
			return (it->second);
		else
			return (*((this->_tree.insert(ft::make_pair(k, mapped_type() ))).first)).second;
    }
	// //-----------------------Modifiers-----------------------//
    // pair<iterator,bool> insert (const value_type& val)
	// {
	// 	iterator it = this->find(val.first);
	// 	Node *it_node = this->m_begin;
    //     if (it != this->end())
	// 		return (make_pair<iterator,bool>(it,false));
	// 	if (empty_map == true)
	// 	{
    //     	(this->allocPair).construct(&p->pair, val);
	// 		this->empty_map = false;
	// 		this->m_end = this->p->left;
	// 		return (make_pair<iterator,bool>(iterator(p),true));
	// 	}
	// 	while ((it_node->left != nullptr && val.first < it_node->pair.first)
	// 			|| (it_node->right != nullptr && !(val.first < it_node->pair.first) ))
	// 	{
	// 		while (val.first < it_node->pair.first && it_node->left)
	// 			it_node = it_node->left;
	// 		while (!(val.first < it_node->pair.first) && it_node->right)
	// 			it_node = it_node->right;
	// 	}
	// 	if (it_node->left == nullptr && val.first < it_node->pair.first)
	// 	{
	//         it_node->left = allocNode.allocate(1);
    //     	(this->allocPair).construct(&it_node->left->pair, val);
	// 		it_node->left->parent = it_node;
	// 		it_node = it_node->left;
	// 		it_node->left = nullptr;
	// 		it_node->right = nullptr;
	// 		// it_node->left->color = 
	// 	}
	// 	else if (it_node->right == nullptr && !(val.first < it_node->pair.first))
	// 	{
	//         it_node->right = allocNode.allocate(1);
    //     	(this->allocPair).construct(&it_node->right->pair, val);
	// 		it_node->right->parent = it_node;
	// 		it_node = it_node->right;
	// 		it_node->left = nullptr;
	// 		it_node->right = nullptr;
	// 		// it_node->right->color = 
	// 	}
	// 	this->m_end->parent = it_node;
	// 	this->m_end->left = nullptr;
	// 	this->m_end->right = nullptr;
	// 	it_node->left = m_end;
	// 	it_node->right = m_end;
	// 	return (make_pair<iterator,bool>(iterator(it_node),true));
	// }
    // iterator insert (iterator position, const value_type& val);
    // template <class InputIterator>
    //     void insert (InputIterator first, InputIterator last);
    // void erase (iterator position);
    // size_type erase (const key_type& k);
    // void erase (iterator first, iterator last);
    // void swap (map& x);
    // void clear();
	//-----------------------Observers-----------------------//
    // key_compare key_comp() const;
    // value_compare value_comp() const;
	//-----------------------Operations-----------------------//
    // iterator find (const key_type& k) {
	// 	iterator it = this->begin();
	// 	while (it != this->end() && it->first != k)
	// 		it++;
	// 	return (it);
	// }
    // const_iterator find (const key_type& k) const {
	// 	const_iterator it = this->begin();
	// 	while (it != this->end() && it->first != k)
	// 		it++;
	// 	return (it);
	// }
    // size_type count (const key_type& k) const;
    // iterator lower_bound (const key_type& k);
    // const_iterator lower_bound (const key_type& k) const;
    // iterator upper_bound (const key_type& k);
    // const_iterator upper_bound (const key_type& k) const;
    // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
    // pair<iterator,iterator>             equal_range (const key_type& k);
	//-----------------------Allocator-----------------------//
    allocator_type get_allocator() const;


// старый код Андрея - есть конструкторы + добавление - удаление

/*
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
    Node	*p;
    Node	*m_begin;
    Node	*m_end;
    key_compare		_compare; // функция для сравнения
    Alloc			allocPair; // std::allocator
    AllocNode		allocNode;
	bool			empty_map;	// Пустая ли map сейчас
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
*/

};

}

#endif