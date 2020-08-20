#include "Counter.cpp"
#include <iostream>

template <class T>

class WeakPtr; //为了用weak_ptr的lock()，来生成share_ptr用，需要拷贝构造用

template <class T>
class SharePtr
{
public:
    SharePtr(T *p = 0) : _ptr(p)
    {
        cnt = new Counter();
        if (p)
            cnt->s = 1;
        std::cout << "in construct " << cnt->s << std::endl;
    }
    ~SharePtr()
    {
        release();
    }

    SharePtr(SharePtr<T> const &s)
    {
        std::cout << "in copy con" << std::endl;
        _ptr = s._ptr;
        (s.cnt)->s++;
        std::cout << "copy construct" << (s.cnt)->s << std::endl;
        cnt = s.cnt;
    }
    SharePtr(WeakPtr<T> const &w) //为了用weak_ptr的lock()，来生成share_ptr用，需要拷贝构造用
    {
        std::cout << "in w copy con " << std::endl;
        _ptr = w._ptr;
        (w.cnt)->s++;
        std::cout << "copy w  construct" << (w.cnt)->s << std::endl;
        cnt = w.cnt;
    }
    SharePtr<T> &operator=(SharePtr<T> &s)
    {
        if (this != &s)
        {
            release();
            (s.cnt)->s++;
            std::cout << "assign construct " << (s.cnt)->s << std::endl;
            cnt = s.cnt;
            _ptr = s._ptr;
        }
        return *this;
    }
    T &operator*()
    {
        return *_ptr;
    }
    T *operator->()
    {
        return _ptr;
    }
    friend class WeakPtr<T>; //方便weak_ptr与share_ptr设置引用计数和赋值

protected:
    void release()
    {
        cnt->s--;
        std::cout << "release " << cnt->s << std::endl;
        if (cnt->s < 1)
        {
            delete _ptr;
            if (cnt->w < 1)
            {
                delete cnt;
                cnt = NULL;
            }
        }
    }

private:
    T *_ptr;
    Counter *cnt;
};