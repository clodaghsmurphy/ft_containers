#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <iostream>
# include <memory>
# include <string>
# include <numeric>
#include<limits>
# include <cmath>
# include <exception>
# include <stdexcept>

namespace ft{
    template< bool B, class T = void >
        struct enable_if {};

    template<bool B>
        struct bool_type {
            static const bool = B;
        };

    typedef bool_type<true>     true_type;
    typedef bool_type<false> false_type;

}

# endif