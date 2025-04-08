class Solution {
private:
    int findIndex(vector<int>& nums, int num, int c) {
        for (int i = 0; i < nums.size(); i++) {
            if (num == nums[i] && i != c) {
                return i;
            }
        }
        return 0;
    }

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        while (left < right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                break;
            }
        }
        return {findIndex(temp, nums[left], -1),
                findIndex(temp, nums[right], findIndex(temp, nums[left], -1))};
    }
};