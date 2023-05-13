#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <mutex>
#include <condition_variable>

using namespace std;
namespace leetcode {
class leetcode1114 {
public:
    leetcode1114() = default;
    void first(function<void()> printFirst);
    void second(function<void()> printSecond);
    void third(function<void()> printThird);

private:
    int condition_count = 0;  // 控制顺序的变量
    std::mutex cond_mutex;    // 条件变量的互斥锁
    std::condition_variable con_var;  // 条件变量
};

}  // namespace leetcode