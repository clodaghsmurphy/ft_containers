#ifndef MAP_HPP
#define MAP_HPP

# include "container.hpp"


namespace ft 
{
    template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<std::pair<const Key,T> > >
    class map
    {
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef pair<const Key, T>                          value_type;
            typedef Compare                                     key_compare;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference                   reference;   
            typedef typename allocator_type::const_reference             const_reference;   
            typedef typename allocator_type::pointer                     pointer;   
            typedef typename allocator_type::const_pointer               const_pointer;  
            typedef std::size_t                                 size_type;
            typedef std::ptrdiff_t                              difference_type;
 
            typedef Reverse_iterator<iterator>                  reverse_iterator;


            /*----------------CANONIICAL------------------*/
            explicit map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type());
            template <class InputIterator>
                map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            map (const map& x);
    };
}

#endif
