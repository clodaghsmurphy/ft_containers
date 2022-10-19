# ifndef TEST_HPP
# define TEST_HPP

#include "container.hpp"
# include <stdio.h>
/* 
template<class IteratorType> 
void myFunction(const IteratorType& myIterator)
{
    IteratorType _ptr = &(*myIterator);
    std::cout << _ptr << std::endl;
} */
template<class T>
void    print_container(T container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    //std::cout << ft::is_integral<typename std::iterator_traits<it>::value_type>::value << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }   
}


void    vector_constructors();
int     test_vector_size();
void    iterator_category();

#endif