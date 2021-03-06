#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:

    vector<int> nextBig;
    int n;

    int find_next(vector<int>& nums, int u) {
        if (nextBig[u] != -2) return nextBig[u];
        if (nums[u] < nums[(u+1)%n]) return nextBig[u] = (u+1)%n;
        int p = (u+1)%n;
        while (p != -1 && nums[u] >= nums[p] && p != u) p = find_next(nums, p);
        if (p == -1 || p == u) return nextBig[u] = -1;
        return nextBig[u] = p;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        nextBig.resize(nums.size());
        if (nums.size() == 0) return nextBig;
        for (int i = 0; i < nums.size(); ++i) nextBig[i] = -2;
        n = nums.size();
        int maxEle = nums[0];
        for (int u : nums) maxEle = max(maxEle, u);
        for (int i = 0; i < nums.size(); ++i) if (nums[i] == maxEle) nextBig[i] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            nextBig[i] = find_next(nums, i);
        }
        vector<int> ans; ans.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (nextBig[i] == -1) ans[i] = -1;
            else ans[i] = nums[nextBig[i]];
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
    vector<int> ans = sol.nextGreaterElements(vec);
    for (int i = 0; i < ans.size(); ++i)
        cout << "ans " << i << "  " << ans[i] << endl;
}
