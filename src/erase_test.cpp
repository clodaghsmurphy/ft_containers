# include "test.hpp"

#define T1 int
#define T2 std::string
typedef ft::pair<const T1, T2> T3;
typedef std::pair<const T1, T2> T4;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

void    erase_map_test(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());

    std::list<T4> lst2;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst2.push_back(T4(i, std::string((lst_size - i), i + 65)));
	std::map<T1, T2> mp2(lst2.begin(), lst2.end()); 
	printSize(mp);
	printSize(mp2);

	ft_erase(mp, ++mp.begin()); //0

	ft_erase(mp, mp.begin()); //1
	ft_erase(mp, --mp.end()); //2

	ft_erase(mp, mp.begin(), ++(++(++mp.begin()))); //3
	ft_erase(mp, --(--(--mp.end())), --mp.end()); // 4

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());
}