/**
 * 739. 每日温度
 * 难度：中等
 * 标签：单调栈、数组
 *
 * 思路：维护一个单调递减栈（存下标），栈顶到栈底温度递减。
 *       遍历每个温度，若当前温度 > 栈顶温度，说明找到了栈顶那天的升温日，
 *       弹出栈顶并计算天数差。当前下标入栈。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // 存下标

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res1 = sol.dailyTemperatures(t1);
    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << "(expected 1 1 4 2 1 1 0 0)" << endl;

    vector<int> t2 = {30, 40, 50, 60};
    vector<int> res2 = sol.dailyTemperatures(t2);
    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << "(expected 1 1 1 0)" << endl;

    vector<int> t3 = {30, 60, 90};
    vector<int> res3 = sol.dailyTemperatures(t3);
    cout << "Test 3: ";
    for (int x : res3) cout << x << " ";
    cout << "(expected 1 1 0)" << endl;

    return 0;
}
