#ifndef MAP_HPP
#define MAP_HPP

# include "container.hpp"
# include "red_black_tree.hpp"
# include "my_pair.hpp"
# include "iterator.hpp"


namespace ft 
{
     template <typename value, typename key_type, typename Node, typename Compare = ft::less<value> >
    class map_iterator_base : public bidirectional_iterator_tag
    {
        public:
        typedef map_iterator_base< value, key_type, Node, Compare >  iterator;
        typedef Node    _node;
       

            typedef typename ft::bidirectional_iterator_tag iterator_category;
            typedef value               value_type;
            typedef value_type          &reference;
            typedef value_type          *pointer;
            typedef std::ptrdiff_t      difference_type;
            typedef rb_tree<value_type, key_type, Compare>    tree_type;
            typedef std::size_t         size_type;

        private:
        std::allocator<value> _alloc;
           _node current; //the rb tree of map
            const tree_type   *_tree;
           _node null_node;
           _node max_node;
           _node min_node;
           Compare          _comp;
        public:
  public:
        map_iterator_base() : current(), _tree() , null_node(), max_node(), min_node(), _comp() {}
        map_iterator_base(bool is_begin, const tree_type *base_tree) :  _tree(base_tree), null_node(base_tree->get_null_node()),  _comp() 
        {
            max_node = _tree->tree_max();
            min_node = _tree->tree_min();
     
           if (is_begin)
           {
                current = min_node;
           
           }
            else
                current = NULL;
        }
        map_iterator_base<value, key_type, Node, Compare>(const iterator& other) : current(other.current), _tree(other._tree),  null_node(other.null_node), max_node(other.max_node), min_node(other.min_node), _comp(other._comp) 
        {}
        ~map_iterator_base() {}

        _node   get_current() const{ return current; }

        reference   operator*() const
        {

            return *(current->value);
        }
        
       pointer  operator->() const
        {
            return (current->value);
        }

        iterator    &operator++()
        {
            
            if (current == NULL)
                return *this;
            if (current == max_node)
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
          
                _node    parent = current->parent;
               while (parent && parent->right && current == parent->right)
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
            map_iterator_base tmp(*this);
            operator++();
            return tmp;
        }
        iterator    &operator--()
        {
            if (current == NULL)
            {
                current = max_node;

            }
            else if (current == min_node)
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
                _node    parent = current->parent;
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
            map_iterator_base tmp(*this);
            operator--();
            return tmp;
        }
        bool operator==(const iterator& x)
        {
            if (!x.current && !current)
                return true;
            if ((!x.current && current) || (!current && x.current))
                return false;
            return !(_comp(*(current->value), *(x.current->value)) || _comp(*(x.current->value), *(current->value)));
        }       

        bool operator!=(const iterator& x)
        {
            if (!x.current && !current)
                return false;
            if ((!x.current && current) || (!current && x.current))
                    return true;  
            return (_comp(*(current->value), *(x.current->value)) || _comp(*(x.current->value), *(current->value)));
        }

    };

    template <typename value, typename key_type, typename Node, typename Compare = ft::less<value> >
    class map_iterator : public bidirectional_iterator_tag
    {
        public:
        typedef map_iterator< value, key_type, Node, Compare >  iterator;
        typedef Node    _node;
       

            typedef typename ft::bidirectional_iterator_tag iterator_category;
            typedef value               value_type;
            typedef value_type          &reference;
            typedef value_type          *pointer;
            typedef std::ptrdiff_t      difference_type;
            typedef rb_tree<value_type, key_type, Compare>    tree_type;
            typedef std::size_t         size_type;
        
         private:
           map_iterator_base<value, key_type, Node, Compare>    _base;
           Compare          _comp;
           //value_type   node_pair;
      

    
        /*--------------CANONICAL--------------------*/
        public:
        map_iterator() : _base(), _comp() {}
        map_iterator(bool is_begin, const tree_type *base_tree) : _base(is_begin, base_tree), _comp() {}
        map_iterator(map_iterator_base<value, key_type, Node, Compare>& o_base) : _base(o_base) {}
        map_iterator<value, key_type, Node, Compare>(const iterator& other) : _base(other._base), _comp(other._comp)  {}
        ~map_iterator() {}

         map_iterator_base<value_type, key_type, Node, Compare> base() const
        {
            return _base;
        }   
        // iterator    &operator=(const iterator &rhs)
        // {

        //     this->_base = rhs._base;
        //     return *this;
        // }
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
            if (!_base.get_current())
                return NULL;
            return &(operator*());
        }
        iterator    &operator++()
        {
            _base++;
            return *this;
        }
        iterator    operator++(int)
        {
            map_iterator tmp = *this;
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
            map_iterator tmp = *this;
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
        map_iterator_base<value, key_type, Node, Compare> get_base() const 
        {
            return this->_base;
        }

        Compare get_comp() const
        {

            return this->_comp;
        }
    };

     template <typename value, typename key_type, typename Node, typename Compare = ft::less<value> >
    class const_map_iterator : public bidirectional_iterator_tag
    {
        public:
        typedef const_map_iterator< value, key_type, Node, Compare >  iterator;
        typedef map_iterator< value, key_type, Node, Compare >  normal_iterator;
        typedef Node    _node;
       

            typedef typename ft::bidirectional_iterator_tag iterator_category;
            typedef const value               value_type;
            typedef value_type          &reference;
            typedef value_type          *pointer;
            typedef std::ptrdiff_t      difference_type;
            typedef rb_tree<value_type, key_type, Compare>   *tree_type;
            typedef std::size_t         size_type;
        
           private:
           map_iterator_base<value, key_type, Node, Compare>    _base;
           Compare          _comp;
           //value_type   node_pair;
      

    
        /*--------------CANONICAL--------------------*/
        public:
        const_map_iterator() : _base(), _comp() {}
        const_map_iterator(bool is_begin, const rb_tree<value, key_type, Compare> *base_tree) : _base(is_begin, base_tree), _comp() {}
        const_map_iterator(const const_map_iterator& other) : _base(other._base), _comp(other._comp)  {}
        const_map_iterator(const map_iterator_base<value, key_type, Node, Compare>& o_base) : _base(o_base) {}
        const_map_iterator<value, key_type, Node, Compare>(const normal_iterator& other) : _base(other.base()), _comp(other.get_comp())  {}
        ~const_map_iterator() {}

   
        iterator    &operator=(const iterator &rhs)
        {
            this->_base = rhs._base;
            return *this;
        }
 
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
            const_map_iterator tmp = *this;
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
            const_map_iterator tmp = *this;
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
           map_iterator_base<value, key_type, Node, Compare> get_base() const 
        {
            return this->_base;
        }
              Compare get_comp() const
        {

            return this->_comp;
        }
    };


    template<class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        
        public:
        /*--------------------------------------TYPEDEFS----------------------------------*/
            typedef ft::pair< Key, T>                          value_type;
            typedef const Key                                         key_type;
            typedef T                                           mapped_type;
            typedef Compare                                     key_compare;
            typedef Allocator                                   allocator_type;
            
            typedef typename allocator_type::reference                   reference;   
            typedef typename allocator_type::const_reference             const_reference;   
            typedef typename allocator_type::pointer                     pointer;   
            typedef typename allocator_type::const_pointer               const_pointer;  
            typedef std::size_t                                         size_type;
            typedef std::ptrdiff_t                                      difference_type;

            typedef map< const Key, T, Compare, Allocator>                    Self;
 

            class value_compare : public binary_function<value_type, value_type, bool>
            {
                public:
                    bool operator()(const value_type& left, const value_type& right) const
                    {
                        return comp(left.first, right.first);
                    }
                    value_compare() : comp() {}
                protected:
                    value_compare(Compare pred) : comp(pred){}
                    key_compare comp;
            };
            class map_compare : public binary_function<value_type, value_type, bool>
            {
                public:
                    bool operator()(const value_type& left, const value_type& right) const
                    {
                        return left < right;
                    }
                    map_compare() : comp() {}
                protected:
                    map_compare(Compare pred) : comp(pred){}
                    key_compare comp;
            };

            typedef rb_tree<value_type, key_type, value_compare>                             RB_tree;
            typedef typename rb_tree<value_type, value_compare>::NodePtr                    _node;

            /*----------------------------ITERATOR TYPEDEFS-------------------------------*/
            typedef map_iterator< value_type, key_type, _node, value_compare>                             iterator;
            typedef const_map_iterator< value_type, key_type, _node, value_compare >                     const_iterator;
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
            map (const Self& x) : tree(), _compare(x._compare), _alloc(x._alloc)
            {
            
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
            iterator                begin() { return iterator(1, &tree);}
            const_iterator          begin() const { return const_iterator(1, &tree);}
            iterator                end() { return iterator(0, &tree);}
            const_iterator         end() const { return const_iterator(0, &tree);}

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

            T&  operator[](const Key& key)
            {
         
                    insert(value_type(key,mapped_type()));
                    return ((*find(key)).second);

            }
            T&          at(const    key_type&   k);
            const T&   at(const    key_type&   k) const;

            void    swap(map<Key, T, Compare>& x)
            {
               

                
                tree.tree_swap(x.tree);
            }

            /*---------------------INSERT / ERASE -----------------------*/

            ft::pair<iterator, bool> insert(const value_type& x)
            {
                bool res = tree.insert(x);
                iterator it = find(x.first);

                return ft::pair<iterator, bool>(it, res);
            }
            iterator    insert(iterator position, const value_type& x)
            {
                (void)position;
                 bool res = tree.insert(x);
                 iterator it;
                if (res)
                {
                    iterator it = find(x.first);
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
                        insert(value_type((*save_first).first, (*save_first).second));
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
                tree.delete_node(value_type(x, mapped_type()));
                return 1;
            }
            void        erase(iterator first, iterator last)
            {
                iterator save_first;
                if (first == begin() && last == end())
                {
                    tree.tree_clear();
                    return ;
                }
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
                    if ((*it).first == x)
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
                    if ((*it).first == x)
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
                    if (!(_compare((*it).first, x) || _compare(x, (*it).first)))
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
                    if (!_compare((*it).first, x))
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
                    res = _compare((*it).first, x);
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
                    if (_compare(x, (*it).first ))
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
                    if (_compare(x, (*it).first ))
                        return it;

                }
                  
                return end();
            }

        pair<iterator, iterator> equal_range(const key_type& x)
        {
            return ft::pair<iterator, iterator>(lower_bound(x), upper_bound(x));
        }
        pair<const_iterator, const_iterator>equal_range(const key_type& x) const
        {
            return ft::pair<const_iterator, const_iterator>(lower_bound(x), upper_bound(x));
        }
        bool operator==(const  map<Key, T, Compare >& rhs) const
        {
            return ft::equal(this->begin(), this->end(), rhs.begin(), rhs.end());
        }
        bool operator!=(const  map<Key, T, Compare >& rhs) const
        {
            return !(*this == rhs);
        }
        bool operator<(const  map<Key, T, Compare >& rhs) const
        {
            return ft::lexicographical_compare<const_iterator, const_iterator, map_compare>(this->begin(), this->end(), rhs.begin(), rhs.end(), map_compare());
        }
        bool operator<=(const  map<Key, T, Compare >& rhs) const
        {
            return (!(rhs < *this));
        }
        bool operator>(const map<Key, T, Compare >& rhs) const
        {
            return (rhs < *this);
        }
        bool operator>=(const map<Key, T, Compare >& rhs) const
        {
            return !(*this < rhs);
        }
    };

    
}

#endif
