#ifndef MAP_HPP
#define MAP_HPP

# include "container.hpp"
# include "red_black_tree.hpp"
# include "pair.hpp"


namespace ft 
{
    template <typename Key, typename T, typename Node >
    class map_iterator : public bidirectional_iterator_tag
    {
        typedef map_iterator< Key, T, Node >  iterator;
        private:
           Node *current; //the rb tree of map
        public:

            typedef typename ft::bidirectional_iterator_tag iterator_category;
            typedef pair<const Key, T> value_type;
            typedef value_type &reference;
            typedef value_type *pointer;
            typedef std::ptrdiff_t   difference_type;
            typedef std::size_t         size_type;
            

        /*--------------CANONICAL--------------------*/
        map_iterator() : current() {}
        map_iterator(Node *n) : current(n) {}
        map_iterator(const map_iterator other) : current(other.current) {}
        ~map_iterator() {}

        bool operator== (const map_iterator& rhs) const;
        bool operator!=(const map_iterator& rhs) const;
        iterator    &operator++()
        {
            if (current->right != null)
            {
                current = current->right;
                while (current->left != NULL)
                    current = current->left
            }
            else
            {
                Node *y = current->parent;
                while (current == y->right)
                {
                    current = y->parent;
                    y = y->parent;
                }
            }
            return *this ;
        }
        iterator    operator++(int){
            map_iterator tmp = *this;
            operator++;
            return tmp;
        }
        iterator    operator--()
        {
            if (current->left != null)
            {
                current = current->left;
                while (current->right != NULL)
                    current = current->right
            }
            else
            {
                Node *y = current->parent;
                while (current == y->right)
                {
                    current = y->parent;
                    y = y->parent;
                }
            }
            return *this;
        }
        iterator    operator--(int)
        {
            map_iterator tmp = *this;
            operator++;
            return tmp;
        }

        bool operator==(const iterator& x)
        {
            return (current == x.current);
        }       

        bool operator!=(const iterator& x)
        {
            return (current != x.current);
        }
        
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
            typedef map_iterator< Key, T, Node >                             iterator;
            typedef map_iterator< const Key, const T, const Node >                       const_iterator;
            typedef Reverse_iterator<iterator>                           reverse_iterator;
            typedef Reverse_iterator< const_iterator>                  const_reverse_iterator;

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
            iterator    insert(iterator position, const value_type& x)
            {
                iterator it = iterator(rb_tree.insert(Node(x.first, x.second)));
            }

            template <class InputIterator>
                void insert(InputIterator first, InputIterator last)
                {
                    for(; first != last; first++)
                        insert(*first.first, *first.second);
                }
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
