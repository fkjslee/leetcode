#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > dp;
    int palindrome(int i, int j, const string& s) {
        if (dp[i][j]) return dp[i][j];
        if (i >= j) return dp[i][j] = 1;
        if (s[i] != s[j]) return dp[i][j] = 2;
        return dp[i][j] = palindrome(i+1, j-1, s);
    }

    void get_ans(vector<vector<string>>& ans, vector<string>& sentence, int l, const string& s) {
        if (l == s.length()) {
            ans.push_back(sentence);
            return;
        }
        for (int i = l; i < s.length(); ++i) {
            if (palindrome(l, i, s) == 1) {
                sentence.push_back(s.substr(l, i-l+1));
                get_ans(ans, sentence, i+1, s);
                sentence.erase(--sentence.end());
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dp.resize(s.length());
        for (int i = 0; i < s.length(); ++i) dp[i].resize(s.length());
        vector<vector<string>> ans;
        vector<string> sentence;
        get_ans(ans, sentence, 0, s);
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    auto ans = sol.partition(s);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            printf("dp[%d][%d] = %d\n", i, j, sol.palindrome(i, j, s));
    cout << sol.dp[0][2] << endl;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << j << ' ' << ans[i][j] << endl;
        cout << "********************************" << endl;
    }
}
