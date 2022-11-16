#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <iostream>
# include "iterator.hpp"
//# include "vector.hpp"
# include <memory>
# include <string>
# include <numeric>
# include <limits>
# include <cmath>
# include <exception>
# include <stdexcept>
# include <iterator>
# include <algorithm>
#include <iomanip>
//# include <type_traits>

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
        struct is_integral<bool> : public true_type { };
    template<> 
        struct is_integral<char> : public true_type { };
    template<>
        struct is_integral<int> : public true_type { };
    template<>
        struct is_integral<unsigned int> : public true_type { };
    template<>
        struct is_integral<unsigned long> : public true_type { };
    
    template<>
        struct is_integral<unsigned char> : public true_type { };
    template<>
        struct is_integral<signed char> : public true_type { };



    template< class InputIt1, class InputIt2 >
        bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
        {
            while (first1 != last1)
            {
                if (*first1 != *first2)
                    return (false);
                first1++;
                first2++;
            }
            return(true);
        }
template<class Arg1, class Arg2, class Result>
    struct binary_function
    {
        typedef Arg1    first_argument_type;
        typedef Arg2   second_argument_type;
        typedef Result result_type;
    };

template< class T >
    struct less : binary_function <T,T,bool>
    {
        bool operator() (const T& lhs, const T& rhs) const
        {
            return lhs < rhs;
        }
    };

    template< class InputIt1, class InputIt2 >
        bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
        {
             for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
            {
                if (*first1 < *first2)
                    return true;
                if (*first2 < *first1)
                    return false;
            }
        
            return (first1 == last1) && (first2 != last2);
        }



}
#endif