#include <setjmp.h>
#include <stdio.h>

/*

1.setjmp(j)设置“jump”点，用正确的程序上下文填充jmp_buf对象j。这个上下文包括程序存放位置、栈和框架指针，
其它重要的寄存器和内存数据。当初始化完jump的上下文，setjmp()返回0值。也就是第一次调用setjmp(j)，初始化成功了，返回0。
2. 以后调用longjmp(j,r)的效果就是一个非局部的goto或“长跳转”到由j描述的上下文
处（也就是到那原来设置j的setjmp()处）。在作为长跳转的目标而被调用时（不是第一次初始化的时候），若longjmp(j,r)函数中r是大于0的整数，
则跳转到setjmp(j)会返回r;若longjmp(j,r)中r是0，即longjmp(j,0)，那么跳转到setjmp(j)后，setjmp(j)返回是1，不会返回0。
注意：setjmp()是不会在longjmp(j,0)时返回0的。

 */

jmp_buf j;

void test1(void)
{
    // 跳到标签处 并且携带一个值[第二个参数]
    longjmp(j, 1);
    printf("1 ......\n");
}

int main(int argc, char const *argv[])
{

    // setjmp 相当于goto语句设置标签
    switch (setjmp(j))
    {
    case 0:
        printf("2 ......\n");
        test1();
        printf("3 ......\n");
        break;
    case 1:
        printf("4 ......\n");
        break;
    default:
        break;
    }
    return 0;
}
