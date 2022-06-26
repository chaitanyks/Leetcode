// https://leetcode.com/problems/linked-list-random-node/
// 382. Linked List Random Node

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
    vector<ListNode*>mp;

    Solution(ListNode*head) {
        while (head != NULL) {
            mp.push_back(head);
            head = head -> next;
        }
    }

    int getRandom() {
        int n = mp.size();
        int pos = rand() % n;
        return mp[pos]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
