/**
 * 394. 字符串解码
 * 难度：中等
 * 标签：栈、字符串、递归
 *
 * 思路：用两个栈分别保存重复次数和之前累积的字符串。
 *       遇到数字：解析完整的倍数
 *       遇到 '[' ：把当前字符串和倍数分别入栈，重置
 *       遇到 ']' ：弹出栈顶，拼接：前缀 + 当前字符串重复 k 次
 *       遇到字母：拼到当前字符串末尾
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> strSt;
        string cur;
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                numSt.push(k);
                strSt.push(cur);
                k = 0;
                cur = "";
            } else if (c == ']') {
                int repeat = numSt.top(); numSt.pop();
                string prev = strSt.top(); strSt.pop();
                string tmp;
                for (int i = 0; i < repeat; i++) tmp += cur;
                cur = prev + tmp;
            } else {
                cur += c;
            }
        }
        return cur;
    }
};

int main() {
    Solution sol;

    cout << "Test 1: " << sol.decodeString("3[a]2[bc]") << " (expected aaabcbc)" << endl;
    cout << "Test 2: " << sol.decodeString("3[a2[c]]") << " (expected accaccacc)" << endl;
    cout << "Test 3: " << sol.decodeString("2[abc]3[cd]ef") << " (expected abcabccdcdcdef)" << endl;

    return 0;
}
