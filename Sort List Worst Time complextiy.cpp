// https://leetcode.com/problems/sort-list/
// 148. Sort List

static auto _speedupMagic = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

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
    
    ListNode * quickSortUtils(ListNode * head,ListNode *low,ListNode *high){
        
        ListNode * temp = low;
        while(temp->next!=high)
            temp = temp->next;
        
        ListNode * pivot = temp;
        int val = pivot->val;
        ListNode * index = low;
        
        temp = low;
        
        while(temp!=high)
        {
            if(pivot->val>temp->val)
            {
                int val = temp->val;
                temp->val = index->val;
                index->val = val;
                index = index->next;
            }
            temp = temp->next;
        }
        
//         if(index==low && low!=high)
//         {
//             ListNode * local = index;
//             int value = index->val;
            
//             while(local->next!=NULL) {
//                 int lv = local->next->val;
//                 local->next->val = value;
//                 value = lv;
//                 local = local->next;
//             }
//             index->val = value;
//         }
//         else
//         {
               
//         }
        pivot->val = index->val;
        index->val = val;
        return index;
    }
    
    void print(ListNode * head) {
        while(head!=NULL) {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    
    bool checkSort(ListNode * head) {
        bool check = true;
        
        while(check && head->next != NULL)
        {
            if(head->val>head->next->val)
                check = false;
            head=head->next;
        }
        
        return check;
    }
    
    void quickSort(ListNode *head,ListNode * low, ListNode *high) {
        // cout<<li<<" "<<hi<<endl;
        if(low!=high) {
            // cout<<li<<" "<<hi<<endl;
            ListNode * pivot = quickSortUtils(head,low,high);
            
            // cout<<pivot->val<<" "<<endl;
            // print(head);
            
            // ListNode * temp = low;
            // ListNode * prev = low;
            // int pindex = li;
            // // cout<<temp->val<<endl;
            // while(temp!=NULL && temp!=pivot && pindex<hi)
            // {
            //     prev = temp;
            //     temp = temp->next;
            //     pindex++;
            // }
            // cout<<prev->val<<endl;
            
            if(!checkSort(head)) {
                quickSort(head,low,pivot);
            }
            
            if(!checkSort(head)) {
                quickSort(head,pivot->next,high);
            }
            
                
        }
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        
        ListNode * first = new ListNode(-100001);
        first->next = head;
        
//         ListNode * temp = new ListNode(-100001);
//         temp->next = head;
        
//         ListNode * curr = head;
//         ListNode * prev = temp;
        
//         while(curr!=NULL)
//         {
//             ListNode * i = curr;
//             ListNode * index = i;
            
//             while(i!=NULL) {
//                 if(i->val < index->val)
//                     index = i;
//                 i = i->next;
//             }
            
//             int val = curr->val;
//             curr->val = index->val;
//             index->val = val;
//             curr=curr->next;
//         }
        
        // ListNode * temp = head;
        // int li = 0;
        // int hi = 0;
        
        // while(temp->next!=NULL) {
        //     temp = temp->next;
        //     hi++;
        // }
        
        ListNode * temp = head;
        ListNode * prev = head;
        
        while(temp->next!=NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        
        if(temp->val < head->val)
        {
            prev->next = NULL;
            temp->next = head;
            head = temp;
            first->next = temp;
        }
                
        quickSort(head,head,NULL);
        return head;
    }
};
