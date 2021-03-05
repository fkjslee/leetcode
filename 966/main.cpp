#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:

    string toLower(string u) {
        string ret;
        for (char c : u) {
            if (c >= 'A' && c <= 'Z') ret += c - 'A' + 'a';
            else ret += c;
        }
        return ret;
    }

    string vowelToA(string u) {
        string ret;
        u = toLower(u);
        for (char c : u) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ret += 'a';
            else ret += c;
        }
        return ret;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        map<string, string> wordMap1;
        map<string, string> wordMap2;
        map<string, string> wordMap3;
        for (int i = wordlist.size() - 1; i >= 0; --i) {
            string s = wordlist[i];
            wordMap1[vowelToA(s)] = s;
        }
        for (int i = wordlist.size() - 1; i >= 0; --i) {
            string s = wordlist[i];
            wordMap2[toLower(s)] = s;
        }
        for (int i = wordlist.size() - 1; i >= 0; --i) {
            string s = wordlist[i];
            wordMap3[s] = s;
        }

        for (string q : queries) {
            if (wordMap3.find(q) != wordMap3.end()) ans.push_back(wordMap3[q]);
            else if (wordMap2.find(toLower(q)) != wordMap2.end()) ans.push_back(wordMap2[toLower(q)]);
            else if (wordMap1.find(vowelToA(q)) != wordMap1.end()) ans.push_back(wordMap1[vowelToA(q)]);
            else ans.emplace_back("");
        }
        return ans;
    }
};

int main() {
    vector<string> vec;
    vec.push_back("KiTe");
    vec.push_back("kite");
    vec.push_back("hare");
    vec.push_back("Hare");
    vector<string> query;
    query.push_back("keti");
    Solution sol;
    auto ans = sol.spellchecker(vec, query);
    for (int i = 0; i < ans.size(); ++i)
        cout << "ans = " << ans[i] << endl;
    return 0;
}