// https://leetcode.com/problems/rotate-list/
// 61. Rotate List

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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next)
            return head;
        
        ListNode * first = head;
        ListNode * last = head;
        int n = 1;
        
        while(last->next)
        {
            n++;
            last = last->next;
        }
        
        k = k%n;
        int rotate = n - k;
        
        while(rotate--)
        {
            ListNode * temp = first->next;
            first->next = NULL;
            last->next = first;
            last = last->next;
            first = temp;
        }
        
        return first;
    }
};
