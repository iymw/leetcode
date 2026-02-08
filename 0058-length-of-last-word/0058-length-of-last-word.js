/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
    let temp = "";
    let res = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] !== " ") {
            temp += s[i];
        }

        if (s[i] === " " || i === s.length - 1) {
            res.push(temp);
            temp = "";
        }
    }

    let filtered = [];
    for (let i = 0; i < res.length; i++) {
        if (res[i] !== "") {
            filtered.push(res[i]);
        }
    }
    return filtered[filtered.length - 1].length;
};