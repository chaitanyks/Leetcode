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

    // reverse
    ListNode *reverse(ListNode *head) {
        if (head->next != NULL) {
            ListNode *root = reverse(head->next);
            head->next->next = head;
            head->next = NULL;
            return root;
        }
        return head;
    }

    void reorderList(ListNode *head) {

        // corner case
        if (head->next == NULL)
            return;

        ListNode *mid = head;
        ListNode *fast = head;
        ListNode *temp = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            temp = mid;
            mid = mid->next;
        }

        temp->next = NULL;
        ListNode *head1;
        head1 = head;
        ListNode *head2 = mid;



        // reverse head2
        head2 = reverse(head2);


        while (head1 != NULL && head2 != NULL) {
            ListNode *temp1;
            ListNode *temp2;
            temp1 = head1->next;
            temp2 = head2->next;
            head1->next = head2;
            // corner case
            if (temp1 != NULL && temp2 != NULL)
                head2->next = temp1;

            head1 = temp1;
            head2 = temp2;
        }

        // return head;

    }
};
