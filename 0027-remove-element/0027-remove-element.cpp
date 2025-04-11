class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                continue;
            } else {
                temp.push_back(nums[i]);
                res++;
            }
        }
        nums = temp;
        temp.clear();
        return nums.size();
    }
};