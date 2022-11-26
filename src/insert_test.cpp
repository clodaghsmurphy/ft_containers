# include "test.hpp"


#define T1 int
#define T2 std::string
typedef ft::map<T1, T2>::value_type T3;
typedef std::map<T1, T2>::value_type T4;
typedef ft::map<T1, T2>::iterator iterator;
typedef std::map<T1, T2>::iterator iterator2;

static int iter = 0;

template <typename T_MAP, typename T, typename U>
void	ft_insert(T_MAP &mp, std::map<T1, T2> &mp2, T param, U param2)
{
	ft::pair<iterator, bool> tmp;
	std::pair<iterator2, bool> tmp2;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	tmp2 = mp2.insert(param2);
	std::cout << "insert return: " << printPair2(tmp.first, tmp2.first);
    if (tmp.second == tmp2.second)
        std::cout << "\033[1m\033[32m ✅ OK \033[0m" << std::endl;
    else
    {
       std::cout << "\033[1m\033[31m MINE : ❌ : " << tmp.second << " REAL : " << tmp2.second << std::endl;
    }
	printSize(mp, mp2);
}

template <typename MAP, typename STD_MAP, typename Inputit,typename InputItTWO, typename V, typename V2>
void	ft_insert(MAP &mp, STD_MAP &mp2, Inputit it, InputItTWO it2,V param,V2 param2)
{
	iterator tmp;
	iterator2 tmp2;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(it, param);
	tmp2 = mp2.insert(it2, param2);
	std::cout << "insert return: " << printPair2(tmp, tmp2);
    printSize(mp);
    printSize(mp2);
	printSize(mp, mp2);
}

void    insert_map_test(void)
{
	ft::map<T1, T2> mp, mp2;
	std::map<T1, T2> mp3, mp4;

	ft_insert(mp, mp3, T3(42, "lol"), T4(42, "lol")); //0
	 ft_insert(mp, mp3, T3(42, "mdr"), T4(42, "mdr")); //1

	 ft_insert(mp, mp3, T3(50, "mdr"), T4(50, "mdr")); //2
	 ft_insert(mp, mp3, T3(35, "funny"), T4(35, "funny")); //3

	 ft_insert(mp, mp3, T3(45, "bunny"), T4(45, "bunny")); //4
	 ft_insert(mp, mp3, T3(21, "fizz"), T4(21, "fizz")); //5
	 ft_insert(mp, mp3, T3(38, "buzz"), T4(38, "buzz")); //6

	 ft_insert(mp, mp3, mp.begin(), mp3.begin(), T3(55, "fuzzy"), T4(55, "fuzzy")); //7

	 ft_insert(mp2, mp4, mp2.begin(), mp4.begin(), T3(1337, "beauty"), T4(1337, "beauty")); //8
	 ft_insert(mp2, mp4, mp2.end(), mp4.end(), T3(1000, "Hello"), T4(1000, "Hello")); //9
	 ft_insert(mp2, mp4, mp2.end(), mp4.end(), T3(1500, "World"), T4(1500, "World")); //10

	return ;
}
