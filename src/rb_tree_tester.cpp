# include "red_black_tree.hpp"
# include "map.hpp"
#include "my_pair.hpp"
//# include "iterator.hpp"
# include <string>
# include <map>


        template <typename MAP, typename T1, typename T2>
    void	ft_bound(MAP &mp, const T1 &param)
    {
        ft_iterator ite = mp.end(), it[2];
        _pair<ft_iterator, ft_iterator> ft_range;

        std::cout << "\t-- [" << iter++ << "] --" << std::endl;
        std::cout << "with key [" << param << "]:" << std::endl;
        it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
        ft_range = mp.equal_range(param);
        std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
        std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
        std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
    }

    template <typename MAP, typename T1, typename T2>
    void	ft_const_bound(const MAP &mp, const T1 &param)
    {
        ft_const_iterator ite = mp.end(), it[2];
        _pair<ft_const_iterator, ft_const_iterator> ft_range;

        std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
        std::cout << "with key [" << param << "]:" << std::endl;
        it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
        ft_range = mp.equal_range(param);
        std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
        std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
        std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
    }
    template <typename MAP, typename T1, typename T2>
    void    bounds()
    {
        std::list<ft::map<T1, T2>::value_type> lst;
        unsigned int lst_size = 10;
        for (unsigned int i = 0; i < lst_size; ++i)
            lst.push_back(T3(i + 1, (i + 1) * 3));
        ft::map<T1, T2> mp(lst.begin(), lst.end());
        printSize(mp);

        ft_const_bound(mp, -10);
        ft_const_bound(mp, 1);
        ft_const_bound(mp, 5);
        ft_const_bound(mp, 10);
        ft_const_bound(mp, 50);

        printSize(mp);

        mp.lower_bound(3)->second = 404;
        mp.upper_bound(7)->second = 842;
        ft_bound(mp, 5);
        ft_bound(mp, 7);

        printSize(mp);
        return (0);

    }


void rb_tester()
{
    {
        ft::map<const int, std::string> test;

        test.insert(ft::pair<const int, std::string>(1, "hello"));
        ft::map<const int, std::string>::iterator it;

        it = test.begin();
        std::cout << it->first << std::endl;
        it = test.find(1);
        std::cout << (*it).first << std::endl;
        it = test.find(9);
        std::cout << it->first << std::endl;


    }
    {
        std::cout << "\n      REAL        \n";
         std::map<int, std::string> test;
        std::map<const int, std::string>::iterator it;

        test.insert(std::pair<int, std::string>(1, "hello"));
        it = test.begin();
        std::cout << (*it).first << std::endl;
        it = test.find(1);
        std::cout << (*it).first << std::endl;
         it = test.end();
        std::cout << it->first << std::endl;
          it = test.find(9);
        std::cout << it->first << std::endl;

    }
    bounds<ft::map, int, int>();
}