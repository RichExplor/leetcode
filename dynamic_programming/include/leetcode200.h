#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
namespace leetcode {
class leetcode200 {
public:
    leetcode200() = default;
    void dfs(vector<vector<char>>& grid, int i, int j);
    int numIslands(vector<vector<char>>& grid);
};
}  // namespace leetcode