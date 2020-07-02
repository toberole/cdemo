#include <thread>
#include <iostream>
/*
创建线程：
std::thread接收一个可调用对象，来创建线程。可调用对象包括：函数、类对象（重载“()”运算符）和lambda。
*/
void thread1() {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "hello thread1" << std::endl;
}

// 线程启动时候传递应用参数
// 以起线程的方式 传递一个基本类型的引用 本质上还是值传递
// 在线程中修改了该引用 不会影响父线程中的值
void thread2(int &i) {
	i++;
	std::cout << "thread i: " << i << std::endl;
}

int main(int argc, char const *argv[])
{
 //   std::thread t1(thread1);
	//t1.detach();

	int i = 0;
	std::thread th2(thread2,std::ref(i));
	th2.join();
	std::cout << "main thread i: " << i << std::endl;

	std::cout << "input any key ...." << std::endl;
	getchar();
    return 0;
}
