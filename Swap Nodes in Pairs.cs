https://leetcode.com/problems/swap-nodes-in-pairs/
24. Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        if(head == null || head.next == null)
            return head;
        
        ListNode temp1 = head;
        ListNode temp2 = head.next;
        
        temp1.next = SwapPairs(temp2.next);
        temp2.next = temp1;
        
        return temp2;
    }
}
