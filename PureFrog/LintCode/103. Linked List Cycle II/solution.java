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
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    public ListNode detectCycle(ListNode head) {  
        if (head == null || head.next == null || head.next.next == null) 
            return null;

        ListNode prev = head.next.next;
        ListNode back = head.next;

        while (prev != back) {
            if (prev.next == null)
                return null;
            prev = prev.next;
            if (prev.next == null)
                return null;
            prev = prev.next;

            back = back.next;
        }
        ListNode entry = head;
        while (entry != prev) {
            prev = prev.next;
            entry = entry.next;
        }
        return entry;
    }
}

