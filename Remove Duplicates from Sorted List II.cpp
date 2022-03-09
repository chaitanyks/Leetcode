// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// 82. Remove Duplicates from Sorted List II

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * start = NULL;
        ListNode * temp = NULL;
        ListNode * prev = head;
        ListNode * curr = head;
        
        int count = 0;
        while(curr!=NULL)
        {
            if(prev->val != curr->val)
            {
                if(count==1)
                {                
                    if(start == NULL)
                        start = prev;
                    else
                        temp->next = prev;
                    
                    temp = prev;
                    temp->next = NULL;
                }
                count = 1;
                prev = curr;
                curr = curr->next;
            }
            else
            {
                count++;
                prev = curr;
                curr = curr->next;
            }
        }
        
        //Last Node
        if(count == 1)
        {
            if(start == NULL)
                start = prev;
            else
                temp->next = prev;
            
            temp = prev;
            temp->next = NULL;
        }
        
        return start;
    }
};
