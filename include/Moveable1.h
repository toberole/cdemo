#ifndef PROJECT_MOVEABLE1_H
#define PROJECT_MOVEABLE1_H

/*
std::move
    c++11中提供了std::move()来将左值转换为右值引用，从而方便的使用移动语义。
    move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存拷贝。
    c++中所有容器都实现了move语义，方便我们实现性能优化。move对于拥有形如对内存、
    文件句柄等资源的成员的对象有效。如果是一些基本类型，比如int或char[10]数组等，
    如果使用move，仍然会发生拷贝（因为没有对应的移动构造函数）。

 std::forward
    右值引用类型是独立于值的，一个右值引用参数作为函数的形参，在函数内部再转发该参数的
    时候它已经变成一个左值，并不是他原来的类型。
    需要一种方法能够按照参数原来的类型转发到另一个函数，这种转发类型称为完美转发。
    完美转发（Perfect Forwarding），是指在函数模板中，完全依照模板的参数的
    类型（即保持参数的左值、右值特征），将参数传递给函数模板中调用的另外一个函数。C++11中提供了这样的一个函数std::forward，它是为转发而生的，不管参数是T&&这种未定的引用还是明确的左值引用或者右值引用，它会按照参数本来的类型转发。



 */

class Moveable1 {
public:
    Moveable1() : i(new int(3)) {
    }

    ~Moveable1() {
        delete i;
    }

    Moveable1(const Moveable1 &m) : i(new int(*m.i)) {
    }

    Moveable1(Moveable1 &&m) : i(m.i) {
        std::cout << "hello move ......" << std::endl;
        m.i = nullptr;
    }

    int *i;
};


#endif //PROJECT_MOVEABLE1_H
