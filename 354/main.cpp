#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int* dp;
    int n;

    int dfs(int i, vector<vector<int>>& envelopes) {
        if (dp[i] != -1) return dp[i];
        dp[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                dp[i] = max(dp[i], dfs(j, envelopes) + 1);
            }
        }
        return dp[i];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        dp = new int[envelopes.size()];
        n = envelopes.size();
        for (int i = 0; i < n; ++i) dp[i] = -1;
        int ans = -1;
        for (int i = 0; i < envelopes.size(); ++i) {
            ans = max(ans, dfs(i, envelopes));
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}