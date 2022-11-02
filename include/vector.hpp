# ifndef VECTOR_HPP
# define VECTOR_HPP

# include "container.hpp"
# include "iterator.hpp"

namespace ft
{
    template<typename T>
    class Vectoriterator
    {
              
        public:
            typedef T                               value_type;
            typedef value_type*                     pointer;
            typedef value_type                      &reference;
            typedef T const                        &const_reference;
            typedef std::ptrdiff_t                  difference_type;
            typedef random_access_iterator_tag      iterator_category;

        protected:
            pointer _ptr;

        public:
            Vectoriterator(pointer ptr) : _ptr(ptr) {
                
            }
            Vectoriterator() : _ptr(NULL) {}
            Vectoriterator(const Vectoriterator& obj) : _ptr(obj._ptr) {
                *this = obj;

            }
            Vectoriterator<T> &operator=(const Vectoriterator& rhs)
            {

                this->_ptr = rhs._ptr;
                return *this;
            }
  
            Vectoriterator<T> &operator++()
            {
                _ptr++;
                return *this;
            }
            Vectoriterator<T> operator++(int)
            {
                Vectoriterator it = *this;
                ++(*this);
                return it;
            }
            Vectoriterator<T> &operator--()
            {
                _ptr--;
                return *this;
            }
            Vectoriterator<T> operator--(int)
            {
                Vectoriterator it = *this;
                operator--();
                //--(*this);
                return it;
            }
            pointer operator->() const
            {
                return _ptr;
            }
            reference operator*() const 
            {
                return *(this->_ptr);
            }
            reference operator[](difference_type n) const
            {
                return this->_ptr[n];
            }
            Vectoriterator  &operator+=(difference_type n)
            {
                this->_ptr += n;
                return *this;
            }
            Vectoriterator operator+(difference_type n) const
            {
                return Vectoriterator(this->_ptr + n);
            }
            Vectoriterator operator+(difference_type n)
            {
                return Vectoriterator(this->_ptr + n);
            }
            difference_type operator+(const Vectoriterator<T> &right) const
            {
                return this->_ptr + right._ptr;
            }
            Vectoriterator &operator-=(difference_type n)
            {
                this->_ptr -= n;
                return *this;
            }
            Vectoriterator operator-(difference_type n) const
            {
                return Vectoriterator(this->_ptr - n);
            }
            Vectoriterator operator-(difference_type n)
            {
                return Vectoriterator(this->_ptr - n);
            }
            bool operator==(const Vectoriterator<T> &y) const
            {
                return _ptr == y._ptr;
            }
            operator Vectoriterator<const T>() const  {return _ptr;}
            
            template <typename _T>
                friend bool operator!=(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y);
            template <typename _T>
                friend bool operator==(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y);
            template <typename _T>
                friend bool operator>=(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y);
            template <typename _T>
                friend bool operator<=(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y);
            template <typename _T>
                friend bool operator>(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y);
            template <typename _T>
                friend bool operator<(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y);
            
            template<typename IteratorL, typename IteratorR>
                friend bool operator!=(const Vectoriterator<IteratorL> &x, const Vectoriterator<IteratorR> &y);
  


            pointer base() const { return _ptr; } 
            void setPointer(pointer ptr) {  _ptr = ptr; }
    };

     template<typename Iterator>
    typename Vectoriterator<Iterator>::difference_type operator-(const Vectoriterator<Iterator> &x, const Vectoriterator<Iterator> &y)
    {
        return x.base() - y.base();
    }
    template<typename IteratorL, typename IteratorR>
    typename Vectoriterator<IteratorL>::difference_type operator-(const Vectoriterator<IteratorL> &x, const Vectoriterator<IteratorR> &y)
    {
        return x.base() - y.base();
    }
  

    template<typename IteratorL, typename IteratorR>
    typename Vectoriterator<IteratorL>::difference_type operator+(const Vectoriterator<IteratorL> &x, const Vectoriterator<IteratorR> &y)
    {
        return x.base() + y.base();
    }
    template<typename Iterator>
    typename Vectoriterator<Iterator>::difference_type operator+(const Vectoriterator<Iterator> &x, const Vectoriterator<Iterator> &y)
    {
        return x.base() + y.base();
    }
    template <typename _T>
    Vectoriterator<_T> operator+(const Vectoriterator<_T> &x, Vectoriterator<_T> &y)
    {
        return x.base() + y.base();
    }
       template <typename _T>
    Vectoriterator<_T> operator+(size_t n, const Vectoriterator<_T> &x)
    {
        return n + x.base();
    }
    template<typename _T>
    bool operator!=(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y)
    {
        return !(x._ptr == y._ptr);
    }

    template<typename IteratorL, typename IteratorR>
    bool operator!=(const Vectoriterator<IteratorL> &x, const Vectoriterator<IteratorR> &y)
    {
        return !(x._ptr == y._ptr);
    }
    template<typename IteratorL, typename IteratorR>
    bool operator==(const Vectoriterator<IteratorL> &x, const Vectoriterator<IteratorR> &y)
    {
        return (x.base() == y.base());
    }
    template<typename _T>
    bool operator>=(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y)
    {
        return !(x._ptr < y._ptr);
    }
    template<typename _T>
    bool operator<=(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y)
    {
        return !(x._ptr > y._ptr);
    }
    template<typename _T>
    bool operator<(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y)
    {
        return (x._ptr < y._ptr);
    }
    template<typename _T>
    bool operator>(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y)
    {
        return (x._ptr > y._ptr);
    }

    template < class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            /*----------------- MEMBER TYPES ------------------*/
            typedef T                           value_type;
            typedef Allocator                   allocator_type;

            typedef T*                          pointer;
            typedef const T*                    const_pointer;

            typedef T&                          reference;
            typedef const T&                    const_reference;

            typedef std::size_t                 size_type;
            typedef std::ptrdiff_t              difference_type;

            typedef Vectoriterator<T >                      iterator;
            typedef Vectoriterator<const T >                const_iterator;
            typedef Reverse_iterator<iterator >             reverse_iterator;
            typedef Reverse_iterator<const_iterator >       const_reverse_iterator;

            T*              _data;
            size_t           _size;
            size_t          _capacity;
            allocator_type  _alloc;
            
            void ReAlloc(size_t n)
            {
                // if (n < _capacity || !n)
                //     return ;
                T* new_block = 0;

                new_block = _alloc.allocate( n);
                size_type i = 0;
                if (n < _size)
                {
                    _size = n;
                }
                for (i = 0; i < _size; i++)
                {
                    _alloc.construct(new_block + i, *(_data + i));
                    _alloc.destroy(_data + i);
                }
               
                _alloc.deallocate(_data, _capacity);
                _data = 0;
                _data = new_block;
                _capacity = n;
            }
            /*----------------- MEMBER FUNCTIONS ---------------*/
            public:
                vector() : _data(NULL), _size(0), _capacity(0) {
                    _data = _alloc.allocate(_capacity);   
                }
                
                 explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : _data(NULL), _size(count), _capacity(count), _alloc(alloc)
                    {
                        _data = _alloc.allocate( count );
                        for (size_t i = 0; i < count; i++)
                           _alloc.construct(_data + i, value);
                    }

                    template <typename InputIt>
                    vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value, iterator>::type* = NULL  ) :  _data(NULL), _size(0), _capacity(0), _alloc(alloc)
                    {
                        //_data = _alloc.allocate(_capacity); 
                        insert(begin(), first, last);
            
                    } 
                vector( const vector& other ) : _data(0), _size(0), _capacity(0)
                {
                    this->insert(begin(), other.begin(), other.end());

                }
                ~vector() {
                    clear();
                    _alloc.deallocate(_data, _capacity);
                    return ;
                }
                vector<T>   operator=(const vector<T> &rhs)
                {
                    if (*this == rhs)
                        return *this;
                    clear();
                    this->insert(begin(), rhs.begin(), rhs.end());
                    return *this;
                }
                /*-----------------CAPACITY -----------------------*/
                bool                empty() const { return _size == 0; }
                size_type           size() const { return this->_size; }
                size_type           max_size() const {
                    size_type res = _alloc.max_size();
                    return (res);
                }
                void                resize(size_type n, value_type val = value_type()) {
                    if (n > _capacity)
                    {                 
                        if (_size == 0)
                            ReAlloc(n);
                        else
                        {
                            size_type j;
                            for (j = 2; (n > _capacity * j); j++)
                                ;
                            ReAlloc(_capacity * j);
                        }
                    }
                    if (n > _size)
                    {
                        for (size_type i = _size; i < n; i++)
                        {
                            _alloc.construct(_data + i, val);
                        }
                        _size = n;
                    }
                    else
                    {
                        for (size_type i = 0; i < n; i++)
                        {
                            _alloc.destroy(_data + (_size - i));
                        }
                        this->_size = n;
                    }

                
                    
                }
                void                reserve (size_type new_cap){
                    if (new_cap > max_size())
                        throw std::length_error("vector");
                    if (new_cap > _capacity)
                        ReAlloc(new_cap);
                }
                size_type           capacity() const { return _capacity; }
                /*------------------ELEMENT ACCESSORS --------------*/
                reference at( size_type pos ) { 
                    if (pos >= _size)
                        throw std::out_of_range("value out of range\n"); 
                    return  *(_data + pos); }
                const_reference at( size_type pos ) const { 
                    if (pos >= _size)
                        throw std::out_of_range("value out fo range\n");
                    return *(_data + pos); }

                reference operator[]( size_type pos ) { return *(_data + pos); }
                const_reference operator[]( size_type pos ) const { return _data + pos; }

                reference front() { return *(begin()); }
                const_reference front() const {return *(begin()); }

                reference back() { return *(end() -  1); }
                const_reference back() const { return *(end() - 1); }

                T* data() {return begin().base(); }
                const T* data() const {return begin().base(); }
                /*------------------ITERATORS----------------------*/
                
                iterator begin() const
                {
                    return iterator(_data);
                }
                const_iterator cbegin() const { return const_iterator(_data); }

                iterator end() const {
                    return iterator(_data + _size);
                }
                const_iterator cend() const { return const_iterator(begin()); }

                reverse_iterator rbegin() 
                { 
                    Reverse_iterator<Vectoriterator<T> > res(iterator(_data + _size));
                    return res;
                }
                reverse_iterator rend() 
                { 
                    return Reverse_iterator<Vectoriterator<T> >(this->begin()); 
                }
                const_reverse_iterator rbegin() const
                { 
                    return Reverse_iterator<Vectoriterator<const T> >(iterator(_data + _size));
                }
                const_reverse_iterator rend() const
                { 
                    return Reverse_iterator<Vectoriterator<const T> >(this->begin()); 
                }
                /*----------------- MODIFIERS ---------------------*/
                template <class InputIt>
                void            assign (InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, iterator>::type* = NULL )
                {
                    size_type n = ft::distance(first, last);
                    
                    clear();
                    if (_capacity >= n)
                    {
                        for (size_type i = 0; first != last; first++, i++)
                            _alloc.construct(_data + i, *first);
                        _size = n;
                        
                    }
                    else
                    {
                        ReAlloc(n);
                        for(size_type i = 0; first != last; first++, i++)
                            _alloc.construct(_data + i, *first);
                        _size = n; 
                    }


                }
                void                assign (size_type n, const value_type& val)
                {
                    int         i;

                    if (n > _capacity)
                    {                 
                        if (_size == 0)
                            ReAlloc(n);
                        else
                        {
                            for (i = 2; (n > _capacity * i); i++)
                                ;
                            ReAlloc(_capacity * i);
                        }
                    }
               
                    _size = n;
                    for (size_type i = 0; i < _size; i++)
                    {
                        _alloc.destroy(_data + i);
                        *(_data + i) = val;
                    }
                }
                void                push_back (const value_type& val) {
                    if(_size == 0 && _capacity == 0)
                    {
                        _data = _alloc.allocate(1);
                        _capacity++;
                    }
                    else if (_size + 1 > _capacity)
                    {                 
                        if (_size == 0)
                            ReAlloc(1);
                        else
                        {
                            ReAlloc(_capacity * 2);
                        }
                    }
                    _alloc.construct(_data +_size, val);
                    _size++;
                }
                void                pop_back()
                {
                    _alloc.destroy(_data + _size - 1);
                    _size--;
               
                }
               
                iterator            insert (iterator position, const value_type& val)
                {
                    size_type index = ft::distance(begin(), position);
                    size_type n = 1;
                    size_type i = _size - 1;
                    size_type end = (_size + 1) - 1;


                    if (n == 0)
                        return position;
                     if (_size + n > _capacity)
                    {                 
                        if (_size == 0)
                            ReAlloc(n);
                        else
                            ReAlloc(_capacity * 2);
                    }
                    if (position == this->end() || _size == 0)
                    {
    
                        *(_data + _size) = val;
                        _size++;
                        return iterator(_data + index);
                    }
                    // std::cout << "end : " << end << std::endl;
                    // std::cout << "i is: " << i << std::endl;
                    // std::cout << "_index : " << index << std::endl;
                    while (end != index)
                    {
                        // for (size_type j= 0; j < _size; j++)
                        //     std::cout << *(_data +  j) << " ";
                        // std::cout << std::endl;
                        // std::cout << "i is: " << i << std::endl;

                        // std::cout << "INSERTING [" << *(_data + i) << "](Index : " << i <<") AT POS " << end << std::endl;
                        _alloc.construct( _data + end, *(_data + i));
                        _alloc.destroy(_data + i);
                        i--;
                        end--;

                    }
                    _size++;
                    *(_data + index) = val;
                    return iterator(_data + index);
                }
                 
                //template<typename InputIt>
                void    insert(iterator position, size_type n, const value_type& val)
                {
                    size_type index = ft::distance(begin(), position);
                    size_type        i = 0;


                    if (n == 0)
                        return ;
                    if (_size + n > _capacity)
                    {                 
                        if (_size == 0)
                            ReAlloc(n);
                        else
                        {
                            size_type j;
                            for (j = 2; (_size + n > _capacity * j); j++)
                                ;
                            ReAlloc(_capacity * j);
                        }
                    }
                    if (position == this->end() || !_size)
                    {
                        for (size_type k = 0; k < n; k++)
                        {
                            *(_data + k) = val;
                        }
                        _size++;
                        return ;
                    }
                     
                    if (index == 0 && !_size)
                    {
                        for (size_type k = 0; k < n; k++)
                        {
                            _alloc.construct((_data +  k + index), val);
                        }
                        _size += n;
                        return ;
                    }
                    if (index == 0)
                    {
                        i = _size - 1;
                        size_type end = (_size + n) - 1;
                        // std::cout << "end : " << end << std::endl;
                        // std::cout << "i is: " << i << std::endl;
                        // std::cout << "_index : " << index << std::endl;
                        while (i + 1 != index)
                        {
                            // for (size_type j= 0; j < _size; j++)
                            //     std::cout << *(_data +  j) << " ";
                            // std::cout << std::endl;
                            // std::cout << "i is: " << i << std::endl;

                            // std::cout << "INSERTING [" << *(_data + i) << "](Index : " << i <<") AT POS " << end << std::endl;
                            _alloc.construct( _data + end, *(_data + i));
                            _alloc.destroy(_data + i);
                            i--;
                            end--;

                        }
                        _size += n;
                         for (size_type k = 0; k < n; k++)
                        {
                            _alloc.construct(_data + k + index, val);
                        }
                        return ;

                    }
                    // if (position == end())
                    // {
                    //     for (size_type i = 0; i < n; i++)
                    //         _alloc.construct(_data + i + _size, val);
                    //     _size += n; 
                    //     return ;
                    // }
                    i = _size - 1;
                    size_type end = (_size + n) - 1;
                    // std::cout << "end : " << end << std::endl;
                    // std::cout << "i is: " << i << std::endl;
                    // std::cout << "_index : " << index << std::endl;
                    while (end != index)
                    {
                        // for (size_type j= 0; j < _size; j++)
                        //     std::cout << *(_data +  j) << " ";
                        // std::cout << std::endl;
                        // std::cout << "i is: " << i << std::endl;

                        // std::cout << "INSERTING [" << *(_data + i) << "](Index : " << i <<") AT POS " << end << std::endl;
                        _alloc.construct( _data + end, *(_data + i));
                        _alloc.destroy(_data + i);
                        i--;
                        end--;

                    }
                    _size += n;

                    for (size_type k = 0; k < n; k++)
                    {
                        _alloc.construct(_data + k + index, val);
                    }

                }
                   template <typename InputIt>
                   
                    void               insert (iterator position, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = NULL )
                    {
                    size_type index = ft::distance(begin(), position);
                    size_type    n = ft::distance(first, last);
                    size_type       i = 0;

                    if (n == 0)


                        return ;
                    if (_size + n > _capacity)
                        ReAlloc(_size + n);
                    if (index == 0 && !_size)
                    {
                        for (size_type k = 0; k < n; k++, first++)
                        {
                            _alloc.construct((_data +  k + index), *first);
                        }
                        _size += n;
                        return ;
                    }
                    if (index == 0)
                    {
                        i = _size - 1;
                        size_type end = (_size + n) - 1;
                        // std::cout << "end : " << end << std::endl;
                        // std::cout << "i is: " << i << std::endl;
                        // std::cout << "_index : " << index << std::endl;
                        while (i + 1 != index)
                        {
                            // for (size_type j= 0; j < _size; j++)
                            //     std::cout << *(_data +  j) << " ";
                            // std::cout << std::endl;
                            // std::cout << "i is: " << i << std::endl;

                            // std::cout << "INSERTING [" << *(_data + i) << "](Index : " << i <<") AT POS " << end << std::endl;
                            _alloc.construct( _data + end, *(_data + i));
                            _alloc.destroy(_data + i);
                            i--;
                            end--;

                        }
                        _size += n;
                         for (size_type k = 0; k < n; k++, first++)
                        {
                            _alloc.construct(_data + k + index, *first);
                        }
                        return ;

                    }
                    i = _size - 1;
                    size_type end = (_size + n) - 1;
                    // std::cout << "end : " << end << std::endl;
                    // std::cout << "i is: " << i << std::endl;
                    // std::cout << "_index : " << index << std::endl;
                    while (end != index && i + 1 != 0)
                    {
                        // for (size_type j= 0; j < _size; j++)
                        //     std::cout << *(_data +  j) << " ";
                        // std::cout << std::endl;
                        // std::cout << "i is: " << i << std::endl;

                        //std::cout << "INSERTING [" << *(_data + i) << "](Index : " << i <<") AT POS " << end << std::endl;
                        _alloc.construct( _data + end, *(_data + i));
                        _alloc.destroy(_data + i);
                        i--;
                        end--;

                    }
                    _size += n;
                    for (size_type k = 0; k < n; k++, first++)
                    {
                        _alloc.construct(_data + k + index, *first);
                    }
                    
                }
                iterator            erase (iterator position)
                {
                    
                    return erase(position, position + 1);
                }
                iterator erase (iterator first, iterator last)
                {
                    iterator first_save = first;
                    size_type count = ft::distance(first, last);
                    if (first != last)
                    {
                        size_type   index = ft::distance(begin(), first);

                        for(; first_save != last; first_save++)
                        {
                            _alloc.destroy(&(*(first)));
                        }

                        size_type   _end = ft::distance(last, end());
                        for (size_type i = 0; i < _end; first++, i++)
                        {
                            _alloc.construct(&(*first), *(last + i));
                            _alloc.destroy(&(*(last + i)));
                        }
                        _size = _size - count;
                        return iterator(_data + index);
                    }
                    return first;
                }
                void                swap (vector& x)
                {
                    pointer tmp_ptr = this->_data;
                    size_type     tmp_cap = this->_capacity;
                    size_type     tmp_size = this->_size;

                    this->_data = x._data;
                    this->_capacity = x._capacity;
                    this->_size = x._size;

                     x._data = tmp_ptr;
                     x._capacity = tmp_cap;
                     x._size = tmp_size;


                }
                void                clear()
                {
                    size_type end = size();
                    for (size_type i = 0; i < _size; i++, end--)
                    {
                        _alloc.destroy(_data + end);
                    
                    }
                    _size = 0;
                }
    };


    /*-----------------NON MEBER FUNC OVERLOADS-------------------------*/
    template< class T, class Alloc >
        bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
        {
            return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.begin(), rhs.end()));
        }
     template< class T, class Alloc >
        bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
        {
            return !(lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin()));
        }
     template< class T, class Alloc >
        bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
        {
            return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
    template< class T, class Alloc >
        bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
        {
            return !(lhs < rhs);
        }
     template< class T, class Alloc >
        bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
        {
            return (lhs < rhs || lhs == rhs);
        }
     template< class T, class Alloc >
        bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
        {
            return (lhs > rhs || lhs == rhs);
        }
}


# endif