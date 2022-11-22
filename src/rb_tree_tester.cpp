# include "red_black_tree.hpp"
# include "map.hpp"
#include "my_pair.hpp"
//# include "iterator.hpp"
# include <string>
# include <map>

template <typename T>
class foo
{
public:
    typedef T value_type;

    foo(void) : value(), _verbose(false){};
    foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose){};
    foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose){};
    ~foo(void)
    {
        if (this->_verbose)
            std::cout << "~foo::foo()" << std::endl;
    };
    void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
    void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
    foo &operator=(value_type src)
    {
        this->value = src;
        return *this;
    };
    foo &operator=(foo const &src)
    {
        if (this->_verbose || src._verbose)
            std::cout << "foo::operator=(foo) CALLED" << std::endl;
        this->value = src.value;
        return *this;
    };
    value_type getValue(void) const { return this->value; };
    void switchVerbose(void) { this->_verbose = !(this->_verbose); };

    operator value_type(void) const
    {
        return value_type(this->value);
    }

private:
    value_type value;
    bool _verbose;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, foo<T> const &bar)
{
    o << bar.getValue();
    return o;
}
// --- End of class foo

template <typename T>
T inc(T it, int n)
{
    while (n-- > 0)
        ++it;
    return (it);
}

template <typename T>
T dec(T it, int n)
{
    while (n-- > 0)
        --it;
    return (it);
}

static int iter = 0;
#define T1 int
#define T2 foo<int>
#define T4 char
#define T5 foo<float>
typedef ft::map<T1, T2>::value_type T3;
typedef ft::map<T1, T2>::iterator ft_iterator;
typedef ft::map<T1, T2>::const_iterator ft_const_iterator;
typedef ft::map<T4, T5> _map;
typedef ft::map<T4, T5>::const_iterator ft_const_it;

template <typename T>
std::string printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
    o << "key: " << iterator->first << " | value: " << iterator->second;
    if (nl)
        o << std::endl;
    return ("");
}

template <typename T_MAP>
void printSize(T_MAP const &mp, bool print_content = 1)
{
    std::cout << "size: " << mp.size() << std::endl;
    std::cout << "max_size: " << mp.max_size() << std::endl;
    if (print_content)
    {
        typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
        std::cout << std::endl
                  << "Content is:" << std::endl;
        for (; it != ite; ++it)
        {
           
            std::cout << "- " << printPair(it, false) << std::endl;

        }
    }
    std::cout << "###############################################" << std::endl;
}

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
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	ft::map<T1, T2> mp(lst.begin(), lst.end());
	ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	ft::map<T1, T2> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	ft::map<T1, T2> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

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
	return ;
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
    //bounds();
    //comp_test();
    copy_map_test();
}