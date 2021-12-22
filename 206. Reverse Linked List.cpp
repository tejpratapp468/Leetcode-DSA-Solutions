class Solution {
public:
  //Time Complexity O(N), N= number of nodes
    ListNode* reverseList(ListNode* head) {
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
