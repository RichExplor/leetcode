#pragma once
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

namespace leetcode {
class leetcode1115 {
public:
    leetcode1115(int n) {
        this->n = n;
    }
    void foo(function<void()> printFoo);
    void bar(function<void()> printBar);
private:
    int n;
    bool loop_process = false;          // 交替执行变量
    std::mutex cond_mutex;              // 互斥锁
    std::condition_variable cond_var;   // 条件变量
};
}  // namespace leetcode