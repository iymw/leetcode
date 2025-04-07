class Solution {
private:
    void columns(string s, string p, int s_len, int p_len,
                 vector<vector<bool>>& v, int j) {
        if (j <= p_len) {
            if (s[s_len - 1] == p[j - 1] || p[j - 1] == '.') {
                v[s_len][j] = v[s_len - 1][j - 1];
            } else if (p[j - 1] == '*') {
                v[s_len][j] = v[s_len][j - 2];
                if (s[s_len - 1] == p[j - 2] || p[j - 2] == '.') {
                    v[s_len][j] = v[s_len - 1][j] || v[s_len][j];
                }
            } else {
                v[s_len][j] = 0;
            }
            columns(s, p, s_len, p_len, v, j + 1);
        }
    }
    void rows(string s, string p, int s_len, int p_len,
              vector<vector<bool>>& v) {
        if (s_len >= 1) {
            rows(s, p, s_len - 1, p_len, v);
            columns(s, p, s_len, p_len, v, 1);
        }
    }
    void initialize_dp_table(string p, int p_len, int j,
                             vector<vector<bool>>& v) {
        if (j <= p_len) {
            if (p[j - 1] == '*') {
                v[0][j] = v[0][j - 2];
            }
            initialize_dp_table(p, p_len, j + 1, v);
        }
    }

public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        vector<vector<bool>> v(s_len + 1, vector<bool>(p_len + 1, 0));
        v[0][0] = 1;
        initialize_dp_table(p, p_len, 1, v);
        rows(s, p, s_len, p_len, v);
        return v[s_len][p_len];
    }
};