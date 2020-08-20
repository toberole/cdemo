#include <iostream>
using namespace std;

class Moveable
{
public:
    Moveable() : i(new int(3))
    {
    }

    ~Moveable()
    {
        delete i;
    }

    Moveable(const Moveable &m) : i(new int(*m.i))
    {
    }

    Moveable(Moveable &&m) : i(m.i)
    {
        std::cout << "hello move ......" << std::endl;
        m.i = nullptr;
    }

    int *i;
};

int main(int argc, char const *argv[])
{
    Moveable a;
    Moveable c(std::move(a)); // 会调用移动构造函数
    cout << *a.i << endl;     // 运行时错误
    return 0;
}
