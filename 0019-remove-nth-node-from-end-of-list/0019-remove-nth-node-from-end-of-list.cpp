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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* current = head;
        ListNode* res = new ListNode();
        ListNode* temp = res;

        while (current) {
            current = current->next;
            count++;
        }

        for (int i = 0; i < count; i++) {
            if (head) {
                if (count - n != i) {
                    temp->next = new ListNode(head->val);
                    temp = temp->next;
                }
                head = head->next;
            }
        }

        return res->next;
    }
};