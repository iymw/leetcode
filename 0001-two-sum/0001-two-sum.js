/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let left = 0, right = nums.length - 1, temp = 0, res = [];
    const sorted = [...nums].sort(function (a, b) { return a - b });
    function findRight(indexLeft, sortedRight) {
        for (let i = 0; i < nums.length; i++) {
            if (sortedRight === nums[i] && indexLeft !== i) {
                return i;
            }
        }
    }
    while (left <= right) {
        temp = sorted[left] + sorted[right];
        if (target === temp) {
            const indexLeft = nums.indexOf(sorted[left]);
            res.push(indexLeft);
            res.push(findRight(indexLeft, sorted[right]));
            return res;
        }

        if (target < temp) {
            right--;
        }

        if (target > temp) {
            left++;
        }
    }
};