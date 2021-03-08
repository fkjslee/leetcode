#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubStringCore(const string& s, int l, int r, int k) {
        if (l >= r) return 0;
        //cout << "long " << l << ' ' << r << endl;
        int ans = -1;
        int vis[26];
        for (int i = 0; i < 26; ++i) vis[i] = 0;
        for (int i = (l+r) / 2, u = 2; i < r; u++) {
            if (!vis[s[i] - 'a']) {
                for (int j = l; j < r; ++j)
                    vis[s[j]-'a'] += s[j] == s[i];
            }
            if (vis[s[i]-'a'] < k) {
                ans = max(longestSubStringCore(s, l, i, k), longestSubStringCore(s, i+1, r, k));
                break;
            }
            if ((u % 2 == 0) && (l+r) / 2 - u / 2 >= l) i = (l+r) / 2 - u / 2;
            else i = (l+r) / 2 + u / 2;
            //cout << "i = " << i << endl;
        }
        if (ans == -1) ans = r - l;
        return ans;
    }

    int longestSubstring(string s, int k) {
        return longestSubStringCore(s, 0, s.length(), k);
    }
};


int main() {
    Solution sol;
    cout << sol.longestSubstring("aaabb", 3);
}
