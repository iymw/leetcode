class Solution {
private:
    bool findDuplicates(int temp, vector<int>& v) {
        for (int i : v) {
            if (i != temp) {
                return 0;
            }
        }
        return 1;
    }
    int getNearest(int x, int y, int target) {
        return target - x >= y - target ? y : x;
    }
    int getNearestElement(vector<int>& arr, int n, int target) {
        if (target <= arr[0]) {
            return arr[0];
        }
        if (target >= arr[n - 1]) {
            return arr[n - 1];
        }
        int left = 0, right = n, mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (arr[mid] == target) {
                return arr[mid];
            }
            if (target < arr[mid]) {
                if (mid > 0 && target > arr[mid - 1]) {
                    return getNearest(arr[mid - 1], arr[mid], target);
                }
                right = mid;
            } else {
                if (mid < n - 1 && target < arr[mid + 1]) {
                    return getNearest(arr[mid], arr[mid + 1], target);
                }
                left = mid + 1;
            }
        }
        return arr[mid];
    }

public:
    int threeSumClosest(vector<int>& nums, int target) {
        int temp;
        bool isFirst = 0, gotIt = 0;
        vector<int> v;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (!isFirst && !gotIt) {
                    isFirst = 1;
                }
                temp = nums[i] + nums[left] + nums[right];
                if (temp < target) {
                    if (isFirst) {
                        v.push_back(temp);
                        gotIt = 1;
                    }
                    if (temp > v[v.size() > 1 ? v.size() - 1 : 0] &&
                        findDuplicates(temp, v)) {
                        v.push_back(temp);
                    }
                    left++;
                } else if (temp > target) {
                    if (isFirst) {
                        v.push_back(temp);
                        gotIt = 1;
                    }
                    if (temp < v[v.size() > 1 ? v.size() - 1 : 0] &&
                        findDuplicates(temp, v)) {
                        v.push_back(temp);
                    }
                    right--;
                } else {
                    return temp;
                }
            }
        }
        sort(v.begin(), v.end());
        return getNearestElement(v, v.size(), target);
    }
};
