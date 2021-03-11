class Solution {
public:
    bool core(vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<int> arr;
        map<int, int> mp;
        for (int u : arr2) {
            if (mp[u] == 0) arr.push_back(u);
            mp[u]++;
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (mp[arr[i]] > 0) {
                auto idx = lower_bound(arr.begin(), arr.end(), arr[i] * 2);
                int u1 = i;
                int u2 = idx - arr.begin();
                //if (idx != arr.end()) cout << "check " << arr[i] << ' ' << *(idx) << endl;
                if (idx != arr.end() && *(idx) == arr[i] * 2) {
                    mp[arr[i]*2] -= mp[arr[i]];
                    if (mp[arr[i]*2] < 0) return false;
                    mp[arr[i]] = 0;
                } else return false;
            }
        }
        return true;
    }

    bool canReorderDoubled(vector<int>& arr) {
        vector<int> vec1, vec2;
        int cnt0 = 0;
        for (int u : arr) {
            if (u > 0) vec1.push_back(u);
            else if (u == 0) cnt0++;
            else vec2.push_back(-u);
        }
        if (!core(vec1) || !core(vec2)) return false;
        return cnt0 % 2 == 0;
    }
};
