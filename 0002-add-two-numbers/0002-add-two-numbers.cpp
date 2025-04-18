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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* current = head;
        int carry = 0, sum;
        while (l1 || l2 || carry) {
            int k1 = l1 ? l1->val : 0;
            int k2 = l2 ? l2->val : 0;
            sum = k1 + k2 + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            l1 = l1 ? l1->next : 0;
            l2 = l2 ? l2->next : 0;
        }
        return head->next;
    }
};