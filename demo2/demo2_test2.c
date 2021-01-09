#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char const *argv[])
{
    void (*p)()  = 0;
    void*p1 = dlsym(RTLD_MAIN_ONLY, "test1");
    if (p1)
    {
        printf("dlsym succ\n");
    }

    printf("end ......\n");
    
    return 0;
}
