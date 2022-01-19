
// 142. Linked List Cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *, bool> mp;
        ListNode * temp = head;
        while(temp!=NULL && mp.find(temp)==mp.end())
        {
            mp[temp] = true;
            temp = temp->next;
        }
        return temp;
    }
};
