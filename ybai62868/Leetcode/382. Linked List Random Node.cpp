/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode * hd;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head):hd(head) {
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode * node = hd;
        int cnt = 0, randVal = 0;
        while ( node ) {
            if ( rand()%(++cnt) == 0 ) randVal = node->val;
                node = node->next;
        }
        return randVal;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
