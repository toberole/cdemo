#include <stdlib.h>
#include <stdio.h>

class demo3
{
public:
    int i;

public:
    demo3(int i);
    ~demo3();
};

demo3::demo3(int i)
{
    this->i = i;
    printf("demo3() i = %d ......\n", i);
}

demo3::~demo3()
{
    printf("~demo3() i = %d ......\n", i);
}

class MT
{
public:
    MT(char const *filename, int lineNum);
};

MT::MT(char const *filename, int lineNum)
{
    printf("MT filename: %s,lineNum: %d\n", filename, lineNum);
}

template <class T>
inline T *operator*(const MT &mt, T *p)
{
    return p;
}

#define MT_NEW MT(__FILE__, __LINE__) * new
#define MT_DELETE printf("deletefile: %s,line: %d",__FILE__, __LINE__);delete

void *my_malloc(unsigned int size, const char *file, int line)
{
    printf("malloc size: %d,file: %s,line: %d\n", size, file, line);
    return malloc(size);
}

void my_free(void *p_m, const char *file, int line)
{
    printf("free file: %s,line: %d\n", file, line);
    free(p_m);
}

#define malloc(size) my_malloc(size, __FILE__, __LINE__)
#define free(p_m) my_free(p_m, __FILE__, __LINE__)

int main(int argc, char const *argv[])
{
    void *p = malloc(100);
    free(p);

    demo3 *demo3_p = MT_NEW demo3(100);
    printf("demo3_p i: %i\n", demo3_p->i);
    MT_DELETE demo3_p;
    return 0;
}
