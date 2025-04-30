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
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        ListNode* res = new ListNode();
        ListNode* temp = res;

        vector<int> c;
        while (current) {
            c.push_back(current->val);
            current = current->next;
        }

        if (c.empty()) {
            return NULL;
        }

        for (int i = 0; i < c.size(); i++) {
            temp->next = new ListNode(i + 1 == c.size() && c.size() % 2 != 0
                                          ? c[i]
                                          : (i % 2 == 0 ? c[i + 1] : c[i - 1]));
            temp = temp->next;
        }
        vector<int>().swap(c);
        return res->next;
    }
};