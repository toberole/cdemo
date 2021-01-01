#include <iostream>
#include <map>
#include "Demo2.h>

void demo2_test1_1()
{
    std::map<char, int> mymap;
    std::map<char, int>::iterator it;

    mymap['a'] = 50;
    mymap['b'] = 100;
    mymap['c'] = 150;
    mymap['d'] = 200;

    std::cout << mymap['a'] << std::endl;
    // std::cout << mymap['x'] << std::endl;

    it = mymap.find('x');
    if (it != mymap.end())
    {
        mymap.erase(it);
    }
    else
    {
        std::cout << "find('x') == end" << std::endl;
    }

    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase(it);

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
    std::cout << "b => " << mymap.find('b')->second << '\n';
    std::cout << "e => " << mymap.find('e')->second << '\n';
}

void demo2_test1_2()
{
    Demo2
}

int main(int argc, char const *argv[])
{
    demo2_test1_2();
    return 0;
}
