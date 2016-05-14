/**
 * Definition for ListNode
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param ListNode head is the head of the linked list 
     * @oaram m and n
     * @return: The head of the reversed ListNode
     */
    public ListNode reverseBetween(ListNode head, int m , int n) {
        if (head == null || head.next == null || m == n)
            return head;

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode fir = dummy, sec = head;
        ListNode preNode = null, firstNode = null;
        for (int cnt = 1; cnt <= n && sec != null; ++cnt) {
            if (cnt < m) {
                fir = sec;
                sec = sec.next;
                continue;
            }
            if (cnt == m) {
                preNode = fir;
                firstNode = sec;
                fir = sec;
                sec = sec.next;
                continue;
            }
            ListNode nextNode = sec.next;
            sec.next = fir;
            fir = sec;
            sec = nextNode;
        }
        firstNode.next = sec;
        preNode.next = fir;
        return dummy.next;
    }
}
