#include "leetcode1114.h"

namespace leetcode {
void leetcode1114::first(function<void()> printFirst) {
    std::unique_lock<std::mutex> lk(cond_mutex);
    printFirst();
    condition_count = 1;   // 修改控制变量
    con_var.notify_one();  // 执行完后唤醒一次，释放锁
}

void leetcode1114::second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lk(cond_mutex);
    con_var.wait(lk, [this]() {return condition_count == 1;});  // 等待释放锁，与条件成立
    printSecond();
    condition_count = 2;   // 修改控制变量
    con_var.notify_one();  // 执行完后再次释放锁
}

void leetcode1114::third(function<void()> printThird) {
    std::unique_lock<std::mutex> lk(cond_mutex);
    con_var.wait(lk, [this]() {return condition_count == 2;});
    printThird();
}
}  // namespace leetcode