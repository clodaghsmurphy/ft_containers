
#ifndef "PAIR_HPP"
#define "PAIR_HPP"

# include "container.hpp"

template< class T1, class T2>
    struct pair
    {
        typedef T1  first_type;
        typedef T2  second_type;

        T1  first;
        T2  second;

        pair() : first(), second() {}
        pair(const pair<T1, T2>& pr) : first(pr.first), second(pr.second) {}
        pair(const first_type& a, const second_type& b) : first(a), second(b) {}
    };

    template <class T1,class T2>
        pair<T1,T2> make_pair (T1 x, T2 y)
        {
            return ( pair<T1,T2>(x,y) );
        }


#endif