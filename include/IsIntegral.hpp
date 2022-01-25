#ifndef ISINTEGRAL_HPP
# define ISINTEGRAL_HPP
#include <type_traits>

/*

Трейт-класс, определяющий, является ли T  интегральным типом данных

*/

namespace ft{

template<class T, bool v>
struct integral_constant
{
    static const bool value = v;
    typedef T value_type;
    typedef integral_constant<T, v> type;
    operator T() {return v;}
};

template <class T> struct is_integral                       :   public ft::integral_constant<T, false> {};
template<> struct is_integral<bool>                         :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<char>                         :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<char16_t>                     :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<char32_t>                     :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<wchar_t>                      :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<signed char>                  :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<short int>                    :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<int>                          :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<long int>                     :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<long long int>                :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<unsigned char>                :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<unsigned short int>           :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<unsigned int>                 :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<unsigned long int>            :   public ft::integral_constant<bool, true> {};
template<> struct is_integral<unsigned long long int>       :   public ft::integral_constant<bool, true> {};

}

#endif