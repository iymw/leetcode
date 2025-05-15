class Solution {
private:
    auto find_n(vector<char>& v, char n) { return find(v.begin(), v.end(), n); }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char n = board[i][j];

                if (n == '.') {
                    continue;
                } else {
                    if (find_n(rows[i], n) == rows[i].end()) {
                        rows[i].push_back(n);
                    } else {
                        return 0;
                    }

                    if (find_n(cols[j], n) == cols[j].end()) {
                        cols[j].push_back(n);
                    } else {
                        return 0;
                    }

                    int box_n = (i / 3) * 3 + (j / 3);
                    if (find_n(boxes[box_n], n) == boxes[box_n].end()) {
                        boxes[box_n].push_back(n);
                    } else {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};