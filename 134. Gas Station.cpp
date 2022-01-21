class Solution {
public:
    //Time Complexity O(n+n+n) = O(n)
    //Space Complexity O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int avail=0,req=0;
        for(auto &x:gas) avail+=x;
        for(auto &x:cost) req+=x;
        if(avail<req) return -1;
        
        int ans=0, curr=0;
        for(int i=0;i<n;i++){
            curr+=gas[i];
            curr-=cost[i];
            if(curr<0){
                curr=0;
                ans=i+1;
            }
        }
        return ans;
    }
};
