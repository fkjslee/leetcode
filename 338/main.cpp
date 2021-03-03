#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>
#include <hash_map>
#include <queue>
#include <math.h>

using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= num; ++i) {
            ans.push_back(ans[i ^ (i & (-i))] + 1);
        }
        return ans;
    }
};

int main() {
    int n = 8;
    auto vec = (new Solution())->countBits(n);
    for (int x : vec)
        cout << x << endl;
}