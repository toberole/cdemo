class Counter
{
public:
    Counter() : s(0), w(0){};

public:
    int s; //share_ptr的引用计数
    int w; //weak_ptr的引用计数
};