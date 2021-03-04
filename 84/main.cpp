#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> incStack;
        incStack.push(-1);
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (heights[incStack.top()] > heights[i]) {
                int v = incStack.top(); incStack.pop();
                int l = incStack.top();
                int area = ((i-1) - l) * heights[v];
                ans = max(ans, area);
                //cout << v << " : " << area << endl;
            }
            incStack.push(i);
        }
        while (incStack.top() != -1) {
            int n = heights.size();
            int v = incStack.top(); incStack.pop();
            int l = incStack.top();
            int area = (n - 1 - l) * heights[v];
            ans = max(ans, area);
            // cout << v << " : " << area << endl;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}