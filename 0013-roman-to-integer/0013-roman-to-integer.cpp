class Solution {
public:
    int dictionary(char s) {
        switch (s) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return 0;
        }
    }
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (dictionary(s[i]) < dictionary(s[i + 1])) {
                int temp = dictionary(s[i]) * (-1);
                sum += temp;
            } else {
                sum += dictionary(s[i]);
            }
        }

        return sum;
    }
};