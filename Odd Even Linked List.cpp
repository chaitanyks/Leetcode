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
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        int n = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            temp = temp->next;
            n++;
        }

        ListNode *headA = head;
        ListNode *headB = head->next;

        ListNode *list1 = head;
        ListNode *list2 = head->next;

        while (list1 != NULL && list2 != NULL) {
            //base case
            if (list2->next == NULL) {
                if (n % 2 == 0)
                    list1->next = headB;
                else {
                    list1->next = list2->next;
                    list2->next = headB;
                }
                break;
            }

            list1->next = list2->next;
            list1 = list2;
            list2 = list2->next;
        }

        return headA;
    }
};
