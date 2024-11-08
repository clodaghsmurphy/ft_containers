#ifndef SET_HPP
#define SET_HPP

# include "container.hpp"

# include "set_red_black_tree.hpp"
# include "my_pair.hpp"
# include "iterator.hpp"


namespace ft 
{
     template <typename value, typename key_type, typename Node, typename Compare = std::less<value> >
    class set_iterator_base : public bidirectional_iterator_tag
    {
        public:
        typedef set_iterator_base< value, key_type, Node, Compare >  iterator;
        typedef Node    _node;
       

            typedef typename ft::bidirectional_iterator_tag iterator_category;
            typedef value               value_type;
            typedef value_type          &reference;
            typedef const value_type          &const_reference;
            typedef value_type          *pointer;
            typedef std::ptrdiff_t      difference_type;
            typedef set_rb_tree<value_type, Compare>    tree_type;
            typedef std::size_t         size_type;

        private:
           _node *current; //the rb tree of set
            const tree_type   *_tree;
           _node *null_node;
           Compare          _comp;
        public:
  public:
        set_iterator_base() : current(), _tree() , null_node(), _comp() {}
        set_iterator_base(_node *n, const tree_type *base_tree) : current(n), _tree(base_tree), null_node(base_tree->get_null_node()), _comp() {}
        set_iterator_base<value, key_type, Node, Compare>(const iterator& other) : current(other.current), _tree(other._tree), null_node(other.null_node), _comp(other._comp)  {}
        ~set_iterator_base() {}


        // iterator    &operator=(const iterator &rhs)
        // {
        //     this->current = rhs.current;
        //     this->null_node = rhs.null_node;
        //     this->_tree = rhs._tree;
        //     return *this;
        // }
        // reference   operator[](const Key& key)
        // {
        //     return current->value;
        // }
        reference   operator*() const
        {
            if (current)
                return *current->value;
            return *(_tree->get_null_node()->value);
        }
        
       pointer  operator->() const
        {
            return current->value;
        }

        iterator    &operator++()
        {
            
            if (current == NULL)
                return *this;
            if (current == _tree->tree_max())
            {
                current = NULL;
                return *this;
            }
            if (current->right != null_node)
            {
                current = current->right;
                while (current && current->left != null_node)
                    current = current->left;
            }
            else
            {
          
                _node    *parent = current->parent;
               while (parent->right && current == parent->right)
               {
                    current = parent;
                    parent = parent->parent;
               }
               if (current->right != parent)
                current = parent;
            }
            return *this ;
        }
        iterator    operator++(int)
        {
            set_iterator_base tmp(*this);
            operator++();
            return tmp;
        }
        iterator    &operator--()
        {
            if (current == NULL)
            {
                current = _tree->tree_max();

            }
            else if (current == _tree->tree_min())
            {
               return *this;
  
            }
            else if (current->left != null_node)
            {
                current = current->left;
                while (current && current->right != null_node)
                    current = current->right;
            }
            else
            {
                _node    *parent = current->parent;
               while (current == parent->left)
               {
                    current = parent;
                    parent = parent->parent;
               }
               if (current->left != parent)
                current = parent;
            }
            return *this ;
        }
        iterator    operator--(int)
        {
            set_iterator_base tmp(*this);
            operator--();
            return tmp;
        }
        bool operator==(const iterator& x)
        {
            if (!x.current && !current)
                return true;
            if ((!x.current && current) || (!current && x.current))
                return false;
            return !(_comp(*current->value, *(x.current->value)) || _comp(*(x.current->value), *current->value));
        }       

        bool operator!=(const iterator& x)
        {
            if (!x.current && !current)
                return false;
            if ((!x.current && current) || (!current && x.current))
                    return true;  
            return (_comp(*current->value, *x.current->value) || _comp(*x.current->value, *current->value));
        }

    };


    template <typename value, typename key_type, typename Node, typename Compare >
    class const_set_iterator;

    template <typename value, typename key_type, typename Node, typename Compare = std::less<value> >
    class set_iterator : public bidirectional_iterator_tag
    {
        public:
        typedef set_iterator< value, key_type, Node, Compare >  iterator;
        typedef const_set_iterator< value, key_type, Node, Compare >  const_iterator;
        typedef Node    _node;
       

            typedef typename ft::bidirectional_iterator_tag iterator_category;
            typedef const value               value_type;
            typedef value_type          &reference;
            typedef value_type          *pointer;
            typedef std::ptrdiff_t      difference_type;
            typedef set_rb_tree<value, Compare>    tree_type;
            typedef std::size_t         size_type;
        
         private:
           set_iterator_base<value, key_type, Node, Compare>    _base;
           Compare          _comp;
           //value_type   node_pair;
      

    
        /*--------------CANONICAL--------------------*/
        public:
        set_iterator() : _base(), _comp() {}
        set_iterator(_node *n, const tree_type *base_tree) : _base(n, base_tree), _comp() {}
        set_iterator(set_iterator_base<value, key_type, Node, Compare>& o_base) : _base(o_base) {}
        set_iterator<value, key_type, Node, Compare>(const iterator& other) : _base(other._base), _comp(other._comp)  {}
        set_iterator<value, key_type, Node, Compare>(const const_iterator& other) : _base(other.base()), _comp(other.get_comp())  {}

        ~set_iterator() {}

         set_iterator_base<value, key_type, Node, Compare> base() const
        {
            return _base;
        }   
        iterator    &operator=(const iterator &rhs)
        {

            this->_base = rhs._base;
            return *this;
        }
        // reference   operator[](const Key& key)
        // {
        //     return current->value;
        // }
        reference   operator*() const
        {
            return *_base;
        }
        
       pointer  operator->() const
        {
            return &(operator*());
        }
        iterator    &operator++()
        {
            _base++;
            return *this;
        }
        iterator    operator++(int)
        {
            set_iterator tmp = *this;
            operator++();
            return tmp;
        }
        iterator    &operator--()
        {
            _base--;
            return *this;
        }
        iterator    operator--(int)
        {
            set_iterator tmp = *this;
            operator--();
            return tmp;
        }

        bool operator==(const iterator& x)
        {
            return (_base == x._base);
        }       

        bool operator!=(const iterator& x)
        {
            return !(_base == x._base);
        }
        set_iterator_base<value, key_type, Node, Compare> get_base() const 
        {
            return this->_base;
        }

        Compare get_comp() const
        {

            return this->_comp;
        }
    };

     template <typename value, typename key_type, typename Node, typename Compare = ft::less<value> >
    class const_set_iterator : public bidirectional_iterator_tag
    {
        public:
        typedef const_set_iterator< value, key_type, Node, Compare >  iterator;
        typedef set_iterator< value, key_type, Node, Compare >  normal_iterator;
        typedef Node    _node;
       

            typedef typename ft::bidirectional_iterator_tag iterator_category;
            typedef const value               value_type;
            typedef value_type          &reference;
            typedef value_type          *pointer;
            typedef std::ptrdiff_t      difference_type;
            typedef set_rb_tree<value_type, Compare>   *tree_type;
            typedef std::size_t         size_type;
        
           private:
           set_iterator_base<value, key_type, Node, Compare>    _base;
           Compare          _comp;
           //value_type   node_pair;
      

    
        /*--------------CANONICAL--------------------*/
        public:
        const_set_iterator() : _base(), _comp() {}
        const_set_iterator(_node *n, const set_rb_tree<value, Compare> *base_tree) : _base(n, base_tree), _comp() {}
        const_set_iterator(const const_set_iterator& other) : _base(other._base), _comp(other._comp)  {}
        const_set_iterator(const set_iterator_base<value, key_type, Node, Compare>& o_base) : _base(o_base) {}
       const_set_iterator<value, key_type, Node, Compare>(const normal_iterator& other) : _base(other.base()), _comp(other.get_comp())  {}
        ~const_set_iterator() {}

   
         set_iterator_base<value, key_type, Node, Compare> base() const
        {
            return _base;
        }
        
        iterator    &operator=(const iterator &rhs)
        {
            this->_base = rhs._base;
            return *this;
        }
        // reference   operator[](const Key& key)
        // {
        //     return current->value;
        // }
        reference   operator*() const
        {
            return *_base;
        }
        
       pointer  operator->() const
        {
            return &(operator*());
        }
        iterator    &operator++()
        {
            _base++;
            return *this;
        }
        iterator    operator++(int)
        {
            const_set_iterator tmp = *this;
            operator++();
            return tmp;
        }
        iterator    &operator--()
        {
            _base--;
            return *this;
        }
        iterator    operator--(int)
        {
            const_set_iterator tmp = *this;
           operator--();
            return tmp;
        }

        bool operator==(const iterator& x)
        {
            return (_base == x._base);
        }       

        bool operator!=(const iterator& x)
        {
            return (_base != x._base);
        }
           set_iterator_base<value, key_type, Node, Compare> get_base() const 
        {
            return this->_base;
        }
              Compare get_comp() const
        {

            return this->_comp;
        }
    };


    template<class Key, class Compare = ft::less<Key>, class Allocator = std::allocator<Key> >
    class set
    {
        
        public:
        /*--------------------------------------TYPEDEFS----------------------------------*/
            typedef Key                                         value_type;
            typedef Key                                   key_type;
            typedef Compare                                     key_compare;
            typedef Compare                                     value_compare;
            typedef Allocator                                   allocator_type;
            
            typedef typename allocator_type::reference                   reference;   
            typedef typename allocator_type::const_reference             const_reference;   
            typedef typename allocator_type::pointer                     pointer;   
            typedef typename allocator_type::const_pointer               const_pointer;  
            typedef std::size_t                                         size_type;
            typedef std::ptrdiff_t                                      difference_type;

            typedef set< Key, Compare, Allocator>                    Self;
 

            // class value_compare : public binary_function<value_type, value_type, bool>
            // {
            //     public:
            //         bool operator()(const value_type& left, const value_type& right) const
            //         {
            //             return comp(left.first, right.first);
            //         }
            //         value_compare() : comp() {}
            //     protected:
            //         value_compare(Compare pred) : comp(pred){}
            //         key_compare comp;
            // };
            // class set_compare : public binary_function<value_type, value_type, bool>
            // {
            //     public:
            //         bool operator()(const value_type& left, const value_type& right) const
            //         {
            //             return comp(left.second, right.second);
            //         }
            //         set_compare() : comp() {}
            //     protected:
            //         set_compare(Compare pred) : comp(pred){}
            //         key_compare comp;
            // };

            typedef set_rb_tree<value_type, value_compare>                             RB_tree;
            typedef typename set_rb_tree<value_type, value_compare>::NodePtr                    _node;

            /*----------------------------ITERATOR TYPEDEFS-------------------------------*/
            typedef set_iterator< value_type, key_type, _node, value_compare>                             iterator;
            typedef const_set_iterator<  value_type, key_type, _node, value_compare >                     const_iterator;
            typedef Reverse_iterator<iterator>                           reverse_iterator;
            typedef Reverse_iterator< const_iterator>                  const_reverse_iterator;

            private:
                RB_tree                        tree;
                key_compare                     _compare;
                allocator_type                  _alloc; 

            public:

            /*----------------ALLOCATION / DEALLOCATIONpass ------------------*/
            explicit set(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type()) :
            tree(), _compare(comp), _alloc(alloc)
            {}
            template <class InputIt>
                set(InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIt>::value, iterator>::type* = NULL ) :
                tree(), _compare(comp), _alloc(alloc)
            {
                insert(first,last);
            }
            set (const Self& x) : tree(x.tree), _compare(x._compare), _alloc(x._alloc)
            {
                return ;
            }
           Self   &operator=(const Self &rhs)
            {
               clear();
               this->tree= rhs.tree;
               this->_compare = _compare;
               this->_alloc = _alloc;
                return *this;
            }
      
            allocator_type  get_allocator() const
            {
                return this->_alloc;
            }

            /*-----------------ACCESSORS--------------------------*/
            key_compare key_comp() const { return _compare; };
            value_compare   value_comp() const { return value_compare(); }

            /*---------------ITERATOR POS------------------*/
            iterator                begin() { return iterator(tree.begin(), &tree);}
            const_iterator          begin() const { return const_iterator(tree.begin(), &tree);}
            iterator                end() { return iterator(NULL, &tree);}
            const_iterator         end() const { return const_iterator(NULL, &tree);}

            reverse_iterator        rbegin() { return reverse_iterator(end());  }
            const_reverse_iterator  rbegin() const { return const_reverse_iterator(const_iterator(end()));}
            reverse_iterator        rend() { return reverse_iterator(iterator(begin()));}
            const_reverse_iterator  rend() const { return const_reverse_iterator(const_iterator(begin()));}

            bool    empty() const
            {
                return (tree.is_empty());
            }

            size_type   size() const
            {
                return tree.size();
            }
            size_type   max_size() const
            {
                std::allocator< _node>  val_alloc;
                return val_alloc.max_size()  ;
            }

            value_type&  operator[](const Key& key)
            {
         
                    insert(key);
                    return ((*find(key)).second);

            }
            value_type&          at(const    key_type&   k);
            const value_type&   at(const    key_type&   k) const;

            void    swap(set<Key, Compare>& x)
            {   
                tree.tree_swap(x.tree);
            }

            /*---------------------INSERT / ERASE -----------------------*/

            ft::pair<iterator, bool> insert(const value_type& x)
            {
                bool res = tree.insert(x);
                iterator it = find(x);

                return ft::pair<iterator, bool>(it, res);
            }
            iterator    insert(iterator position, const value_type& x)
            {
                (void)position;
                 bool res = tree.insert(x);
                 iterator it;
                if (res)
                {
                    iterator it = find(x);
                    return it;
                }
                return end();
            }

            template <class InputIterator>
                void insert(InputIterator first, InputIterator last)
                {
                    InputIterator save_first = first;
                    for(; save_first != last; save_first++)
                    {
                        insert((*save_first));
                    }
                }
            void    erase(iterator position)
            {
                tree.delete_node((*position));
            }
            size_type   erase(const key_type& x)
            {
                iterator it = find(x);

                if (it == end())
                    return 0;
                tree.delete_node(x);
                return 1;
            }
            void        erase(iterator first, iterator last)
            {
                iterator save_first;
                while(first != last)
                {
                    save_first= first;
                    first++;
                    //std::cout << (*first).first << std::endl;
                    tree.delete_node(*save_first);
                }
            }
            void        clear()
            {
                tree.tree_clear();
            }

            /*-------------------OPERATIONS-------------------*/
            iterator find(const key_type& x)
            {
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if ((*it) == x)
                        return it;
                    it++;
                }
                return end();
            }
            const_iterator find(const key_type& x) const
            {
                const_iterator it = begin();
                const_iterator ite = end();

                while (it != ite)
                {
                    if ((*it) == x)
                        return it;
                    it++;
                }
                return end();
            }

            size_type   count(const key_type& x) const
            {
                size_t count = 0;
                const_iterator it = begin();
                const_iterator ite = end();

                while (it != ite)
                {
                    if (!(_compare((*it), x) || _compare(x, (*it))))
                        count++;
                    it++;
                }
                return count;
            }

            iterator    lower_bound(const key_type& x)
            {
                iterator it = begin();
                iterator ite = end();

                while (it != ite)
                {
                    if (!_compare((*it), x))
                        return it;
                    it++;
                }
                return end();
            }

            const_iterator    lower_bound(const key_type& x) const
            {
                const_iterator it = begin();
                const_iterator ite = end();
                bool res;

                while (it != ite)
                {
                    res = _compare((*it), x);
                    if (!res)
                        return it;
                    it++;
                }
                return end();
            }

              iterator    upper_bound(const key_type& x)
            {
                iterator it = begin();
                iterator ite = end();

                for(; it != ite; it++)
                {
                    if (_compare(x, (*it) ))
                        return it;

                }
                   
                return end();
            }

            const_iterator    upper_bound(const key_type& x) const
            {
                const_iterator it = begin();
                const_iterator ite =end();

                for(; it != ite; it++)
                {
                    if (_compare(x, (*it) ))
                        return it;

                }
                  
                return end();
            }

        pair<iterator, iterator> equal_range(const Key& x)
        {
            return ft::pair<iterator, iterator>(lower_bound(x), upper_bound(x));
        }
        pair<const_iterator, const_iterator>equal_range(const Key& x) const
        {
            return ft::pair<const_iterator, const_iterator>(lower_bound(x), upper_bound(x));
        }
        bool operator==(const  set<Key, Compare >& rhs) const
        {
            return ft::equal(this->begin(), this->end(), rhs.begin(), rhs.end());
        }
        bool operator!=(const  set<Key, Compare >& rhs) const
        {
            return !(*this == rhs);
        }
        bool operator<(const  set<Key, Compare >& rhs) const
        {
            return ft::lexicographical_compare<const_iterator, const_iterator, value_compare>(this->begin(), this->end(), rhs.begin(), rhs.end(), value_compare());
        }
        bool operator<=(const  set<Key, Compare >& rhs) const
        {
            return (!(rhs < *this));
        }
        bool operator>(const set<Key, Compare >& rhs) const
        {
            return (rhs < *this);
        }
        bool operator>=(const set<Key, Compare >& rhs) const
        {
            return !(*this < rhs);
        }
    };

    
}

#endif