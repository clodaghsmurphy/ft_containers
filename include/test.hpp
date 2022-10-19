# ifndef TEST_HPP
# define TEST_HPP

#include "container.hpp"

template<class T>
void    print_container(T container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    //std::cout << ft::is_integral<typename std::iterator_traits<it>::value_type>::value << std::endl;

    while (it != ite)
    {
        int t = *it;
        std::cout << &t << " : " << *it << std::endl;
        it++;
    }   
}


void    vector_constructors();
int     test_vector_size();
void    iterator_category();

#endif