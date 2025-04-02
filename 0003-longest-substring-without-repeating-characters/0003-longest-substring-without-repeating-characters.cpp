class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str;
        int num, final = 0;
        for (int p = 0; p < s.length(); p++) {
            int found_it = str.find(s[p]);
            if (found_it != string::npos) {
                str = str.substr(found_it + 1);
            }
            str += s[p];
            num = str.length();
            if (num > final) {
                final = num;
            }
        }
        return final;
    }
};