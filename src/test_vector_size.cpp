# include <vector>
# include "vector.hpp"

void test_vector_size()
{
     std::vector<int> vec2;
    ft::vector<int> vec;

    std::cout << "\033[1m\033[34mMY VEC MAX SIZE : \033[1m\033[37m" << vec.max_size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC MAX SIZE : \033[1m\033[37m" << vec2.max_size() << std::endl << std::endl;


    std::cout << "\033[1m\033[34mMY VEC SIZE : \033[1m\033[37m" << vec.size() << std::endl;
    std::cout << "\033[1m\033[34mMY VEC CAPACITY \033[1m\033[37m" <<vec.capacity() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC SIZE : \033[1m\033[37m" << vec2.size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC CAPACITY \033[1m\033[37m" <<vec2.capacity() << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    std::cout << std::endl;
    std::cout << "\033[1m\033[34mMY VEC SIZE : \033[1m\033[37m" << vec.size() << std::endl;
    std::cout << "\033[1m\033[34mMY VEC CAPACITY \033[1m\033[37m" <<vec.capacity() << std::endl;
     std::cout << "\033[1m\033[33mREAL VEC SIZE : \033[1m\033[37m" << vec2.size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC CAPACITY \033[1m\033[37m" <<vec2.capacity() << std::endl;
    vec.push_back(3);
    vec2.push_back(3);
    std::cout << "\033[1m\033[34mMY VEC SIZE : \033[1m\033[37m" << vec.size() << std::endl;
    std::cout << "\033[1m\033[34mMY VEC CAPACITY \033[1m\033[37m" <<vec.capacity() << std::endl;
     std::cout << "\033[1m\033[33mREAL VEC SIZE : \033[1m\033[37m" << vec2.size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC CAPACITY \033[1m\033[37m" <<vec2.capacity() << std::endl;
   vec.push_back(1);
    vec2.push_back(1);
    std::cout << std::endl;
    std::cout << "\033[1m\033[34mMY VEC SIZE : \033[1m\033[37m" << vec.size() << std::endl;
    std::cout << "\033[1m\033[34mMY VEC CAPACITY \033[1m\033[37m" <<vec.capacity() << std::endl;
     std::cout << "\033[1m\033[33mREAL VEC SIZE : \033[1m\033[37m" << vec2.size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC CAPACITY \033[1m\033[37m" <<vec2.capacity() << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    std::cout << std::endl;
    std::cout << "\033[1m\033[34mMY VEC SIZE : \033[1m\033[37m" << vec.size() << std::endl;
    std::cout << "\033[1m\033[34mMY VEC CAPACITY \033[1m\033[37m" <<vec.capacity() << std::endl;
     std::cout << "\033[1m\033[33mREAL VEC SIZE : \033[1m\033[37m" << vec2.size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC CAPACITY \033[1m\033[37m" <<vec2.capacity() << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    std::cout << std::endl;
    std::cout << "\033[1m\033[34mMY VEC SIZE : \033[1m\033[37m" << vec.size() << std::endl;
    std::cout << "\033[1m\033[34mMY VEC CAPACITY \033[1m\033[37m" <<vec.capacity() << std::endl;
     std::cout << "\033[1m\033[33mREAL VEC SIZE : \033[1m\033[37m" << vec2.size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC CAPACITY \033[1m\033[37m" <<vec2.capacity() << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    std::cout << std::endl;
    std::cout << "\033[1m\033[34mMY VEC SIZE : \033[1m\033[37m" << vec.size() << std::endl;
    std::cout << "\033[1m\033[34mMY VEC CAPACITY \033[1m\033[37m" <<vec.capacity() << std::endl;
     std::cout << "\033[1m\033[33mREAL VEC SIZE : \033[1m\033[37m" << vec2.size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC CAPACITY \033[1m\033[37m" <<vec2.capacity() << std::endl;
    vec.push_back(1);
    vec2.push_back(1);
    std::cout << std::endl;
    std::cout << "\033[1m\033[34mMY VEC SIZE : \033[1m\033[37m" << vec.size() << std::endl;
    std::cout << "\033[1m\033[34mMY VEC CAPACITY \033[1m\033[37m" <<vec.capacity() << std::endl;
     std::cout << "\033[1m\033[33mREAL VEC SIZE : \033[1m\033[37m" << vec2.size() << std::endl;
    std::cout << "\033[1m\033[33mREAL VEC CAPACITY \033[1m\033[37m" <<vec2.capacity() << std::endl;
    //print_vec(vec);
    return ;
}