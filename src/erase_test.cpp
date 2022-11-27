# include "test.hpp"

#define T1 int
#define T2 std::string
typedef ft::pair<const T1, T2> T3;
typedef std::pair<const T1, T2> T4;

static int iter = 0;

template <typename MAP, typename STD_MAP,typename U,typename U2>
void	ft_erase(MAP &mp, U param, STD_MAP &mp2, U2 param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	printSize(mp);
	printSize( mp2);

	mp.erase(param);
	mp2.erase(param2);
	printSize(mp);
	printSize( mp2);

	printSize(mp, mp2);
}

template <typename MAP, typename STD_MAP, typename U2, typename V2,typename U, typename V>
void	ft_erase(MAP &mp, U it, V it2,STD_MAP &mp2, U2 std_it, V2 std_it2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	printSize(mp);
	printSize( mp2);
	mp.erase(it, it2);
	mp2.erase(std_it, std_it2);
		printSize(mp);
	printSize( mp2);
	printSize(mp, mp2);
}

void    erase_map_test(void)
{
	// std::list<T3> lst;
	// unsigned int lst_size = 10;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	// ft::map<T1, T2> mp(lst.begin(), lst.end());

    // std::list<T4> lst2;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst2.push_back(T4(i, std::string((lst_size - i), i + 65)));
	// std::map<T1, T2> mp2(lst2.begin(), lst2.end()); 
	// printSize(mp, mp2);

	// ft_erase(mp, ++mp.begin(), mp2, ++mp2.begin()); //0

	// ft_erase(mp, mp.begin(), mp2, mp2.begin()); //1
	// ft_erase(mp, --mp.end(), mp2, --mp2.end()); //2

	// ft_erase(mp, mp.begin(), ++(++(++mp.begin())), mp2, mp2.begin(), ++(++(++mp2.begin()))); //3
	// ft_erase(mp, --(--(--mp.end())), --mp.end(), mp2, --(--(--mp2.end())), --mp2.end()); // 4

	// mp[10] = "Hello";
	// mp[11] = "Hi there";

	// mp2[10] = "Hello";
	// mp2[11] = "Hi there";
	// printSize(mp, mp2);
	// ft_erase(mp, --(--(--mp.end())), mp.end(), mp2, --(--(--mp2.end())), mp2.end());

	// mp[12] = "ONE";
	// mp[13] = "TWO";
	// mp[14] = "THREE";
	// mp[15] = "FOUR";

	// mp2[12] = "ONE";
	// mp2[13] = "TWO";
	// mp2[14] = "THREE";
	// mp2[15] = "FOUR";
	// printSize(mp, mp2);
	// ft_erase(mp, mp.begin(), mp.end(), mp2, mp2.begin(), mp2.end());
	{
		std::list<T3> lst;
		unsigned int lst_size = 6;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
		ft::map<T1, T2> mp(lst.begin(), lst.end());

		std::list<T4> lst2;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst2.push_back(T4(i, std::string((lst_size - i), i + 65)));
		std::map<T1, T2> mp2(lst2.begin(), lst2.end());
		printSize(mp, mp2);

		for (int i = 2; i < 4; ++i)
			ft_erase(mp, i, mp2, i);

		ft_erase(mp, mp.begin()->first, mp2, mp2.begin()->first);
		ft_erase(mp, (--mp.end())->first, mp2, (--mp2.end())->first);

		mp[-1] = "Hello";
		mp[10] = "Hi there";
		mp[10] = "Hi there";

		mp2[-1] = "Hello";
		mp2[10] = "Hi there";
		mp2[10] = "Hi there";
		printSize(mp, mp2);

		ft_erase(mp, 0, mp2, 0);
		ft_erase(mp, 1, mp2, 1);
	}
	
}