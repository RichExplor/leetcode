#include "leetcode207.h"

namespace leetcode {
bool leetcode207::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    std::vector<int> outdeg(numCourses, 0);  // 保存出度
    std::vector<std::vector<int>> edges(numCourses, std::vector<int>());  // 保存连接关系

    // 1. 更新连接关系（0， 1）每个prerequisites仅包含两个课程
    for (size_t i = 0; i < prerequisites.size(); ++i) {
        edges[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        outdeg[prerequisites[i][0]]++;
    }

    // 2. 初始化queue，将出度（最顶层的节点）送入queue中
    std::queue<int> que;
    for (size_t i = 0; i < outdeg.size(); ++i) {
        if (outdeg[i] == 0) {
            que.push(i);
        }
    }

    // 3.统计课程总数，从queue读取出度为0的节点，并判断
    int counts = 0;
    while (!que.empty()) {
        int idx = que.front();
        que.pop();
        counts++;

        // 4.将与出度顶点连接的子节点数量减一
        for (size_t j = 0; j < edges[idx].size(); ++j) {
            int node_idx = edges[idx][j];
            outdeg[node_idx]--;
            if (outdeg[node_idx] == 0) {
                que.push(node_idx);
            }
        }
    }

    if (counts != numCourses) {
        return false;
    }

    return true;
}
}  // namespace leetcode
