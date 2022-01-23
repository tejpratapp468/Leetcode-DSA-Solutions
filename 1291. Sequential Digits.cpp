class Solution {
public:
    //TC O(45)=constant time
    //SC O(45)=constant space
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for(int i=1;i<=9;i++) q.push(i);
        bool done=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--){
                int p=q.front();q.pop();
                if(p>=low && p<=high) ans.push_back(p);
                if(p>high) {
                    done=1;break;
                }
                int rem=p%10;
                if(rem<9)
                {
                    p=(p*10 + rem+1);
                    q.push(p);
                }
            } 
            if(done==1) break;
        }
        return ans;
    }
};
