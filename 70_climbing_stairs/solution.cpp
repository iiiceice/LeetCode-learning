/**
 * 70. 爬楼梯 (Climbing Stairs)
 * 简单
 * 标签: 动态规划
 *
 * 思路: 到第 n 阶只能从第 n-1 阶迈一步或第 n-2 阶迈两步
 *       dp[i] = dp[i-1] + dp[i-2]，本质就是斐波那契
 * 时间 O(n)，空间 O(1)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2; // dp[1]=1, dp[2]=2
        for (int i = 3; i <= n; i++) {
            int cur = prev1 + prev2; // dp[i] = dp[i-1] + dp[i-2]
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    cout << "n=2: " << sol.climbStairs(2) << endl;  // 期望: 2
    cout << "n=3: " << sol.climbStairs(3) << endl;  // 期望: 3
    cout << "n=5: " << sol.climbStairs(5) << endl;  // 期望: 8
    cout << "n=10: " << sol.climbStairs(10) << endl; // 期望: 89

    return 0;
}
