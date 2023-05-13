#include "leetcode1114.h"
#include <thread>

using namespace std;
using namespace leetcode;
int main(int argc, char** argv) {

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

    return 0;
}