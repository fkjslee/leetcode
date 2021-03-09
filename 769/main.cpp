#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int ans = 1;

    void dfs(const vector<int>& arr, vector<int>& vec, int point) {
        if (vec.size() == point) {
            cout << "point = " << point << endl;
            for (int i = 0; i < vec.size(); ++i) cout << vec[i] << ' ' ;
            cout << endl;
            vec.push_back(arr.size() - 1);
            vector<int> sortArr(arr);
            int p = 0;
            for (int i = 0; i < vec.size(); ++i) {
                cout << "i = " << vec[i] << endl;
                sort(sortArr.begin() + p, sortArr.begin() + vec[i] + 1);
                p = vec[i] + 1;
            }
            cout << "sortArr" << endl;
            for (int i = 0; i < sortArr.size(); ++i)
                cout << sortArr[i] << ' ';
            cout << endl;
            int arrSorted = true;
            for (int i = 0; i < sortArr.size() - 1; ++i)
                if (sortArr[i] > sortArr[i+1]) arrSorted = false;
            if (arrSorted) ans = max(ans, point+1);
            vec.pop_back();
            cout << "sorted " << arrSorted << endl << endl;
            return;
        }
        for (int i = vec.size() ? (*(--vec.end())+1) : 0; i < arr.size() - 1; ++i) {
            vec.push_back(i);
            dfs(arr, vec, point);
            vec.pop_back();
        }
    }


    int maxChunksToSorted(vector<int>& arr) {
        for (int chunk = 2; chunk <= arr.size(); ++chunk) {
            int point = chunk - 1;
            vector<int> vec;
            dfs(arr, vec, point);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(1);
    cout << sol.maxChunksToSorted(vec) << endl;
}
