#include "A.h"

int main(int argc, char const *argv[])
{
    A a1;
    std::cout << "address: " << &a1 << std::endl;

    A a2 = a1.return_this_1();
    std::cout << "return_this_1 address: " << &a2 << std::endl;

    std::cout << "return_this_2 address: " << &(a1.return_this_2()) << std::endl;

    return 0;
}
