#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <iostream>
# include <memory>
# include <string>
# include <numeric>
# include <limits>
# include <cmath>
# include <exception>
# include <stdexcept>
# include <iterator>

namespace ft{
    template< bool Cond, class T = void >
        struct enable_if {};

    template<class T>
        struct enable_if <true, T> {
            typedef T type;
        };

    
}

#endif