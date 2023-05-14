// https://leetcode.com/problems/linked-list-cycle-ii/
// 142. Linked List Cycle II
// https://www.youtube.com/watch?v=-YiQZi3mLq0

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;

        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast)
                break;
        }

        if (fast == NULL || fast -> next == NULL)
            return NULL;

        slow = head;
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }

        return fast;
    }
};
