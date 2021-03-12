#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> ugly;
        ugly.push(1);
        long long int ans = 1;
        while (n--) {
            long long int u = ans = ugly.top(); ugly.pop();
            //cout << "ans = " << ans << endl;
            ugly.push(u * 2);
            ugly.push(u * 3);
            ugly.push(u * 5);
            while (ugly.top() == ans || ugly.top() > 0x3f3f3f3f) ugly.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.nthUglyNumber(1) << endl;
}
