#include <vector>
#include "vector.hpp"
#include "test.hpp"

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second)
{
	if (!(first < second))
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
	else if (!(first <= second))
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
	else if (!(first > second)) 
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
	else if (!(first >= second)) 
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
}

template <typename T, typename U>
int    vectors_equal(T &vec, U &vec2)
{
    typename T::iterator it = vec.begin();
    typename T::iterator ite = vec.end();
    typename U::iterator it2 = vec2.begin();
    typename U::iterator ite2 = vec2.end();
   
    if (vec.size() != vec2.size() || vec.capacity() != vec2.capacity() || vec.empty() != vec2.empty())
    {
         std::cout << "REAL VEC IS : " << std::endl;
            print_container(vec);
            std::cout << std::endl;
            std::cout << "MY VEC IS : " << std::endl;
            print_container(vec2);
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
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
      }
      {

          std::vector<int> vec;
          ft::vector<int> my_vec;


          for (int i = 0; i < 100; i++)
              vec.push_back(i);
          std::vector<int>::iterator it = vec.begin();

          it = vec.insert(it, 5);
          for (int i = 0; i < 100; i++)
              my_vec.push_back(i);
          ft::vector<int>::iterator my_it = my_vec.begin();

          my_vec.insert(my_it, 5);

          if (vectors_equal(vec, my_vec))
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
      }
      {

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
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
      }
      {

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
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
      }
      {

          std::vector<int> vec;
          ft::vector<int> my_vec;


          vec.push_back(1);
          vec.push_back(2);
          vec.push_back(3);
          vec.push_back(4);
          std::vector<int>::iterator it = vec.begin();

          vec.insert(it, 3, 0);
          /* std::cout << "in main and container is : " << std::endl;
          print_container(vec); */

          my_vec.push_back(1);
          my_vec.push_back(2);
          my_vec.push_back(3);
          my_vec.push_back(4);
          ft::vector<int>::iterator my_it = my_vec.begin();

          my_vec.insert(my_it, 3, 0);
          /* std::cout << "in main and my container is : " << std::endl;
          print_container(my_vec); */

          if (vectors_equal(vec, my_vec))
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
      }
        {

          std::vector<int> vec;
          ft::vector<int> my_vec;


          vec.push_back(1);
          vec.push_back(2);
          vec.push_back(3);
          vec.push_back(4);
          std::vector<int>::iterator it = vec.end();

          vec.insert(it, 3, 0);
          /* std::cout << "in main and container is : " << std::endl;
          print_container(vec); */

          my_vec.push_back(1);
          my_vec.push_back(2);
          my_vec.push_back(3);
          my_vec.push_back(4);
          ft::vector<int>::iterator my_it = my_vec.end();

          my_vec.insert(my_it, 3, 0);
          /* std::cout << "in main and my container is : " << std::endl;
          print_container(my_vec); */

          if (vectors_equal(vec, my_vec))
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
          std::vector<int>::iterator itb = vec.begin();
          std::vector<int>::iterator itb2 = vec2.begin();
          std::vector<int>::iterator ite = vec.end();

          vec2.insert(itb2 , itb, ite);
            // std::cout << "in main and container is : " << std::endl;
            // print_container(vec);

          my_vec.push_back(1);
          my_vec.push_back(2);
          my_vec.push_back(3);
          my_vec.push_back(4);
          ft::vector<int>::iterator my_itb = my_vec.begin();
          ft::vector<int>::iterator my_itb2 = my_vec2.begin();
          ft::vector<int>::iterator my_ite = my_vec.end();

          my_vec2.insert(my_itb2, my_itb, my_ite);
            //std::cout << "in main and my container is : " << std::endl;
            //print_container(my_vec);

          if (vectors_equal(vec2, my_vec2))
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
      }
      {

          std::vector<int> vec;
          std::vector<int> vec2;
          ft::vector<int> my_vec;
          ft::vector<int> my_vec2;


          for (int i = 0; i < 100; i++)
              vec.push_back(1);
          std::vector<int>::iterator itb = vec.begin();
          std::vector<int>::iterator itb2 = vec2.begin();
          std::vector<int>::iterator ite = vec.end();

          vec2.insert(itb2 , itb, ite);
            // std::cout << "in main and container is : " << std::endl;
            // print_container(vec);

          for (int i = 0; i < 100; i++)
              my_vec.push_back(1);
  
          ft::vector<int>::iterator my_itb = my_vec.begin();
          ft::vector<int>::iterator my_itb2 = my_vec2.begin();
          ft::vector<int>::iterator my_ite = my_vec.end();

          my_vec2.insert(my_itb2, my_itb, my_ite);
            //std::cout << "in main and my container is : " << std::endl;
            //print_container(my_vec);

          if (vectors_equal(vec2, my_vec2))
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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

          std::vector<int>::iterator itb = vec.end();
          std::vector<int>::iterator itb2 = vec2.begin();
          std::vector<int>::iterator ite = vec.end();

          vec2.insert(itb2 , itb, ite);
            // std::cout << "in main and container is : " << std::endl;
            // print_container(vec);

          my_vec.push_back(1);
          my_vec.push_back(2);
          my_vec.push_back(3);
          my_vec.push_back(4);
          ft::vector<int>::iterator my_itb = my_vec.end();
          ft::vector<int>::iterator my_itb2 = my_vec2.begin();
          ft::vector<int>::iterator my_ite = my_vec.end();

          my_vec2.insert(my_itb2, my_itb, my_ite);
            //std::cout << "in main and my container is : " << std::endl;
            //print_container(my_vec);

          if (vectors_equal(vec2, my_vec2))
              std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
          else
              std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
      }
    {
        int             arr1[5] = {1, 2, 3, 4, 5};
        std::vector<int> v1;
        ft::vector<int> v2;
        std::vector<int>::iterator it;
        ft::vector<int>::iterator it2;


        it = v1.insert(v1.end(), 1);
        it2 = v2.insert(v2.end(), 1);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        it = v1.insert(v1.end(), 2);
        it2 = v2.insert(v2.end(), 2);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        it = v1.insert(v1.begin(), 0);
        it2 = v2.insert(v2.begin(), 0);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        v1.insert(v1.begin() + 1, arr1 + 1, arr1 + 4);
        v2.insert(v2.begin() + 1, arr1 + 1, arr1 + 4);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        
        v1.insert(v1.begin() + 2, (size_t)3, (int)-1);
        v2.insert(v2.begin() + 2, (size_t)3, (int)-1);

        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
    }
      {
         std::vector<int> vec;
         std::vector<int> vec2;
         ft::vector<int> my_vec;
         ft::vector<int> my_vec2;


  
         //std::vector<int>::iterator itb = vec.begin();
         std::vector<int>::iterator itb2 = vec2.end();
         //std::vector<int>::iterator ite = vec.end();

         itb2 = vec2.insert(itb2 , 1);
         itb2 = vec2.insert(itb2 , 2);
        //    std::cout << "in main and container is : " << std::endl;
        //    print_container(vec);

    
         //ft::vector<int>::iterator my_itb = my_vec.begin();
         ft::vector<int>::iterator my_itb2 = my_vec2.end();
         //ft::vector<int>::iterator my_ite = my_vec.end();

         my_itb2 = my_vec2.insert(my_itb2, 1);
         my_itb2 =my_vec2.insert(my_itb2, 2);
        //   std::cout << "in main and my container is : " << std::endl;
        //   print_container(my_vec);

         if (vectors_equal(vec2, my_vec2))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
    
         std::vector<int>::iterator itb = vec.begin();
         std::vector<int>::iterator itb2 = vec2.end();
         std::vector<int>::iterator ite = vec.end();

         vec2.insert(itb2 , itb, ite);
        //    std::cout << "in main and container is : " << std::endl;
        //    print_container(vec);

         my_vec.push_back(1);
         my_vec.push_back(2);
         my_vec.push_back(3);
         my_vec.push_back(4);
         ft::vector<int>::iterator my_itb = my_vec.begin();
         ft::vector<int>::iterator my_itb2 = my_vec2.end();
         ft::vector<int>::iterator my_ite = my_vec.end();

         my_vec2.insert(my_itb2, my_itb, my_ite);
        //    std::cout << "in main and my container is : " << std::endl;
        //    print_container(my_vec);

         if (vectors_equal(vec2, my_vec2))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
     }
     {
         int         arr1[5] = {1, 2, 3, 4, 5};
         std::string arr2[3] = {"bonjour", "je", "suis"};
         //float       arr3[4] = {42.1, 42.2, 42.3, 42.4};

         ft::vector<int> v1(arr1, arr1 + 5);
         std::vector<int> v2(arr1, arr1 + 5);
    
     if (vectors_equal(v2, v1))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
     }
     {
         std::string arr2[3] = {"bonjour", "je", "suis"};

         ft::vector<std::string> v2(arr2, arr2 + 3);
         std::vector<std::string> v3(arr2, arr2 + 3);

         for (size_t i = 0; i < v2.size(); i++)
         {
             if (!(v2[i] == arr2[i]))
             {
                 std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl; 
                 std::cout << "MINE : " << v2[i] << std::endl;
                 std::cout << "ARRAY : " << arr2[i] << std::endl;
             }
         }
        
         if (vectors_equal(v3, v2))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
     }
     {
         int             arr1[5] = {1, 2, 3, 4, 5};
         ft::vector<int> v1;
         ft::vector<int>::iterator it;
         std::vector<int> v2;
         std::vector<int>::iterator it2;

         it = v1.insert(v1.end(), 1);
         it2 = v2.insert(v2.end(), 1);
         if (vectors_equal(v2, v1))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

         it = v1.insert(v1.end(), 2);
         it2 = v2.insert(v2.end(), 2);
         if (vectors_equal(v2, v1))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

         it = v1.insert(v1.begin(), 0);
         it2 = v2.insert(v2.begin(), 0);
         if (vectors_equal(v2, v1))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

         v1.insert(v1.begin() + 1, arr1 + 1, arr1 + 4);
         v2.insert(v2.begin() + 1, arr1 + 1, arr1 + 4);
         if (vectors_equal(v2, v1))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
 //       ft::vector<int>::iterator my_it = my_vec.begin();

        my_vec2.assign(my_vec.end(), my_vec.end());

        if (vectors_equal(vec, my_vec))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
    

    my_vec.push_back(1);
    my_vec.push_back(2);
    my_vec.push_back(3);
    my_vec.push_back(4);


    if (vectors_equal(vec, my_vec))
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
    ft::vector<int>::iterator my_it = my_vec.begin();
    vec.erase(it);
    
    my_vec.erase(my_it);

    if (vectors_equal(vec, my_vec))
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
    else
        std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
    }
    {
        int             arr1[5] = {1, 2, 3, 4, 5};
        std::vector<int> v1(arr1, arr1 + 5);
        std::vector<int>::iterator it;
        ft::vector<int> v2(arr1, arr1 + 5);
        ft::vector<int>::iterator it2;

        it = v1.erase(v1.begin());
        it2 = v2.erase(v2.begin());
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        it = v1.erase(v1.end() - 1);
        it2 = v2.erase(v2.end() -1);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        it = v1.erase(v1.end() - 2);
        it2 = v2.erase(v2.end() -2);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        v1.assign(arr1, arr1 + 5);
        v2.assign(arr1, arr1 + 5);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        it = v1.erase(v1.begin() + 1, v1.begin() + 3);
        it2 = v2.erase(v2.begin()  + 1, v2.begin() + 3);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
    }
    {
        std::vector<std::string> v1(10);
        ft::vector<std::string> v2(10);
        for (unsigned long int i = 0; i < v1.size(); ++i)
		    v1[i] = std::string((v1.size() - i), i + 65);
        for (unsigned long int i = 0; i < v2.size(); ++i)
		    v2[i] = std::string((v2.size() - i), i + 65);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        v1.erase(v1.begin() + 2);
        v2.erase(v2.begin() + 2);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        v1.erase(v1.begin());
        v2.erase(v2.begin());
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        v1.erase(v1.end() - 1);
        v2.erase(v2.end() - 1);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        v1.erase(v1.begin(), v1.begin() + 3);
        
        v2.erase(v2.begin(), v2.begin() + 3);
            if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        v1.erase(v1.end() - 3, v1.end() - 1);
        v2.erase(v2.end() - 3, v2.end() - 1);
        if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        v1.push_back("Hello");
        v2.push_back("Hello");
        v1.push_back("Hi there");
        v2.push_back("Hi there");
        v1.erase(v1.end() - 3, v1.end());
        v2.erase(v2.end() - 3, v2.end());
    if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        v1.push_back("ONE");
        v1.push_back("TWO");
        v1.push_back("THREE");
        v1.push_back("FOUR");

        v2.push_back("ONE");
        v2.push_back("TWO");
        v2.push_back("THREE");
        v2.push_back("FOUR");
        v1.erase(v1.begin(), v1.end());
        v2.erase(v2.begin(), v2.end());
            if (vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
    }
    {
        int j =0;
            std::vector<int> vct(10);
            std::vector<int> vct2;
            std::vector<int> vct3;
            ft::vector<int> ft_vct(10);
            ft::vector<int> ft_vct2;
            ft::vector<int> ft_vct3;

            for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = (vct.size() - i) * 3;
            for (unsigned long int i = 0; i < ft_vct.size(); ++i)
                ft_vct[i] = (ft_vct.size() - i) * 3;
            if (vectors_equal(vct, ft_vct))
                std::cout << j++ << ": \033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << j++ << ": \033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

            vct2.insert(vct2.end(), 42);
            vct2.insert(vct2.begin(), 2, 21);
            ft_vct2.insert(ft_vct2.end(), 42);
            ft_vct2.insert(ft_vct2.begin(), 2, 21);
            if (vectors_equal(vct2, ft_vct2))
                std::cout << j++ << ": \033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << j++ << ": \033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

            vct2.insert(vct2.end() - 2, 42);
            ft_vct2.insert(ft_vct2.end() - 2, 42);
            if (vectors_equal(vct2, ft_vct2))
                std::cout << j++ << ": \033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << j++ << ": \033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

            vct2.insert(vct2.end(), 2, 84);
            ft_vct2.insert(ft_vct2.end(), 2, 84);
            if (vectors_equal(vct2, ft_vct2))
                std::cout << j++ << ": \033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << j++ << ": \033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

            vct2.resize(4);
            ft_vct2.resize(4);
            if (vectors_equal(vct2, ft_vct2))
                std::cout << j++ << ": \033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << j++ << ": \033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

            vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
            vct.clear();
            ft_vct2.insert(ft_vct2.begin() + 2, ft_vct.begin(), ft_vct.end());
            ft_vct.clear();
            if (vectors_equal(vct2, ft_vct2))
                std::cout << j++ << ": \033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << j++ << ": \033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

             if (vectors_equal(vct, ft_vct))
                std::cout << j++ << ": \033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << j++ << ": \033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

            for (int i = 0; i < 5; ++i)
                vct3.insert(vct3.end(), i);
            for (int i = 0; i < 5; ++i)
                ft_vct3.insert(ft_vct3.end(), i);
            vct3.insert(vct3.begin() + 1, 2, 111);
            ft_vct3.insert(ft_vct3.begin() + 1, 2, 111);
            if (vectors_equal(vct3, ft_vct3))
                std::cout << j++ << ": \033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << j++ << ": \033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
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
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
     }
     {
         std::string                     arr2[3] = {"bonjour", "je", "suis"};
         ft::vector<std::string>         v1_duplicated(arr2, arr2 + 3);
         std::vector<std::string>         v2_duplicated(arr2, arr2 + 3);

         ft::vector<std::string> v1(10, "zzz");
         std::vector<std::string> v2(10, "zzz");

         v1 = v1_duplicated;
         v2 = v2_duplicated;
         vectors_equal(v1, v2);
         v1[0] = "aaa";
         v2[0] = "aaa";
         v1[1] = "bbb";
         v2[1] = "bbb";
         v1[2] = "ccc";
         v2[2] = "ccc";
       
      
         if(vectors_equal(v1, v2))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
     }
      {
        //   ft::vector< ft::vector<char*> > v4_duplicated;
        //   std::cout << "v4 duplicated empty is : " << &v4_duplicated << std::endl;

        //   ft::vector< ft::vector<char*> > v4(2, ft::vector<char*>(2, NULL));
        //   std::cout << "v4 after copy initializiation is : " << &v4 << std::endl;
        //   v4 = v4_duplicated;
        //   std::cout << "v4 after copy assignment is : " << &v4 << std::endl;
        //   std::cout << "v4 duplicated empty is : " << &v4_duplicated << std::endl;
      }
    {
        std::string                     arr2[3] = {"bonjour", "je", "suis"};

        std::vector<std::string>         v1_duplicated(arr2, arr2 + 3);
        ft::vector<std::string>         v2_duplicated(arr2, arr2 + 3);

        std::vector<std::string> v1(10, "zzz");
        ft::vector<std::string> v2(10, "zzz");

        v1 =v1_duplicated;
        v2 =v2_duplicated;
        if(vectors_equal(v1_duplicated, v2_duplicated))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        if(vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;


    }
}

    void    iterator_test()
    {
        {
            std::string                     arr2[3] = {"bonjour", "je", "suis"};

            ft::vector<std::string>         v1_duplicated(arr2, arr2 + 3);
            std::vector<std::string>         v2_duplicated(arr2, arr2 + 3);


            ft::vector<std::string> v1;
            std::vector<std::string> v2;
            v1 = v1_duplicated;
            v2 = v2_duplicated;

            std::vector<std::string>::iterator it1= v2.begin();
            ft::vector<std::string>::iterator it2 = v1.begin();

            while (it1 != v2.end() && it2 != v1.end())
            {
                
                it1++;
                it2++;
            }
            std::cout << std::endl;
        }
        {
            ft::vector<int> vct;
            ft::vector<int>::iterator it = vct.begin();
            ft::vector<int>::const_iterator cit = vct.begin();

            ft::vector<int>::reverse_iterator rit(it);

            ft::vector<int>::const_reverse_iterator crit(rit);
            ft::vector<int>::const_reverse_iterator crit_(it);
            ft::vector<int>::const_reverse_iterator crit_2(cit);

            /* error expected
            ft::vector<int>::reverse_iterator rit_(crit);
            ft::vector<int>::reverse_iterator rit2(cit);
            ft::vector<int>::iterator it2(rit);
            ft::vector<int>::const_iterator cit2(crit);
            */

            std::cout << "OK" << std::endl;

        }
        {
            std::string                     arr2[3] = {"bonjour", "je", "suis"};

            ft::vector<std::string>         v1_duplicated(arr2, arr2 + 3);
            std::vector<std::string>         v2_duplicated(arr2, arr2 + 3);


            ft::vector<std::string> v1;
            std::vector<std::string> v2;
            v1 = v1_duplicated;
            v2 = v2_duplicated;

            std::vector<std::string>::reverse_iterator it1= v2.rbegin();
            ft::vector<std::string>::reverse_iterator it2 = v1.rbegin();

            while (it1 != v2.rend() && it2 != v1.rend())
            {
                
                it1++;
                it2++;  
            }
            std::cout << std::endl;
        }
        {
            	const int size = 5;
        ft::vector<int> v2(size);
        std::vector<int> v1(size);
        std::vector<int>::iterator it_ = v1.begin();
        ft::vector<int>::iterator it_2 = v2.begin();
        ft::vector<int>::reverse_iterator it2(it_2);
        std::vector<int>::reverse_iterator it(it_);

        for (int i = 0; i < size; ++i)
            v1[i] = (i + 1) * 5;
        for (int i = 0; i < size; ++i)
            v2[i] = (i + 1) * 5;
        if(vectors_equal(v1, v2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        if ((it_ == it.base()) == (it_2 == it2.base()) )
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        if ((it_ == (it + 3).base()) == (it_ == (it + 3).base())) 
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        std::cout << (it_2 == it2.base()) << std::endl;
        std::cout << (it_2 == (it2 + 3).base()) << std::endl;

        std::cout << *(it.base() + 1) << std::endl;
        std::cout << *(it - 3) << std::endl;
        std::cout << *(it - 3).base() << std::endl;
        it -= 3;
        it2 -= 3;
        std::cout << *it.base() << std::endl;

        std::cout << "TEST OFFSET" << std::endl;
        if (*(it) == *(it2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        
        if (*(it).base() == *(it2).base()) 
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        if (*(it - 0) == *(it2 - 0)) 
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        if (*(it - 0).base() == *(it2 - 0).base()) 
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        if (*(it - 1).base() == *(it - 1).base())
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        }
        {
            std::cout << std::endl;
            const int size = 5;
            std::vector<int> v1(size);
            ft::vector<int> v2(size);
            std::vector<int>::iterator it = v1.begin();
            ft::vector<int>::iterator it2 = v2.begin();
            std::vector<int>::const_iterator ite = v1.begin();
            ft::vector<int>::const_iterator ite2 = v2.begin();

            for (int i = 0; i < size; ++i)
                it[i] = (size - i) * 5;
            for (int i = 0; i < size; ++i)
                it2[i] = (size - i) * 5;
            //prepost_incdec(v1);
            if(vectors_equal(v1, v2))
                std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
            it = it + 5;
            it = 1 + it;
            it = it - 4;

            it2 = it2 + 5;
            it2 = 1 + it2;
            it2 = it2 - 4;

            if (*(it += 2) == *(it2 += 2))
                std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
            if (*(it -= 1) == *(it2 -= 1))
                std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;   

            *(it -= 2) = 42;
            *(it += 2) = 21;

            *(it2 -= 2) = 42;
            *(it2 += 2) = 21;

            if (*(ite += 2) == *(ite2 += 2))
                std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
            if (*(ite -= 2) ==*(ite2 -= 2))
                std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

            if ((ite == it) == (ite2 == it2))
                std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
            if ((ite - it) == (ite2 - it2))
                std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
             if ((ite + 3 == it) ==(ite2 + 3 == it2))
                std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
            else
                std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        }

     {
         std::string                     arr1[3] = {"bonjour", "je", "suis"};
         ft::vector<std::string>                 v1_copied(arr1, arr1 + 3);
         std::vector<std::string>                 v2_copied(arr1, arr1 + 3);

         ft::vector<std::string> v1(v1_copied);
         std::vector<std::string> v2(v2_copied);

          if (vectors_equal(v2, v1))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
     }
  
     {
        const int size = 5;
        std::vector<int> v1(size);
        ft::vector<int> v2(size);
        std::vector<int>::reverse_iterator it(v1.rbegin());
        ft::vector<int>::reverse_iterator it2(v2.rbegin());
        std::vector<int>::const_reverse_iterator ite(v1.rend());
        ft::vector<int>::const_reverse_iterator ite2(v2.rend());

        for (int i = 1; it != ite; ++i)
            *it++ = (i * 7);
        for (int i = 1; it2 != ite2; ++i)
            *it2++ = (i * 7);

        it = v1.rbegin();
        ite = v1.rbegin();

       
        it2 = v2.rbegin();
        ite2 = v2.rbegin();
         if (*ite == *ite2)
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m " <<  *ite << " | " << *ite2 << std::endl;
        
        if  (*(++ite) == *(++ite2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m " <<  *ite << " | " << *ite2 << std::endl;
        if (*(ite++) == *(ite2++))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *ite << " | " << *ite2<< std::endl;
         if (*ite++ == *ite2++)
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *ite << " | " << *ite2<< std::endl;
        if (*++ite == *++ite2)
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *ite << " | " << *ite2<< std::endl;
         if (*ite == *ite2)
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m " <<  *ite << " | " << *ite2 << std::endl;
        // // if (it->m() == it2->m())
        // //     std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        // // else
        // //      std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        // //   if (ite->m() == ite2->m())
        // //     std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        // // else
        // //      std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;

        if (*(++it) == *(++it2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *it << " | " << *it2<< std::endl;
        if (*(it++) == *(it2++))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *it << " | " << *it2<< std::endl;
        if (*it++ == *it2++)
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *it << " | " << *it2<< std::endl;
        if (*++it == *++it2)
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *it << " | " << *it2<< std::endl;
        if (*(--it) == *(--it2))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *it << " | " << *it2<< std::endl;
        if (*--it == *--it2)
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m "  <<  *it << " | " << *it2<< std::endl;

        // (*it).m();
        // (*ite).m();

        // std::cout << *(--it) << std::endl;
        // std::cout << *(it--) << std::endl;
        // std::cout << *it-- << std::endl;
        // std::cout << *--it << std::endl;
     }
     {
        std::list<int> lst;
        std::list<int>::iterator lst_it;
        for (int i = 1; i < 5; ++i)
            lst.push_back(i * 3);

        std::vector<int> v1(lst.begin(), lst.end());
        ft::vector<int> v2(lst.begin(), lst.end());

        lst_it = lst.begin();
        for (int i = 1; lst_it != lst.end(); ++i)
            *lst_it++ = i * 5;
        v1.assign(lst.begin(), lst.end());
        v2.assign(lst.begin(), lst.end());

        v1.insert(v1.end(), lst.rbegin(), lst.rend());
        v2.insert(v2.end(), lst.rbegin(), lst.rend());
        if (vectors_equal(v1, v2))
             std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
         else
             std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
     }
     {
        const int size = 5;
        std::vector<int> v1(size);
        std::vector<int>::iterator it_0(v1.begin());
        std::vector<int>::iterator it_1(v1.end());
        std::vector<int>::iterator it_mid;

        std::vector<int>::const_iterator cit_0 = v1.begin();
        std::vector<int>::const_iterator cit_1;
        std::vector<int>::const_iterator cit_mid;

        ft::vector<int> v2(size);
        ft::vector<int>::iterator ft_it_0(v2.begin());
        ft::vector<int>::iterator ft_it_1(v2.end());
        ft::vector<int>::iterator ft_it_mid;

        ft::vector<int>::const_iterator ft_cit_0 = v2.begin();
        ft::vector<int>::const_iterator ft_cit_1;
        ft::vector<int>::const_iterator ft_cit_mid;

        for (int i = size; it_0 != it_1; --i)
            *it_0++ = i;
          for (int i = size; ft_it_0 != ft_it_1; --i)
            *ft_it_0++ = i;
        it_0 = v1.begin();
        ft_it_0 = v2.begin();
        cit_1 = v1.end();
        ft_cit_1 = v2.end();
        it_mid = it_0 + 3;
        ft_it_mid = ft_it_0 + 3;
        cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;
        ft_cit_mid = ft_it_0 + 3; ft_cit_mid = ft_cit_0 + 3; ft_cit_mid = ft_it_mid;

        std::cout << std::boolalpha;
        std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << " |  ";
        
        std::cout << ((ft_it_0 + 3 == ft_cit_0 + 3) && (ft_cit_0 + 3 == ft_it_mid)) << std::endl;
        

        std::cout << "\t\tft_eq_ope:" << std::endl;
        // regular it
        ft_eq_ope(it_0 + 3, it_mid);
        // ft_eq_ope(it_0, it_1);
        // ft_eq_ope(it_1 - 3, it_mid);
        // // const it
        // ft_eq_ope(cit_0 + 3, cit_mid);
        // ft_eq_ope(cit_0, cit_1);
        // ft_eq_ope(cit_1 - 3, cit_mid);
        // // both it
        // ft_eq_ope(it_0 + 3, cit_mid);
        // ft_eq_ope(it_mid, cit_0 + 3);
        // ft_eq_ope(it_0, cit_1);
        // ft_eq_ope(it_1, cit_0);
        // ft_eq_ope(it_1 - 3, cit_mid);
        // ft_eq_ope(it_mid, cit_1 - 3);
        }
        {
            ft::vector<int> v1(5);
            ft::vector<int>::iterator it = v1.begin(), ite = v1.end();

            std::cout << "len: " << (ite - it) << std::endl;
            for (; it != ite; ++it)
                *it = (ite - it);

            it = v1.begin();
            ft::vector<int> v1_range(it, --(--ite));
            for (int i = 0; it != ite; ++it)
                *it = ++i * 5;

            it = v1.begin();
            ft::vector<int> v1_copy(v1);
            for (int i = 0; it != ite; ++it)
                *it = ++i * 7;
            v1_copy.push_back(42);
            v1_copy.push_back(21);

            std::cout << "\t-- PART ONE --" << std::endl;
       

            v1 = v1_copy;
            v1_copy = v1_range;
            v1_range.clear();


        }
        {
            // const int size = 5;
            // ft::vector<int> const vct(size);
            // //ft::vector<int>::iterator it = vct.begin(); // <-- error expected

            // for (int i = 0; i < size; ++i)
            //     it[i] = i;
        }
    }

    void resize_test()
    {
        int             arr1[5] = {1, 2, 3, 4, 5};
        ft::vector<int> v1(arr1, arr1 + 5);
        std::vector<int> v2(arr1, arr1 + 5);

        
        v1.resize(7);
        v2.resize(7);
        
        if (vectors_equal(v2, v1))
            std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
        else
            std::cout << "\033[1m\033[31m ❌ WRONG \033[0m" << std::endl;
        v1.resize(10, 42);
        for (size_t i = 0; i < 5; i++)
        for (size_t i = 5; i < 7; i++)
        for (size_t i = 7; i < v1.size(); i++)

        v1.resize(10);
        for (size_t i = 0; i < 5; i++)
        for (size_t i = 5; i < 7; i++)
        for (size_t i = 7; i < v1.size(); i++)

        v1.resize(6);
        for (size_t i = 0; i < 5; i++)

        v1.resize(1);

        v1.resize(0);
}

template <class T, class Alloc, class T2, class Alloc2>
void	cmp(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs, const std::vector<T2, Alloc2> &lhs2, const std::vector<T2, Alloc2> &rhs2)
{
	static int i = 0;
    int flag = 0;

    std::cout << std::boolalpha;
	std::cout << "\033[0m############### [" << i++ << "] ###############"  << std::endl;
    if (!((lhs == rhs) == (lhs2 == rhs2)))
    {
	    std::cout << "\033[0m\033[31m eq: \033[0m" << ((lhs == rhs) == (lhs2 == rhs2))<< std::endl;
        flag = 1;

    }
    if (!((lhs != rhs) == (lhs2 != rhs2)))
    {
        std::cout << "\033[0m\033[31m ne: \033[0m" <<((lhs != rhs) == (lhs2 != rhs2)) << std::endl;
        flag = 1;

    }
    if(!((lhs <  rhs) == (lhs2 <  rhs2)))
    {
	    std::cout << "\033[0m\033[31mlt: \033[0m" << ((lhs <  rhs) == (lhs2 <  rhs2)) << std::endl;
        flag = 1;
    }
    if ( !((lhs <= rhs) == (lhs2 <= rhs2))) 
    {
        std::cout << "\033[0m\033[31m le: \033[0m" << ((lhs <= rhs) == (lhs2 <= rhs2)) << std::endl;
        flag = 1;
    }
    if (!((lhs >  rhs) == (lhs2 >  rhs2)))
    {
	    std::cout << "\033[0m\033[31mgt: \033[0m" << ((lhs >  rhs) == (lhs2 >  rhs2)) << std::endl;
        flag = 1;
    }
    if ( !((lhs >= rhs) == (lhs2 >= rhs2)))
    {
        std::cout << "\033[0m\033[31m ge: \033[0m" << ((lhs >= rhs) == (lhs2 >= rhs2))<< std::endl;
        flag = 1;
    }
    if (!flag)
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
}

void		cmp_op(void)
{
	ft::vector<int> vct(4);
	ft::vector<int> vct2(4);
    std::vector<int> v(4);
	std::vector<int> v2(4);

	cmp(vct, vct, v, v2);  // 0
	cmp(vct, vct2, v, v2); // 1

	vct2.resize(10);
	v2.resize(10);

	cmp(vct, vct2, v, v2); // 2
	cmp(vct, vct2, v, v2); // 3

	vct2[2] = 42;
	v2[2] = 42;

	cmp(vct, vct2, v, v2); // 4
	cmp(vct, vct2, v, v2); // 5

	swap(vct, vct2);
	swap(v, v2);

	cmp(vct, vct2, v, v2); // 6
	cmp(vct, vct2, v, v2); // 7

	{
        const int size = 5;
        ft::vector<int> vct(size);
        ft::vector<int>::reverse_iterator it_0(vct.rbegin());
        ft::vector<int>::reverse_iterator it_1(vct.rend());
        ft::vector<int>::reverse_iterator it_mid;

        ft::vector<int>::const_reverse_iterator cit_0 = vct.rbegin();
        ft::vector<int>::const_reverse_iterator cit_1;
        ft::vector<int>::const_reverse_iterator cit_mid;

        for (int i = size; it_0 != it_1; --i)
            *it_0++ = i;
        //printSize(vct, 1);
        it_0 = vct.rbegin();
        cit_1 = vct.rend();
        it_mid = it_0 + 3;
        cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

        std::cout << std::boolalpha;
        std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

        std::cout << "\t\tft_eq_ope:" << std::endl;
        // regular it
        ft_eq_ope(it_0 + 3, it_mid);
        ft_eq_ope(it_0, it_1);
        ft_eq_ope(it_1 - 3, it_mid);
        // const it
        ft_eq_ope(cit_0 + 3, cit_mid);
        ft_eq_ope(cit_0, cit_1);
        ft_eq_ope(cit_1 - 3, cit_mid);
        // both it
        ft_eq_ope(it_0 + 3, cit_mid);
        ft_eq_ope(it_mid, cit_0 + 3);
        ft_eq_ope(it_0, cit_1);
        ft_eq_ope(it_1, cit_0);
        ft_eq_ope(it_1 - 3, cit_mid);
        ft_eq_ope(it_mid, cit_1 - 3);
    }
}


void modifiers()
{
     pop_back_test();
    insert_test();
     copy_test();
    resize_test();
    cmp_op();
      iterator_test();
     erase_test();
     assign_test();
}