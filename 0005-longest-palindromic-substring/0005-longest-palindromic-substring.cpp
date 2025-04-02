class Solution {
public:
    string longestPalindrome(string s) {
        int s_length = s.length(), final_count = 0, temp = 0;
        string result;
        for (int i = 0; i < s_length; i++) {
            for (int j = i; j < s_length; j++) {
                bool flag = true;
                int left = i, right = j;
                while (left < right) {
                    if (s[left] != s[right]) {
                        flag = false;
                        break;
                    }
                    left++;
                    right--;
                }
                if (flag) {
                    temp = j - i + 1;
                    if (temp > final_count) {
                        final_count = temp;
                        result = s.substr(i, final_count);
                    }
                }
            }
        }
        return s_length != 1 ? result : s;
    }
};