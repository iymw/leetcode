class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        vector<vector<char>> arr(numRows, vector<char>(s.length(), ' '));
        bool isZigZag = 0;
        int col = 0, temp_row = 0, temp_col = 0;
        string result = "";
        for (int row = temp_row; row < s.length(); row++) {
            if (temp_row + 1 != s.length()) {
                temp_row = (row == 0 && col == 0) ? 0 : temp_row + 1;
                if (isZigZag) {
                    row -= 2;
                    col++;
                }
                arr[row].insert(arr[row].begin() + col, s[temp_row]);
                if (row % (numRows - 1) == 0 && col % (numRows - 1) == 0) {
                    isZigZag = !isZigZag;
                    if (row == 0 && col == 0) {
                        isZigZag = !isZigZag;
                    }
                }
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                if (arr[i][j] != ' ') {
                    result += arr[i][j];
                }
            }
        }

        return result;
    }
};