/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
    candidates.sort(function (a, b) {
        return a - b;
    });
    let res = [];
    function BT(total, temp, i) {
        if (total === target) {
            res.push([...temp]);
            return;
        }
        if (total > target || i >= candidates.length) return;
        temp.push(candidates[i]);
        BT(total + candidates[i], temp, i + 1);
        temp.pop();
        while (i + 1 < candidates.length && candidates[i] === candidates[i + 1]) {
            i += 1;
        }
        BT(total, temp, i + 1);
    }
    BT(0, [], 0);
    return res;
};