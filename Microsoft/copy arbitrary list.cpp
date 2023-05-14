Node *copyList(Node *head) {
    //Write your code here
    map<Node *, Node *> mp;

    Node *second = NULL;\
        Node *node = new Node(head->data);
    second = node;
    Node *temp = head->next;
    Node *stemp = second;
    mp[head] = second;
    while (temp != NULL) {
        Node *node = new Node(temp->data);
        stemp->next = node;
        stemp = node;
        mp[temp] = node;
        temp = temp->next;
    }

    temp = head;
    stemp = second;
    while (temp != NULL) {
        stemp->arb = mp[temp->arb];
        temp = temp->next;
        stemp = stemp->next;
    }

    return second;
};
