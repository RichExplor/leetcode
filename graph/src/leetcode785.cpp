#include "leetcode785.h"

namespace leetcode {
bool leetcode785::isBipartite(vector<vector<int>>& graph) {
    // 1.使用染色图表示
    std::vector<int> color(graph.size(), -1);  // graph的顶点
    std::stack<int> color_stack;  // 存储已经着色的顶点

    // 2.深度优先遍历（DFS）
    for (size_t i = 0; i < graph.size(); ++i) {
        // 2.1如果顶点未染色，初始化，并送入stack
        if (color[i] == -1) {
            color[i] = 0;
            color_stack.push(i);

            // 2.2栈不为空，则dfs循环
            while (!color_stack.empty()) {
                // 2.3取出栈顶的idx
                int idx = color_stack.top();
                color_stack.pop();
                // 2.4该栈顶的连接点逐个遍历
                for (size_t j = 0; j < graph[idx].size(); ++j) {
                    // 2.5如果与栈顶相连的节点未着色，将其着为不同颜色
                    if (color[graph[idx][j]] == -1) {
                        color[graph[idx][j]] = color[idx] ^ 1;
                        color_stack.push(graph[idx][j]);
                    } else {
                        if (color[graph[idx][j]] == color[idx]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
}  // namespace leetcode
