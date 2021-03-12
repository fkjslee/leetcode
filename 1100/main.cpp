#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int ans = 0;
        if (S.length() < K) return 0;
        int r = K - 1;
        int cnt[200];
        for (int i = 0; i < 200; ++i) cnt[i] = 0;
        for (int i = 0; i < r; ++i) cnt[S[i]]++;
        set<int> unFitNums;
        for (int i = 0; i < r; ++i)
            if (cnt[S[i]] > 1)
                unFitNums.insert(S[i]);
        while (r < S.length()) {
            // remove left
            if (r-K >= 0) {
                cnt[S[r-K]]--;
                if (cnt[S[r-K]] == 1) {
                    unFitNums.erase(unFitNums.find(S[r-K]));
                }
            }

            // add right
            cnt[S[r]]++;
            if (cnt[S[r]] > 1) unFitNums.insert(S[r]);

            // count
            if (unFitNums.empty()) ++ans;
            r++;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}