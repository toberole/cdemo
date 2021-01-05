#include <iostream>
#include <map>
#include "Demo2.h"
#include <string>
#include <variant>
#include <dlfcn.h>

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
    std::string s = "";
    std::cout << s.empty() << std::endl;
    std::cout << "s size: " << s.size() << std::endl;
    auto *temp = static_cast<char *>(malloc(sizeof(char) * s.size()));
    if (!temp)
    {
        std::cout << "malloc size: " << s.size() << std::endl;
    }
}

void demo2_test1_3()
{
    std::variant<std::monostate, int, double> v1 = {}; // 构造空variant
    std::cout << "index: " << v1.index() << std::endl;
}

void demo2_test1_4()
{
    void *handle = dlopen("/Users/apple/code/cpp_code/cdemo/demo2/libdemo5.dylib", RTLD_LAZY);
    if (!handle)
    {
        std::cout << "dlopen error: " << dlerror() << std::endl;
    }
    int (*p)(int, int);
    p = (int (*)(int, int))dlsym(handle, "demo5_test1");
    if (!p)
    {
        std::cout << "dlsym error: " << dlerror() << std::endl;
    }

    int i = p(1,2);
    std::cout << "p add: " << i << std::endl;
}

int main(int argc, char const *argv[])
{
    demo2_test1_4();
    return 0;
}
