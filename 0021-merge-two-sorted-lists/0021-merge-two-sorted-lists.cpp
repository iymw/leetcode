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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* current = head;
        int a = -1, b = -1;

        while (list1 || list2) {
            if (list1) {
                a = list1->val;
            }
            if (list2) {
                b = list2->val;
            }
            if (list1 && list2) {
                if (a < b) {
                    current->next = new ListNode(a);
                    current = current->next;
                    if (list1) {
                        list1 = list1->next;
                    }
                } else {
                    current->next = new ListNode(b);
                    current = current->next;
                    if (list2) {
                        list2 = list2->next;
                    }
                }
            } else {
                if (list1) {
                    current->next = new ListNode(a);
                    current = current->next;
                    if (list1) {
                        list1 = list1->next;
                    }
                }
                if (list2) {
                    current->next = new ListNode(b);
                    current = current->next;
                    if (list2) {
                        list2 = list2->next;
                    }
                }
            }
        }
        return head->next;
    }
};