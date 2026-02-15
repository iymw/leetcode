/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function (nums) {
    let res = [];
    function backTrack(cur, i) {
        if (i === nums.length) {
            res.push([...cur]);
            return;
        }

        cur.push(nums[i]);
        backTrack(cur, i + 1);
        cur.pop();

        backTrack(cur, i + 1);
    }

    backTrack([], 0);
    return res;
};