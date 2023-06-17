#include "leetcode15.h"

namespace leetcode {
vector<vector<int>> leetcode15::threeSum(const vector<int>& nums) {
    // 1.排序
    vector<int> sort_nums(nums);
    std::sort(sort_nums.begin(), sort_nums.end(), [&](int a, int b) { return a < b; });

    // 2.双指针去重
    vector<vector<int>> result;
    size_t num_size = sort_nums.size();
    for (size_t i = 0; i < num_size; ++i) {
        // 2.1 有序数组>0不需要继续执行
        if (sort_nums[i] > 0) break;

        // 2.2 去重
        if (i > 0 && sort_nums[i] == sort_nums[i-1]) {
            continue;
        }

        // 2.3 双指针判断
        size_t left = i + 1;
        size_t right = num_size - 1;
        while(right > left) {
            // 2.4 三者之和大于0移动右指针；<0移动左指针；=0保存数据
            double three_sum = sort_nums[i] + sort_nums[left] + sort_nums[right];
            if (three_sum > 0) {
                right--;
            } else if (three_sum < 0) {
                left++;
            } else {
                result.emplace_back(vector<int>{sort_nums[i], sort_nums[left], sort_nums[right]});
                std::cout << sort_nums[i] << "," << sort_nums[left] << "," << sort_nums[right] << std::endl;

                // 2.5 指针去重，直接跳过（因为只能存在一个解）
                while(right > left && sort_nums[left] == sort_nums[left+1]) {
                    left++;
                }
                while(right > left && sort_nums[right] == sort_nums[right-1]) {
                    right--;
                }

                // 2.6 移动双指针
                left++;
                right--;
            }
        }
    }
    return result;
}
}  // namespace leetcode