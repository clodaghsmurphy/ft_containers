# include "vector.hpp"
# include <vector>
# include "test.hpp"
# include "iterator.hpp"
# include<typeinfo>


// template <class T>
// std::string get_iterator_type(T it)
// {
//     std::cout << "TYPE : " << typeid(it).name() << "TAG : " << std::endl;

//     // if the iterator category of (it) matches input
//     if (typeid(typename iterator_traits<T>::iterator_category)
//         == typeid(input_iterator_tag))
//         return "Input";
  
//     // if the iterator category of (it) matches output
//     else if (typeid(typename iterator_traits<T>::iterator_category)
//              == typeid(output_iterator_tag))
//         return "Output";
  
//     // if the iterator category of (it) matches forward
//     else if (typeid(typename iterator_traits<T>::iterator_category)
//              == typeid(forward_iterator_tag))
//         return "Forward";
  
//     // if the iterator category of (it) matches bidirectional
//     else if (typeid(typename iterator_traits<T>::iterator_category)
//              == typeid(bidirectional_iterator_tag))
//         return "Bidirectional";
  
//     // if the iterator category of (it) matches random_access
//     else if (typeid(typename iterator_traits<T>::iterator_category)
//              == typeid(random_access_iterator_tag))
//         return "Random_Access";
//     // if the iterator category of (it)
//     // does not match any of the above
//     return "Missing";
// }

// void ft_reverse_iterator()
// {
//      {
//         std::vector<int> vec;

//         vec.push_back(2);
//         vec.push_back(3);
//         vec.push_back(4);
//         vec.push_back(5);
//         std::vector<int>::reverse_iterator ritb = vec.rbegin();
//         std::vector<int>::reverse_iterator rite = vec.rend();
//         std::vector<int>::iterator itb = vec.begin();
//         std::vector<int>::iterator ite = vec.end();
//         std::cout << get_iterator_type(ritb) << std::endl;
//         std::cout << get_iterator_type(rite) << std::endl;

//         std::cout << "iterator end :" << *ite << std::endl;
//         std::cout << "iterator begin :" << *itb << std::endl;
//         std::cout << "reverse iterator end :" << *rite << std::endl;
//         std::cout << "reverse iterator begin :" << *ritb << std::endl;
//          std::cout << "REVERSE" << std::endl;
//         while (ritb != rite)
//         {
//             std::cout << *ritb << std::endl;
//             ritb++;
//         }
//         std::cout << "FORWARD" << std::endl;

//         std::cout << std::endl;
//         while (itb != ite)
//         {
//             std::cout << *itb << std::endl;
//             itb++;
//         }
//         (void)ritb;
//     }
//     {
//         ft::vector<int> vec;

//         vec.push_back(2);
//         vec.push_back(3);
//         vec.push_back(4);
//         vec.push_back(5);
//         ft::vector<int>::reverse_iterator ritb = vec.rbegin();
//         ft::vector<int>::reverse_iterator rite = vec.rend();
//         ft::vector<int>::iterator itb = vec.begin();
//         ft::vector<int>::iterator ite = vec.end();
//         std::cout <<  get_iterator_type(ritb) << std::endl;
//         std::cout <<  get_iterator_type(rite) << std::endl;

//         std::cout << "iterator end :" << *ite << std::endl;
//         std::cout << "iterator begin :" << *itb << std::endl;
//         std::cout << "reverse iterator end : " << *rite << std::endl;
//         std::cout << "reverse iterator begin : " << *ritb << std::endl;
//         std::cout << std::endl << "FORWARD" << std::endl;
//         while (itb != ite)
//         {
//             std::cout << *itb << std::endl;
//             itb++;
//         }
       
//         std::cout << std::endl << "REVERSE" << std::endl;
//         while (ritb != rite)
//         {
//             std::cout << *ritb << std::endl;
//             ritb++;
//         }
//     }

// }


// void    iterator_category()
// {
//     ft::vector<int> vec(5, 5);

//     ft::vector<int>::iterator it;
//     it = vec.begin();
//     std::cout << get_iterator_type(it) << std::endl;
//      ft::vector<int> vec2(5, 5);

//     ft::vector<int>::const_iterator it2;
//     it2 = vec2.cbegin();
//     std::cout << get_iterator_type(it) << std::endl;
//     ft_reverse_iterator();
// }