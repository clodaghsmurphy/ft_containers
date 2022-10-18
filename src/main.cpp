# include "container.hpp"
# include"vector.hpp"
# include "vector"

template<class T>
void    print_vec(T vec)
{
    typename T::iterator it = vec.begin();
    typename T::iterator ite = vec.end();

    //std::cout << ft::is_integral<typename std::iterator_traits<it>::value_type>::value << std::endl;

     std::cout << "before" << std::endl;
    while (it != ite)
    {
        int t = *it;
        std::cout << &t << " : " << *it << std::endl;
        it++;
    }   
}


void test1()
{
    {
        ft::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);


        print_vec(vec);
    }
    {
        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);


        print_vec(vec);
    }
}

 void test2()
{
    std::vector<int> vec(5, 5);
    ft::vector<int> vec1(5, 5);

    ft::vector<int> vec2(vec1.begin(), vec1.end());

     print_vec(vec1); 
     print_vec(vec); 
     print_vec(vec2); 

}
 

/* 
void test3()
{
    ft::vector<int> vec();
    ft::vector<int>::iterator it;

     std::cout << std::boolalpha;
 
    std::cout << ft::is_integral<A>::value << std::endl;
    std::cout << ft::is_integral<int>::value << std::endl;


} */

int main()
{
    //test1();
    test2();
    //test3();    




    return 0;
}


