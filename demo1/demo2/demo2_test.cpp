#include <string>
#include <iostream>

void arg_cnt(int cnt, ...)
{
    int value=0;
    int i=0;
    int arg_cnt=cnt;
    va_list arg_ptr; 
    va_start(arg_ptr, cnt); 
    for(i = 0; i < cnt; i++)
    {
        value = va_arg(arg_ptr,int);
        printf("value%d=%d\n", i+1, value);
    }
    va_end(arg_ptr);

}

int main(int argc, char const *argv[])
{
    std::string s = "";
    std::cout << s.size() << std::endl;

    const char *strpath = "hello";

    arg_cnt(3,1,2,3);

    return 0;
}
