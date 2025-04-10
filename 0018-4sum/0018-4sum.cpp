class Solution {
   private:
    bool checkingForDuplicates(vector<vector<int>>& v, vector<int>& temp) {
        for (auto i : v) {
            if (i == temp) {
                return 0;
            }
        }
        return 1;
    }

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
                        vector<int> temp = {nums[j], nums[i], nums[left], nums[right]};
                        if (v.empty() || checkingForDuplicates(v, temp)) {
                            v.push_back({nums[j], nums[i], nums[left], nums[right]});
                        }
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
        return v;
    }
};