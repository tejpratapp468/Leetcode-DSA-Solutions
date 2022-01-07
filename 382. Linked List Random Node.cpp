//O(1) Space & O(1) Time
class Solution {
public:
    //TC O(N), N=number of nodes
    //SC O(1)
    ListNode* h;
    Solution(ListNode* head) {
        h=head;
    }
    
    int getRandom() {
        ListNode* tmp=h;
        int len=0, res;
        while(tmp){
            len++;
            if(rand() % len == 0){ //note check rand(0%len==len-1)
                res = tmp->val;
            }
            tmp = tmp->next;
        }
        return res;
    }
};

//O(N) Spac & O(N) time
class Solution {
public:
    //TC O(N)
    //SC O(N)
    vector<int> values;
    Solution(ListNode* head) {
        ListNode*curr=head;
        while(curr){
            values.push_back(curr->val);curr=curr->next;
        }
    }
    
    int getRandom() {
        int n=values.size();
        int pos=rand()%n; // 0-n-1
        int ans=values[pos];
        return ans;
    }
};
