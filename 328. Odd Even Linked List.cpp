class Solution {
public:
    //Time Complexity O(n), n=number of nodes in List
    //Space Complexity O(1)
    ListNode* oddEvenList(ListNode* head) {
         if(head==NULL) return head;
        ListNode *odd=head, *even=head->next, *evenHead=head->next;
        while(even && even->next){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};
