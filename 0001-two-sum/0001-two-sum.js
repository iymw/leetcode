/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let left = 0, right = nums.length - 1, temp = 0, res = [];
    const sorted = [...nums].sort(function (a, b) { return a - b });
    function findAllIndex(left, right) {
        for (let i = 0; i < nums.length; i++) {
            if (left === nums[i]) {
                res.push(i);
                continue;
            }

            if (right === nums[i]) {
                res.push(i);
            }
        }
        return res;
    }
    while (left <= right) {
        temp = sorted[left] + sorted[right];
        if (target === temp) {
            return findAllIndex(sorted[left], sorted[right]);
        }

        if (target < temp) {
            right--;
        }

        if (target > temp) {
            left++;
        }
    }
};