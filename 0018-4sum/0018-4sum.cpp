class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); j++) {
            for (int i = j + 1; i < nums.size(); i++) {
                int left = i + 1, right = nums.size() - 1;
                while (left < right) {
                    long long sum = (long long)nums[j] + (long long)nums[i] + (long long)nums[left] + (long long)nums[right];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        v.push_back({nums[j], nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left - 1] == nums[left]) {
                            left++;
                        }
                        while (right > left && nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }
        sort(v.begin(), v.end());
        v.resize(distance(v.begin(), unique(v.begin(), v.end())));
        return v;
    }
};