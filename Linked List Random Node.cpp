// https://leetcode.com/problems/linked-list-random-node/
// 382. Linked List Random Node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:

    ListNode*Head;

    Solution(ListNode*head) {
        Head = head;
    }

    int getRandom() {

        ListNode * temp = Head;
        int pos;
        int n = 0;
        while (temp != NULL) {
            temp = temp -> next;
            pos = rand();
            if (pos < n) {
                break;
            }
            n++;
        }

        if (pos > n) {
            pos = rand() % n;
        }

        temp = Head;
        while (pos--) {
            temp = temp -> next;
        }

        return temp -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
