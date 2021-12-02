#ifndef MAP_HPP
# define MAP_HPP

#include <memory>       // std::allocator
#include <unistd.h>
#include <stdexcept>    // std::exeption
#include <iterator>     // std::iterator

#include <utility>      // std::make_pair
#include <functional>   // std::less

namespace ft {
template < class Key,                                           // map::key_type
           class T,                                             // map::mapped_type
           class Compare = std::less<Key>,                          // map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
           > 
class map
{
public:

	//-----------------------Typedef-----------------------//
    typedef Key                                      key_type;
    typedef T                                        mapped_type;
    typedef std::pair<const key_type, mapped_type>   value_type;
    typedef Compare                                  key_compare;
    typedef Alloc                                    allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;

    // typedef implementation-defined                   iterator;
    // typedef implementation-defined                   const_iterator;
    // typedef std::reverse_iterator<iterator>          reverse_iterator;
    // typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
	
    struct Node {
        bool red;
        Node* parent;
        Node* left;
        Node* right;
        std::pair<const Key, T> pair;
    };
    
    //-----------------------Param-----------------------//
private:
    Node *p;
    Alloc alloc;
    key_compare _compare;
	//-----------------------Constructor-----------------------//
public:
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
        _compare(comp)
    {
        // p = (this->alloc).allocate(sizeof(Node));
        (void)alloc;
        (void)comp;
        p->parent = p;
        p->right = (nullptr);
        p->left = (nullptr);
        p->red = (0);
        // p->pair = std::make_pair( 0, 0);
    }
    template <class InputIterator>
    map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    {
        (void)first;
        (void)last;
        (void)alloc;
        (void)comp;
    }
    map(const map& x);
	virtual ~map()
    { }

	map& operator= (const map& x);
	//-----------------------Iterators-----------------------//
    // iterator begin();
    // const_iterator begin() const;
    // iterator end();
    // const_iterator end() const;
    // reverse_iterator rbegin();
    // const_reverse_iterator rbegin() const;
    // reverse_iterator rend();
    // const_reverse_iterator rend() const;
	//-----------------------Capacity-----------------------//
    bool empty() const;
    size_type size() const;
    size_type max_size() const;
	//---------------------Element access---------------------//
    mapped_type& operator[] (const key_type& k)
    {(void)k;}
	//-----------------------Modifiers-----------------------//
    // pair<iterator,bool> insert (const value_type& val);
    // iterator insert (iterator position, const value_type& val);
    // template <class InputIterator>
    //     void insert (InputIterator first, InputIterator last);
    // void erase (iterator position);
    size_type erase (const key_type& k);
    // void erase (iterator first, iterator last);
    void swap (map& x);
    void clear();
	//-----------------------Observers-----------------------//
    key_compare key_comp() const;
    // value_compare value_comp() const;
	//-----------------------Operations-----------------------//
    // iterator find (const key_type& k);
    // const_iterator find (const key_type& k) const;
    size_type count (const key_type& k) const;
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