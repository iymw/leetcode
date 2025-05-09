class Solution {
private:
    bool isFlag(bool flag, vector<int>& nums, string check) {
        bool isCondition = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            isCondition = check == "de"
                              ? nums[i] >= nums[i + 1]
                              : (check == "sa" ? nums[i] == nums[i + 1] : 0);
            if (isCondition) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
        return flag;
    };

public:
    void nextPermutation(vector<int>& nums) {
        bool biggerThanOne = nums.size() > 1;
        bool decreasing = biggerThanOne ? isFlag(0, nums, "de") : 0;
        if (decreasing) {
            reverse(nums.begin(), nums.end());
        } else {
            bool allTheSame = biggerThanOne ? isFlag(0, nums, "sa") : 0;
            if (biggerThanOne && !allTheSame) {
                vector<int> res;
                int c = 0;
                do {
                    if (c == 1) {
                        for (int i = 0; i < nums.size(); i++) {
                            res.push_back(nums[i]);
                        }
                        break;
                    }
                    c++;
                } while (next_permutation(nums.begin(), nums.end()));
                nums = res;
            }
        }
    }
};