class Solution {
private:
    int binary_search(vector<int>& nums, int target, bool left_check) {
        int i = -1;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {
                i = mid;
                if (left_check) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            }
        }

        return i;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binary_search(nums, target, 1), binary_search(nums, target, 0)};
    }
};