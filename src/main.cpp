# include <vector>
# include "vector.hpp"
# include "test.hpp"
# include <map>

int main()
{
    // test_vector_size();
    // vector_constructors();
    // modifiers();
    // rb_tester();
    // insert_ft::map_test();
    // erase_ft::map_test();
    // stack_test();
    // set_test();

    ft::map<int, int> test;
    test.insert(ft::pair<int, int>(1, 1));
    test.insert(ft::pair<int, int>(2, 2));
    test.insert(ft::pair<int, int>(3, 3));

    ft::map<int, int>::iterator it = test.begin();
    std::cout << &(it->first) << std::endl;
    std::cout << it->first << std::endl;
    it++;
    std::cout << &(it->first) << std::endl;
    std::cout << it->first << std::endl;
    test.erase(test.begin(), test.end());
    



}

// int main ()
// {
//         ft::map<char,int> foo,bar;

//         foo['x']=100;
//         foo['y']=200;

//         bar['a']=11;
//         bar['b']=22;
//         bar['c']=33;


//         ft::map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
//         ft::map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

//         swap(bar, foo); //tmp iterates through bar
//                         //tmp2 iterates through foo


//         ft::map<char, int>	other;

//         other['1'] = 73;
//         other['2'] = 173;
//         other['3'] = 763;
//         other['4'] = 73854;
//         other['5'] = 74683;
//         other['6'] = 753;

//         ft::map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

//         std::cout << "foo contains:\n";
//         for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
//             std::cout << it->first << " => " << it->second << '\n';

//         std::cout << "bar contains:\n";
//         for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
//             std::cout << it->first << " => " << it->second << '\n';

//         while(tmp != bar.end())
//         {
//             std::cout << tmp->first << " => " << tmp->second << '\n';
//             tmp++;
//         }
//         tmp--;

//         while(tmp2 != foo.end())
//         {
//             std::cout << tmp2->first << " => " << tmp2->second << '\n';
//             tmp2++;
//         }
//         tmp2--;

//         swap(other, foo); //tmp2 iterates through other
//                         //tmp3 iterates throught foo
//         print(other);
//         print(foo);
//         print(bar);
//         while(tmp != bar.begin())
//         {
//             std::cout << tmp->first << " => " << tmp->second << '\n';
//             tmp--;
//         }
//         std::cout << tmp->first << " => " << tmp->second << '\n';

//         while(tmp2 != other.begin())
//         {
//             std::cout << tmp2->first << " => " << tmp2->second << '\n';
//             tmp2--;
//         }
//         std::cout << tmp2->first << " => " << tmp2->second << '\n';

//         while(tmp3 != foo.end())
//         {
//             std::cout << tmp3->first << " => " << tmp3->second << '\n';
//             tmp3++;
//         }
//         tmp3--;

//         swap(bar, foo);
//         swap(foo, bar);
//         swap(bar, foo); //tmp3 iterates through bar
//                     //tmp iterates through foo

//         print(other);
//         print(foo);
//         print(bar);

//         while(tmp != foo.end())
//         {
//             std::cout << tmp->first << " => " << tmp->second << '\n';
//             tmp++;
//         }

//         while(tmp2 != other.end())
//         {
//             std::cout << tmp2->first << " => " << tmp2->second << '\n';
//             tmp2++;
//         }

//         while(tmp3 != bar.begin())
//         {
//             std::cout << tmp3->first << " => " << tmp3->second << '\n';
//             tmp3--;
//         }
//         std::cout << tmp3->first << " => " << tmp3->second << '\n';
// }
