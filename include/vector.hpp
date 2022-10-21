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

        private:
            pointer _ptr;

        public:
            Vectoriterator(pointer ptr) : _ptr(ptr) {}
            Vectoriterator() : _ptr(NULL) {}
            Vectoriterator(const Vectoriterator& obj) : _ptr(obj._ptr) {}
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
            difference_type operator-(const Vectoriterator<T> &right) const
            {
                return this->_ptr - right._ptr;
            }

            bool operator==(const Vectoriterator<T> &y) const
            {
                return _ptr == y._ptr;
            }
            bool operator!=(const Vectoriterator<T> &y) const
            {
                return (_ptr != y._ptr);
            }
    };

   /* template <typename T>
    diiffence_type operator-(const Vectoriterator<T> &x, const Vectoriterator<T> &y) const
    {
        return x._ptr == y._ptr;
    }
    template<typename T>
    bool operator!=(const Vectoriterator<T> &x, const Vectoriterator<T> &y)
    {
        return !(x._ptr == y._ptr);
    }*/

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
                T* new_block = new T[n];
                if (n < _size)
                {
                    _size = n;
                }
                for (size_t i = 0; i < _size; i++)
                    new_block[i] = _data[i];
                delete[] _data;
                _data = new_block;
                _capacity = n;
            }
            /*----------------- MEMBER FUNCTIONS ---------------*/
            public:
                vector() : _data(NULL), _size(0), _capacity(0) {
                    _data = _alloc.allocate(_capacity);   
                }
                
                 explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()) :  _size(count), _capacity(count), _alloc(alloc)
                    {
                        _data = _alloc.allocate( count );
                        for (size_t i = 0; i < count; i++)
                           _alloc.construct(_data + i, value);
                    }

            
                    vector( iterator first, iterator last, const Allocator& alloc = Allocator() ) : _alloc(alloc)
                    {
                        int i = 0;
                        _data = _alloc.allocate(distance(first, last));
                        while (first != last)
                        {
                            _alloc.construct(_data + i, *first);
                            first++;
                            i++;
                        }
                    } 
                vector( const vector& other )
                {
                    _data = other._data;
                    _alloc = other._alloc;
                    _capacity = other._size;
                    _size = other._size;
                }
                // vector( const vector& other, const Allocator& alloc );

                ~vector() {
                        clear();
                    // _alloc.deallocate(_data, _capacity);
                    

                    return ;
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
               /*  reference at( size_type pos );
                const_reference at( size_type pos ) const;

                reference operator[]( size_type pos );
                const_reference operator[]( size_type pos ) const;

                reference front();
                const_reference front() const;

                reference back();
                const_reference back() const;

                T* data();
                const T* data() const; */
                /*------------------ITERATORS----------------------*/
                
                iterator begin()
                {
                    return iterator(_data);
                }
                const_iterator cbegin() const { return const_iterator(_data); }

                iterator end(){
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
                template <class InputIterator>  
                    void            assign (InputIterator first, InputIterator last);
                void                assign (size_type n, const value_type& val);
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
                    reserve(1);
                    _alloc.construct((_data + 1) + 1, val);
                    _size++;
                    (void)position;
                    return iterator(_data);
                }
                void                insert (iterator position, size_type n, const value_type& val);
                template <class InputIterator>    
                    void               insert (iterator position, InputIterator first, InputIterator last);
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
                            for(size_type i = index; i < _size ; i++)
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
                    for (size_type i; i < _size; i++)
                    {
                        _alloc.destroy(_data + (_capacity - i));
                        _alloc.deallocate(_data + (_capacity - i), 1);
                    }
                }
    };
}

# endif