// https://leetcode.com/problems/copy-list-with-random-pointer/
// 138. Copy List with Random Pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * headNew = new Node(0);
        Node * index = headNew;
        Node * temp = head;
        map<Node *,Node *> mp;
        
        while(temp)
        {
            index->next = new Node(temp->val);
            index = index->next;
            mp[temp] = index;
            temp = temp->next;
        }
        
        temp = head;
        index = headNew->next;
        while(temp)
        {
            if(temp->random)
                index->random = mp[temp->random];
            index = index->next;
            temp = temp->next;
        }
        
        return headNew->next;
    }
};
