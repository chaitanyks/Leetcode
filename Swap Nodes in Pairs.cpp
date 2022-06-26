// https://leetcode.com/problems/swap-nodes-in-pairs/
// 24. Swap Nodes in Pairs

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
    ListNode* swapPairs(ListNode* head) {
        ListNode * temp1 = head;
        
        if(temp1==NULL)
            return temp1;
        
        ListNode * temp2 = head->next;
        
        if(temp2==NULL)
            return temp1;
        
        temp1->next = swapPairs(temp2->next);
        temp2->next = temp1;
        
        return temp2;
    }
};
