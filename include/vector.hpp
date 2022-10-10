# ifndef VECTOR_HPP
# define VECTOR_HPP

# include "container.hpp"

template < class T, class Allocator = std::allocator<T> >
class vector
{
    private:
        /*----------------- MEMBER TYPES ------------------*/
        T               value_type;
        T*              pointer;
        const T*        const_pointer;
        T&              reference;
        const T&        const_reference;
        std::size_t     size_type;
        std::ptrdiff_t  difference_type;
        
        template <class U > struct rebind {
            typedef allocator<U> other;
        };

        /*----------------- MEMBER FUNCTIONS ---------------*/
        public:
            vector();
            ~vector();
            /*-----------------CAPACITY -----------------------*/
            bool empty() const;
            size_type   size() const;
            size_type   max_size() const;
            void resize(size_type n, value_type vale = value_type());
            void    reserve (size_type new_cap);
            size_type capacity() const;
            /*----------------- MODIFIERS ---------------------*/
            void    clear();

        
};


# endif