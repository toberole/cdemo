#include <iostream>

template <typename T>
class Shared_ptr
{
private:
    T *ptr;
    int *use_count; // 指针引用计数
public:
    Shared_ptr()
    {
        ptr = nullptr;
        use_count = nullptr;
    }

    Shared_ptr(T *p)
    {
        ptr = p;
        use_count = new int(1);
    }

    Shared_ptr(const Shared_ptr<T> &other)
    {
        ptr = other.ptr;
        ++(*other.use_count);
        use_count = other.use_count;
    }

    Shared_ptr<T> &operator=(const Shared_ptr &other)
    {
        if (this == &other)
            return *this;

        (*other.use_count)++;

        if (ptr && --(*use_count) == 0 /* 当前智能指针重新赋值 */)
        {
            delete ptr;
            delete use_count;
        }

        ptr = other.ptr;
        use_count = other.use_count;
        return *this;
    }

    // "*" 运算符重载
    T &operator*()
    {
        return *ptr; // 返回指针的引用
    }

    // "->" 运算符重载
    T *operator->()
    {
        return ptr;
    }

    void reset()
    {
        if (ptr)
        {
            ptr = nullptr;
        }

        if (--(*use_count) <= 0)
        {
            delete use_count;
            delete ptr;
        }
    }

    int get_use_count()
    {
        if (use_count == nullptr)
            return 0;
        return *use_count;
    }

    ~Shared_ptr()
    {
        if (ptr && --(*use_count) == 0)
        {
            delete ptr;
            ptr = nullptr;

            delete use_count;
            use_count = nullptr;
        }
    }
};