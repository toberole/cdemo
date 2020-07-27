#pragma once

#include <functional>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>

namespace com {
    namespace zw {
        class ThreadPoolExecutor {
        private:
            using Task = std::function<void()>;

            std::vector<std::thread> thread_pool;

            std::queue<Task> tasks;

            std::mutex mtx;
            std::condition_variable cond;

            std::atomic<bool> stoped;

            std::atomic_int corePoolSize;
            std::atomic_int maximumPoolSize;
            std::atomic_int idleThreadNum;
            long keepAliveTime = 0;

        public:
            inline ThreadPoolExecutor(int corePoolSize,
                                      int maximumPoolSize,
                                      long keepAliveTime) {
                this->keepAliveTime = keepAliveTime;
                this->corePoolSize = corePoolSize;
                this->maximumPoolSize = maximumPoolSize;
                this->idleThreadNum = corePoolSize;

                for (int i = 0; i < corePoolSize; ++i) {
                    thread_pool.emplace_back(
                            [this] {
                                std::function<void()> task;
                                while (!this->stoped) {
                                    std::unique_lock<std::mutex> lock(this->mtx);
                                    this->cond.wait(
                                            lock, [this] {
                                                return this->stoped.load() || !this->tasks.empty();
                                            });

                                    if (this->stoped && this->tasks.empty())break;

                                    task = std::move(this->tasks.front());
                                    this->tasks.pop();
                                    idleThreadNum--;
                                    task();
                                    idleThreadNum++;
                                }
                            });
                }
            }

            inline ~ThreadPoolExecutor() {
                stoped.store(true);
                cond.notify_all();
                // 注意此处std::thread &th 引用的写法
                // 否则 error: calling a private constructor of class 'std::__1::thread'
                for (std::thread &th : thread_pool) {
                    if (th.joinable()) {
                        th.join();
                    }
                }
            }

            // 有两种方法可以实现调用类成员，
            // 一种是使用 bind: .commit(std::bind(&Dog::sayHello, &dog));
            // 一种是用 mem_fn: .commit(std::mem_fn(&Dog::sayHello), &dog)
            template<class F, class... Args>
            auto commit(F &&f, Args &&... args) -> std::future<decltype(f(args...))> {
                if (stoped.load()) {
                    throw std::runtime_error("commit on ThreadPool is stopped.");
                }

                // typename std::result_of<F(Args...)>::type, 函数 f 的返回值类型
                using RetType = decltype(f(args...));
                auto task = std::make_shared<std::packaged_task<RetType()>>(
                        std::bind(std::forward<F>(f), std::forward<Args>(args)...));
                std::future<RetType> future = task->get_future();
                std::lock_guard<std::mutex> lock(mtx);
                tasks.emplace([task]() { (*task)(); });
                cond.notify_one();
                return future;
            }

            void execute(Task &task) {
                if (!stoped.load()) {
                    std::lock_guard<std::mutex> lock(mtx);
                    tasks.emplace(task);
                    cond.notify_one();
                }
            }
        };
    } // namespace zw
} // namespace com