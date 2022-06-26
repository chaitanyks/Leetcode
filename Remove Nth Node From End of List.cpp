// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// 19. Remove Nth Node From End of List

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {

        if (head->next == NULL)
            return NULL;

        ListNode *k1 = head;
        ListNode *k2 = head;
        ListNode *prev = NULL;

        int count = 0;
        while (k2 != NULL) {
            count++;
            if (count > n) {
                prev = k1;
                k1 = k1->next;
            }
            k2 = k2->next;
        }
        if (prev != NULL)
            prev->next = k1->next;
        else
            head = head->next;
        return head;
    }
};
