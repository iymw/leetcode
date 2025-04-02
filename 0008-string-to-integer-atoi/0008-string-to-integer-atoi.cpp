class Solution {
public:
    int myAtoi(string s) {
        long long num, temp = 0;
        bool isNegative = false, isLocked = false;
        string c, result = "";
        int min = -2147483648, max = 2147483647;
        for (int i = 0; i < s.length(); i++) {
            c = s[i];
            num = s[i] - '0';
            if (!isLocked && (c == "-" || c == "+")) {
                if (!isNegative && c == "-") {
                    isNegative = !isNegative;
                }
                isLocked = !isLocked;
            } else if (!isLocked && (num < 0 || num > 9)) {
                if (c != "-" && c != "+" && c != " ") {
                    return temp;
                }
            } else if (num >= 0 && num <= 9) {
                if (temp >= min && temp <= max) {
                    temp = temp * 10 + num;
                    if (!isLocked) {
                        isLocked = !isLocked;
                    }
                }
            } else if (isLocked) {
                break;
            }
        }

        if (isNegative) {
            temp *= -1;
        }

        return temp < min ? min : temp > max ? max : temp;
    }
};