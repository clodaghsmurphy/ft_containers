#include "test.hpp"
# include "map.hpp"
# include <list>
#include <map>
#define T1 char
#define T2 int

#define T3 float
#define T4 foo<int>
typedef ft::pair<const T3, T4> T5;
typedef std::pair<const T3, T4> T6;

typedef ft::pair<const T1, T2> T7;
typedef std::pair<const T1, T2> T8;
void    rev_it_construct(void)
{
    {
        ft::map<T1, T2> mp;
        ft::map<T1, T2>::iterator it = mp.begin();
        ft::map<T1, T2>::const_iterator cit = mp.begin();

        ft::map<T1, T2>::reverse_iterator rit(it);

        ft::map<T1, T2>::const_reverse_iterator crit(rit);
        ft::map<T1, T2>::const_reverse_iterator crit_(it);
        ft::map<T1, T2>::const_reverse_iterator crit_2(cit);



        std::cout << "OK" << std::endl;
    }
    {
        std::map<T1, T2> mp;
        std::map<T1, T2>::iterator it = mp.begin();
        std::map<T1, T2>::const_iterator cit = mp.begin();

        std::map<T1, T2>::reverse_iterator rit(it);

        std::map<T1, T2>::const_reverse_iterator crit(rit);
        std::map<T1, T2>::const_reverse_iterator crit_(it);
        std::map<T1, T2>::const_reverse_iterator crit_2(cit);

        /* error expected
        std::map<T1, T2>::reverse_iterator rit_(crit);
        std::map<T1, T2>::reverse_iterator rit2(cit);
        std::map<T1, T2>::iterator it2(rit);
        std::map<T1, T2>::const_iterator cit2(crit);
        */

        std::cout << "OK" << std::endl;
    }
    {
        std::list<T5> lst;
        unsigned int lst_size = 5;
        for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T5(2.5 - i, (i + 1) * 7));

        ft::map<T3, T4> mp(lst.begin(), lst.end());
        ft::map<T3, T4>::reverse_iterator it(mp.rbegin());
        ft::map<T3, T4>::const_reverse_iterator ite(mp.rbegin());


        std::list<T6> lst2;
        unsigned int lst_size2 = 5;
        for (unsigned int j = 0; j < lst_size2; ++j)
		lst2.push_back(T6(2.5 - j, (j + 1) * 7));

        std::map<T3, T4> mp_std(lst2.begin(), lst2.end());
        std::map<T3, T4>::reverse_iterator it_std(mp_std.rbegin());
        std::map<T3, T4>::const_reverse_iterator ite_std(mp_std.rbegin());
        printSize(mp);
        printSize(mp_std);

        printPair2(++ite, ++ite_std);
        printPair2(ite++, ite_std++);
        printPair2(ite++, ite_std++);
        printPair2(++ite, ++ite_std);

        it->second.m();
        ite->second.m();

        it_std->second.m();
        ite_std->second.m();

        printPair2(++it, ++it_std);
        printPair2(it++, it_std++);
        printPair2(it++, it_std++);
        printPair2(++it, ++it_std);

        printPair2(--ite, --ite_std);
        printPair2(ite--, ite_std--);
        printPair2(--ite, --ite_std);
        printPair2(ite--, ite_std--);

        (*it).second.m();
        (*ite).second.m();

        (*it_std).second.m();
        (*ite_std).second.m();

        printPair2(--it, --it_std);
        printPair2(it--, it_std--);
        printPair2(it--, it_std--);
        printPair2(--it, --it_std);


    }
    {
        std::list<T5> lst;
        unsigned int lst_size = 5;
        for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T5(2.5 + i, (i + 1)));

        ft::map<T3, T4> mp(lst.begin(), lst.end());
        ft::map<T3, T4>::iterator it(mp.begin());
        ft::map<T3, T4>::const_iterator ite(mp.begin());


        std::list<T6> lst2;
        unsigned int lst_size2 = 5;
        for (unsigned int j = 0; j < lst_size2; ++j)
		lst2.push_back(T6(2.5 +  j, (j + 1)));

        std::map<T3, T4> mp_std(lst2.begin(), lst2.end());
        std::map<T3, T4>::iterator it_std(mp_std.begin());
        std::map<T3, T4>::const_iterator ite_std(mp_std.begin());
        printSize(mp);
        printSize(mp_std);

        printPair2(++ite, ++ite_std);
        printPair2(ite++, ite_std++);
        printPair2(ite++, ite_std++);
        printPair2(++ite, ++ite_std);

        it->second.m();
        ite->second.m();

        it_std->second.m();
        ite_std->second.m();

        printPair2(++it, ++it_std);
        printPair2(it++, it_std++);
        printPair2(it++, it_std++);
        printPair2(++it, ++it_std);

        printPair2(--ite, --ite_std);
        printPair2(ite--, ite_std--);
        printPair2(--ite, --ite_std);
        printPair2(ite--, ite_std--);

        (*it).second.m();
        (*ite).second.m();

        (*it_std).second.m();
        (*ite_std).second.m();

        printPair2(--it, --it_std);
        printPair2(it--, it_std--);
        printPair2(it--, it_std--);
        printPair2(--it, --it_std);


    }
    {
        std::list<T7> lst;
        unsigned int lst_size = 5;
        for (unsigned int i = 0; i < lst_size; ++i)
            lst.push_back(T7('a' + i, (i + 1) * 7));

        ft::map<T1, T2> mp(lst.begin(), lst.end());
        ft::map<T1, T2>::iterator it_ = mp.begin();
        ft::map<T1, T2>::reverse_iterator it(it_), ite;

        std::list<T8> lst_std;
        for (unsigned int i = 0; i < lst_size; ++i)
            lst_std.push_back(T8('a' + i, (i + 1) * 7));

        std::map<T1, T2> mp_std(lst_std.begin(), lst_std.end());
        std::map<T1, T2>::iterator it_std = mp_std.begin();
        std::map<T1, T2>::reverse_iterator it2(it_std), ite2;
        printSize(mp);
        printSize(mp_std);

        // if ((it_ == it.base()) == (it_std == it2.base()))
        //     std::cout << "\033[1m\033[32m ✅ OK \033[0m" << (it_std == it2.base()) << std::endl;
        // else
        //     std::cout << "MINE : " (it_ == it.base()) << "\nREAL : "<<  std::endl;

        // if ((it_ == dec(it, 3).base()) == (it_std == dec(it2, 3).base()))
        //     std::cout << "\033[1m\033[32m ✅ OK \033[0m" << (it_std == it2.base()) << std::endl;
        // else
        //     std::cout << "MINE : " (it_ == it.base()) << "\nREAL : "<<  std::endl;
     

        printPair2(it.base(), it2.base());
        printPair2(inc(it.base(), 1), inc(it2.base(), 1));

        std::cout << "TEST OFFSET" << std::endl;
        --it;
        --it2;
        printPair2(it, it2);
        printPair2(it.base(), it2.base());

        it = mp.rbegin(); ite = mp.rend();
        it2 = mp_std.rbegin(); ite2 = mp_std.rend();
        while (it != ite)
            std::cout << "[rev] " << printPair(it++, false) << std::endl;
        printReverse(mp, mp_std);
    }

    }
