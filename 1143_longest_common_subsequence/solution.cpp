/**
 * 1143. 最长公共子序列
 * 难度：中等
 * 标签：动态规划、字符串
 *
 * 思路：dp[i][j] 表示 text1[0..i-1] 和 text2[0..j-1] 的 LCS 长度。
 *       字符相同：dp[i][j] = dp[i-1][j-1] + 1
 *       字符不同：dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;

    cout << "Test 1: " << sol.longestCommonSubsequence("abcde", "ace") << " (expected 3)" << endl;
    cout << "Test 2: " << sol.longestCommonSubsequence("abc", "abc") << " (expected 3)" << endl;
    cout << "Test 3: " << sol.longestCommonSubsequence("abc", "def") << " (expected 0)" << endl;

    return 0;
}
