class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode *head1,*head2;
       head1=head2=NULL;
       ListNode *cur1,*cur2;
       cur1=cur2=NULL;
       while(head){
        ListNode *cur=head;
        head=head->next;
        cur->next=NULL;
        if(cur->val<x){
            if(!head1){
                head1=cur;
                cur1=head1;
            }
            else{
                cur1->next=cur;   
                cur1=cur1->next;
            }
            
        }else{
            if(!head2){
                head2=cur;
                cur2=head2;
            }else{
                cur2->next=cur;
                cur2=cur2->next;
            }
        }
       }
        if(!cur1)
            return head2;
        cur1->next=head2;
        return head1;
    }
};
