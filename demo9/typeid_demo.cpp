#include <stdio.h>
#include <typeinfo>
#include <iostream>

class Base
{
public:
    Base()
    {
        printf("Base() ......\n");
    }

    ~Base()
    {
        printf("~Base() ......\n");
    }
};

struct STU
{
};

int main(int argc, char const *argv[])
{
    Base *b = new Base;
    
    //获取一个普通变量的类型信息
    int n = 100;
    const std::type_info &nInfo = typeid(n);
    std::cout << nInfo.name() << " | " << nInfo.hash_code() << std::endl;
    //获取一个字面量的类型信息
    const std::type_info &dInfo = typeid(25.65);
    std::cout << dInfo.name() << " | "
              << " | " << dInfo.hash_code() << std::endl;
    //获取一个对象的类型信息
    Base obj;
    const std::type_info &objInfo = typeid(obj);
    std::cout << objInfo.name() << " | "
              << " | " << objInfo.hash_code() << std::endl;
    //获取一个类的类型信息
    const std::type_info &baseInfo = typeid(Base);
    std::cout << baseInfo.name() << " | "
              << " | " << baseInfo.hash_code() << std::endl;
    //获取一个结构体的类型信息
    const std::type_info &stuInfo = typeid(struct STU);
    std::cout << stuInfo.name() << " | "
              << " | " << stuInfo.hash_code() << std::endl;
    //获取一个普通类型的类型信息
    const std::type_info &charInfo = typeid(char);
    std::cout << charInfo.name() << " | "
              << " | " << charInfo.hash_code() << std::endl;
    //获取一个表达式的类型信息
    const std::type_info &expInfo = typeid(20 * 45 / 4.5);
    std::cout << expInfo.name() << " | "
              << " | " << expInfo.hash_code() << std::endl;

    return 0;
}
