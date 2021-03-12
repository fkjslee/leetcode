class Solution {
public:

    vector<int> sum;
    vector<vector<int>> dp;

    int cnt(const vector<int>& piles, int l, int r) {
        return sum[r] - sum[l];
    }

    int dfs(const vector<int>& piles, int id, int m, int l) {
        //cout << "dfs " << id << ' ' << m << ' ' << l << " players " << players[0] << ' ' << players[1] << endl;
        if (piles.size() - l < 2 * m) {
            return cnt(piles, l, piles.size());
        }
        if (dp[m][l]) return dp[m][l];
        int ans = 0;
        for (int x = 1; x <= 2 * m; ++x) {
            int u = cnt(piles, l, l + x);
            int laterMaxGetScore = cnt(piles, l + x, piles.size()) - dfs(piles, !id, max(m, x), l + x);
            ans = max(ans, u + laterMaxGetScore);
        }
        return dp[m][l] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        sum.push_back(0);
        for (int u : piles) sum.push_back(*(--sum.end()) + u);
        dp.resize(piles.size());
        for (int i = 0; i < piles.size(); ++i) dp[i].resize(piles.size());
        return dfs(piles, 0, 1, 0);
    }
};
