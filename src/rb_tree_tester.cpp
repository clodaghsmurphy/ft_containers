# include "red_black_tree.hpp"
# include "test.hpp"
# include "map.hpp"
#include "my_pair.hpp"
//# include "iterator.hpp"
# include <string>
# include <map>




static int iter = 0;
#define T1 int
#define T2 foo<int>
#define T4 char
#define T5 foo<float>
#define T6 std::string
typedef ft::map<T1, T2>::value_type T3;
typedef std::pair<T1,T2> T3STD;
typedef ft::map<T1, T2>::iterator ft_iterator;
typedef ft::map<T1, T2>::const_iterator ft_const_iterator;
typedef ft::map<T4, T5> _map;
typedef ft::map<T4, T5>::const_iterator ft_const_it;



template <typename MAP>
void ft_bound(MAP &mp, const T1 &param)
{
    ft_iterator ite = mp.end(), it[2];
    ft::pair<ft_iterator, ft_iterator> ft_range;

    std::cout << "\t-- [" << iter++ << "] --" << std::endl;
    std::cout << "with key [" << param << "]:" << std::endl;
    it[0] = mp.lower_bound(param);
    it[1] = mp.upper_bound(param);
    ft_range = mp.equal_range(param);
    std::cout << (it[0] == ite) << std::endl;
    std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
    std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
    std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void ft_const_bound(const MAP &mp, const T1 &param)
{
    ft_const_iterator ite = mp.end(), it[2];

    ft::pair<ft_const_iterator, ft_const_iterator> ft_range;

    std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
    std::cout << "with key [" << param << "]:" << std::endl;
    it[0] = mp.lower_bound(param);
    it[1] = mp.upper_bound(param);
    ft_range = mp.equal_range(param);
    std::cout << (it[0] == ite) << std::endl;

    std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
    std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
    std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}


void  bounds(void)
{
    std::list<T3> lst;
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
    return ;
}



void	ft_comp(const _map &mp, const ft_const_it &it1, const ft_const_it &it2)
{
    static unsigned int i = 0;
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}


void	comp_test(void)
{
	_map	mp;

	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;
	printSize(mp);

	for (ft_const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
		for (ft_const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
			ft_comp(mp, it1, it2);

	printSize(mp);
	return ;
}



    void		copy_map_test(void)
{
    {
        std::list<std::pair<T1, T2> > lst;
        unsigned int lst_size = 7;
        for (unsigned int i = 0; i < lst_size; ++i)
            lst.push_back(std::pair<T1, T2>(lst_size - i, i));

        std::map<T1, T2> mp(lst.begin(), lst.end());
        std::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
        --(--ite);
        std::cout << (*ite).first << std::endl;
        (void)it;
        ft::map<T1, T2> mp_range(it, --(--ite));

    }  
    
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	ft::map<T1, T2> mp(lst.begin(), lst.end());
	ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
    
  
	ft::map<T1, T2> mp_range(it, --(--ite));
    std::cout << "---------------------INTIALIZING------------------\033[1m\033[33m\n\n";
    printSize(mp);
	printSize(mp_range);
    std::cout << "---------------------INTIALIZING------------------\n\n";
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;
    std::cout << "---------------------AFTER 5 MULTIPLEs------------------\033[1m\033[35m\n\n";
    printSize(mp);
	printSize(mp_range);
  std::cout << "---------------------AFTER 5 MULTIPLEs------------------\n\n\033[0m";

	it = mp.begin(); ite = --(--mp.end());
	ft::map<T1, T2> mp_copy(mp);
    std::cout << "---------------------MP COPY------------------\033[1m\033[33m\n\n";
	printSize(mp_copy);

	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;
        std::cout << "---------------------AFTER 7 MULTIPLEs------------------\033[1m\033[35m\n\n";
    printSize(mp);
	printSize(mp_copy);
  std::cout << "---------------------AFTER 7 MULTIPLEs------------------\n\n\033[0m";

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);
    {
            std::list<std::pair<T1,T2> > lst;
        unsigned int lst_size = 7;
        for (unsigned int i = 0; i < lst_size; ++i)
            lst.push_back(std::pair<T1,T2>(lst_size - i, i));

        std::map<T1, T2> mp(lst.begin(), lst.end());
        std::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
        
    
        std::map<T1, T2> mp_range(it, --(--ite));
        std::cout << "---------------------INTIALIZING------------------\033[1m\033[33m\n\n";
        printSize(mp);
        printSize(mp_range);
        std::cout << "---------------------INTIALIZING------------------\n\n";

        for (int i = 0; it != ite; ++it)
            it->second = ++i * 5;
        std::cout << "---------------------AFTER 5 MULTIPLEs------------------\033[1m\033[35m\n\n";
        printSize(mp);
        printSize(mp_range);
        std::cout << "---------------------AFTER 5 MULTIPLEs------------------\n\n\033[0m";

        it = mp.begin(); ite = --(--mp.end());
        std::map<T1, T2> mp_copy(mp);
        std::cout << "---------------------MP COPY------------------\033[1m\033[33m\n\n";
        printSize(mp_copy);

        for (int i = 0; it != ite; ++it)
            it->second = ++i * 7;
        std::cout << "---------------------AFTER 7 MULTIPLEs------------------\033[1m\033[35m\n\n";
        printSize(mp);
        printSize(mp_copy);
        std::cout << "---------------------AFTER 7 MULTIPLEs------------------\n\n\033[0m";

        std::cout << "\t-- PART ONE --" << std::endl;
        printSize(mp);
        printSize(mp_range);
        printSize(mp_copy);

        mp = mp_copy;
        mp_copy = mp_range;
        mp_range.clear();

        std::cout << "\t-- PART TWO --" << std::endl;
        printSize(mp);
        printSize(mp_range);
        printSize(mp_copy);
    }
}
template <class T>
void	is_empty(T const &mp)
{
	std::cout << "is_empty: " << mp.empty() << std::endl;
}

void		map_empty_test(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, lst_size - i));

	ft::map<T1, T2> mp(lst.begin(), lst.end()), mp2;
	ft::map<T1, T2>::iterator it;

	lst.clear();
	is_empty(mp);
	printSize(mp);

	is_empty(mp2);
	mp2 = mp;
	is_empty(mp2);

	it = mp.begin();
	for (unsigned long int i = 3; i < mp.size(); ++i)
		it++->second = i * 7;

	printSize(mp);
	printSize(mp2);

	mp2.clear();
	is_empty(mp2);
	printSize(mp2);
	return ;
}


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
    void map_erase_test()
    {
        // {

        //     std::list<ft::pair<T1,T6> lst;
        //     unsigned int lst_size = 10;
        //     for (unsigned int i = 0; i < lst_size; ++i)
        //         lst.push_back(ft::pair<T1,T6>(i, std::string((lst_size - i), i + 65)));
        //     ft::map<T1, T6> mp(lst.begin(), lst.end());
        //     printSize(mp);

        //     ft_erase(mp, ++mp.begin());

        //     ft_erase(mp, mp.begin());
        //     ft_erase(mp, --mp.end());

        //     ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
        //     ft_erase(mp, --(--(--mp.end())), --mp.end());

        //     mp[10] = "Hello";
        //     mp[11] = "Hi there";
        //     printSize(mp);
        //     ft_erase(mp, --(--(--mp.end())), mp.end());

        //     mp[12] = "ONE";
        //     mp[13] = "TWO";
        //     mp[14] = "THREE";
        //     mp[15] = "FOUR";
        //     printSize(mp);
        //     ft_erase(mp, mp.begin(), mp.end());
        // }
        //  {
        //     std::cout << "REAL --------------------\n\n\033[1m\033[33m";

        //     std::list<std::pair<T1,T6> > lst;
        //     unsigned int lst_size = 10;
        //     for (unsigned int i = 0; i < lst_size; ++i)
        //         lst.push_back(std::pair<T1,T6>(i, std::string((lst_size - i), i + 65)));
        //     std::map<T1, T6> mp(lst.begin(), lst.end());
        //     printSize(mp);

        //     ft_erase(mp, ++mp.begin());

        //     ft_erase(mp, mp.begin());
        //     ft_erase(mp, --mp.end());

        //     ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
        //     ft_erase(mp, --(--(--mp.end())), --mp.end());

        //     mp[10] = "Hello";
        //     mp[11] = "Hi there";
        //     printSize(mp);
        //     ft_erase(mp, --(--(--mp.end())), mp.end());

        //     mp[12] = "ONE";
        //     mp[13] = "TWO";
        //     mp[14] = "THREE";
        //     mp[15] = "FOUR";
        //     printSize(mp);
        //     ft_erase(mp, mp.begin(), mp.end());
        // }
        {
            std::list<std::pair<T1,T6> > lst;
            unsigned int lst_size = 6;
            for (unsigned int i = 0; i < lst_size; ++i)
                lst.push_back(std::pair<T1,T6>(i, std::string((lst_size - i), i + 65)));
           ft::map<T1, T6> mp(lst.begin(), lst.end());
            printSize(mp);

            for (int i = 2; i < 4; ++i)
                ft_erase(mp, i);

            ft_erase(mp, mp.begin()->first);
            ft_erase(mp, (--mp.end())->first);

            mp[-1] = "Hello";
            mp[10] = "Hi there";
            mp[10] = "Hi there";
            printSize(mp);

            ft_erase(mp, 0);
            ft_erase(mp, 1);
        }
    }



template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	ft::pair<typename MAP::iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	typename MAP::iterator tmp;
    static int iter = 0;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}

void mpa_insert(void)
{
	ft::map<T1, T6> mp, mp2;
    

	ft_insert(mp, ft::map<T1,T6>::value_type (42, "lol"));
	ft_insert(mp, ft::map<T1,T6>::value_type(42, "mdr"));

	ft_insert(mp, ft::map<T1,T6>::value_type(50, "mdr"));
	ft_insert(mp, ft::map<T1,T6>::value_type(35, "funny"));

	ft_insert(mp, ft::map<T1,T6>::value_type(45, "bunny"));
	ft_insert(mp, ft::map<T1,T6>::value_type(21, "fizz"));
	ft_insert(mp, ft::map<T1,T6>::value_type(38, "buzz"));

	ft_insert(mp, mp.begin(), ft::map<T1,T6>::value_type(55, "fuzzy"));

	ft_insert(mp2, mp2.begin(), ft::map<T1,T6>::value_type(1337, "beauty"));
	ft_insert(mp2, mp2.end(), ft::map<T1,T6>::value_type(1000, "Hello"));
	ft_insert(mp2, mp2.end(), ft::map<T1,T6>::value_type(1500, "World"));
}


void ite_arrow()
{
    	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(2.5 + i, i + 1));

	ft::map<T1, T2> mp(lst.begin(), lst.end());
	ft::map<T1, T2>::iterator it(mp.begin());
	ft::map<T1, T2>::const_iterator ite(mp.begin());
	printSize(mp);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->second.m();
	ite->second.m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).second.m();
	(*ite).second.m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);

}
void reverse_it()
{
    std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(2.5 - i, (i + 1) * 7));

	ft::map<T1, T2> mp(lst.begin(), lst.end());
	ft::map<T1, T2>::reverse_iterator it(mp.rbegin());
	ft::map<T1, T2>::const_reverse_iterator ite(mp.rbegin());
	printSize(mp);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->second.m();
	ite->second.m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).second.m();
	(*ite).second.m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);
}


void	ft_find(T1 const &k, ft::map<T1, T6> mp)
{
	ft::map<T1, T6>::iterator ret = mp.find(k);
    ft::map<T1, T6>::iterator it =mp.end();

	if (ret != it)
		printPair(ret);
	else
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k,ft::map<T1, T6> mp)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}

void    find_count()
{
    ft::map<T1, T6> mp;
    ft::map<T1, T6>::iterator it = mp.end();
    mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

	std::cout << "\t-- FIND --" << std::endl;
	ft_find(12, mp);
	ft_find(3, mp);
	ft_find(35, mp);
	ft_find(90, mp);
	ft_find(100, mp);

	std::cout << "\t-- COUNT --" << std::endl;
	ft_count(-3, mp);
	ft_count(12, mp);
	ft_count(3, mp);
	ft_count(35, mp);
	ft_count(90, mp);
	ft_count(100, mp);

	mp.find(27)->second = "newly inserted mapped_value";

	printSize(mp);

	ft::map<T1, T6> const c_map(mp.begin(), mp.end());
	std::cout << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
	std::cout << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;
}
void rb_tester()
{
  
    {
        // std::cout << "\n      REAL        \n";
        //  std::map<int, std::string> test;
        // std::map<const int, std::string>::iterator it;

        // test.insert(std::pair<int, std::string>(1, "hello"));
        // test.insert(std::pair<int, std::string>(2, "hello"));

        // it = test.begin();
        // it++;
        // it++;
        // std::cout << (*it).first << std::endl;
        // it--;
        // std::cout << (*it).first << std::endl;

        // it = test.find(1);
        // std::cout << (*it).first << std::endl;
        //  it = test.end();
        // std::cout << it->first << std::endl;
        //   it = test.find(9);
        // std::cout << it->first << std::endl;

    }
//     bounds();
//     comp_test();
//      copy_map_test();
//      map_empty_test();
//      map_erase_test();
//      ite_arrow();
//      reverse_it();
//    relational_ope();
//     rev_it_construct();
   swap_insert();
  // map_find_count();

}