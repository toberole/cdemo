#include<iostream>

class Student
{
public:
	Student()
	{
		std::cout << "student 1111 构造函数" << std::endl;
	}

	Student(const Student&stu) {
		std::cout << "student 2222 拷贝构造函数" << std::endl;
	}

	~Student()
	{
		std::cout << "student 3333 析构函数" << std::endl;
	}

	void test() {
		std::cout << "student test" << std::endl;
		std::thread th(&Student::test_thread,this);
		th.join();
	}

	void test_thread() {
		std::cout << "student test_thread" << std::endl;
	}
};

