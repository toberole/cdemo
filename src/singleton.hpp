#include<mutex>

class Singleton
{
private:
	std::mutex mtx;
	Singleton*instance = nullptr;

	std::once_flag once_flag;
private:
	Singleton() {
	}

	// 拷贝构造
	Singleton(const Singleton&) {
	}

	// 赋值运算符
	Singleton& operator=(const Sinleton&) {};

	static Singleton*makeInstance() {
		if (!instance) {
			instance = new Singleton();
		}

		return instance;
	}

public:
	// 方式1
	static Singleton* GetInstance() {
		if (!instance) {
			std::lock_guard<std::mutex> lock(mtx);
			if (!instance) {
				instance = new Singleton();
			}
		}

		return instance;
	}

	// 方式二
	Singleton*GetInstance() {
		// std::call_once 保证makeInstance只会被调用一次
		std::call_once(once_flag, makeInstance);
		return instance;
	}

	~Singleton() {
	}
};
