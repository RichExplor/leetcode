#include "leetcode55.h"

namespace leetcode {

bool leetcode55::canJump(const vector<int>& nums) {
    // 0. 贪心算法
    int max_dist = 0;
    int nums_size = static_cast<int>(nums.size());
    // 1. 从左到右遍历数组
    for (int i = 0; i < nums.size(); ++i) {
        // 2. 如果当前位置大于最远移动距离，说明无法到达最后一个位置
        if (i > max_dist) {
            return false;
        }
        // 3. 更新最远移动距离
        max_dist = std::max(max_dist, i + nums[i]);

        // 4. 最远移动距离大于数组大小，则表示成功
        if (max_dist >= nums_size -1) {
            return true;
        }
    }
    return false;
}
}  // namespace leetcode