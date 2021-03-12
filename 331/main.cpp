#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:

    bool isValidCore(vector<string>& seris, int& p) {
        if (p == seris.size()) return false;
        cout << "seris " << seris[p] << endl;
        if (seris[p] == "#") {
            p++;
            return true;
        }
        p++;
        return isValidCore(seris, p) && isValidCore(seris, p);
    }

    bool isValidSerialization(string preorder) {
        vector<string> seris;
        while (preorder.find(",") != string::npos) preorder.replace(preorder.find(","), 1, " ");
        istringstream iss(preorder);
        string buffer;
        while (iss >> buffer) {
            seris.push_back(buffer);
        }
        int p = 0;
        return isValidCore(seris, p) && p == seris.size();
    }
};

int main() {
    Solution sol;
    cout << sol.isValidSerialization("9,#,#,1") << endl;
}
