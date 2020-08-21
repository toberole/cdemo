#include <thread>
#include <iostream>
#include "student.h"
#include "thread_pool.hpp"
#include "Moveable1.h"
#include "test_forward.h"
/*
    1、若传递int这种简单的类型，建议都是值传递，不要使用引用
    2、如果传递类对象，避免隐式类型转换，应该全部在创建线程时，构造出临时对象，然后在函数参数中用引用来接收，否则系统还会构建临时对象，浪费，即构造三个对象。
*/

/*
创建线程：
    std::thread接收一个可调用对象，来创建线程。可调用对象包括：函数、类对象（重载“()”运算符）和lambda。
*/

void thread1() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "hello thread1" << std::endl;
}

// 线程启动时候传递应用参数
// 以起线程的方式 传递一个基本类型的引用 本质上还是值传递
// 在线程中修改了该引用 不会影响父线程中的值
void thread2(int &i) {
    i++;
    std::cout << "thread i: " << i << std::endl;
}

void test_shared_ptr() {
    Student *pStu = new Student();
    std::shared_ptr<Student> s1(pStu);
    s1->sysHello();

    Student *pStu1 = new Student();
    std::shared_ptr<void> s2(pStu1);
    Student *pStu2 = static_cast<Student *>(s2.get());
    pStu2->sysHello();
}

void test_shared_ptr1() {
    Student *s1 = new Student();
    s1->sysHello();
    Object *obj = s1;
    // 子类指针 赋值给父类的时 使用子类指针释放资源的时候
    // 父类的析构函数必须是virtual的，否则没法调用到子类的析构函数
    delete (obj);
}

void test_shared_ptr2() {
}

void fun1(int slp) {
    printf("  hello, fun1 !  %d\n", std::this_thread::get_id());
    if (slp > 0) {
        printf(" ======= fun1 sleep %d  =========  %d\n", slp, std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(slp));
    }
}

// 线程池
void test_thread_pool() {
    com::zw::ThreadPoolExecutor executor(10, 10, 10);
    std::future<void> ff = executor.commit(fun1, 100);

    std::thread th([] {

    });
}

void test_rv(int &&i) {
    std::cout << i << std::endl;
}

void test_moveable() {
    Moveable1 a;
    Moveable1 c(std::move(a)); // 会调用移动构造函数
    std::cout << "********** " << *a.i << std::endl;     // 运行时错误
}

void test_forward() {
    TestForward(1);
    int x = 1;
    // TestForward(x); //使print(std::forward<T>(v));编译错误
    TestForward(std::forward<int>(x));
}

#include "empty_class.h"

void test_empty_class_size() {
    std::cout << "empty class size: " << sizeof(EmptyClass) << std::endl;
}

#include "offsetof.h"

void test_offsetof() {
    printf("%d\n", offsetof(Node, a));
    printf("%d\n", offsetof(Node, b));
    printf("%d\n", offsetof(Node, c));
    printf("%d\n", offsetof(Node, d));
}

int main(int argc, char const *argv[]) {
    std::cout << "input any key ...." << std::endl;

//    test_thread_pool();
//    test_rv(110);
//    test_moveable();

//    test_forward();

//    test_empty_class_size();

    test_offsetof();

    std::cin.get();
    return 0;
}
