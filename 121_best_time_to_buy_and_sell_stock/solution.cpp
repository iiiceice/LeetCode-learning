/**
 * 121. 买卖股票的最佳时机
 * 难度：简单
 * 标签：数组、贪心、动态规划
 *
 * 思路：一次遍历，维护到当前为止的最低买入价，
 *       同时计算当天卖出的最大利润，取全局最大值即可。
 */

// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <climits>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;

    // 测试用例 1：正常情况
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test 1: " << sol.maxProfit(prices1) << " (expected 5)" << endl;

    // 测试用例 2：价格一直下跌，无利润
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test 2: " << sol.maxProfit(prices2) << " (expected 0)" << endl;

    // 测试用例 3：只有两天
    vector<int> prices3 = {1, 2};
    cout << "Test 3: " << sol.maxProfit(prices3) << " (expected 1)" << endl;

    return 0;
}
