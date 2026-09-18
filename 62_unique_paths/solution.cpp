// 62. 不同路径 (Unique Paths)
// 难度：中等
// 标签：动态规划、滚动数组优化

#include <iostream>
#include <vector>
using namespace std;

/*
思路：动态规划
- dp[j] 表示从起点到当前行第 j 列的路径数
- 转移方程：dp[j] = dp[j] + dp[j-1]
  （dp[j] 是上一行同列的值，dp[j-1] 是当前行左边的值）
- 初始条件：第一行、第一列全为 1（只有一种走法：一直向右 / 一直向下）
- 用一维滚动数组代替二维 dp，空间从 O(mn) 优化到 O(n)

数学解法（组合数）：总共走 m+n-2 步，其中 m-1 步向下，方案数 C(m+n-2, m-1)。
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);  // 第一行全部初始化为 1
        for (int i = 1; i < m; i++) {       // 逐行向下递推
            for (int j = 1; j < n; j++) {   // 第一列恒为 1，从 j=1 开始
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    // 测试用例 1：3x7 网格，期望 28
    cout << "m=3, n=7: " << s.uniquePaths(3, 7) << " (期望 28)" << endl;
    // 测试用例 2：3x2 网格，期望 3
    cout << "m=3, n=2: " << s.uniquePaths(3, 2) << " (期望 3)" << endl;
    // 测试用例 3：1x1 网格（起点即终点），期望 1
    cout << "m=1, n=1: " << s.uniquePaths(1, 1) << " (期望 1)" << endl;
    // 测试用例 4：10x10，期望 48620
    cout << "m=10, n=10: " << s.uniquePaths(10, 10) << " (期望 48620)" << endl;
    return 0;
}
