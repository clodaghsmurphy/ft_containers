#include <vector>
#include "vector.hpp"
#include "test.hpp"

void test1()
{
    std::vector<int> vec(5, 5);

    print_container(vec);
    vec.assign(2, 3);
    print_container(vec);

}

void modifiers()
{
    test1();
}