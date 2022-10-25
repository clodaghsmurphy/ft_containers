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

    if (vec.size() != vec2.size() || vec.capacity() != vec2.capacity() || vec.empty() != vec2.empty())
    {
        std::cout << "VEC CAP : " << vec.capacity() << " MY VEC : " << vec2.capacity() << std::endl;
        std::cout << "VEC SIZE : " << vec.size() << " MY VEC : " << vec2.size() << std::endl;
        return (0);
    }
    /* std::cout << "in print coantiners OG VEC IS : " << std::endl;

    print_container(vec);
     
    std::cout << std::endl; */

    while (it !=ite || it2 != ite2)
    {
        if(*it != *it2)
        {
            std::cout << "REAL VEC IS : " << std::endl;
            print_container(vec);
            std::cout << std::endl;
            std::cout << "MY VEC IS : " << std::endl;
            print_container(vec2);
            std::cout << *it << " != " << *it2 << std::endl;
            return (0);

        }
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
    // {
    //     std::cout <<std::endl << "\033[1m\033[33mVECTOR INSERT : \033[0m\033[37m" << std::endl;

    //     std::vector<int> vec;
    //     ft::vector<int> my_vec;


    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    //     std::vector<int>::iterator it = vec.begin();

    //     it = vec.insert(it, 5);
    //     my_vec.push_back(1);
    //     my_vec.push_back(2);
    //     my_vec.push_back(3);
    //     my_vec.push_back(4);
    //     ft::vector<int>::iterator my_it = my_vec.begin();

    //     my_vec.insert(my_it, 5);

    //     if (vectors_equal(vec, my_vec))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    //{

    //     std::vector<int> vec;
    //     ft::vector<int> my_vec;


    //     for (int i = 0; i < 100; i++)
    //         vec.push_back(i);
    //     std::vector<int>::iterator it = vec.begin();

    //     it = vec.insert(it, 5);
    //     for (int i = 0; i < 100; i++)
    //         my_vec.push_back(i);
    //     ft::vector<int>::iterator my_it = my_vec.begin();

    //     my_vec.insert(my_it, 5);

    //     if (vectors_equal(vec, my_vec))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    // {

    //     std::vector<int> vec;
    //     ft::vector<int> my_vec;


    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    //     std::vector<int>::iterator it = vec.begin();

    //     it = vec.insert(it + 2, 5);
    //     my_vec.push_back(1);
    //     my_vec.push_back(2);
    //     my_vec.push_back(3);
    //     my_vec.push_back(4);
    //     ft::vector<int>::iterator my_it = my_vec.begin();

    //     my_vec.insert(my_it + 2, 5);

    //     if (vectors_equal(vec, my_vec))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    // {

    //     std::vector<int> vec;
    //     ft::vector<int> my_vec;


    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    //     std::vector<int>::iterator it = vec.end();

    //     it = vec.insert(it, 5);
    //     my_vec.push_back(1);
    //     my_vec.push_back(2);
    //     my_vec.push_back(3);
    //     my_vec.push_back(4);
    //     ft::vector<int>::iterator my_it = my_vec.end();

    //     my_vec.insert(my_it, 5);

    //     if (vectors_equal(vec, my_vec))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    // {

    //     std::vector<int> vec;
    //     ft::vector<int> my_vec;


    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    //     std::vector<int>::iterator it = vec.begin();

    //     vec.insert(it, 3, 0);
    //     /* std::cout << "in main and container is : " << std::endl;
    //     print_container(vec); */

    //     my_vec.push_back(1);
    //     my_vec.push_back(2);
    //     my_vec.push_back(3);
    //     my_vec.push_back(4);
    //     ft::vector<int>::iterator my_it = my_vec.begin();

    //     my_vec.insert(my_it, 3, 0);
    //     /* std::cout << "in main and my container is : " << std::endl;
    //     print_container(my_vec); */

    //     if (vectors_equal(vec, my_vec))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    //   {

    //     std::vector<int> vec;
    //     ft::vector<int> my_vec;


    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    //     std::vector<int>::iterator it = vec.end();

    //     vec.insert(it, 3, 0);
    //     /* std::cout << "in main and container is : " << std::endl;
    //     print_container(vec); */

    //     my_vec.push_back(1);
    //     my_vec.push_back(2);
    //     my_vec.push_back(3);
    //     my_vec.push_back(4);
    //     ft::vector<int>::iterator my_it = my_vec.end();

    //     my_vec.insert(my_it, 3, 0);
    //     /* std::cout << "in main and my container is : " << std::endl;
    //     print_container(my_vec); */

    //     if (vectors_equal(vec, my_vec))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    //   {

    //     std::vector<int> vec;
    //     std::vector<int> vec2;
    //     ft::vector<int> my_vec;
    //     ft::vector<int> my_vec2;


    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    //     std::vector<int>::iterator itb = vec.begin();
    //     std::vector<int>::iterator itb2 = vec2.begin();
    //     std::vector<int>::iterator ite = vec.end();

    //     vec2.insert(itb2 , itb, ite);
    //     // std::cout << "in main and container is : " << std::endl;
    //     // print_container(vec);

    //     my_vec.push_back(1);
    //     my_vec.push_back(2);
    //     my_vec.push_back(3);
    //     my_vec.push_back(4);
    //     ft::vector<int>::iterator my_itb = my_vec.begin();
    //     ft::vector<int>::iterator my_itb2 = my_vec2.begin();
    //     ft::vector<int>::iterator my_ite = my_vec.end();

    //     my_vec2.insert(my_itb2, my_itb, my_ite);
    //     // std::cout << "in main and my container is : " << std::endl;
    //     // print_container(my_vec);

    //     if (vectors_equal(vec2, my_vec2))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    // {

    //     std::vector<int> vec;
    //     std::vector<int> vec2;
    //     ft::vector<int> my_vec;
    //     ft::vector<int> my_vec2;


    //     for (int i = 0; i < 100; i++)
    //         vec.push_back(1);
    //     std::vector<int>::iterator itb = vec.begin();
    //     std::vector<int>::iterator itb2 = vec2.begin();
    //     std::vector<int>::iterator ite = vec.end();

    //     vec2.insert(itb2 , itb, ite);
    //     // std::cout << "in main and container is : " << std::endl;
    //     // print_container(vec);

    //     for (int i = 0; i < 100; i++)
    //         my_vec.push_back(1);
  
    //     ft::vector<int>::iterator my_itb = my_vec.begin();
    //     ft::vector<int>::iterator my_itb2 = my_vec2.begin();
    //     ft::vector<int>::iterator my_ite = my_vec.end();

    //     my_vec2.insert(my_itb2, my_itb, my_ite);
    //     // std::cout << "in main and my container is : " << std::endl;
    //     // print_container(my_vec);

    //     if (vectors_equal(vec2, my_vec2))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    // {

    //     std::vector<int> vec;
    //     std::vector<int> vec2;
    //     ft::vector<int> my_vec;
    //     ft::vector<int> my_vec2;


    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);

    //     std::vector<int>::iterator itb = vec.end();
    //     std::vector<int>::iterator itb2 = vec2.begin();
    //     std::vector<int>::iterator ite = vec.end();

    //     vec2.insert(itb2 , itb, ite);
    //     // std::cout << "in main and container is : " << std::endl;
    //     // print_container(vec);

    //     my_vec.push_back(1);
    //     my_vec.push_back(2);
    //     my_vec.push_back(3);
    //     my_vec.push_back(4);
    //     ft::vector<int>::iterator my_itb = my_vec.end();
    //     ft::vector<int>::iterator my_itb2 = my_vec2.begin();
    //     ft::vector<int>::iterator my_ite = my_vec.end();

    //     my_vec2.insert(my_itb2, my_itb, my_ite);
    //     // std::cout << "in main and my container is : " << std::endl;
    //     // print_container(my_vec);

    //     if (vectors_equal(vec2, my_vec2))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    // {

    //     std::vector<int> vec;
    //     std::vector<int> vec2;
    //     ft::vector<int> my_vec;
    //     ft::vector<int> my_vec2;


    //     vec.push_back(1);
    //     vec.push_back(2);
    //     vec.push_back(3);
    //     vec.push_back(4);
    
    //     std::vector<int>::iterator itb = vec.begin();
    //     std::vector<int>::iterator itb2 = vec2.end();
    //     std::vector<int>::iterator ite = vec.end();

    //     vec2.insert(itb2 , itb, ite);
    //     // std::cout << "in main and container is : " << std::endl;
    //     // print_container(vec);

    //     my_vec.push_back(1);
    //     my_vec.push_back(2);
    //     my_vec.push_back(3);
    //     my_vec.push_back(4);
    //     ft::vector<int>::iterator my_itb = my_vec.begin();
    //     ft::vector<int>::iterator my_itb2 = my_vec2.end();
    //     ft::vector<int>::iterator my_ite = my_vec.end();

    //     my_vec2.insert(my_itb2, my_itb, my_ite);
    //     // std::cout << "in main and my container is : " << std::endl;
    //     // print_container(my_vec);

    //     if (vectors_equal(vec2, my_vec2))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    // {
    //     int         arr1[5] = {1, 2, 3, 4, 5};
    //     std::string arr2[3] = {"bonjour", "je", "suis"};
    //     //float       arr3[4] = {42.1, 42.2, 42.3, 42.4};

    //     ft::vector<int> v1(arr1, arr1 + 5);
    //     std::vector<int> v2(arr1, arr1 + 5);
    
    // std::cout << v2.size() << " vs " << v1.size() << std::endl;
    // if (vectors_equal(v2, v1))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    {
        std::string arr2[3] = {"bonjour", "je", "suis"};

        ft::vector<std::string> v2(arr2, arr2 + 3);
        std::vector<std::string> v3(arr2, arr2 + 3);

        for (size_t i = 0; i < v2.size(); i++)
        {
            if (!(v2[i] == arr2[i]))
            {
                std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl; 
                std::cout << "MINE : " << v2[i] << std::endl;
                std::cout << "ARRAY : " << arr2[i] << std::endl;
            }
        }
        
        if (vectors_equal(v3, v2))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
    
}


void    assign_test()
{
    {
        std::cout <<std::endl << "\033[1m\033[33mASSIGN INSERT : \033[0m\033[37m" << std::endl;

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::vector<int>::iterator it = vec.begin();

        vec.assign(it, vec.end());
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);
        ft::vector<int>::iterator my_it = my_vec.begin();

        my_vec.assign(my_it, my_vec.end());

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
     {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::vector<int>::iterator it = vec.begin();

        vec.assign(it, vec.end());
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);
        ft::vector<int>::iterator my_it = my_vec.begin();

        my_vec.assign(my_it, my_vec.end());

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
    {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::vector<int>::iterator it = vec.begin();

        vec.assign(it, it);
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);
        ft::vector<int>::iterator my_it = my_vec.begin();

        my_vec.assign(my_it, my_it);

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
 {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        //std::vector<int>::iterator it = vec.begin();

        vec2.assign(vec.end(), vec.end());
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);
        //ft::vector<int>::iterator my_it = my_vec.begin();

        my_vec2.assign(my_vec.end(), my_vec.end());

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
      {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::vector<int>::iterator it = vec.begin();

        vec2.assign(it, vec.end());
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);
        ft::vector<int>::iterator my_it = my_vec.begin();

        my_vec2.assign(my_it, my_vec.end());

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }  
     {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        vec2.assign(5, 1);
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);

        my_vec2.assign(5, 1);

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
      {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        vec2.assign(150, 1);
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);

        my_vec2.assign(150, 1);

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
    {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        vec2.assign(0, 1);
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);

        my_vec2.assign(0, 1);

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
     {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        vec.assign(0, 0);
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);

        my_vec.assign(0, 0);

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
     {

        std::vector<int> vec;
        std::vector<int> vec2;
        ft::vector<int> my_vec;
        ft::vector<int> my_vec2;


        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);

        vec.assign(0, 'c');
        my_vec.push_back(1);
        my_vec.push_back(2);
        my_vec.push_back(3);
        my_vec.push_back(4);

        my_vec.assign(0, 'c');

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

void copy_test()
{
   {
        int                             arr1[5] = {1, 2, 3, 4, 5};
        ft::vector<int>                 v1_copied(arr1, arr1 + 5);
        std::vector<int>                 v2_copied(arr1, arr1 + 5);

        ft::vector<int> v1(v1_copied);
        std::vector<int> v2(v2_copied);
         if (vectors_equal(v2, v1))
            std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    }
    {
        int                             arr1[5] = {1, 2, 3, 4, 5};
        std::string                     arr2[3] = {"bonjour", "je", "suis"};
        ft::vector<int>                 v1_duplicated(arr1, arr1 + 5);
        std::vector<int>                 v2_duplicated(arr1, arr1 + 5);
        ft::vector<std::string>         v3_duplicated(arr2, arr2 + 3);
        std::vector<std::string>         v4_duplicated(arr2, arr2 + 3);


        ft::vector<int> v1;
        std::vector<int> v2;
        v1 = v1_duplicated;
        v2 = v2_duplicated;
        vectors_equal(v1, v2);
        v1[0] = 0;
    

        ft::vector<std::string> v3(10, "zzz");
        std::vector<std::string> v4(10, "zzz");
        v3 = v3_duplicated;
        v4 = v4_duplicated;
        vectors_equal(v3, v4);
    }
    // {
    //     std::string                     arr1[3] = {"bonjour", "je", "suis"};
    //     ft::vector<std::string>                 v1_copied(arr1, arr1 + 3);
    //     std::vector<std::string>                 v2_copied(arr1, arr1 + 3);

    //     ft::vector<std::string> v1(v1_copied);
    //     std::vector<std::string> v2(v2_copied);

    //      if (vectors_equal(v2, v1))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // }
    // //float       arr3[4] = {42.1, 42.2, 42.3, 42.4};
        
    // ft::vector<float>               v3_copied(6, 42.0f);
    // ft::vector<float>               v3(v3_copied);
    // std::vector<float>               v4_copied(6, 42.0f);
    // std::vector<float>               v4(v4_copied);
    //   if (vectors_equal(v4, v3))
    //         std::cout << "\033[1m\033[32m ✅ OK " << std::endl;
    //     else
    //         std::cout << "\033[1m\033[31m ❌ WRONG" << std::endl;
    // {
    //         std::vector< ft::vector<char*> >            v4_copied;
    //         ft::vector<ft::vector<char*> >               v3_copied;
    //         ft::vector<ft::vector<char*> >               v3(v3_copied);
    //         std::vector<ft::vector<char*> >               v4(v4_copied);
    // }
    // ft::vector< ft::vector<char*> > v4(v4_copied);
    // (v4.empty() == v4_copied.empty());
    // (v4.size() == v4_copied.size());
    // (v4.capacity() == v4_copied.capacity());
}

void modifiers()
{
    // pop_back_test();
    //insert_test();
    copy_test();
    // erase_test();
   // assign_test();
}