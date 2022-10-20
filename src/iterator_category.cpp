# include "vector.hpp"
# include <vector>
# include "test.hpp"
# include "iterator.hpp"
# include<typeinfo>


template <class T>
std::string get_iterator_type(T it)
{
    std::cout << typeid(it).name() << std::endl;

    // if the iterator category of (it) matches input
    if (typeid(typename iterator_traits<T>::iterator_category)
        == typeid(input_iterator_tag))
        return "Input";
  
    // if the iterator category of (it) matches output
    else if (typeid(typename iterator_traits<T>::iterator_category)
             == typeid(output_iterator_tag))
        return "Output";
  
    // if the iterator category of (it) matches forward
    else if (typeid(typename iterator_traits<T>::iterator_category)
             == typeid(forward_iterator_tag))
        return "Forward";
  
    // if the iterator category of (it) matches bidirectional
    else if (typeid(typename iterator_traits<T>::iterator_category)
             == typeid(bidirectional_iterator_tag))
        return "Bidirectional";
  
    // if the iterator category of (it) matches random_access
    else if (typeid(typename iterator_traits<T>::iterator_category)
             == typeid(random_access_iterator_tag))
        return "Random_Access";
    // if the iterator category of (it)
    // does not match any of the above
    return "Missing";
}

void ft_reverse_iterator()
{
    {
        std::vector<int> vec;

        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::vector<int>::reverse_iterator rit = vec.rbegin();

        while(rit != vec.rend())
        {
            std::cout << *rit << std::endl;
            rit++;
        }
    }
    {
         ft::vector<int> vec;

        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        ft::vector<int>::reverse_iterator rit2 = vec.rbegin();

        while(rit2 != vec.rend())
        {
            std::cout << *rit2 << std::endl;
            rit2++;
        }
    }

}


void    iterator_category()
{
    ft::vector<int> vec(5, 5);

    ft::vector<int>::iterator it;
    it = vec.begin();
    std::cout << get_iterator_type(it) << std::endl;
     ft::vector<int> vec2(5, 5);

    ft::vector<int>::const_iterator it2;
    it2 = vec2.cbegin();
    std::cout << get_iterator_type(it) << std::endl;
    ft_reverse_iterator();
}