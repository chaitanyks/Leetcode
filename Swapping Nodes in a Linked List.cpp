// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// 1721. Swapping Nodes in a Linked List

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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode * temp = head;
        ListNode * first = head;
        ListNode * last = head;
        
        int count = 1;
        
        while(temp!=NULL)
        {
            if(count==k)
                first = temp;
            
            if(count>k)
                last = last->next;
            
            temp = temp->next;
            count++;
        }
        
        int val = first->val;
        first->val = last->val;
        last->val = val;
        
        return head;
    }
};
