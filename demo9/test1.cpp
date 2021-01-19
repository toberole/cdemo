#include <stdio.h>
#include <pthread.h>
#include <iostream>

/**
 * 读取文件每一行
 */
void test1()
{
    printf("test1 ......\n");

    FILE *fp = NULL;

    char line[1024] = {0};
    fp = fopen("./readme.txt", "r");
    if (fp)
    {
        while (true)
        {
            fgets(line, sizeof(line), fp);
            if (!feof(fp))
            {
                printf("line: %s", line);
            }
            else
            {
                fclose(fp);
                break;
            }
        }
    }
}

// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);
void *p_e(void *args)
{
    printf("p_e: %s\n", (char *)args);
    return NULL;
}

void test2()
{
    pthread_t p_t;
    int ret = pthread_create(&p_t, NULL, p_e, (void *)"Hello pthread");
    if (ret)
    {
        printf("create thread error: %d", ret);
    }

    pthread_join(p_t,NULL);
}

int main(int argc, char const *argv[])
{
    printf("Hello Main\n");

    // test1();

    test2();

    printf("press any key to exit ......\n");
    std::cin.get();

    return 0;
}
