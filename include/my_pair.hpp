
#ifndef MY_PAIR_HPP
# define MY_PAIR_HPP

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
        pair    &operator=(const pair &rhs)
        {
            first = rhs.first;
            second = rhs.second;
            return *this;
        }
    };

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
        }

    template <class T1, class T2>
    bool operator==(pair<T1, T2> rhs, pair<T1,T2> lhs)
    {
        return rhs.first == lhs.first && rhs.second == lhs.second;
    }

    template <class T1, class T2>
    bool operator!=(pair<T1, T2> rhs, pair<T1, T2> lhs)
    {
        return !(rhs.first == lhs.first && rhs.second == lhs.second);
    }

    template <class T1, class T2>
    bool operator<(pair<T1, T2> rhs, pair<T1, T2> lhs)
    {
        return (rhs.first < lhs.first && rhs.second < lhs.second);
    }

    template <class T1, class T2>
    bool operator>(pair<T1, T2> rhs, pair<T1, T2> lhs)
    {
        return !(rhs.first < lhs.first && rhs.second < lhs.second);
    }

    template <class T1, class T2>
    bool operator>=(pair<T1, T2> rhs, pair<T1, T2> lhs)
    {
        return (rhs.first >= lhs.first && rhs.second >= lhs.second);
    }

    template <class T1, class T2>
    bool operator<=(pair<T1, T2> rhs, pair<T1, T2> lhs)
    {
        return (rhs.first <= lhs.first && rhs.second <= lhs.second);
    }

#endif