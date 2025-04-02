class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        vector<vector<char>> arr(numRows);
        bool isZigZag = false, isFirst = false;
        int temp_row, c;
        string result = "";

        for (int row = 0; row < s.length(); row++) {
            isFirst = row == 0 ? true : false;
            temp_row = isZigZag ? c - 1 : (row != 0 ? c + 1 : (row));
            arr[temp_row].push_back(s[row]);
            if (!isFirst && row % (numRows - 1) == 0) {
                isZigZag = !isZigZag;
            }
            c = temp_row;
        }

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                result += arr[i][j];
            }
        }

        return result;
    }

    /*
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        vector<vector<char>> arr(numRows, vector<char>(s.length(), ' '));
        bool isZigZag = false;
        int temp_row = 0, temp_col = 0;
        string result = "";
        for (int col = temp_col; col < numRows; col++) {
            for (int row = temp_row; row < s.length(); row++) {
                if (temp_row + 1 != s.length()) {
                    temp_row = row == 0 && col == 0 ? 0 : temp_row + 1;
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
    */
};