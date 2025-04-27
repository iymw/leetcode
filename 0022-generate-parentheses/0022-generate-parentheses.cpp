class Solution {
private:
    void backtracking(int open, int closed, vector<string>& p,
                      vector<string>& temp) {
        if (open > 0) {
            temp.push_back("(");
            backtracking(open - 1, closed, p, temp);
            temp.pop_back();
        }

        if (open < closed) {
            temp.push_back(")");
            backtracking(open, closed - 1, p, temp);
            temp.pop_back();
        }

        if (open == 0 && closed == 0) {
            p.push_back(accumulate(temp.begin(), temp.end(), string{}));
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> p;
        vector<string> temp;
        backtracking(n, n, p, temp);
        return p;
    }
};