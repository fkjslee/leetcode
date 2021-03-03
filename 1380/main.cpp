#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); ++i) {
            int minValueIdx = 0;
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] < matrix[i][minValueIdx])
                    minValueIdx = j;
            }
            bool maxValueInCol = true;
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[j][minValueIdx] > matrix[i][minValueIdx])
                    maxValueInCol = false;
            }
            if (maxValueInCol)
                ans.push_back(matrix[i][minValueIdx]);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}