#include "common.h"

void leetcode1114_function();
void leetcode1115_function();
int main(int argc, char** argv) {

    leetcode1114_function();
    leetcode1115_function();
    return 0;
}

void leetcode1114_function() {
    std::function<void()> firstFunction = []() { std::cout<< "first function!" << std::endl; };
    std::function<void()> secondFunction = []() { std::cout<< "second function!" << std::endl; };
    std::function<void()> thirdFunction = []() { std::cout<< "third function!" << std::endl; };

    leetcode1114 test_class;
    std::thread t3(&leetcode1114::third, &test_class, thirdFunction);
    std::thread t2{&leetcode1114::second, &test_class, secondFunction};
    std::thread t1{&leetcode1114::first, &test_class, firstFunction};

    t1.join();
    t3.join();
    t2.join();
}

void leetcode1115_function() {
    std::function<void()> fooFunction = []() { std::cout << "foo"; }; 
    std::function<void()> barFunction = []() { std::cout << "bar"; };

    leetcode1115 test_class(5);
    std::thread foo_thread(&leetcode1115::foo, &test_class, fooFunction);
    std::thread bar_thread(&leetcode1115::bar, &test_class, barFunction);

    if (bar_thread.joinable()) {
        bar_thread.join();
    }
    if (foo_thread.joinable()) {
        foo_thread.join();
    }
}