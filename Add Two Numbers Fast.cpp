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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode * start = new ListNode(0);
        ListNode * index = start;
        
        while(l1 || l2)
        {
            int val = l1?l1->val:0;
            val += l2?l2->val:0;
            val += carry;
            
            carry = val/10;
            val %= 10;
            
            ListNode * temp = new ListNode(val);
            index->next = temp;
            index = temp;
            
            if(l1)
                l1 = l1->next;
            
            if(l2)
                l2 = l2->next;
        }
        
        if(carry!=0)
        {
            ListNode * temp = new ListNode(carry);
            index->next = temp;
            index = temp;
        }
        
        return start->next;        
    }
};
