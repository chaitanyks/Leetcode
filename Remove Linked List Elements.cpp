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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *temp;
        ListNode *prev;

        while (head != NULL && head->val == val) {
            head = head->next;
        }

        if (head == NULL)
            return head;
            
        prev = head;
        temp = head->next;
        while (temp != NULL) {
            if (temp->val == val) {
                temp = temp->next;
                prev->next = temp;
                // prev = temp;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
