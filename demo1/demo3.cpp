#include <stdlib.h>
#include <stdio.h>

#include "MemTrack.h"

class demo3
{
private:
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

    demo3 *demo3_p = new demo3(110);
    MemTrack::TrackDumpBlocks();
	MemTrack::TrackListMemoryUsage();
    delete demo3_p;

    return 0;
}
