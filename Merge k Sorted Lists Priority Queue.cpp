// https://leetcode.com/problems/merge-k-sorted-lists/
// 23. Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    ListNode*

    mergeKLists(vector<ListNode*>&lists) {
        int n = lists.size();
        priority_queue<pair<int, ListNode *>>pq;

        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL)
                pq.push({-lists[i]->val, lists[i]});
        }

        ListNode * ans = NULL;
        ListNode * prev = NULL;

        while (!pq.empty()) {
            ListNode * temp = pq.top().second;
            pq.pop();

            if (ans == NULL)
                ans = temp;
            else
                prev -> next = temp;

            prev = temp;
            if (temp -> next != NULL)
                pq.push({-temp -> next -> val, temp -> next});
        }

        return ans;
    }
};