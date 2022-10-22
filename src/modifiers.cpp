#include <vector>
#include "vector.hpp"
#include "test.hpp"


template <typename T, typename U>
int    vectors_equal(T &vec, U &vec2)
{
    typename T::iterator it = vec.begin();
    typename T::iterator ite = vec.end();
    typename U::iterator it2 = vec2.begin();
    typename U::iterator ite2 = vec2.end();

    if (vec.size() != vec2.size() || vec.capacity() != vec2.capacity())
    {
        std::cout << "VEC CAP : " << vec.capacity() << " MY VEC : " << vec2.capacity() << std::endl;
        std::cout << "VEC SIZE : " << vec.size() << " MY VEC : " << vec2.size() << std::endl;
        return (0);
    }
    print_container(vec);
    std::cout << std::endl;
    print_container(vec2);
    while (it !=ite || it2 != ite2)
    {
        if(*it != *it2)
            return (0);
        it++;
        it2++;
    }
    return (1);
}
void pop_back_test()
{
    std::cout <<std::endl << "\033[1m\033[33mVECTOR POP_BACK : \033[0m\033[37m" << std::endl;

    std::vector<int> vec;
    ft::vector<int> my_vec;



    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.pop_back();

    my_vec.push_back(1);
    my_vec.push_back(2);
    my_vec.push_back(3);
    my_vec.push_back(4);

    my_vec.pop_back();

     if (vectors_equal(vec, my_vec))
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
}


void    insert_test()
{
    {
        std::cout <<std::endl << "\033[1m\033[33mVECTOR INSERT : \033[0m\033[37m" << std::endl;

        std::vector<int> vec;
        ft::vector<int> my_vec;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::vector<int>::iterator it = vec.begin();

        it = vec.insert(it, 5);
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);
        ft::vector<int>::iterator my_it = my_vec.begin();

        my_vec.insert(my_it, 5);

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
    {
        std::cout <<std::endl << "\033[1m\033[33mVECTOR INSERT : \033[0m\033[37m" << std::endl;

        std::vector<int> vec;
        ft::vector<int> my_vec;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::vector<int>::iterator it = vec.begin();

        it = vec.insert(it + 2, 5);
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);
        ft::vector<int>::iterator my_it = my_vec.begin();

        my_vec.insert(my_it + 2, 5);

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
    {
        std::cout <<std::endl << "\033[1m\033[33mVECTOR INSERT : \033[0m\033[37m" << std::endl;

        std::vector<int> vec;
        ft::vector<int> my_vec;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::vector<int>::iterator it = vec.end();

        it = vec.insert(it, 5);
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);
        ft::vector<int>::iterator my_it = my_vec.end();

        my_vec.insert(my_it, 5);

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
    
}

void    erase_test()
{
    std::cout <<std::endl << "\033[1m\033[33mVECTOR ERASE : \033[0m\033[37m" << std::endl;

    {
    std::vector<int> vec;
    ft::vector<int> my_vec;


    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    std::vector<int>::iterator it = vec.begin();
    
    vec.erase(it);

    my_vec.push_back(1);
    my_vec.push_back(2);
    my_vec.push_back(3);
    my_vec.push_back(4);

    ft::vector<int>::iterator my_it = my_vec.begin();
    
    my_vec.erase(my_it);

    if (vectors_equal(vec, my_vec))
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
    {
         std::vector<int> vec;
    ft::vector<int> my_vec;


    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    std::vector<int>::iterator it = vec.begin();
    
    vec.erase(it + 1, it + 2);

    my_vec.push_back(1);
    my_vec.push_back(2);
    my_vec.push_back(3);
    my_vec.push_back(4);

    ft::vector<int>::iterator my_it = my_vec.begin();
    
    my_vec.erase(my_it + 1, my_it +2);

    if (vectors_equal(vec, my_vec))
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
     {
         std::vector<int> vec;
    ft::vector<int> my_vec;


    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    std::vector<int>::iterator it = vec.end();
    
    vec.erase(it - 1, it);

    my_vec.push_back(1);
    my_vec.push_back(2);
    my_vec.push_back(3);
    my_vec.push_back(4);

    ft::vector<int>::iterator my_it = my_vec.end();
    
    my_vec.erase(my_it - 1, my_it);

    if (vectors_equal(vec, my_vec))
        std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
}

void modifiers()
{
    pop_back_test();
    insert_test();
    //erase_test();
}