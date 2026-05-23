/**
 * 279. 完全平方数 (Perfect Squares)
 * 中等
 * 标签: 动态规划
 *
 * 思路: dp[i] = 凑成 i 最少需要几个完全平方数
 *       对每个 i，尝试所有 j*j <= i：
 *       dp[i] = min(dp[i], dp[i - j*j] + 1)
 *       即：用了一个 j*j，再看剩下的部分最少需要几个
 * 时间 O(n*sqrt(n))，空间 O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;

    cout << sol.numSquares(12) << endl;  // 3 (4+4+4)
    cout << sol.numSquares(13) << endl;  // 2 (4+9)
    cout << sol.numSquares(1) << endl;   // 1 (1)
    cout << sol.numSquares(7) << endl;   // 4 (4+1+1+1)

    return 0;
}
