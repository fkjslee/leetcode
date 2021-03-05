#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        bool ans = true;
        vector<string> vec;
        istringstream iss(s);
        string buffer;
        while (iss >> buffer) vec.push_back(buffer);
        if (vec.size() != pattern.length()) return false;
        map<string, char> mp;
        map<char, string> mp2;
        for (int i = 0; i < pattern.length(); ++i) {
            string word = vec[i];
            if (mp.find(word) == mp.end()) mp[word] = pattern[i];
            else {
                if (mp[word] != pattern[i]) ans = false;
            }
            if (mp2.find(pattern[i]) == mp2.end()) mp2[pattern[i]] = word;
            else {
                if (mp2[pattern[i]] != word) ans = false;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}