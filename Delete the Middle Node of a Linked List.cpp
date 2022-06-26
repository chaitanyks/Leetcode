// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// 2095. Delete the Middle Node of a Linked List

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
    ListNode *deleteMiddle(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *fast = head;
        ListNode *slow = head;

        // corner case only 1 node
        if (head->next == NULL)
            return NULL;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;
        return head;
    }
};
