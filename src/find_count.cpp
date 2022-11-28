# include "test.hpp"

#define T1 int
#define T2 std::string

ft::map<T1, T2> mp;
ft::map<T1, T2>::iterator it = mp.end();

std::map<T1, T2> mp2;
std::map<T1, T2>::iterator it2 = mp2.end();

void	ft_find(T1 const &k)
{
	ft::map<T1, T2>::iterator ret = mp.find(k);
	std::map<T1, T2>::iterator ret2 = mp2.find(k);

	if ((ret != it) && (ret2 != it2))
		printPair2(ret, ret2);
	else if (((ret != it) && (ret2 == it2)) || ((ret == it) && (ret2 != it2)))
        std::cout << "❌ map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
	std::cout << "map::count(" << k << ")\treturned [" << mp2.count(k) << "]" << std::endl;
}

void map_find_count(void)
{
	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";

    mp2[42] = "fgzgxfn";
	mp2[25] = "funny";
	mp2[80] = "hey";
	mp2[12] = "no";
	mp2[27] = "bee";
	mp2[90] = "8";
	printSize(mp);
	printSize(mp2);

	std::cout << "\t-- FIND --" << std::endl;
	ft_find(12);
	ft_find(3);
	ft_find(35);
	ft_find(90);
	ft_find(100);

	std::cout << "\t-- COUNT --" << std::endl;
	ft_count(-3);
	ft_count(12);
	ft_count(3);
	ft_count(35);
	ft_count(90);
	ft_count(100);

	mp.find(27)->second = "newly inserted mapped_value";
	//mp2.find(27)->second = "newly inserted mapped_value";

	// printSize(mp);
	// printSize(mp2);

	// ft::map<T1, T2> const c_map(mp.begin(), mp.end());
	// std::map<T1, T2> const c_map2(mp2.begin(), mp2.end());
    // printSize(c_map);
	// printSize(c_map2);
	// std::cout << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
	// std::cout << "const map.find(" << 42 << ")->second: [" << c_map2.find(42)->second << "]" << std::endl;
	// std::cout << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;
	// std::cout << "const map.count(" << 80 << "): [" << c_map2.count(80) << "]" << std::endl;
}