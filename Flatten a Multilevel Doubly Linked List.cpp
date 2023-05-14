/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node *flat(Node *head) {
        if (head == NULL)
            return head;

        if (head->child == NULL && head->next == NULL)
            return head;

        if (head->child != NULL) {
            if (head->next != NULL) {
                Node *tempNext = head->next;
                Node *tempChild = head->child;
                head->child = NULL;
                head->next = tempChild;
                tempChild->prev = head;

                // Node* lastNode = flat(tempChild)
                tempNext->prev = flat(tempChild);
                tempNext->prev->next = tempNext;

                return flat(tempNext);
            } else {
                Node *tempChild = head->child;
                head->child = NULL;
                head->next = tempChild;
                tempChild->prev = head;
                return flat(tempChild);
            }
        }
        return flat(head->next);
    }

    Node *flatten(Node *head) {
        flat(head);

        Node *temp = head;
        while (temp != NULL) {
            temp->child = NULL;
            cout << temp->val << " ";
            temp = temp->next;
        }

        return head;
    }
};
