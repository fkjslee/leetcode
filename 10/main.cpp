#include <iostream>

using namespace std;

class Solution {
public:
    bool matchCore(const string &s, const string &p, int si, int pi) {
        //cout << "si " << si << " pi " << pi << endl;
        if (si == s.length() && pi == p.length()) return true;
        if (si == s.length() && p.length() - pi == 2 && p[pi+1] == '*') return true;
        if (pi == p.length() && si != s.length()) return false;
        if (si == s.length()) {
            if (p.length() - pi == 1) return false;
            if (p[pi+1] == '*') return matchCore(s, p, si, pi + 2);
            return false;
        }
        if (p.length() - pi == 1) {
            if (p[pi] == '.') return s.length() - si == 1;
            return p[pi] == s[si] && s.length() - si == 1;
        }
        if (p[pi] == '.' && p[pi+1] == '*') return matchCore(s, p, si, pi+2) || matchCore(s, p, si+1, pi);
        if (p[pi+1] == '*') {
            if (s[si] == p[pi]) return matchCore(s, p, si, pi + 2) || matchCore(s, p, si+1, pi);
            else return matchCore(s, p, si, pi + 2);
        }
        if (p[pi] == '.') return matchCore(s, p, si+1, pi+1);
        if (s[si] == p[pi]) return matchCore(s, p, si+1, pi+1);
        return false;
    }

    bool isMatch(string s, string p) {
        return matchCore(s, p, 0, 0);
    }
};


int main() {
    Solution sol;
    cout << sol.isMatch("ab", ".*c") << endl;
}
