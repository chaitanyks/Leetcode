// https://leetcode.com/problems/merge-k-sorted-lists/
// 23. Merge k Sorted Lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<ListNode*> head(n);
        
        for(int i=0;i<n;i++)
            head[i] = lists[i];
        
        ListNode * ans;
        ans = NULL;
        
        ListNode * temp;
        ListNode * prev;
        temp = NULL;
        prev = NULL;
        int pos;
        
        while(true)
        {
            temp = NULL;
            
            for(int i=0;i<n;i++)
            {
                if(head[i] == NULL)
                    continue;
   
                if(temp == NULL){
                    temp = head[i];
                    pos = i;
                }
                else
                {                    
                    if(temp->val > head[i]->val)
                    {
                        temp = head[i];
                        pos = i;
                    }
                }
            }
            
            if(temp == NULL)
            {
                if(prev != NULL)                
                    prev->next = NULL;
                break;
            }
            
            if(ans == NULL)
                ans = temp;
            else
                prev->next = temp;
            
            prev = temp;
            if(head[pos]!=NULL)
                head[pos] = head[pos]->next;
        }
        
        return ans;
    }
};