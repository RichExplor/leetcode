#include "common.h"

int main(int argc, char* argv[]) {
    leetcode15 test_class;
    vector<int> nums{-6, -4, -8, 9, 1, 2, 4, 3, 1, -1, 2};
    vector<vector<int>> result;
    result = test_class.threeSum(nums);
    return 0;
}