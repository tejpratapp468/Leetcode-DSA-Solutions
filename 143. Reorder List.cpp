class Solution {
public:
    //Time Complexity O(n + n + n) = O(n)
    //Space Complexity O(1)
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        //solution in three steps
        //step 1: divide list in two equal halves
        ListNode* slow=head,*fast=head, *prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        
        //step 2: Reverse second half
        ListNode* l2=reverseList(slow);
        ListNode* l1=head;
        
        //step 3 merge two lists l1 and l2;
        while(l1!=NULL && l2!=NULL){
            ListNode *n1=l1->next, *n2=l2->next;
            l1->next=l2;
            if(n1==NULL) break;
            l2->next=n1;
            
            l1=n1;
            l2=n2;
        }
    }
    
    ListNode* reverseList(ListNode* head) { //TC O(N) N=number of nodes
        ListNode *curr=head, *prev=NULL, *next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
         }
        return prev;
    }
    
};
