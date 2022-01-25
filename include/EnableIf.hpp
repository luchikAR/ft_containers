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
}






#endif