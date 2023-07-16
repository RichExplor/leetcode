#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
namespace leetcode {
class leetcode130 {
public:
    leetcode130() = default;
    void dfs(vector<vector<char>>& grid, int i, int j);
    void solve(vector<vector<char>>& board);
};
}  // namespace leetcode