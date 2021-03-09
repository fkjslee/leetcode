#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        if (S.empty()) return "";
        list<char> lst;
        for (char u : S) {
            lst.push_back(u);
        }
        int changed = true;
        string ans;
        while (changed) {
            changed = false;
            for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
                list<char>::iterator after = ++iter;
                --iter;
                if (after == lst.end()) break;
                if (*after == *iter) {
                    lst.erase(iter);
                    lst.erase(after);
                    changed = true;
                    break;
                }
            }
            ans = "";
            for (char u : lst)
                ans += u;
            cout << ans << endl;

        }
        return ans;
    }
};

int main() {
    Solution sol;
    sol.removeDuplicates("abbaca");
}
