#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft{

template <class T1, class T2> 
struct pair
{

    //-----------------------Param-----------------------//
    typedef T1      first_type;
    typedef T2      second_type;
public:
    T1 first;
    T2 second;
    //-----------------------Constructor-----------------------//
public:
    pair()
    {
        first = first_type();
        second = second_type();
    }
    template<class U, class V>
        pair (const pair<U,V>& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
        }
    pair (const first_type& a, const second_type& b)
    {
        this->first = a;
        this->second = b;
    }
    pair& operator= (const pair& pr)
    {
        this->first = pr.first;
        this->second = pr.second;
        return(*this);
    }
};
	//-----------------------Relational operators-----------------------//
    template <class T1, class T2>
        bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
            return lhs.first==rhs.first && lhs.second==rhs.second; }
    template <class T1, class T2>
        bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
            return !(lhs==rhs); }
    template <class T1, class T2>
        bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
            return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
    template <class T1, class T2>
        bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
            return !(rhs<lhs); }
    template <class T1, class T2>
        bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
            return rhs<lhs; }
    template <class T1, class T2>
        bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
            return !(lhs<rhs); }

    template <class T1, class T2>
        ft::pair<T1,T2> make_pair (T1 x, T2 y) {
            return ( ft::pair<T1,T2>(x,y) );
        }
}

#endif