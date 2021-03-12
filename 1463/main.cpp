class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp;
        dp.resize(2);
        dp[0].resize(m);
        dp[1].resize(m);
        for (int i = 0; i < 2; ++i) for (int j = 0; j < m; ++j) {
            dp[i][j].resize(m);
            for (int k = 0; k < m; ++k)
                dp[i][j][k] = 0xcfcfcfcf;
        }
        int ans = dp[0][0][m-1] = (m == 1 ? grid[0][0] : grid[0][0] + grid[0][m-1]);
        for (int k = 1; k < grid.size(); ++k) {
            //cout << "k = " << k << endl;
            for (int i = 0; i < m; ++i) {
                for (int j = i; j < m; ++j) {
                    int pre = (k + 1) % 2;
                    int now = k % 2;
                    int benefit = grid[k][i] + (i == j?0:grid[k][j]);
                    if (i > 0 && j > 0) dp[now][i][j] = max(dp[now][i][j], dp[pre][i-1][j-1] + benefit);
                    if (i > 0) dp[now][i][j] = max(dp[now][i][j], dp[pre][i-1][j] + benefit);
                    if (i > 0 && j < m-1) dp[now][i][j] = max(dp[now][i][j], dp[pre][i-1][j+1] + benefit);

                    if (j > 0) dp[now][i][j] = max(dp[now][i][j], dp[pre][i][j-1] + benefit);
                    dp[now][i][j] = max(dp[now][i][j], dp[pre][i][j] + benefit);
                    if (j < m-1) dp[now][i][j] = max(dp[now][i][j], dp[pre][i][j+1] + benefit);

                    if (i < m-1 && j > 0) dp[now][i][j] = max(dp[now][i][j], dp[pre][i+1][j-1] + benefit);
                    if (i < m-1) dp[now][i][j] = max(dp[now][i][j], dp[pre][i+1][j] + benefit);
                    if (i < m-1 && j < m-1) dp[now][i][j] = max(dp[now][i][j], dp[pre][i+1][j+1] + benefit);

                    //cout << i << " " << j << " = " << dp[now][i][j] << endl;
                    ans = max(ans, dp[now][i][j]);
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    cout << sol.isValidSerialization("9,#,#,1") << endl;
}
