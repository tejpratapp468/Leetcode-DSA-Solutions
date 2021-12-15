
class Solution {
public:
    //n=number of nodes
    //Time Complexity O(n^2)
    //Space Complexity O(1)
    ListNode* insertionSortList(ListNode* head) {
        if( head == NULL ){
			return head;
		}
		
		ListNode* helper = new ListNode(-5001); //new starter of the sorted list
		ListNode* curr = head; //the node will be inserted
		ListNode* pre = helper; //insert node between pre and pre.next
		ListNode* next = NULL; //the hold address of next node 
		
		while( curr != NULL ){//not the end of input list
			next = curr->next;
			//find the right place to insert
			while( pre->next != NULL && pre->next->val < curr->val ){
				pre = pre->next;
			}
			//insert between pre and pre.next
			curr->next = pre->next;
			pre->next = curr;
			pre = helper;
			curr = next;
		}
		
		return helper->next;   
    }
};
