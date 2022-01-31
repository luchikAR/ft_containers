#ifndef ENABLEIF_HPP
# define ENABLEIF_HPP

/*
хз че это вообще 
*/
#include <type_traits>

namespace ft
{
template <bool Cond, class T = void> 
struct enable_if {};

template <class T> 
struct enable_if<true, T> {typedef T type;};

template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	  while (first1!=last1) {
		      if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				        return false;
			      ++first1; ++first2;
				    }
	    return true;
}
}






#endif