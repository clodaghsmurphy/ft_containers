# include "container.hpp"
# include"vector.hpp"
# include "vector"

template<class T>
void    print_vec(T vec)
{
    typename T::iterator it = vec.begin();
    typename T::iterator ite = vec.end();

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

     print_vec(vec1); 
     print_vec(vec); 

}

int main()
{
    test1();
    test2();
    




    return 0;
}


