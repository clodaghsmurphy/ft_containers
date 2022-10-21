#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "container.hpp"
#include "vector.hpp"

//////////////////////ITERATOR TRAITS //////////////////////////////////

    struct input_iterator_tag {};
    ///  Marking output iterators.
    struct output_iterator_tag {};
    /// Forward iterators support a superset of input iterator operations.
    struct forward_iterator_tag : public input_iterator_tag {};
    /// Bidirectional iterators support a superset of forward iterator
    /// operations.
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    /// Random-access iterators support a superset of bidirectional iterator
    /// operations.
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

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
struct iterator_traits<_Iterator*>
{
    typedef  random_access_iterator_tag iterator_category;
    typedef  _Iterator                  value_type;
    typedef  std::ptrdiff_t              difference_type;
    typedef  _Iterator*                 pointer;
    typedef  _Iterator&                reference;
};

 

    template<typename Iterator>
    typename iterator_traits<Iterator>::difference_type
    distance (Iterator first, Iterator last)
    {
        return distance (first, last, typename iterator_traits<Iterator>::iterator_category());
    }

    template<typename RandomAccessIterator>
    typename iterator_traits<RandomAccessIterator>::difference_type
    distance (RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag)
    {
        return (last - first);
    }

    template<typename InputIterator>
    typename iterator_traits<InputIterator>::difference_type
    distance (InputIterator first, InputIterator last, input_iterator_tag)
    {
        typename iterator_traits<InputIterator>::difference_type result;
        for (result = 0; first != last; first++, result++)
        {
            ;
        }
        return result;
        
    }

    ////////////////////// REVERSE ITERATOR //////////////////////////////////
    template <class Iterator>
    class Reverse_iterator
    {
        protected:
        Iterator m_iterator;
        public:
        Reverse_iterator() {}
        explicit Reverse_iterator(Iterator x) : m_iterator(x) {}
        Reverse_iterator(const Reverse_iterator &obj): m_iterator(obj.m_iterator) {}

        template<typename OtherIterator>
        Reverse_iterator(const Reverse_iterator<OtherIterator> &obj) : m_iterator(obj.base()) {}

        typedef typename iterator_traits<Iterator>::iterator_category    iterator_category;
        typedef typename iterator_traits<Iterator>::value_type           value_type;
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type      difference_type;
        typedef typename iterator_traits<Iterator>::pointer              pointer;
        typedef typename iterator_traits<Iterator>::reference            reference;

        iterator_type base() const { return m_iterator; }
        reference operator*() const
        {
            Iterator tmp(m_iterator);
            --tmp;
            return *tmp;
        }
        pointer operator->() const{
            return &(operator*());
        }
        Reverse_iterator    &operator++()
        {
            --m_iterator;
            return *this;
        }
        Reverse_iterator    &operator--()
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
        Reverse_iterator operator+=(difference_type n)
        {
            m_iterator -= n;
            return *this;
        }
        Reverse_iterator operator-(difference_type n) const 
        {
            return Reverse_iterator(m_iterator + n);
        }
        Reverse_iterator operator-=(difference_type n)
        {
            m_iterator += n;
            return *this;
        }
        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }
        bool operator==(const Reverse_iterator<Iterator> y)
        {
            return base() == y.base();
        }
        bool operator!=(const Reverse_iterator<Iterator> &y)
        {
            return base() != y.base();
        }
        /*friend bool operator==(const Reverse_iterator<Iterator> x, const Reverse_iterator<Iterator> y);
        friend bool operator!=(const Reverse_iterator<Iterator> &x, const Reverse_iterator<Iterator> &y);*/
        };

    /*template<typename Iterator>
        bool operator==(const Reverse_iterator<Iterator> x, const Reverse_iterator<Iterator> y)
            {
                return x.base() == y.base();
            }*/
        template <typename Iter>
        inline bool
            operator<(const Reverse_iterator<Iter> x, const Reverse_iterator<Iter> y)
            {
                return x.base() < y.base();
            }
        template <typename Iter>
        inline bool
            operator>(const Reverse_iterator<Iter> x, const Reverse_iterator<Iter> y)
            {
                return x.base() > y.base();
            }
        /*template <typename Iterator>
        bool operator!=(const Reverse_iterator<Iterator> &x, const Reverse_iterator<Iterator> &y)
        {
            return x.base() != y.base();
        }*/
        template <typename Iter>
        inline bool
            operator<=(const Reverse_iterator<Iter> x, const Reverse_iterator<Iter> y)
            {
                return !(y.base() < x.base() );
            }
        template <typename Iter>
        inline bool
            operator>=(const Reverse_iterator<Iter> x, const Reverse_iterator<Iter> y)
            {
                return !(x.base() < y.base());
            }

#endif