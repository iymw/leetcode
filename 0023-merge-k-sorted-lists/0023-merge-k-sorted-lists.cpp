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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* current = lists[i];
            while (current) {
                v.push_back(current->val);
                current = current->next;
            }
        }
        stable_sort(v.begin(), v.end());
        ListNode* head = new ListNode();
        ListNode* temp = head;
        for (auto i : v) {
            temp->next = new ListNode(i);
            temp = temp->next;
        }
        return head->next;
    }
};