class Solution {
public:
    bool isValid(string s) {
        bool flag = 0;
        int s_len = s.length();
        stack<char> opening_bracket;
        string m = "";
        for (int i = 0; i < s_len; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                flag = 0;
                opening_bracket.push(s[i]);
            }
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                m = "";
                if (opening_bracket.empty()) {
                    return 0;
                }
                m += opening_bracket.top();
                m += s[i];
                if (m == "[]" || m == "()" || m == "{}") {
                    flag = 1;
                    opening_bracket.pop();
                } else {
                    return 0;
                }
            }
        }
        return opening_bracket.empty() ? flag : 0;
    }
};