#include "leetcode130.h"

namespace leetcode {

// 深度优先遍历，将所有连接区域的1置为0
void leetcode130::dfs(vector<vector<char>>& board, int i, int j) {
    int m = board.size();
    int n = board[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') {
        return;
    }
    board[i][j] = 'A';

    dfs(board, i-1, j);
    dfs(board, i, j-1);
    dfs(board, i+1, j);
    dfs(board, i, j+1);
}

void leetcode130::solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = 0;
    if (m > 0) {
        n = board[0].size();
    }

    // 遍历最左和最右列，寻找O的连通域，将其置为A
    for (int i = 0; i < m; ++i) {
        dfs(board, i, 0);
        dfs(board, i, n-1);
    }

    // 遍历最上和最下行，寻找O的连通域，将其置为A
    for (int j = 1; j < n-1; ++j) {
        dfs(board, 0, j);
        dfs(board, m-1, j);
    }

    // 根据上述遍历的结果，重新遍历一遍 将A变为O，而将原始O变为X
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'A') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}
}  // namespace leetcode
