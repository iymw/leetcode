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
    /*
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int> value = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};
        for (int i = 0; i < s.length(); i++) {
            if (value[s[i]] < value[s[i + 1]]) {
                int temp = value[s[i]] * (-1);
                sum += temp;
            } else {
                sum += value[s[i]];
            }
        }

        return sum;
    }
    */
};