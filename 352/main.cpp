#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


class SummaryRanges {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> intervals;

    int binarySearchLower(const vector<vector<int>>& a, int x, int idx) {
        int l = 0, r = a.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m][idx] < x) l = m + 1;
            else r = m;
        }
        return l;
    }

    int binarySearchUpper(const vector<vector<int>>& a, int x, int idx) {
        int l = 0, r = a.size();
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (a[m][idx] <= x) l = m;
            else r = m - 1;
        }
        return l;
    }

    SummaryRanges() {

    }

    void addNum(int val) {
        int lower = binarySearchUpper(intervals, val, 1) - 1; //  刚好 <= x的值的下标
        if (lower == -1) { // val是最小值
            intervals.insert(intervals.begin(), {val, val});
        } else {
            if (val - intervals[lower][1] <= 1) intervals[lower][1] = val;
            else intervals.insert(intervals.begin() + lower, {val, val});
        }
        int upper = binarySearchLower(intervals, val, 0); // 刚好 >= x的值的下标
        if (upper == intervals.size()) {
            intervals.push_back({val, val});
        } else {
            if (intervals[upper][0] - val <= 1) intervals[upper][0] = val;
            else intervals.insert(intervals.begin() + upper, {val, val});
        }
        lower = binarySearchLower(intervals, val, 0);
        upper = binarySearchLower(intervals, val, 1);
        if (upper - lower == 1) {

        }
    }

    vector<vector<int>> getIntervals() {

    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

 int binary(int a[], int x) {
    int l = 0, r = 3;
    while (l < r) {
        int m = (l + r) >> 1;
        //cout << "m = " << m << ' ' << l << ' ' << r << endl;
        if (a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
 }


 int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.insert(vec.begin() + 1, -1);
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << endl;
 }
