/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ( head->next==NULL ) return NULL;
        int size = 1;
        ListNode * temp = head;
        while ( temp->next!=NULL ) {
            size++;
            temp = temp->next;
        }
        temp = head;
        if ( size > n ) {
            for ( int i = 0;i < size-n-1;i++ ) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        else if ( size == n ) {
            head = head->next;
        }
        return head;
    } 
};
