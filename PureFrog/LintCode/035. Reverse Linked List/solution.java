/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The head of linked list.
     * @return: The new head of reversed linked list.
     */
    public ListNode reverse(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode fir = head, sec = head.next;
        head.next = null;
        while (sec != null) {
            ListNode nextNode = sec.next;
            sec.next = fir;
            fir = sec;
            sec = nextNode;
        }
        return fir;
    }
}


