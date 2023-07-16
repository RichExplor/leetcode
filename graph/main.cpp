#include "common.h"

int main(int argc, char* argv[]) {
    // leetcode785 test_class;
    // vector<vector<int>> nums{{1,2,3},{0,2},{0,1,3},{0,2}};
    // bool result = test_class.isBipartite(nums);
    // std::cout << "result: " << result << std::endl;

    // leetcode207 test_class;
    // vector<vector<int>> nums{{0,1},{1,2},{2,0}};
    // bool result = test_class.canFinish(3, nums);
    // std::cout << "result: " << result << std::endl;

    leetcode210 test_class;
    vector<vector<int>> nums{{0,1},{1,2},{0, 2}};
    auto result = test_class.findOrder(3, nums);
    for (const auto& res : result)
        std::cout << "result: " << res << std::endl;
    return 0;
}