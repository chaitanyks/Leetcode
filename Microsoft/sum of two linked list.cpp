class Solution {
public:

    Node *reverse(Node *first) {
        if (first->next != NULL) {
            Node *head = reverse(first->next);
            first->next->next = first;
            first->next = NULL;
            return head;
        }

        return first;
    }

    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second) {
        // code here
        Node *ans = NULL;
        Node *temp = NULL;
        //reveres
        Node *ifirst = reverse(first);
        Node *isecond = reverse(second);
        int c = 0;
        int v1 = 0;
        int v2 = 0;
        int sum = 0;
        while (ifirst != NULL || isecond != NULL) {
            v1 = ifirst ? ifirst->data : 0;
            v2 = isecond ? isecond->data : 0;
            // cout<<v1<<" "<<v2<<endl;
            sum = v1 + v2 + c;
            c = sum >= 10 ? 1 : 0;
            int x = sum % 10;
            Node *node = new Node(x);
            sum = sum / 10;
            if (ans == NULL) {
                ans = node;
                temp = node;
            } else {
                temp->next = node;
                temp = node;
            }

            ifirst = ifirst ? ifirst->next : ifirst;
            isecond = isecond ? isecond->next : isecond;
        }
        while (sum != 0) {
            int x = sum % 10;
            Node *node = new Node(x);
            sum = sum / 10;
            temp->next = node;
            temp = node;
        }

        return reverse(ans);
    }
};
