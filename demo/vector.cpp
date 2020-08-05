#include <iostream>
#include <vector> 

// <queue>头文件queue主要包括循环队列queue和优先队列priority_queue两个容器
#include <queue>

/**
 * vector是变长数组，支持随机访问，不支持在任意位置 O(1)O(1) 插入。
 * 为了保证效率，元素的增删一般应该在末尾进行。
 * 
 */

void test_vector()
{
    // 一维动态数组
    std::vector<int> v;

    // 二维动态数组,100个std::vector<int>
    std::vector<int> vs[100];

    v.push_back(2);
    // 元素个数
    int size = v.size();
    // 判断是否为空
    bool b = v.empty();

    int i = v.front();
    std::cout << "si                          " << size << ",b: " << b << std::endl;
    std::cout << "i: " << i << std::endl;

    /*
    迭代器
        迭代器就像STL容器的“指针”，可以用星号“*”操作符解除引用。一个保存int的
        vector的迭代器声明方法:vector<int>::iterator it;vector的迭代器是“随机
        访问迭代器”，可以把vector的迭代器与一个整数相加减，其行为和指针的移动类
        似。可以把vector的两个迭代器相减，其结果也和指针相减类似，得到两个迭代器
        对应下标之间的距离。
    */

    /*
   begin/end
        begin函数返回指向vector中第一个元素的迭代器。
        所有的容器都可以视作一个“前闭后开”的结构，end函数返回vector的尾部，即第n
        个元素再往后的“边界”。
   */

    // 遍历
    int n = v.size();
    for (i = 0; i < n; i++)
    {
        std::cout << "i: " << i << "," << v[i] << std::endl;
    }

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << std::endl;
    }


    /*
    front/back
        front函数返回vector的第一个元素，等价于*(a.begin()) 和 a[0]。
        back函数返回vector的最后一个元素，等价于*(a.end()) 和 a[a.size() – 1]。
    */

    /*
   push_back() 和 pop_back()
        a.p   把元素x插入到vector a的尾部。
        b.pop_back() 删除vector a的最后一个元素。
   */
}

void test_queue(){
  /**
   * 循环队列 queue
   *    push 从队尾插入 
   *    pop 从队头弹出 
   *    front 返回队头元素 
   *    back 返回队尾元素
   */ 

  /*
    优先队列 priority_queue
            push 把元素插入堆
            pop 删除堆顶元素
            top  查询堆顶元素（最大值）
  */

    std::queue<int> q;
    q.push(1);
    std::cout << q.back() <<std::endl;
}

void test_deque(){
    // #include <deque>
    // 双端队列deque是一个支持在两端高效插入或删除元素的连续线性存储空间。它就像
    // 是vector和queue的结合。与vector相比，deque在头部增删元素仅需要O(1)的时间；
    // 与queue相比，deque像数组一样支持随机访问。
    // [] 随机访问
    // begin/end，返回deque的头/尾迭代器
    // front/back 队头/队尾元素
    // push_back 从队尾入队
    // push_front 从队头入队
    // pop_back 从队尾出队
    // pop_front 从队头出队
    // clear 清空队列

}

void test_stack(){
    // #include <stack>
    // 头文件stack包含栈。声明和前面的容器类似。
    // push 向栈顶插入
    // pop 弹出栈顶元素

}



int main(int argc, char const *argv[])
{

    // test_vector();

    test_queue();

    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
