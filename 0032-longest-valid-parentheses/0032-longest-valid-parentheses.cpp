class Solution {
private:
    int find_max(int left, int right, string s, int max) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            }

            if (s[i] == ')') {
                right++;
            }

            if (right > left) {
                left = 0;
                right = 0;
            }

            if (right == left) {
                int temp = left + right;
                if (temp > max) {
                    max = temp;
                }
            }
        }

        return max;
    }

    string reverse_string(string s, string reversed) {
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                reversed += ")";
            } else if (s[i] == ')') {
                reversed += "(";
            }
        }

        return reversed;
    }

public:
    int longestValidParentheses(string s) {
        int max_1 = find_max(0, 0, s, 0);
        int max_2 = find_max(0, 0, reverse_string(s, ""), 0);
        return max(max_1, max_2);
    }
};