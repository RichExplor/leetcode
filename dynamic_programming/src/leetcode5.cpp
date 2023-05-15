#include "leetcode5.h"

namespace leetcode {

std::string leetcode5::longestPalindrome(std::string s) {
    int s_size = static_cast<int>(s.size());
    if (s_size <= 1) {  // 字符串长度<=1直接返回
        return s;
    }
    
    int max_length = -1;   // 回文最大长度
    int start_index = -1;  // 起始回文字符下标
    std::vector<std::vector<bool>> dp(s_size, std::vector<bool>(s_size, false)); // dp二维数组，存储两个下标间是否为回文字符串

    // 1. 循环遍历相邻字符是否可构建回文,初始化dp数组
    for (int i = 0; i < s_size; ++i) {
        dp[i][i] = true;
        if (i < s_size-1 &&s[i] == s[i+1]) {
            dp[i][i+1] = true;
            max_length = 2;
            start_index = i;
        }
    }

    // 2. 循环遍历长度从3开始的回文字符串
    for (int len = 3; len <= s_size; ++len) {
        // 3. 遍历字符串（0,sz-len+1），其中sz-len+1表示可遍历的最大左边界字符串下标
        for (int i = 0; i < s_size - len + 1; ++i) {
            int j = i + len - 1;  // 右边界字符串下标
            if (s[i] == s[j] && dp[i+1][j-1]) {  // 只有满足大回文包含小回文[absba]，才更新dp数组
                dp[i][j] = true;
                if (len > max_length) { // 更新最大回文长度和初始下标
                    max_length = len;
                    start_index = i;
                }
            }
        }
    }

    // 3. 截取回文数据
    return (max_length != -1 ? s.substr(start_index, max_length) : "*********");
}
}  // namespace leetcode