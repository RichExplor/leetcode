#include "leetcode200.h"

namespace leetcode {

// 深度优先遍历，将所有连接区域的1置为0
void leetcode200::dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();

    grid[i][j] = '0';

    if (i-1 >= 0 && grid[i-1][j] == '1') dfs(grid, i-1, j);
    if (j-1 >= 0 && grid[i][j-1] == '1') dfs(grid, i, j-1);
    if (i+1 < m && grid[i+1][j] == '1') dfs(grid, i+1, j);
    if (j+1 < n && grid[i][j+1] == '1') dfs(grid, i, j+1);
}

int leetcode200::numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = 0;
    if (m > 0) {
        n = grid[0].size();
    }

    int is_lands = 0;
    // 遍历每个格子
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 遇到格子为1，开始深度优先遍历，将所有连接区域置0
            if (grid[i][j] == '1') {
                is_lands++;
                dfs(grid, i, j);
            }
        }
    }
    return is_lands;
}
}  // namespace leetcode
