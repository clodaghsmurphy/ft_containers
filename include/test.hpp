# ifndef TEST_HPP
# define TEST_HPP

#include <stdio.h>
#include "iterator.hpp"
#include "vector.hpp"
# include "map.hpp"
# include <list>
# include <map>
/* 
template<class IteratorType> 
void myFunction(const IteratorType& myIterator)
{
    IteratorType _ptr = &(*myIterator);
    std::cout << _ptr << std::endl;
} */

template <typename T>
class foo
{
public:
    typedef T value_type;

    foo(void) : value(), _verbose(false){};
    foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose){};
    foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose){};
    ~foo(void)
    {
        if (this->_verbose)
            std::cout << "~foo::foo()" << std::endl;
    };
    void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
    void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
    foo &operator=(value_type src)
    {
        this->value = src;
        return *this;
    };
    foo &operator=(foo const &src)
    {
        if (this->_verbose || src._verbose)
            std::cout << "foo::operator=(foo) CALLED" << std::endl;
        this->value = src.value;
        return *this;
    };
    value_type getValue(void) const { return this->value; };
    void switchVerbose(void) { this->_verbose = !(this->_verbose); };

    operator value_type(void) const
    {
        return value_type(this->value);
    }

private:
    value_type value;
    bool _verbose;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, foo<T> const &bar)
{
    o << bar.getValue();
    return o;
}
// --- End of class foo

template <typename T>
std::string printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
    o << "key: " << iterator->first << " | value: " << iterator->second;
    if (nl)
        o << std::endl;
    return ("");
}

template <typename T, typename U>
std::string printPair2(const T &iterator, const U &iterator2, bool nl = true, std::ostream &o = std::cout)
{
    if (iterator->first == iterator2->first && iterator->second == iterator2->second )
        o << "\033[1m\033[32m ✅ OK \033[0m";
    else
    {
         o << "\033[1m\033[31m MINE : ❌ key: " << iterator->first << " | value: " << iterator->second << std::endl;
        o  << "\033[1m\033[31m REAL : ❌ key: " << iterator2->first << " | value: " << iterator2->second <<std::endl;

    }
    if (nl)
        o << std::endl;
    return ("");
}

template <typename T1, typename T2>
void	printReverse(ft::map<T1, T2> &mp, std::map<T1, T2> &mp2)
{
	typename ft::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();
	typename std::map<T1, T2>::iterator it2 = mp2.end(), ite2= mp2.begin();

	std::cout << "\033[1m\033[37mprintReverse:" << std::endl;
	while (it != ite && it2 != ite2) {
		it--;
        it2--;
		std::cout << "-> " << printPair2(it, it2) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}

template <typename T_MAP, typename U_MAP>
void printSize(T_MAP const &mp, U_MAP const &mp2,  bool print_content = 1)
{
    if ((mp.size() == mp2.size()) && (mp.max_size() == mp2.max_size()))
        std::cout << "\033[1m\033[32m ✅ SIZE/MX_SIZE OK \033[0m" << std::endl;
    if (print_content)
    {
        typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
        typename U_MAP::const_iterator it2 = mp2.begin(), ite2 = mp2.end();
        std::cout << std::endl
                  << "Content is:" << std::endl;
        for (; it != ite && it2 != ite2; ++it, ++it2)
        {
           
            std::cout << "- " << printPair2(it, it2) << std::endl;

        }
    }
    std::cout << "###############################################" << std::endl;
}

template <typename T_MAP>
void printSize(T_MAP const &mp, bool print_content = 1)
{
    std::cout << "size: " << mp.size() << std::endl;
    std::cout << "max_size: " << mp.max_size() << std::endl;
    if (print_content)
    {
        typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
        std::cout << std::endl
                  << "Content is:" << std::endl;
        for (; it != ite; ++it)
        {
           
            std::cout << "- " << printPair(it, false) << std::endl;

        }
    }
    std::cout << "###############################################" << std::endl;
}


template <typename T>
T inc(T it, int n)
{
    while (n-- > 0)
        ++it;
    return (it);
}

template <typename T>
T dec(T it, int n)
{
    while (n-- > 0)
        --it;
    return (it);
}
template<class T>
void    print_container(T &container)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    //std::cout << ft::is_integral<typename std::iterator_traits<it>::value_type>::value << std::endl;

    while (it != ite)
    {
        std::cout << *it << "  " ;
        it++;
    }   
    std::cout << std::endl;
}


void    vector_constructors();
int     test_vector_size();
void    iterator_category();
void    modifiers();
void    rb_tester();
void relational_ope(void);
void    rev_it_construct();
void    swap_insert();
void    tricky_construct();
void    map_find_count();
void    insert_map_test();
void    erase_map_test();

#endif