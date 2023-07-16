#include "leetcode210.h"

namespace leetcode {
vector<int> leetcode210::findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    std::vector<int> result;
    std::vector<int> outdeg(numCourses, 0);
    std::vector<std::vector<int>> edges(numCourses, std::vector<int>());

    // 1.更新边连接关系
    for (size_t i = 0; i < prerequisites.size(); ++i) {
        edges[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        outdeg[prerequisites[i][0]]++;
    }

    // 3.创建队列，出度为0的数据送入
    std::queue<int> que;
    for (size_t i = 0; i < outdeg.size(); ++i) {
        if (outdeg[i] == 0) {
            que.push(i);
        }
    }

    // 4.BFS搜索
    while (!que.empty()) {
        int idx = que.front();
        que.pop();
        result.emplace_back(idx);

        for (size_t j = 0; j < edges[idx].size(); ++j) {
            int node_idx = edges[idx][j];
            outdeg[node_idx]--;
            if (outdeg[node_idx] == 0) {
                que.push(node_idx);
            }
        }
    }

    if (result.size() == numCourses) {
        return result;
    }

    return std::vector<int>();
}
}  // namespace leetcode
