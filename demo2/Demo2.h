#ifndef DEMO_DEMO2_H
#define DEMO_DEMO2_H


class Demo2 {
public:
    int i = 0;
public:
    Demo2();

    Demo2(const Demo2 &demo2);

    Demo2 operator=(const Demo2 &demo2);

    Demo2(const Demo2 &&demo2);

    ~Demo2();

};


#endif //DEMO_DEMO2_H
