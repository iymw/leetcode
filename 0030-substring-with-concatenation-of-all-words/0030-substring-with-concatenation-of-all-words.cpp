class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_length = s.length(), wds_size = words.size(),
            w_length = words[0].length();

        if (w_length * wds_size > s_length || s_length == 0 || words.empty()) {
            return {};
        }

        unordered_map<string, int> um;
        for (auto& word : words) {
            um[word]++;
        }

        vector<int> res;
        unordered_map<string, int> seen;

        for (int i = 0; i < w_length; i++) {
            int lt = i, num = 0;
            seen.clear();
            for (int rt = i; rt + w_length <= s_length; rt += w_length) {
                string sub = s.substr(rt, w_length);
                if (um.find(sub) == um.end()) {
                    seen.clear();
                    num = 0;
                    lt = rt + w_length;
                } else {
                    seen[sub]++;
                    num++;

                    while (seen[sub] > um[sub]) {
                        string lt_word = s.substr(lt, w_length);
                        seen[lt_word]--;
                        num--;
                        lt += w_length;
                    }

                    if (num == wds_size) {
                        res.push_back(lt);
                    }
                }
            }
        }

        return res;
    }
};