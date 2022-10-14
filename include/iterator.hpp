#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "container.hpp"

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
#endif