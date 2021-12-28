//method 1 slow & fast pointe solution
class Solution {
public:
    //TC O(n/2) => O(n) //one pass
    //SC O(1)
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;//1 step;
            fast=fast->next->next; //2 step
        }
        ListNode* ans=slow;
        return ans;
    }
};

//method 2 two pass solution O(n) time & O(1) space
class Solution {
public:
    //SOlution by two passes
    //TC O(n+n) = O(n)
    //SC O(1)
    ListNode* middleNode(ListNode* head) {
        int len=0;
        ListNode* tmp=head;
        while(tmp){
            len++;tmp=tmp->next;
        }
        int req=(len+1)/2;
        if(len%2==0) req++;
        int currPos=1;
        tmp=head;
        while(currPos<req){
            tmp=tmp->next;
            currPos++;
        }
        ListNode* ans=tmp;
        return ans;
    }
};

//method 3 Basic method O(n) time & O(n) space
class Solution {
public:
    //TC O(n)
    //SC O(n)
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> v;
        while(head){
            v.push_back(head);
            head=head->next;
        }
        int n=v.size();
        ListNode* ans=v[n/2];
        return ans;
    }
};
