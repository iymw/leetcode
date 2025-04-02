class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double output;
        int n, me;
        for (int i = 0; i < nums2.size(); i++) {
            nums1.push_back(nums2[i]);
        }
        stable_sort(nums1.begin(), nums1.end());
        n = nums1.size() + 1;
        me = n / 2;
        return n % 2 == 0
                   ? nums1[me - 1]
                   : double((double(nums1[me - 1]) + double(nums1[me])) / 2);

        return 0;
    }
};