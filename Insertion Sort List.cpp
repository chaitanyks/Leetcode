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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(-5001);
        dummy->next = head;

        ListNode *temp = head;
        ListNode *prev = dummy;

        while (temp != NULL) {
            if (prev->val > temp->val) {
                // actual algo
                ListNode *dmy = dummy;
                while (dmy->next->val < temp->val) {
                    dmy = dmy->next;
                }

                // 3 pointer
                ListNode *temp1 = dmy->next;
                // ListNode * temp2 = temp->next;
                prev->next = temp->next;
                dmy->next = temp;
                temp->next = temp1;
            }
            prev = temp;
            temp = temp->next;
        }

        return dummy->next;
        //
    }
};
