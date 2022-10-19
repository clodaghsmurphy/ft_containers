#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "container.hpp"

    //////////////////////ITERATOR TRAITS //////////////////////////////////

    template <class Iter >
        struct iterator_traits;

    template< class T >
        struct iterator_traits<T*>;
        
    template<typename _Iterator>
        struct iterator_traits
     {
        typedef typename _Iterator::iterator_category iterator_category;
        typedef typename _Iterator::value_type        value_type;
        typedef typename _Iterator::difference_type   difference_type;
        typedef typename _Iterator::pointer           pointer;
        typedef typename _Iterator::reference         reference;
     };

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

    ////////////////////// REVERSE ITERATOR //////////////////////////////////
    template <class Iterator>
    class reverse_iterator
    {
        public:
        reverse_iterator() {}
        explicit reverse_iterator(Iterator x) : m_iterator(x) {}
        reverse_iterator(const reverse_iterator &obj): m_iterator(obj.m_iterator) {}

        template<typename OtherIterator>
        reverse_iterator(const reverse_iterator<OtherIterator> &obj) : m_iterator(obj.base()) {}

        typedef typename iterator_traits<Iterator>::iterator_category    iterator_category;
        typedef typename iterator_traits<Iterator>::value_type           value_type;
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type      difference_type;
        typedef typename iterator_traits<Iterator>::pointer              pointer;
        typedef typename iterator_traits<Iterator>::reference            reference;

        iterator_type base() const { return m_iterator; }
        reference operator*() const
        {
            Iterator tmp = m_iterator;
            return *--tmp;
        }
        pointer operator->() const{
            return &(operator*());
        }
        reverse_iterator    &operator++()
        {
            --m_iterator;
            return *this;
        }
        reverse_iterator    &operator--()
        {
            ++m_iterator;
            return *this;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --m_iterator;
            return tmp;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++m_iterator;
            return tmp;
        }
        reverse_iterator operator+(difference_type n) const 
        {
            return reverse_iterator(m_iterator - n);
        }
        reverse_iterator operator+=(difference_type n)
        {
            m_iterator -= n;
            return *this;
        }
        reverse_iterator operator-(difference_type n) const 
        {
            return reverse_iterator(m_iterator + n);
        }
        reverse_iterator operator-=(difference_type n)
        {
            m_iterator += n;
            return *this;
        }
        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }
        template<typename Iter>
        inline bool
            operator==(const reverse_iterator<Iter> x, const reverse_iterator<Iter> y)
            {
                return x.base() == y.base();
            }
         template<typename Iter>
         inline bool
            operator<(const reverse_iterator<Iter> x, const reverse_iterator<Iter> y)
            {
                return y.base() < x.base() ;
            }
        template<typename Iter>
         inline bool
            operator<(const reverse_iterator<Iter> x, const reverse_iterator<Iter> y)
            {
                return x.base() < y.base();
            }
        private:
        Iterator m_iterator;
    };

    
#endif