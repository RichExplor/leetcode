#include "offer13.h"

namespace leetcode {

// 计算数字的位数和
int offer13::calaulate_sum(int num) {
    int sum = 0;
    int i = num;
    while (i > 0) {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

// 深度搜索
int offer13::dfs(int i, int j, int m, int n, int k, std::vector<std::vector<bool>>& visited) {
    // 遇到越界直接返回
    if (i < 0 || j < 0 || i >= m || j >= n) {
        return 0;
    }

    // 遇到条件不满足直接返回
    if (calaulate_sum(i) + calaulate_sum(j) > k) {
        return 0;
    }

    // 访问过的直接返回
    if (visited[i][j] == true) {
        return 0;
    }

    // 标记访问过的位置
    visited[i][j] = true;

    // 子问题累计，当前位置+1
    return 1 + dfs(i-1, j, m, n, k, visited) + dfs(i, j-1, m, n, k, visited) +
        dfs(i+1, j, m, n, k, visited) + dfs(i, j+1, m, n, k, visited);
}

int offer13::movingCount(int m, int n, int k) {
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    return dfs(0, 0, m, n, k, visited);
}
}  // namespace leetcode
