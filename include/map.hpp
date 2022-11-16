#ifndef MAP_HPP
#define MAP_HPP

# include "container.hpp"
# include "red_black_tree.hpp"
# include "my_pair.hpp"
# include "iterator.hpp"


namespace ft 
{
    template <typename Key, typename T, typename Node >
    class map_iterator : public bidirectional_iterator_tag
    {
        public:
        typedef map_iterator< Key, T, Node >  iterator;
        typedef Node    _node;
       

            typedef typename ft::bidirectional_iterator_tag iterator_category;
            typedef pair<const Key, T> value_type;
            typedef value_type          &reference;
            typedef value_type          *pointer;
            typedef std::ptrdiff_t      difference_type;
            typedef std::size_t         size_type;
        
         private:
           _node *current; //the rb tree of map
           //value_type   node_pair;

        /*--------------CANONICAL--------------------*/
        public:
        map_iterator() : current() {}
        map_iterator(_node *n) : current(n) {}
        map_iterator<Key, T, Node>(const iterator& other) : current(other.current) {}
        ~map_iterator() {}

        iterator    &operator=(const iterator &rhs)
        {
            this->current = rhs.current;
            return *this;
        }
        reference   operator*() const
        {
            return current->value;
        }
       pointer  operator->() const
        {
            return &(operator*());
        }
        iterator    &operator++()
        {
            if (current->right != NULL)
            {
                current = current->right;
                while (current->left != NULL)
                    current = current->left;
            }
            else
            {
                _node *y = current->parent;
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
            this++;
            return tmp;
        }
        iterator    operator--()
        {
            if (current->left != NULL)
            {
                current = current->left;
                while (current->right != NULL)
                    current = current->right;
            }
            else
            {
                _node *y = current->parent;
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
            this--;
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
            typedef pair<const Key, T>                          value_type;
            typedef rb_tree<value_type, Compare>                             RB_tree;
            typedef typename rb_tree<value_type, Compare>::NodePtr                    _node;
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
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
                    value_compare(key_compare pred) : comp(pred){}
                protected:
                    key_compare comp;
            };
            /*----------------------------ITERATOR TYPEDEFS-------------------------------*/
            typedef map_iterator< Key, T, _node >                             iterator;
            typedef map_iterator< const Key, const T, const _node >                       const_iterator;
            typedef Reverse_iterator<iterator>                           reverse_iterator;
            typedef Reverse_iterator< const_iterator>                  const_reverse_iterator;

            private:
                RB_tree                        tree;
                key_compare                     _compare;
                allocator_type                  _alloc; 

            public:

            /*----------------ALLOCATION / DEALLOCATIONpass ------------------*/
            explicit map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()) :
            tree(), _compare(comp), _alloc(alloc)
            {}
            template <class InputIt>
                map(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIt>::value, iterator>::type* = NULL ) :
                tree(), _compare(comp), _alloc(alloc)
            {
                insert(first,last);
            }
            map (const map& x) : tree(), _compare(x._compare), _alloc(x._alloc)
            {
                //copy map by using insert method
            }
            Self    &operator=(const Self &rhs)
            {
                clear();
                insert(rhs.begin(), rhs.end());
                // insert using insert
            }

            allocator_type  get_allocator() const
            {
                return this->_alloc;
            }

            /*-----------------ACCESSORS--------------------------*/
            key_compare key_comp() const;
            value_compare   value_comp() const;

            /*---------------ITERATOR POS------------------*/
            iterator                begin() { return iterator(tree.begin());}
            const_iterator          begin() const { return const_iterator(tree.begin());}
            iterator                end() { return iterator(tree.end());}
            const_iterator         end() const { return const_iterator(tree.end());}

            reverse_iterator        rbegin() { return reverse_iterator(iterator(tree.end()));  }
            const_reverse_iterator  rbegin() const { return const_reverse_iterator(const_iterator(tree.end()));}
            reverse_iterator        rend() { reverse_iterator(iterator(tree.begin()));}
            const_reverse_iterator  rend() const { const_reverse_iterator(const_iterator(tree.begin()));}

            bool    empty()
            {
                return (tree.is_empty());
            }

            size_type   size() const
            {
                return tree.tree_size(tree);
            }
            size_type   max_size()
            {
                return _alloc.max_szie();
            }

            T&          operator[] (const key_type& k);
            T&          at(const    key_type&   k);
            const T&   at(const    key_type&   k) const;

            void    swap(Self& x);

            /*---------------------INSERT / ERASE -----------------------*/

            pair<iterator, bool> insert(const value_type& x)
            {
                bool res = tree.insert(x);
                if (res)
                {
                    iterator it = find(x.first);
                    return ft::pair<iterator, bool>(it, 1);
                }
                return ft::pair<iterator, bool>(NULL, 0);
            }
            iterator    insert(iterator position, const value_type& x)
            {
                (void)position;
                //need to finish this
                iterator it = iterator(tree.insert(Node<value_type>(x)));
            }

            template <class InputIterator>
                void insert(InputIterator first, InputIterator last)
                {
                    for(; first != last; first++)
                        insert(value_type(*first.first, *first.second));
                }
            void    erase(iterator position);
            size_type   erase(const key_type& x);
            void        erase(iterator first, iterator last);
            void        clear();

            /*-------------------OPERATIONS-------------------*/
            iterator find(const key_type& x)
            {
                _node *res = tree.find_node( ft::pair<key_type, mapped_type>(x, mapped_type()), _compare);
                if (res == NULL)
                    return end();
                return iterator(res);
            }
            const_iterator find(const key_type& x) const
            {
                _node *res = tree.find_node( ft::pair<key_type, mapped_type>(x, mapped_type()), _compare);
                if (res == NULL)
                    return end();
                return iterator(res);
            }

            size_type   count(const value_type& x)
            {
                size_t count = 0;
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if (it.current.first == x)
                        count++;
                    it++;
                }
                return count;
            }

            iterator    lower_bound(const value_type& x)
            {
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if (it.current.first >= x)
                        return it;
                    it++;
                }
                return it;
            }

            const_iterator    lower_bound(const value_type& x) const
            {
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if (it.current.first >= x)
                        return it;
                    it++;
                }
                return it;
            }

              iterator    upper_bound(const value_type& x)
            {
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if (!comp(it.current.first, x))
                        return it;
                    it++;
                }
                return it;
            }

            const_iterator    upper_bound(const value_type& x) const
            {
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if (!comp(it.current.first, x))
                        return it;
                    it++;
                }
                return it;
            }

        pair<iterator, iterator> equal_range(const value_type& x);
        pair<const_iterator, const_iterator>equl_range(const value_type& x);

            
    };

    
}

#endif
