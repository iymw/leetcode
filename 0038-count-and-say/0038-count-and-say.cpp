class Solution {
public:
    string countAndSay(int n) {
        string result = "";

        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                result = "1";
            } else {
                int count = 1;
                string temp = "";
                for (int j = 0; j < result.length(); j++) {
                    if (result[j] == result[j + 1]) {
                        count++;
                    } else {
                        temp += to_string(count);
                        temp += result[j];
                        count = 1;
                    }
                }
                result = temp;
            }
        }
        return result;
    }
};