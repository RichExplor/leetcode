#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

namespace leetcode {
class offer13 {
public:
    offer13() = default;
    int calaulate_sum(int num);
    int dfs(int i, int j, int m, int n, int k, std::vector<std::vector<bool>>& visited);
    int movingCount(int m, int n, int k);
};
}  // namespace leetcode