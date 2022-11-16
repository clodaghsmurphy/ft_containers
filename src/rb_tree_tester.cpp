# include "red_black_tree.hpp"
# include "map.hpp"

void rb_tester()
{
    {
        ft::map<int, std::string> test;

        test.insert(ft::pair<int, std::string>(1, "hello"));
    }
    {
         std::map<int, std::string> test;

        test.insert(std::pair<int, std::string>(1, "hello"));
    }
}