#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "container.hpp"
//#include "vector.hpp"

namespace ft
{
    //////////////////////ITERATOR TRAITS //////////////////////////////////

    struct input_iterator_tag
    {
    };
    ///  Marking output iterators.
    struct output_iterator_tag
    {
    };
    /// Forward iterators support a superset of input iterator operations.
    struct forward_iterator_tag : public input_iterator_tag
    {
    };
    /// Bidirectional iterators support a superset of forward iterator
    /// operations.
    struct bidirectional_iterator_tag : public forward_iterator_tag
    {
    };
    /// Random-access iterators support a superset of bidirectional iterator
    /// operations.
    struct random_access_iterator_tag : public bidirectional_iterator_tag
    {
    };

    template <class Iter>
    struct iterator_traits;

    template <class T>
    struct iterator_traits<T *>;

    template <typename _Iterator>
    struct iterator_traits
    {
        typedef typename _Iterator::iterator_category iterator_category;
        typedef typename _Iterator::value_type value_type;
        typedef typename _Iterator::difference_type difference_type;
        typedef typename _Iterator::pointer pointer;
        typedef typename _Iterator::reference reference;
    };

    template <typename _Iterator>
    struct iterator_traits<_Iterator *>
    {
        typedef random_access_iterator_tag iterator_category;
        typedef _Iterator value_type;
        typedef std::ptrdiff_t difference_type;
        typedef _Iterator *pointer;
        typedef _Iterator &reference;
    };

    template <typename Iterator>
    typename iterator_traits<Iterator>::difference_type
    distance(Iterator first, Iterator last)
    {
        typename iterator_traits<Iterator>::difference_type result;
        for (result = 0; first != last; first++, result++)
        {
            ;
        }
        return result;
    }

    template <class InputIterator, class Distance>
        void advance(InputIterator& i, Distance n);

    ////////////////////// REVERSE ITERATOR //////////////////////////////////
    template <class Iterator>
    class Reverse_iterator
    {
    protected:
        Iterator m_iterator;

    public:
        Reverse_iterator() {}
        explicit Reverse_iterator(Iterator x) : m_iterator(x) {}
        Reverse_iterator(const Reverse_iterator &obj) : m_iterator(obj.m_iterator) {}

        template <typename OtherIterator>
        Reverse_iterator(const OtherIterator &obj) : m_iterator(obj.base()) {}

        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::reference reference;

        Iterator base() const { return m_iterator; }
        Reverse_iterator &operator=(const Reverse_iterator &rhs)
        {
            m_iterator = rhs.base();
            return *this;
        }

        reference operator*() const
        {
            Iterator tmp = m_iterator;
            return (*--tmp);
        }
        pointer operator->() const
        {
            return &(operator*());
        }
        Reverse_iterator &operator++()
        {
            --m_iterator;
            return *this;
        }
        Reverse_iterator &operator--()
        {
            ++m_iterator;
            return *this;
        }
        Reverse_iterator operator++(int)
        {
            Reverse_iterator tmp = *this;
            --m_iterator;
            return tmp;
        }
        Reverse_iterator operator--(int)
        {
            Reverse_iterator tmp = *this;
            ++m_iterator;
            return tmp;
        }
        Reverse_iterator operator+(difference_type n) const
        {  
            return Reverse_iterator(m_iterator - n);
        }
        Reverse_iterator operator+(difference_type n) 
        {  
            return Reverse_iterator(m_iterator - n);
        }
        Reverse_iterator operator+=(difference_type n)
        {
            m_iterator -= n;
            return *this;
        }
        Reverse_iterator operator-=(difference_type n)
        {
            m_iterator += n;
            return *this;
        }
        Reverse_iterator operator-(difference_type n) const
        {  
            return Reverse_iterator(m_iterator + n);
        }
          Reverse_iterator operator-(difference_type n) 
        {  
            return Reverse_iterator(m_iterator + n);
        }
        reference operator[](difference_type n) const
        {
            return (m_iterator[-n -1]);
        }
    };
    template <class IteratorL, class IteratorR>
        bool operator==(const Reverse_iterator<IteratorL>& x, const Reverse_iterator<IteratorR>& y)
        {
            return (x.base() == y.base());
        }
    template <class IteratorL, class IteratorR>
        bool operator<(const Reverse_iterator<IteratorL>& x, const Reverse_iterator<IteratorR>& y)
        {
            return (x.base() > y.base());
        }
    template <class IteratorL, class IteratorR>
        bool operator!=(const Reverse_iterator<IteratorL>& x, const Reverse_iterator<IteratorR>& y)
        {
            return !(x.base() == y.base());
        }
    template <class IteratorL, class IteratorR>
        bool operator>(const Reverse_iterator<IteratorL>& x,const Reverse_iterator<IteratorR>& y)
        {
            return (x.base() < y.base());
        }
    template <class IteratorL, class IteratorR>
        bool operator>=(const Reverse_iterator<IteratorL>& x, const Reverse_iterator<IteratorR>& y)
        {
            return (x.base() <= y.base());
        }
    template <class IteratorL, class IteratorR>
        bool operator<=(const Reverse_iterator<IteratorL>& x, const Reverse_iterator<IteratorR>& y)
        {
            return (x.base() >= y.base());
        }

    template <class IteratorL, class IteratorR>
        typename Reverse_iterator<IteratorL>::difference_type operator-(const Reverse_iterator<IteratorL>& x, const Reverse_iterator<IteratorR>& y)
        {
            return (y.base() - x.base());
        }
    template <class IteratorL, class IteratorR>
        Reverse_iterator<IteratorL> operator-(typename Reverse_iterator<IteratorL>::difference_type n, const Reverse_iterator<IteratorR>& x)
        {
            return Reverse_iterator<IteratorL>(x.base() + n);
        }
     template <class IteratorL, class IteratorR>
        Reverse_iterator<IteratorL> operator-(const Reverse_iterator<IteratorR>& x, typename Reverse_iterator<IteratorL>::difference_type n)
        {
            return Reverse_iterator<IteratorL>(x.base() + n);
        }
    template <class IteratorL, class IteratorR>
        Reverse_iterator<IteratorL> operator+(typename Reverse_iterator<IteratorL>::difference_type n, const Reverse_iterator<IteratorR>& x)
        {
            return Reverse_iterator<IteratorL>(x.base() - n);
        }
    template <class Iterator>
        Reverse_iterator<Iterator> operator+(typename Reverse_iterator<Iterator>::difference_type n, const Reverse_iterator<Iterator>& x)
        {
            return Reverse_iterator<Iterator>(x.base() - n);
        }


}


#endif