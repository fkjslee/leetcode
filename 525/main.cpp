#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:

    int findMaxLengthCore(const vector<int>& nums) {
        vector<int> sum;
        sum.push_back(0);
        for (int u : nums) {
            sum.push_back(*(--sum.end()) + (u == 0 ? -1 : 1));
        }
        //for (int i = 0; i < sum.size(); ++i)
            //cout << "i = " << i << " sum = " << sum[i] << endl;
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < sum.size(); ++i)
            if (sum[i] < sum[stk.top()])
                stk.push(i);

        int p = sum.size() - 1;
        int ans = 0;
        while (p >= 0 && !stk.empty()) {
            //cout << "p = " << p <<" top = " << stk.top() << ' ' << stk.size() <<endl;
            if (p < stk.top()) stk.pop();
            else if (sum[p] >= sum[stk.top()]) {
                int u = p;
                while (sum[u] > sum[stk.top()]) {
                    u -= sum[u] - sum[stk.top()];
                    //cout << "u = " << u << endl;
                }
                if (sum[u] == sum[stk.top()]) ans = max(ans, u - stk.top());
                stk.pop();
            } else {
                --p;
            }
        }
        return ans;
    }

    int findMaxLength(vector<int>& nums) {
        int ans = findMaxLengthCore(nums);
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = !nums[i];
        }
        ans = max(ans, findMaxLengthCore(nums));
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    cout << sol.findMaxLength(vec) << endl;
    return 0;
}