#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;


class Solution {
public:
    vector<vector<int>> dp;

    int cntNums(const string& s, const string& t, int p1, int p2) {
        if (p2 == t.length()) return 1;
        if (p1 == s.length()) return 0;
        if (~dp[p1][p2]) return dp[p1][p2];
        int cnt = 0;
        for (int i = p1; i < s.length(); ++i) {
            if (s[i] == t[p2]) {
                cnt += cntNums(s, t, i+1, p2+1);
            }
        }
        return dp[p1][p2] = cnt;
    }

    int numDistinct(string s, string t) {
        int n = max(s.length(), t.length());
        dp.resize(n);
        for (int i = 0; i < n; ++i) dp[i].resize(n);
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dp[i][j] = -1;
        return cntNums(s, t, 0, 0);
    }
};


int main() {
    string s = "rabbbit";
    string t = "rabbit";
    Solution sol;
    cout << sol.numDistinct(s, t) << endl;
    for (int i = 0; i < 7; ++i)
        for (int j = 0; j < 7; ++j)
            printf("dp[%d][%d] = %d\n", i, j, sol.cntNums(s, t, i, j));
    cout << endl;
}
