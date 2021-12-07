//optimised code 
class Solution {
public:
    //Time Complexity O(n) n=number of nodes
    //Space Complexity O(1)
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=NULL)
        {
            ans=ans<<1; //ans=ans*2;
            ans+=head->val;
            head=head->next;
        }
        
        return ans;
    }
};

//Basic Code
class Solution {
public:
    //Time Complexity O(n) n=number of nodes
    //Space Complexity O(n)
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);head=head->next;
        }
        //reverse(v.begin(),v.end());
        int ans=0;int p=1;
        while(!v.empty()){
           if(v.back()==1) {
               ans+=p; //left shift: (1<<i)= 1*pow(2,i)   //right shift: (1>>i)= 1/pow(2,i);
           } 
            p*=2;
            v.pop_back();
        }
        return ans;
    }
};
