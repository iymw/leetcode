class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = -1;
        int left = 0, mid = 0, right = nums.size() - 1;

        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            }
        }

        if (target > nums[mid]) {
            i = mid + 1;
        } else if (target < nums[mid]) {
            i = mid;
        }

        return i;
    }
};