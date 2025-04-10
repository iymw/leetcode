class Solution {
   private:
    void calculateCombinations(vector<string> &store_ordered_value,
                               int size_store_ordered_value,
                               vector<string> &res, string c, bool flag) {
        if (size_store_ordered_value > 1) {
            vector<string> temp;
            if (!res.empty()) {
                for (int i = 0; i < res.size(); i++) {
                    for (int j = 0; j < store_ordered_value[0].size(); j++) {
                        c = res[i];
                        c += store_ordered_value[0][j];
                        temp.push_back(c);
                    }
                }
            } else {
                for (int i = 0; i < store_ordered_value[0].size(); i++) {
                    for (int j = 0; j < store_ordered_value[1].size(); j++) {
                        c = store_ordered_value[0][i];
                        c += store_ordered_value[1][j];
                        temp.push_back(c);
                    }
                }
            }

            res = temp;
            temp.clear();

            if (size_store_ordered_value > 2) {
                store_ordered_value.erase(
                    store_ordered_value.begin(),
                    store_ordered_value.begin() + (!flag ? 1 : 2));
                calculateCombinations(store_ordered_value,
                                      size_store_ordered_value - 1, res, "", 0);
            }
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }
        unordered_map<char, string> um = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        vector<string> store_ordered_value;
        for (int i = 0; i < digits.length(); i++) {
            store_ordered_value.push_back(um.find(digits[i])->second);
        }
        if (store_ordered_value.size() > 1) {
            calculateCombinations(store_ordered_value,
                                  store_ordered_value.size(), res, "", 1);
        } else {
            for (int i = 0; i < store_ordered_value[0].size(); i++) {
                string c = "";
                c += store_ordered_value[0][i];
                res.push_back(c);
            }
        }
        return res;
    }
};