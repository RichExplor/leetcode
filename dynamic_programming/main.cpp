#include <iostream>
#include "common.h"

using namespace std;
using namespace leetcode;

void leetcode55_function();
void leetcode5_function();

int main(int argc, char** argv) {

    leetcode55_function();
    leetcode5_function();
    std::cout << "Hello World!" << std::endl;
    return 0;
}

void leetcode55_function() {
    leetcode55 test_class;
    std::vector<int> test_nums = {2,3,1,1,4};
    bool result = test_class.canJump(test_nums);

    std::cout << "if can jump: " << result << std::endl;
}

void leetcode5_function() {
    leetcode5 test_class;
    std::string test_str = "aabasbaa";
    std::string result = test_class.longestPalindrome(test_str);

    std::cout << "longest palindrome is: " << result << std::endl;
}