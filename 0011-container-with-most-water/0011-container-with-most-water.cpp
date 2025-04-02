class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.end() - height.begin() - 1;
        int h, area = 0, temp;
        while (left < right) {
            h = min(height[left], height[right]);
            area = max(area, h * (right - left));
            (height[left] < height[right]
                 ? left++
                 : (height[left] > height[right] ? right-- : left++));
        }
        return area;
    }
};