/**
 * 155. 最小栈
 * 难度：中等
 * 标签：栈、设计
 *
 * 思路：用一个辅助栈 minSt 同步记录当前最小值。
 *       每次 push 时，minSt 也 push 当前最小值（min(新元素, minSt栈顶)）。
 *       pop 时两个栈同步 pop，getMin 直接取 minSt 栈顶。
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty()) {
            minSt.push(val);
        } else {
            minSt.push(min(val, minSt.top()));
        }
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "getMin: " << minStack.getMin() << " (expected -3)" << endl;

    minStack.pop();
    cout << "top: " << minStack.top() << " (expected 0)" << endl;

    cout << "getMin: " << minStack.getMin() << " (expected -2)" << endl;

    return 0;
}
