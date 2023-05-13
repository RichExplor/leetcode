#include <iostream>
#include "leetcode55.h"

using namespace std;
using namespace leetcode;

int main(int argc, char** argv) {
    leetcode55 test_class;
    std::vector<int> test_nums = {2,3,1,1,4};
    bool result = test_class.canJump(test_nums);

    std::cout << "if can jump: " << result << std::endl;
    std::cout << "Hello World!" << std::endl;
    return 0;
}