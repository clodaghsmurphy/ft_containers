# include "red_black_tree.hpp"

void rb_tester()
{
    ft::rb_tree<int, int> tree;

    tree.insert(4, 4);
    tree.print();
    std::cout << std::endl;

    tree.insert(1, 1);
    tree.print();
    std::cout << std::endl;


    tree.insert(3, 3);
    tree.print();
    std::cout << std::endl;

    tree.insert(2, 2);
    tree.print();


}