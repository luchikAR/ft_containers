#ifndef TREEITERATOR_HPP
# define TREEITERATOR_HPP

#include <iterator>
#include "IteratorTraits.hpp"

namespace ft{

template<class T>
struct Node
{
    typedef T       value_type;

    T       *value;     //значение -  ft::pair
    Node    *parent;    //родители узла
    Node    *left;      //значение левого узла меньше текущего
    Node    *right;     //значение правого узла больше текущего
    bool    is_red;     //true - Если узел красный, в противном случае от черный О_о
    bool    is_nil;     //true - Если не существует дочернего или родительского узла, по отношению к данному

    Node()
    {
        this->value = NULL;
        this->parent = 0;
        this->left = 0;
        this->right = 0;
        this->is_red = false;
        this->is_nil = true;
    }

    Node(T *val)
    {
        this->value = val;
        this->parent = 0;
        this->left = 0;
        this->right = 0;
        this->is_red = true;
        this->is_nil = false; 
    }
    
    Node(Node const &other)
    {
        this->value = other.value;
        this->parent = other.parent;
        this->left = other.left;
        this->right = other.right;
        this->is_red = other.is_red;
        this->is_nil = other.is_nil;
    }

    Node &operator=(Node const &other)
    {
        this->value = other.value;
        this->parent = other.parent;
        this->left = other.left;
        this->right = other.right;
        this->is_red = other.is_red;
        this->is_nil = other.is_nil;
        return(this);  // virtual was here
    }

    virtual ~Node(){}
};


template<class T>
class TreeIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
 // забить здесь самому значения
    // typedef typename ft::iterator_traits<T>::difference_type  difference_type;
    typedef typename ft::iterator_traits<T>::value_type       value_type;
    typedef typename ft::iterator_traits<T>::pointer          pointer;
    typedef typename ft::iterator_traits<T>::reference        reference;
    typedef typename ft::Node<value_type>*                   node_p;
private:
    node_p _node;

    node_p tree_min(node_p x) const // стр 324 Кормен
    {
        while(!x->left->is_nil)
            x = x->left;
        return x;
    }

    node_p tree_max(node_p x) const
    {
        while(!x->right->is_nil)
            x = x->right;
        return x;
    }

public:
    TreeIterator() {}

    TreeIterator(node_p _node)
    {
        this->_node = _node;
    }
    
    TreeIterator(TreeIterator<value_type> const &other)
    {
        *this = other;
    }

    TreeIterator &operator=(TreeIterator<value_type> const &other)
    {
        this->_node = other._node;
        return *this;
    }


    reference operator*(){
        return(*this->_node->value);
    }

    pointer operator->(){
        return(this->_node->value);
    }

    TreeIterator &operator++(){
        
        if(!_node->right->is_nil)
            _node = tree_min(_node->right);
        else
        {
            node_p y = _node->parent;
            while(!y->is_nil && _node == y->right)
            {
                _node = y;
                y = y->parent;
            }
            _node = y;
        }
        return *this;
    }

    TreeIterator operator++(int){
        TreeIterator<value_type> tmp = *this;
        if(!_node->right->is_nil)
            _node = tree_min(_node->right);
        else
        {
            node_p y = _node->parent;
            while(!y->is_nil && _node == y->right)
            {
                _node = y;
                y = y->parent;
            }
            _node = y;
        }
        return tmp;

    }

    TreeIterator &operator--(){
        if(!_node->left->is_nil)
            _node = tree_max(_node->left);
        else
        {
            node_p y = _node->parent;
            while(!y->is_nil && _node == y->left)
            {
                _node = y;
                y = y->parent;
            }
            _node = y;
        }
        return *this;
    }

    TreeIterator operator--(int){
        TreeIterator<value_type> tmp = *this;
        if(!_node->left->is_nil)
            _node = tree_max(_node->left);
        else
        {
            node_p y = _node->parent;
            while(!y->is_nil && _node == y->left)
            {
                _node = y;
                y = y->parent;
            }
            _node = y;
        }
        return tmp;
    }

    node_p getNode() const
    {
        return _node;
    }

};

template<typename A, typename B>
bool operator==(const TreeIterator<A> &lhs, const TreeIterator<B> &rhs)
{
    return  lhs.getNode() == rhs.getNode();
}

template<typename A, typename B>
bool operator!=(const TreeIterator<A> &lhs, const TreeIterator<B> &rhs)
{
    return  lhs.getNode() != rhs.getNode();
}


}

/* 
   1)Корень дерева всегда черный
   2)Каждый лист дерева (NIL) явл черным узлом
   3)После красного узла должен идти обязательно черный 
   4)Для каждого узла все простые пути до листьев явл
   потомками данного узла, содержат одно и тоже
   количество черных узлов
*/


#endif