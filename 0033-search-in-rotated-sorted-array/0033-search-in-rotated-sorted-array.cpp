class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        int res = it - nums.begin();
        return res == nums.size() ? -1 : res;
    }
};