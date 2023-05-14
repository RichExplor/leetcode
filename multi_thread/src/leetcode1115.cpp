#include "leetcode1115.h"

namespace leetcode {
void leetcode1115::foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
        std::unique_lock<std::mutex> lk(cond_mutex);
        cond_var.wait(lk, [this]() {return loop_process == false;});
        printFoo();
        loop_process = true;
        cond_var.notify_one();  // 需要唤醒（很重要，不然会锁死）
    }
}

void leetcode1115::bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
        std::unique_lock<std::mutex> lk(cond_mutex);
        cond_var.wait(lk, [this]() {return loop_process == true;});
        printBar();
        loop_process = false;
        cond_var.notify_one();  // 需要唤醒
    }
}
}  // namespace leetcode