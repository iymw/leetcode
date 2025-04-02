class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int selisih, sizeOfArray = nums.size();

        for (int i = 0; i < sizeOfArray; i++) {
            selisih = target - nums[i];
            auto it = find(nums.begin(), nums.end(), selisih);
            int found = it - nums.begin();
            if (found != i && found < sizeOfArray) {
                return {i, found};
                break;
            }
        }
        return {};
    }
};