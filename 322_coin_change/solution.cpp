/**
 * 322. 零钱兑换 (Coin Change)
 * 中等
 * 标签: 动态规划
 *
 * 思路: dp[i] = 凑成金额 i 最少需要几枚硬币
 *       对每个金额 i，尝试每种硬币 coin：
 *       dp[i] = min(dp[i], dp[i - coin] + 1)
 *       和279完全平方数思路一样，只是"硬币面值"替代了"完全平方数"
 * 时间 O(amount * n)，空间 O(amount)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;

    vector<int> coins1 = {1, 2, 5};
    cout << sol.coinChange(coins1, 11) << endl;  // 3 (5+5+1)

    vector<int> coins2 = {2};
    cout << sol.coinChange(coins2, 3) << endl;   // -1 (凑不出)

    vector<int> coins3 = {1};
    cout << sol.coinChange(coins3, 0) << endl;   // 0

    return 0;
}
