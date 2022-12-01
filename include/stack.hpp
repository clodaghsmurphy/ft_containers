#ifndef STACK_HPP
#define STACK_HPP

# include "vector.hpp"
# include "container.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack 
    {
       public :
       typedef  T           value_type;
       typedef  Container   container_type;
       typedef  std::size_t size_type;
       typedef  T           &reference;
       typedef  const T     &const_reference;


        explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {}
        stack (const stack& other) : c(other.c) {}
        ~stack() {}
        stack   &operator=( const stack&other)
        {
            this->c = other.c;
        }


        /*------------------------------*/
        reference       top()
        {
            return (c.back());
        }
        const_reference top() const
        {
            return (c.back());
        }
        bool    empty()
        {
            return c.empty();
        }
        size_type   size()
        {
            return c.size();
        }
        void    push(const value_type& value)
        {
            c.push_back(value);
        }
        void    pop()
        {
            c.pop_back();
        }

        bool operator==(const ft::stack<T,Container>& rhs ) const
        {
            return (this->c == rhs.c);
        }
        bool operator!=(const ft::stack<T,Container>& rhs ) const
        {
            return (this->c != rhs.c);
        }
        bool operator<(const ft::stack<T,Container>& rhs ) const
        {
            return (this->c < rhs.c);
        }
        bool operator<=(const ft::stack<T,Container>& rhs ) const 
        {
            return (this->c <= rhs.c);
        }
        bool operator>(const ft::stack<T,Container>& rhs ) const 
        {
            return (this->c > rhs.c);
        }
        bool operator>=(const ft::stack<T,Container>& rhs ) const
        {
            return (this->c >= rhs.c);
        }
        protected:
        container_type c;
    };
}
#endif