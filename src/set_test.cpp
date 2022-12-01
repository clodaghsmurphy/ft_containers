# include "test.hpp"

//static int iter = 0;
#define T1 int


void		set_copy_test(void)
{
    std::list<T1> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(lst_size - i);

	ft::set<T1> st(lst.begin(), lst.end());
	ft::set<T1>::iterator it = st.begin(), ite = st.end();

	ft::set<T1> st_range(it, --(--ite));

    std::list<T1> lst2;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst2.push_back(lst_size - i);

	std::set<T1> st2(lst2.begin(), lst2.end());
	std::set<T1>::iterator it2 = st2.begin(), ite2 = st2.end();

	std::set<T1> st_range2(it2, --(--ite2));


	for (int i = 0; i < 5; ++i)
		st.insert(i * 5);
    for (int i = 0; i < 5; ++i)
		st2.insert(i * 5);

	it = st.begin(); ite = --(--st.end());
	ft::set<T1> st_copy(st);
	std::set<T1> st_copy2(st2);
	for (int i = 0; i < 7; ++i)
		st.insert(i * 7);
	for (int i = 0; i < 7; ++i)
		st2.insert(i * 7);

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize_set(st, st2);
	printSize_set(st_range, st_range2);
	printSize_set(st_copy, st_copy2);

	st = st_copy;
	st_copy = st_range;
	st_range.clear();

    st2 = st_copy2;
	st_copy2 = st_range2;
	st_range2.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize_set(st, st2);
	printSize_set(st_range, st_range2);
	printSize_set(st_copy, st_copy2);
	return ;
}

void    set_test()
{
    ft::set<int> set;

    set.insert(1);
    set.insert(2);
    set.insert(3);

    set_copy_test();
}