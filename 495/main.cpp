#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        sort(timeSeries.begin(), timeSeries.end());
        int ans = 0;
        for (int i = 0; i < int(timeSeries.size() - 1); ++i) {
            if (timeSeries[i] + duration < timeSeries[i+1]) {
                ans += duration;
            } else {
                ans += timeSeries[i+1] - timeSeries[i];
            }
        }
        return ans + duration;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}