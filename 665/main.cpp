class Solution {
public:
    bool core(vector<int>& vec) {
        for (int i = 0; i < vec.size() - 1; ++i)
            if (vec[i+1] < vec[i]) return false;
        return true;
    }

    bool checkPossibility(vector<int>& nums) {
        int ans = 0;
        if (nums.size() <= 1) return 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i+1] < nums[i]) {
                int p1 = nums[i];
                int p2 = nums[i+1];
                nums[i] = p2;
                if (core(nums)) return true;
                nums[i] = nums[i+1] = p1;
                break;
            }
        }
        return core(nums);
    }
};
