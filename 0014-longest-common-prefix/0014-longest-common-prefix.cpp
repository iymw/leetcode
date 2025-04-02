/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string c = "", temp_j = "", temp_k = "";
        bool flag = 0;
        replace(strs.begin(), strs.end(), (string) "", (string) "_");
        for (int j = 0; j < strs[0].size(); j++) {
            temp_j = strs[0][j] == '_' ? " " : temp_j + strs[0][j];
            for (int k = 0; k < strs.size(); k++) {
                temp_k += strs[k][j];
                if (temp_j == temp_k) {
                    flag = 1;
                } else {
                    flag = 0;
                    break;
                }
                if (k != strs.size() - 1) {
                    temp_k.pop_back();
                }
            }
            if (flag) {
                c += strs[0][j];
            }
        }
        return c == " " ? "" : c;
    }
};

/*
int main() {
    Solution myObj;
    vector<string> strs = {"aaa", "aa", "aaa"};
    cout << myObj.longestCommonPrefix(strs) << endl;
    return 0;
}
*/