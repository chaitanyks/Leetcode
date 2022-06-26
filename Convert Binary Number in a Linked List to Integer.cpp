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
    int getDecimalValue(ListNode *head) {
        int n = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            temp = temp->next;
            n++;
        }
        int ans = 0;
        temp = head;
        while (temp != NULL) {
            n--;
            ans = ans + pow(2, n) * temp->val;
            temp = temp->next;
        }

        return ans;
    }
};
