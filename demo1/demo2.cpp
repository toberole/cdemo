#include <map>
#include <string>
#include <iostream>

void test1()
{
    std::cout << "test1 ......" << std::endl;
}

void test2()
{
    std::cout << "test2 ......" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::map<
        std::string /* moudle name */,
        std::shared_ptr<std::map<
            std::string /* primitive原始接口名 */,
            /* 对应moudle中的对应函数指针 */ void *>>>
        module_func_map;

    return 0;
}
