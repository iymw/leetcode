/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
function calculate(a, b) {
    while (a.length < b.length) a.unshift(0);
    while (b.length < a.length) b.unshift(0);

    let temp = [],
        excess = 0;

    for (let i = a.length - 1; i >= 0; i--) {
        let total = a[i] + b[i] + excess;
        let digit = total % 10;
        excess = Math.floor(total / 10);
        temp.unshift(digit);
    }

    if (excess > 0) {
        temp.unshift(excess);
    }

    return temp;
}

function sum(group) {
    let x = 0;
    while (x < group.length) {
        let y = x;
        while (y > 0) {
            group[x].push(0);
            y--;
        }
        x++;
    }

    let res = [];
    group = group.reverse();
    for (let i = 0; i < group.length; i++) {
        if (i === 0) {
            res = group[i];
        } else {
            res = calculate(res, group[i]);
        }

        while (res.length < group[i].length) {
            res.unshift(0);
        }
    }

    return res;
}

var multiply = function (num1, num2) {
    if (num1 === "0" || num2 === "0") {
        return "0";
    }
    let bottom = "",
        top = "";
    if (num1.length < num2.length) {
        bottom = num1;
        top = num2;
    } else {
        bottom = num2;
        top = num1;
    }

    let group = [];

    for (let i = bottom.length - 1; i >= 0; i--) {
        let excess = 0;
        let temp = [];

        for (let j = top.length - 1; j >= 0; j--) {
            let res = Number(bottom[i]) * Number(top[j]) + excess;
            let digit = res % 10;
            excess = Math.floor(res / 10);
            temp.unshift(digit);
        }

        if (excess > 0) {
            temp.unshift(excess);
        }

        group.push(temp);
    }

    let res = "";
    sum(group).forEach((element) => (res += element.toString()));
    return res;
};