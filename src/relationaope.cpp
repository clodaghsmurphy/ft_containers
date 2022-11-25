#include "test.hpp"
# include "map.hpp"

#define T1 char
#define T2 int
typedef ft::pair<const T1, T2> T3;

template <class MAP, class U_MAP>
void	cmp(const MAP &lhs, const MAP &rhs, const U_MAP &lhs2, const U_MAP &rhs2)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	if (((lhs == rhs) == (lhs2 == rhs2)) && ((lhs != rhs) == (lhs2 != rhs2)))
		std::cout << "\033[1m\033[32m ✅ OK \033[0m\n";
	else
	{
		std::cout << "\033[1m\033[31m MINE : ❌ eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
		std::cout << "\033[1m\033[31m REAL : ❌ eq: " << (lhs2 == rhs2) << " | ne: " << (lhs2 != rhs2) << std::endl;
	}
	if (((lhs < rhs) == (lhs2 < rhs2)) && ((lhs <= rhs) == (lhs2 <= rhs2)))
		std::cout << "\033[1m\033[32m ✅ OK \033[0m\n";
	else
	{
		std::cout << "\033[1m\033[31m MINE : ❌ lt: " << (lhs < rhs) << " | le: " << (lhs <= rhs) << std::endl;
		std::cout << "\033[1m\033[31m REAL : ❌ lt: " << (lhs2 < rhs2) << " | le: " << (lhs2 <= rhs2) << std::endl;
	}
	if (((lhs > rhs) == (lhs2 > rhs2)) && ((lhs >= rhs) == (lhs2 >= rhs2)))
		std::cout << "\033[1m\033[32m ✅ OK \033[0m\n";
	else
	{
		std::cout << "\033[1m\033[31m MINE : ❌ gt: " << (lhs > rhs) << " | ge: " << (lhs >= rhs) << std::endl;
		std::cout << "\033[1m\033[31m REAL : ❌ gt: " << (lhs2 > rhs2) << " | ge: " << (lhs2 >= rhs2) << std::endl;
	}
}

void relational_ope(void)
{
	ft::map<T1, T2> mp1;
	ft::map<T1, T2> mp2;

	std::map<T1, T2> mp3;
	std::map<T1, T2> mp4;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	mp3['a'] = 2; mp3['b'] = 3; mp3['c'] = 4; mp3['d'] = 5;
	mp4['a'] = 2; mp4['b'] = 3; mp4['c'] = 4; mp4['d'] = 5;

	cmp(mp1, mp1, mp3, mp3); // 0
	cmp(mp1, mp2, mp4, mp4); // 1

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;
	mp4['e'] = 6; mp4['f'] = 7; mp4['h'] = 8; mp4['h'] = 9;

	cmp(mp1, mp2, mp3, mp4); // 2
	cmp(mp2, mp1, mp4, mp3); // 3

	(++(++mp1.begin()))->second = 42;
	(++(++mp3.begin()))->second = 42;

	cmp(mp1, mp2, mp3, mp4); // 2
	cmp(mp2, mp1, mp4, mp3);

	swap(mp1, mp2);
	swap(mp3, mp4);

	cmp(mp1, mp2, mp3, mp4); // 2
	cmp(mp2, mp1, mp4, mp3); // 3


}