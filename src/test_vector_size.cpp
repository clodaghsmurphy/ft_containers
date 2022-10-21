# include <vector>
# include "vector.hpp"


void    size_capacity()
{
     std::vector<int> vec2;
    ft::vector<int> vec;
    std::cout << std::endl << "\033[1m\033[33mSIZE AND CAPACITY \033[0m\033[37m" << std::endl << std::endl;
     if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    vec.push_back(3);
    vec2.push_back(3);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
   vec.push_back(1);
    vec2.push_back(1);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
}

void    maximum_size()
{
    std::vector<int> vec2;
    ft::vector<int> vec;

    std::cout <<std::endl << "\033[1m\033[33m VECTOR MAX SIZE : \033[0m\033[37m" << std::endl;
    if (vec.max_size() == vec2.max_size())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl << std::endl;

}

void reserve_test()
{
    std::vector<int> vec2;
    ft::vector<int> vec;

    std::cout <<std::endl << "\033[1m\033[33mVECTOR RESERVE AND CAPACITY : \033[0m\033[37m" << std::endl;

    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    vec.reserve(4);
    vec2.reserve(4);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    vec.reserve(100);
    vec2.reserve(100);
    if (vec.size() == vec2.size() && vec.capacity() == vec2.capacity())
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
}

void test_vector_size()
{
     std::vector<int> vec2;
    ft::vector<int> vec;

    size_capacity();
    maximum_size();
    reserve_test();
    
 
    
    //print_vec(vec);
    return ;
}