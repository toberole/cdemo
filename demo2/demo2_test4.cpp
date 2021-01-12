#include <map>
#include <iostream>
void test_func()
{
}
void demo2_test4_1()
{
    std::shared_ptr<std::map<std::string, void *> > m_p = std::make_shared<std::map<std::string, void *> >();
    m_p->insert(std::make_pair<std::string, void * >("test_func", (void *)test_func));
    std::cout << "hello demo2_test4_1 ......" << std::endl;
}

int main(int argc, char const *argv[])
{
    demo2_test4_1();
    return 0;
}
