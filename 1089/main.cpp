class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        for (int u : arr) {
            if (u) ans.push_back(u);
            else {
                ans.push_back(u);
                ans.push_back(u);
            }
        }
        int n = arr.size();
        for (int i = 0; i < n; ++i)
            arr[i] = ans[i];
    }
};
