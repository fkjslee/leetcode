#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, int> mp;
        vector<vector<string>> ans;
        for (string path : paths) {
            for (int i = 0; i < path.size(); ++i)
                if (path[i] == '(' || path[i] == ')') path[i] = ' ';
            istringstream iss(path);
            string dic, name, content;
            iss >> dic;
            while (iss >> name >> content) {
                name = dic + "/" + name;
                if (mp.find(content) == mp.end()) {
                    int ttt = mp.size();
                    mp[content] = ttt;
                    ans.push_back(vector<string>());
                }
                ans[mp[content]].push_back(name);
            }
        }
        vector<vector<string>> ans2;
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i].size() != 1) ans2.push_back(ans[i]);
        }
        return ans2;
    }
};


int main() {
    Solution sol;
    vector<string> vec;
    vec.push_back("root/a 1.txt(abcd) 2.txt(efgh)");
    vec.push_back("root/c 3.txt(abcd)");
    vec.push_back("root/c/d 4.txt(efgh)");
    vec.push_back("root 4.txt(efgh)");
    auto ans = sol.findDuplicate(vec);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}
