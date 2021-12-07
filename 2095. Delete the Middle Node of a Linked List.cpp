//solution using fast and slow pointer
class Solution {
public:
    //Time Complexity O(n) , n=number of nodes
    //Space Comlexity O(1)
     ListNode* deleteMiddle(ListNode* head){
        if(!head) return NULL;
        if(head->next==NULL) return NULL;
    
        ListNode *slow=head, *fast= head, *prev=0;
    
	     // Find middle Node 
          while (fast and fast->next){
              prev=slow;
              slow= slow->next; fast = fast->next->next ;
          }
    
	      //Deleting the mid using prev  
          prev->next = slow->next;
          return head;
    
     }
};

//Solution using two pass
class Solution {
public:
    //Time Complexity O(n) , n=number of nodes
    //Space Comlexity O(1)
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return NULL;
        if(head->next==NULL) return NULL;
        ListNode* curr=head;
        int cnt=0;
        while(curr){
            cnt++;curr=curr->next;
        }
        int req=cnt/2 ;
        int pos=0;curr=head;
        ListNode *prev=head;
        while(pos<=req-1){
            prev=curr;
            curr=curr->next;pos++;
        }
        prev->next=curr->next;
        return head;
    }
};
