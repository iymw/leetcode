class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        nums.resize(distance(nums.begin(), unique(nums.begin(), nums.end())));
        return nums.size();
    }
};