#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int getDis(vector<int> v1, vector<int> v2) {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }

    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(0);
        for (vector<int> ghost : ghosts) {
            if (getDis(ghost, target) <= getDis(vec, target))
                return false;
        }
        return true;
    }

};
