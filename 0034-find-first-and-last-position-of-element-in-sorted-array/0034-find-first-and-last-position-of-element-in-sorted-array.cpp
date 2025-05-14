class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i]) {
                res.push_back(i);
            }
        }

        if (res.empty()) {
            return {-1, -1};
        } else {
            return {res[0], res[res.size() - 1]};
        }
    }
};