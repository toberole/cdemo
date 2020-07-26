#include <vector>
#include <iostream>
#include <memory>
/*
for(auto x : range)创建拷贝[注意效率]，无法修改range中的元素

for(auto& x : range)可以修改range中的元素，但一般用以下这种
for(auto&& x : range)

for(const auto & x : range)只读range中的元素
*/
int main(int argc, char const *argv[])
{

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto iter = v.cbegin(); iter != v.cend(); iter++)
    {
        std::cout << (*iter) << std::endl;
    }

    std::cout << "-------" << std::endl;
    for (auto &&i : v)
    {
        std::cout << i << std::endl;
    }

    int *ip = new int;
    std::shared_ptr<int> sp(ip);
    std::cout << (*ip) << std::endl;
    return 0;
}
