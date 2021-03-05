#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:

    stack<int> stk1, stk2;

    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }

    void transStk1ToStk2() {
        if (stk2.empty()) while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stk2.empty()) return -1;
        int ans = stk2.top();
        stk2.pop();
        return ans;
    }

    /** Get the front element. */
    int peek() {
        transStk1ToStk2();
        if (stk2.empty()) return -1;
        return stk2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        transStk1ToStk2();
        return stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}