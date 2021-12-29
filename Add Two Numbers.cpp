// https://leetcode.com/problems/add-two-numbers/
// 2. Add Two Numbers

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *head = NULL;
        ListNode *temp = NULL;
        while (l1 != NULL && l2 != NULL) {
            int v1 = l1->val;
            int v2 = l2->val;

            int sum = v1 + v2 + carry;
            ListNode *local = new ListNode(sum % 10);
            carry = sum / 10;

            if (head == NULL) {
                head = local;
                temp = local;
            } else {
                temp->next = local;
                temp = local;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            int v1 = l1->val;

            int sum = v1 + carry;
            ListNode *local = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = local;
            temp = local;

            l1 = l1->next;
        }

        while (l2 != NULL) {
            int v2 = l2->val;

            int sum = v2 + carry;
            ListNode *local = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = local;
            temp = local;

            l2 = l2->next;
        }

        if (carry != 0) {
            ListNode *local = new ListNode(carry);
            temp->next = local;
            temp = local;
        }
        return head;
    }
};
