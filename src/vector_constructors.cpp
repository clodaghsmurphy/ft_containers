# include <vector>
# include "vector.hpp"
# include "test.hpp"

void test1()
{
    std::cout << std::endl << "\033[1m\033[35mPUSH BACK INTIALIZING \033[1m\033[37m"  << std::endl << std::endl;
    {
        std::cout << "\033[1m\033[33mMINE \033[1m\033[37m"  << std::endl;
        ft::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);


        print_container(vec);
    }
    {
        std::cout << "\033[1m\033[33mREAL \033[1m\033[37m"  << std::endl;
        std::vector<int> vec;

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);


        print_container(vec);
    }
}

 void test2()
{
    std::cout << std::endl << "\033[1m\033[35mFILL CONSTRUCTOR \033[1m\033[37m"  << std::endl << std::endl;
    std::vector<int> vec(5, 5);
    ft::vector<int> vec1(5, 5);

    //ft::vector<int> vec2(vec1.begin(), vec1.end());

    std::cout << "\033[1m\033[33mMINE \033[1m\033[37m"  << std::endl;
    print_container(vec1); 

    std::cout << "\033[1m\033[33mREAL \033[1m\033[37m"  << std::endl;
    print_container(vec); 


    //print_container(vec2); 

}

 void test3()
{
    std::cout << std::endl << "\033[1m\033[35mRANGE CONSTRUCTOR \033[1m\033[37m"  << std::endl << std::endl;
    std::vector<int> vec(5, 5);
    ft::vector<int> vec1(5, 5);

    ft::vector<int> vec2(vec1.begin(), vec1.end());
    std::vector<int> vec3(vec.begin(), vec.end());
    

    std::cout << "\033[1m\033[33mMINE \033[1m\033[37m"  << std::endl;
    print_container(vec2); 

    std::cout << "\033[1m\033[33mREAL \033[1m\033[37m"  << std::endl;
    print_container(vec3); 


    //print_container(vec2); 

}

void    vector_constructors()
{
    test1();
    test2();
    test3();
}