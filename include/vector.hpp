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
                --(*this);
                return it;
            }
            value_type  *operator->()
            {
                return _ptr;
            }
            reference operator*()
            {
                return *(this->_ptr);
            }
            const_reference operator*() const
            {
                return *_ptr;
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
            Vectoriterator operator+(difference_type n)
            {
                //this->_ptr += n;
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
            Vectoriterator operator-(difference_type n)
            {
                //this->_ptr - n;
                return Vectoriterator(this->_ptr - n);
            }
            // difference_type operator-(const Vectoriterator<T> &right) const
            // {
            //     return this->_ptr - right._ptr;
            // }

            // bool operator==(const Vectoriterator<T> &y) const
            // {
            //     return _ptr == y._ptr;
            // }
            // bool operator!=(const Vectoriterator<T> &y) const
            // {
            //     return (_ptr != y._ptr);
            // }
            template <typename _T>
                friend std::ptrdiff_t operator-(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y);
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
            template <typename _T>
                friend std::ptrdiff_t operator-(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y);
            template<typename IteratorL, typename IteratorR>
                friend bool operator!=(const IteratorL &x, const IteratorR &y);

            // template <typename _T, class Allocator = std::allocator<_T> >
            //     friend class vector;
            pointer base() const { return _ptr; } 
            void setPointer(pointer ptr) {  _ptr = ptr; }
    };


    template <typename _T>
    std::ptrdiff_t operator-(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y)
    {
        return x._ptr - y._ptr;
    }
    template<typename _T>
    bool operator!=(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y)
    {
        return !(x._ptr == y._ptr);
    }

    template<typename IteratorL, typename IteratorR>
    bool operator!=(const IteratorL &x, const IteratorR &y)
    {
        return !(x._ptr == y._ptr);
    }
    template<typename _T>
    bool operator==(const Vectoriterator<_T> &x, const Vectoriterator<_T> &y)
    {
        return (x._ptr == y._ptr);
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

            typedef Vectoriterator<T >          iterator;
            typedef Vectoriterator<const T > const_iterator;
            typedef Reverse_iterator<iterator >     reverse_iterator;

            T*              _data;
            size_t           _size;
            size_t          _capacity;
            allocator_type  _alloc;
            
            void ReAlloc(size_t n)
            {
                if (n < _capacity || !n)
                    return ;
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

            
                    vector( iterator first, iterator last, const Allocator& alloc = Allocator() ) :  _data(NULL), _size(0), _capacity(0), _alloc(alloc)
                    {
                        _data = _alloc.allocate(_capacity); 
                        insert(begin(), first, last);
            
                    } 
                vector( const vector& other ) : _data(0), _size(0), _capacity(0)
                {
                    this->insert(begin(), other.begin(), other.end());

                }
                ~vector() {
                    clear();
                    _alloc.deallocate(_data, 1);
                    return ;
                }
                vector<T>   operator=(const vector<T> &rhs)
                {
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
                void                resize(size_type n, value_type vale = value_type()) {
                    std::cout << sizeof(vale) << std::endl;
                    std::cout << n << std::endl;
                }
                void                reserve (size_type new_cap){
                    if (new_cap > max_size())
                        throw std::length_error("vector");
                    ReAlloc(new_cap);
                }
                size_type           capacity() const { return _capacity; }
                /*------------------ELEMENT ACCESSORS --------------*/
                reference at( size_type pos ) { 
                    if (pos >= _size)
                        throw std::out_of_range("value out of range\n"); 
                    return _data + pos; }
                const_reference at( size_type pos ) const { 
                    if (pos >= _size)
                        throw std::out_of_range("value out fo range\n");
                    return _data + pos; }

                reference operator[]( size_type pos ) { return *(_data + pos); }
                const_reference operator[]( size_type pos ) const { return _data + pos; }

                reference front() { return *(begin()); }
                const_reference front() const {return *(begin()); }

                reference back() { return *(end()); }
                const_reference back() const { return *(end()); }

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
                const_iterator cend() const { return const_iterator(_data + _size); }

                reverse_iterator rbegin() 
                { 
                    return Reverse_iterator<Vectoriterator<T> >(this->end());
                }
                reverse_iterator rend() 
                { 
                    return Reverse_iterator<Vectoriterator<T> >(this->begin()); 
                }
                /*----------------- MODIFIERS ---------------------*/
                void            assign (iterator first, iterator last)
                {
                    size_type n = last - first;
                    //bool        flag;
                    pointer     cpy = 0;

                    
                    if (_data == first.base())
                    {
                        cpy = _alloc.allocate(_size);
                        for (size_type i = 0; i < _size; i++)
                            cpy[i] = *(first.base() + i);
                        first.setPointer(cpy);
                    }   
                    clear();
                    if (n == 0)
                    {
                        _alloc.deallocate(cpy, _capacity);
                        return ;            
                        
                    }
                    ReAlloc(n);
                    _size = n;
                    for (size_type i = 0; i < _size; i++)
                    {
                       
                        _alloc.destroy(_data + i);
                        *(_data + i) = *(first + i);
                    }
                    _alloc.deallocate(cpy, _capacity);


                }
                void                assign (size_type n, const value_type& val)
                {
                    int         i;

                    if (n >= _capacity)
                    {                 
                        if (_size == 0)
                            ReAlloc(n);
                        else
                        {
                            for (i = 2; (n >= _capacity * i); i++)
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
                    if (_size >= _capacity)
                    {
                        if (_size == 0)
                            reserve(1);
                        else
                            reserve(_capacity * 2);
                    }
                    _alloc.construct(_data +_size, val);
                    _size++;
                }
                void                pop_back()
                {
                    if (_size == 0)
                        return ;
                    _alloc.destroy(_data + _size - 1);
                    _size--;
               
                }

                iterator            insert (iterator position, const value_type& val)
                {
                    size_type index = position - begin();
                    T                   tmp;

                    if (_size + 1 >= _capacity)
                    {
                        if (_size == 0)
                            ReAlloc(1);
                        else
                            ReAlloc(_capacity * 2);
                    }
                    if (position == end())
                    {
                        push_back(val);
                        return position ;
                    }
                    else if (index == 0)
                    {
          
                        size_type i = index;  
                        tmp = (*_data);
                        while (i < _size)
                        {
                             
                            _alloc.construct(_data + i + 1, tmp);
                            i++;
                            tmp = (*_data + i);
                            _alloc.destroy(_data + i);

                        }
                        *_data = val;
                    }
                    else
                    {
                        size_type i = index + 1;  
                        tmp = (*_data + index);
                        while (i < _size)
                        {
                             
                            _alloc.construct(_data + i + 1, tmp);
                            i++;
                            tmp = (*_data + i);
                            _alloc.destroy(_data + i);

                        }
                        *(_data + index) = val;
                    }
                    
                    _size++;
                    return iterator(_data);
                }

                void    insert(iterator position, size_type n, const value_type& val)
                {
                    size_type index = position - begin();
                    T         tmp;
                    int        i;


                    if (position == end())
                    {
                        for (size_type i = 0; i < n; i++)
                            push_back(val);
                    }
                    if (_size + n >= _capacity)
                    {                 
                        if (_size == 0)
                            ReAlloc(n);
                        else
                        {
                            for (i = 2; (_size + n >= _capacity * i); i++)
                                ;
                            ReAlloc(_capacity * i);
                        }
                    }
                    
                    _size += n;
                    if (index == 0)
                    {
                        size_type i = index;
            
                        tmp = (*_data);
                        while (i < _size - n)
                        {
                            _alloc.construct(_data + i + n, tmp);
                            std::cout << "ADDRESS :  " << _data + i + n << std::endl;
                            std::cout << "i+ n = " << i + n << std::endl;
                            i++;
                            tmp = (*_data + i);
                            _alloc.destroy(_data + i);
                        }
                        for (size_type k = 0; k < n; k++)
                            *(_data + k) = val;
                    }
                    else
                    {
                        size_type i = index;
            
                        tmp = (*_data);
                        while (i < _size - n)
                        {
                            _alloc.construct(_data + i + n, tmp);
                            i++;
                            tmp = (*_data + i);
                            _alloc.destroy(_data + i);
                        }
                        for (size_type k = 0; k < n; k++)
                            *(_data + index + k) = val;
                    }

                }
                    void               insert (iterator position, iterator first, iterator last)
                    {
                    size_type index = position - begin();
                    size_type    n = last - first;

                    ReAlloc(_size + n); 
                    _size += n;
                    size_type i = index;
        
                    
                    while (i < _size - n)
                    {
                        _alloc.construct(_data + i + n, *(_data + i));
                        i++;
                        _alloc.destroy(_data + i);
                    }
                    for (size_type k = 0; k < n; k++)
                    {
                        _alloc.construct(_data + k, *(first + k));

                    }
               
                    }
                iterator            erase (iterator position)
                {
                    return erase(position, position + 1);
                }
                iterator erase (iterator first, iterator last)
                {
                    if (first != last)
                    {
                        size_type   index = first - begin();
                        size_type   _end = end() - last;
                        size_type   count = last - first;

                        if ( index <= 0)
                        {
                            
                            _alloc.destroy((_data));
                            for(size_type i = 0; i < _end ; i++)
                            {

                                _alloc.construct(_data + i, *(_data + i + 1));
                                _alloc.destroy((_data + i + 1));

                            }
                            _size--;
                            return (last);
                        }
                        else
                        {
                            for(size_type i = index; i < _size - 1; i++)
                            {
                                _alloc.construct(_data + i, *(_data + i + 1));
                                _alloc.destroy((_data + i + 1));

                            }
                            _size = _size - count;
                        }
                        return first;
                    }
                    return first;
                }
                void                swap (vector& x);
                void                clear()
                {
                    for (size_type i = 0; i < _capacity; i++)
                    {
                        _alloc.destroy(_data + i);

                    }
                    _size = 0;
                }
    };
}

# endif