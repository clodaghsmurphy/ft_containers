# include "test.hpp"

#define T1 char
#define T2 int
#define T5 std::string
typedef ft::pair<const T1, T2> T3;
typedef std::pair<const T1, T2> T4;
typedef ft::pair<const T2, T5> T7;
typedef std::pair<const T2, T5> T8;

void    swap_insert()
{
    std::list<T3> lst;

	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, lst_size - i));
	ft::map<T1, T2> foo(lst.begin(), lst.end());

	lst.clear(); lst_size = 4;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('z' - i, i * 5));
	ft::map<T1, T2> bar(lst.begin(), lst.end());

	ft::map<T1, T2>::const_iterator it_foo = foo.begin();
	ft::map<T1, T2>::const_iterator it_bar = bar.begin();

    // std::list<T4> lst1;

	// lst_size = 7;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst1.push_back(T4('a' + i, lst_size - i));
	// std::map<T1, T2> foo1(lst1.begin(), lst1.end());

	// lst1.clear(); lst_size = 4;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst1.push_back(T4('z' - i, i * 5));
	// std::map<T1, T2> bar1(lst1.begin(), lst1.end());

	// std::map<T1, T2>::const_iterator it_foo1 = foo1.begin();
	// std::map<T1, T2>::const_iterator it_bar1 = bar1.begin();

	// std::cout << "BEFORE SWAP" << std::endl;

	// std::cout << "foo contains:" << std::endl;
	// printSize(foo, foo1);
	// std::cout << "bar contains:" << std::endl;
	// printSize(bar, bar1);

	// foo1.swap(bar1);
	foo.swap(bar);

	// std::cout << "AFTER SWAP" << std::endl;

	// std::cout << "foo contains:" << std::endl;
	// printSize(foo, foo1);
	// std::cout << "bar contains:" << std::endl;
	// printSize(bar, bar1);

	// std::cout << "Iterator validity:" << std::endl;
    // if ((it_foo == bar.begin()) == (it_foo1 == bar1.begin()))
    //     std::cout << "\033[1m\033[32m ✅ OK \033[0m\n";
    // else
    // {

    //     std::cout <<"\033[1m\033[31m iterator invalid " << std::endl;
    // }
	// if ((it_bar == foo.begin()) == (it_bar1 == foo1.begin()))
    //     std::cout << "\033[1m\033[32m ✅ OK \033[0m\n";
    // else
    // {

    //     std::cout <<"\033[1m\033[31m iterator invalid " << std::endl;
    // }

    //     tricky_construct();
    //     {
            
    //     }
}

void    tricky_construct()
{
        std::list<T7> lst;
            std::list<T7>::iterator itlst;

            lst.push_back(T7(42, "lol"));
             lst.push_back(T7(50, "mdr"));
             lst.push_back(T7(35, "funny"));
            lst.push_back(T7(45, "bunny"));
            lst.push_back(T7(21, "fizz"));
            lst.push_back(T7(35, "this key is already inside"));
            lst.push_back(T7(55, "fuzzy"));
            lst.push_back(T7(38, "buzz"));
            lst.push_back(T7(55, "inside too"));

            std::list<T8> lst1;
            std::list<T8>::iterator itlst1;

            lst1.push_back(T8(42, "lol"));
            lst1.push_back(T8(50, "mdr"));
            lst1.push_back(T8(35, "funny"));
            lst1.push_back(T8(45, "bunny"));
            lst1.push_back(T8(21, "fizz"));
            lst1.push_back(T8(35, "this key is already inside"));
            lst1.push_back(T8(55, "fuzzy"));
            lst1.push_back(T8(38, "buzz"));
            lst1.push_back(T8(55, "inside too"));

            std::cout << "List contains: " << lst.size() << " elements." << std::endl;
            for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
                printPair(itlst);
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "List contains: " << lst1.size() << " elements." << std::endl;
            for (itlst1 = lst1.begin(); itlst1 != lst1.end(); ++itlst1)
                printPair(itlst1);
            std::cout << "---------------------------------------------" << std::endl;

             ft::map<T2, T5> mp(lst.begin(), lst.end());
             std::map<T2, T5> mp2(lst1.begin(), lst1.end());
            lst.clear();
            lst1.clear();
            printSize(mp);
            printSize(mp2);
            printSize(mp, mp2);
}
