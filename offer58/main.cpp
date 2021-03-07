class Solution {
public:
    void reverseCore(string& s, int i, int j) {
        for (int l = i, r = j; l < r; ++l, --r)
            swap(s[l], s[r]);
    }
    string reverseLeftWords(string s, int n) {
        reverseCore(s, 0, n - 1);
        reverseCore(s, n, s.length() - 1);
        reverseCore(s, 0, s.length() - 1);
        return s;
    }
};
