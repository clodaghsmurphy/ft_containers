#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <iostream>
# include "iterator.hpp"
# include <memory>
# include <string>
# include <numeric>
# include <limits>
# include <cmath>
# include <exception>
# include <stdexcept>
# include <iterator>
#include <iomanip>
#include <type_traits>

namespace ft
{
    //////////////////////ENABLE IF //////////////////////////////////
    template< bool Cond, class T = void >
        struct enable_if {};

    template<class T>
        struct enable_if <true, T> {
            typedef T type;
        };

    template<bool B>
        struct bool_type {
            static const bool value = B;
        };

    //////////////////////IS_INTEGRAL //////////////////////////////////

    typedef bool_type<true> true_type;
    typedef bool_type<false> false_type;

    template <class T> struct is_integral;

    template<typename T>
        struct is_integral : false_type {};

    template<typename T>
        struct is_integral<const T> : is_integral<T> {};

    template<typename T>
        struct is_integral<volatile T> : is_integral<T> {};
    template<> 
        struct is_integral<bool> : true_type { };
    template<> 
        struct is_integral<char> : true_type { };
    template<>
        struct is_integral<int> : true_type { };
    template<>
        struct is_integral<unsigned char> : true_type { };
    template<>
        struct is_integral<signed char> : true_type { };

}

#endif