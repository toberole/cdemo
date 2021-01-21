#include <stdio.h>
#include <cstdlib>
#include <iostream>

class new_delete
{
private:
    int i;
    double d;

public:
    new_delete();
    ~new_delete();
};

new_delete::new_delete()
{
}

new_delete::~new_delete()
{
}
int g_counter = 0;

void *operator new(size_t size) throw(std::bad_alloc)
{

    ++g_counter;
    std::cout << "new mem:" << g_counter << std::endl;

    return malloc(size);
}

void operator delete(void *ptr) throw()
{
    --g_counter;
    std::cout << "delete mem:" << g_counter << std::endl;

    free(ptr);
}

void on_exit()
{
    std::cout << "exit,mem counter = " << g_counter << std::endl;
}

int main(int argc, char const *argv[])
{
    new_delete *p = new new_delete;
    
    on_exit();
    return 0;
}
