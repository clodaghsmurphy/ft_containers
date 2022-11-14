#ifndef MAP_HPP
#define MAP_HPP

# include "container.hpp"
# include "red_black_tree.hpp"
# include "pair.hpp"


namespace ft 
{
    template <typename Iterator, typename Compare >
    class map_iterator : public bidirectional_iterator_tag
    {
        typedef map_iterator< Iterator, Compare >  Self;
        private:
            Iterator current; //the rb tree of map
        public:
            typedef ft::iterator_traits<Iterator>       traits;


            typedef typename traits::iterator_category iterator_category;
            typedef typename traits::value_type        value_type;
            typedef typename traits::difference_type   difference_type;
            typedef typename traits::reference         reference;
            typedef typename traits::pointer           pointer;

        /*--------------CANONICAL--------------------*/
        map_iterator() : current() {}

        bool operator== (const map_iterator& rhs) const;
        bool operator!=(const map_iterator& rhs) const;
        Self    &operator++();
        Self    operator++(int);
        Self    operator--();
        Self    operator--(int);

        private:
        
        
    };


    template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<std::pair<const Key,T> > >
    class map
    {
        
        public:
        /*--------------------------------------TYPEDEFS----------------------------------*/
            typedef rb_tree<Key, T>                             RB_tree;
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef pair<const Key, T>                          value_type;
            typedef Compare                                     key_compare;
            typedef Allocator                                   allocator_type;
            
            typedef typename allocator_type::reference                   reference;   
            typedef typename allocator_type::const_reference             const_reference;   
            typedef typename allocator_type::pointer                     pointer;   
            typedef typename allocator_type::const_pointer               const_pointer;  
            typedef std::size_t                                         size_type;
            typedef std::ptrdiff_t                                      difference_type;

            typedef map< Key, T, Compare, Allocator>                    Self;
 

            class value_compare : public binary_function<value_type, value_type, bool>
            {
                public:
                    bool operator()(const value_type& left, const value_type& right) const
                    {
                        return comp(left.first, right.first);
                    }
                    value_compare(key_compare pred) : comp(pred);
                protected:
                    key_compare comp;
            };
            /*----------------------------ITERATOR TYPEDEFS-------------------------------*/
            typedef map_iterator< comp, T >                             iterator;
            typedef map_iterator< comp, const T >                       const_iterator;
            typedef Reverse_iterator<iterator>                           reverse_iterator;
            typedef Reverse_iterator< const iterator>                  const_reverse_iterator;

            private:
                RB_tree         rb_tree;
                key_compare     _compare;
                allocator_type  _alloc; 

            public:

            /*----------------ALLOCATION / DEALLOCATIONpass ------------------*/
            explicit map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()):
            _compare(comp), _alloc(allloc), rb_tree()
            {}
            template <class InputIterator>
                map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
                _compare(comp), _alloc(alloc)
            {
                //use insert method to insert
            }
            map (const map& x) : _compare(map._compare), _alloc(map._alloc), rb_tree()
            {
                //copy map by using insert method
            }
            Self    &operator=(const Self &rhs)
            {
                //clear everything
                // insert using insert
            }

            allocator_type  get_allocator() const
            {
                return this->_alloc;
            }

            /*-----------------ACCESSORS--------------------------*/
            key_compare key_comp() const;
            value_compare   value_comp const;

            /*---------------ITERATOR POS------------------*/
            iterator                begin() {}
            const_iterator          begin() const {}
            iterator                end() {}
            const_iterartor         end() const {}

            reverse_iterator        rbegin() {}
            const_reverse_iterator  rbegin() const {}
            reverse_iterator        rend() {}
            const_reverse_iterator  rend() const {}

            bool    empty()
            {
                return (rb_tree.is_empty());
            }

            size_type   size() const
            {
                return rb_tree.tree_size(rb_tree);
            }
            size_type   max_size()
            {
                return _alloc.max_szie();
            }

            T&  operator[] (const key_type& k);
            T&  at(const    key_type&   k);
            T   at(const    key_type&   k);

            void    swap(Self& x);

            /*---------------------INSERT / ERASE -----------------------*/

            pair<iterator, bool> insert(const value_type& x);
            iterator    insert(iterator position, const value_type& x);

            template <class InputIterator>
                void insert(InputIterator first, InputIterator last);
            void    erase(iterator position);
            size_type   erase(const key_type& x);
            void        erase(iterator first, iterator last);
            void        clear();

            /*-------------------OPERATIONS-------------------*/
            iterator find(const key_type& x)
            {
                return (iterator(rb_tree.find_node(rb_tree, x)));
            }
            const_iterator find(const key_type& x)
            {
                return (iterator(rb_tree.find_node(rb_tree, x)));
            }

            size_type   count(const key_type& x)
            {
                size_t count = 0;
                iterator it = begin();
                iterator ite = end()

                while (it != ite)
                {
                    if (it.current.key == x)
                        count++;
                    it++;
                }
                return count;
            }

            iterator    lower_bound(const key_type& x)
            {
                iterator it = begin();
                iterator ite = end()

                while (it != ite)
                {
                    if (it.current.key >= x)
                        return it;
                    it++;
                }
                return it;
            }

            const_iterator    lower_bound(const key_type& x) const
            {
                iterator it = begin();
                iterator ite = end()

                while (it != ite)
                {
                    if (it.current.key >= x)
                        return it;
                    it++;
                }
                return it;
            }

              iterator    upper_bound(const key_type& x)
            {
                iterator it = begin();
                iterator ite = end()

                while (it != ite)
                {
                    if (!comp(it.current.key, x))
                        return it;
                    it++;
                }
                return it;
            }

            const_iterator    upper_bound(const key_type& x) const
            {
                iterator it = begin();
                iterator ite = end()

                while (it != ite)
                {
                    if (!comp(it.current.key, x))
                        return it;
                    it++;
                }
                return it;
            }

        pair<iterator, iterator> equal_range(const key_type& x);
        pair<const_iterator, const_iterator>equl_range(const key_type& x);

            
    };

    
}

#endif
