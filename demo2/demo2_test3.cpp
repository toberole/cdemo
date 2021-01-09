#include <iostream>
#include <string>
struct demo2_test3
{
    demo2_test3()
    {
        std::cout << "Hello world demo2_test3" << std::endl;
    }
};

demo2_test3 d;

int main(int argc, char const *argv[])
{
    std::string path = "/test/libatest.so";
    int index = path.find_last_of("\\.");
    std::string suffix = path.substr(index + 1);
    std::cout << "index: " << index << std::endl;
    std::cout << "suffix: " << suffix << std::endl;

    int index1 = path.find_last_of("lib");
    std::cout << "index1: " << index1 << std::endl;
    std::string suffix1 = path.substr(index1 + 1, index - index1 - 1);
    std::cout << "suffix1: " << suffix1 << std::endl;

    std::cout << "sizeof demo2_test3: " << sizeof(demo2_test3) << std::endl;

    return 0;
}
