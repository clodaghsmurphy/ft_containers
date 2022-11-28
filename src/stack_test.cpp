# include "container.hpp"
# include "test.hpp"
# include "stack.hpp"
# include <stack>

void    stack_test()
{
    ft::stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    for (size_t i = 0; i < stack.size(); i++)
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    std::cout << "REAL" << std::endl;

     std::stack<int> stack2;

    stack2.push(1);
    stack2.push(2);
    stack2.push(3);

    for (size_t i = 0; i < stack2.size(); i++)
    {
        std::cout << stack2.top() << std::endl;
        stack2.pop();
    }
}