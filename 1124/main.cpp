class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> presum;
        presum.push_back(0);
        for (int u : hours) {
            presum.push_back((*(--presum.end())) + (u > 8 ? 1 : -1));
        }
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < presum.size(); ++i)
            if (presum[i] < presum[stk.top()])
                stk.push(i);
        int p = presum.size() - 1;
        int ans = 0;
        while (p >= 0 && !stk.empty()) {
            //cout << "p = " << p << " " << "top = " << stk.top() << endl;
            if (p < stk.top()) stk.pop();
            else if (presum[p] > presum[stk.top()]) {
                ans = max(ans, -stk.top() + p);
                stk.pop();
            } else {
                --p;
            }
        }
        return ans;
    }
};
