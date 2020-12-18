#include <thread>
#include <iostream>
#include "student.h"
#include "thread_pool.hpp"
#include "Moveable1.h"
#include "test_forward.h"

#include <variant>
#include <optional>

/*
    1、若传递int这种简单的类型，建议都是值传递，不要使用引用
    2、如果传递类对象，避免隐式类型转换，应该全部在创建线程时，构造出临时对象，然后在函数参数中用引用来接收，否则系统还会构建临时对象，浪费，即构造三个对象。
*/

/*
创建线程：
    std::thread接收一个可调用对象，来创建线程。可调用对象包括：函数、类对象（重载“()”运算符）和lambda。
*/

void thread1()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "hello thread1" << std::endl;
}

// 线程启动时候传递应用参数
// 以起线程的方式 传递一个基本类型的引用 本质上还是值传递
// 在线程中修改了该引用 不会影响父线程中的值
void thread2(int &i)
{
    i++;
    std::cout << "thread i: " << i << std::endl;
}

void test_shared_ptr()
{
    Student *pStu = new Student();
    std::shared_ptr<Student> s1(pStu);
    s1->sysHello();

    Student *pStu1 = new Student();
    std::shared_ptr<void> s2(pStu1);
    Student *pStu2 = static_cast<Student *>(s2.get());
    pStu2->sysHello();
}

void test_shared_ptr1()
{
    Student *s1 = new Student();
    s1->sysHello();
    Object *obj = s1;
    // 子类指针 赋值给父类的时 使用子类指针释放资源的时候
    // 父类的析构函数必须是virtual的，否则没法调用到子类的析构函数
    delete (obj);
}

void test_shared_ptr2()
{
}

void fun1(int slp)
{
    printf("  hello, fun1 !  %d\n", std::this_thread::get_id());
    if (slp > 0)
    {
        printf(" ======= fun1 sleep %d  =========  %d\n", slp, std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(slp));
    }
}

// 线程池
void test_thread_pool()
{
    com::zw::ThreadPoolExecutor executor(10, 10, 10);
    std::future<void> ff = executor.commit(fun1, 100);

    std::thread th([] {

    });
}

void test_rv(int &&i)
{
    std::cout << i << std::endl;
}

void test_moveable()
{
    Moveable1 a;
    Moveable1 c(std::move(a));                       // 会调用移动构造函数
    std::cout << "********** " << *a.i << std::endl; // 运行时错误
}

void test_forward()
{
    TestForward(1);
    int x = 1;
    // TestForward(x); //使print(std::forward<T>(v));编译错误
    TestForward(std::forward<int>(x));
}

#include "empty_class.h"

void test_empty_class_size()
{
    std::cout << "empty class size: " << sizeof(EmptyClass) << std::endl;
}

#include "offsetof.h"

void test_offsetof()
{
    printf("%d\n", offsetof(Node, a));
    printf("%d\n", offsetof(Node, b));
    printf("%d\n", offsetof(Node, c));
    printf("%d\n", offsetof(Node, d));
}

void test_variant()
{

    std::variant<int64_t, std::string> var{"hi"}; // initialized with string alternative
    std::cout << var.index() << std::endl;        // prints 1
    var = 42;                                     // now holds int alternative
    var.emplace<0>(0);
    var.emplace<int64_t>(0);
    std::cout << var.index() << std::endl;
    ; // prints 0
    try
    {
        std::string s = std::get<std::string>(var); // access by type
        int i = std::get<0>(var);                   // access by index
    }
    catch (const std::bad_variant_access &e)
    { // in case a wrong type/index is used
        e.what();
    }
}

// convert string to int if possible:
std::optional<int> asInt(const std::string &s)
{
    try
    {
        return std::stoi(s);
    }
    catch (...)
    {
        return std::nullopt;
    }
}

void test_optional()
{
    for (auto s : {"42", " 077", "hello", "0x33"})
    {
        // convert s to int and use the result if possible:
        std::optional<int> oi = asInt(s);
        if (oi)
        {
            std::cout << "convert '" << s << "' to int: " << *oi << "\n";
        }
        else
        {
            std::cout << "can't convert '" << s << "' to int\n";
        }
    }
}

#include <stdio.h>
void testx_1()
{
    using std::string;
    // 准备数据
    string haha("haha");
    int num = 3;
    // 准备格式
    string fmt("test string: %s. test number: %d");
    char targetString[1024];
    // 格式化，并获取最终需要的字符串
    int realLen = snprintf(targetString, sizeof(targetString),
                           fmt.c_str(), haha.c_str(), num);

    std::cout << "realLen: " << realLen << std::endl;
    std::cout << "targetString: " << targetString << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "input any key ...." << std::endl;

    testx_1();
    // test_variant();
    // test_optional();
    //    test_thread_pool();
    //    test_rv(110);
    //    test_moveable();

    //    test_forward();

    //    test_empty_class_size();
    //
    //    test_offsetof();
    //
    //    Student *stu = new Student;
    //    delete stu;

    std::cin.get();
    return 0;
}
