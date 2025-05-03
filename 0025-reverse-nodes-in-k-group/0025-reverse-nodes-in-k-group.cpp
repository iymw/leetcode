/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        vector<int> v;
        vector<int> temp;
        vector<int> res;
        ListNode* rn = new ListNode();
        ListNode* ct = rn;
        while (current) {
            v.push_back(current->val);
            current = current->next;
        }
        bool flag = 0;
        for (int i = 1; i <= v.size(); i++) {
            temp.push_back(v[i - 1]);
            if (i % k == 0 && !flag) {
                reverse(temp.begin(), temp.end());
                res.insert(res.end(), temp.begin(), temp.end());
                temp.clear();
                if (i + v.size() % k == v.size()) {
                    flag = 1;
                    continue;
                }
            }
            if (i == v.size() && flag) {
                res.insert(res.end(), temp.begin(), temp.end());
            }
        }
        for (auto i : res) {
            ct->next = new ListNode(i);
            ct = ct->next;
        }

        return rn->next;
    }
};