class Solution {
public:
    string removeVowels(string s) {
        string res;
        for (char c : s) {
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
                res += c;
        }
        return res;
    }
};
