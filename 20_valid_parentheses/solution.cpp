/**
 * 20. 有效的括号
 * 难度：简单
 * 标签：栈、字符串
 *
 * 思路：用哈希表存储右括号到左括号的映射，遇到左括号入栈，
 *       遇到右括号检查栈顶是否匹配。最后栈必须为空。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> st;
        for (char c : s) {
            if (!mp.count(c)) {
                st.push(c);
            } else {
                if (st.empty() || st.top() != mp[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;

    cout << "Test 1: " << (sol.isValid("()") ? "true" : "false") << " (expected true)" << endl;
    cout << "Test 2: " << (sol.isValid("()[]{}") ? "true" : "false") << " (expected true)" << endl;
    cout << "Test 3: " << (sol.isValid("(]") ? "true" : "false") << " (expected false)" << endl;
    cout << "Test 4: " << (sol.isValid("([)]") ? "true" : "false") << " (expected false)" << endl;
    cout << "Test 5: " << (sol.isValid("{[]}") ? "true" : "false") << " (expected true)" << endl;

    return 0;
}
