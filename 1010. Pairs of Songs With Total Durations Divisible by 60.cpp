class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(60) = constant space
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        int ans=0;
        int cntRem[60];memset(cntRem,0,sizeof(cntRem));
        for(int x:time){
            int rem=x%60;
            if(rem==0) ans+=cntRem[0];
            else ans+=cntRem[60-rem];
            cntRem[rem]++;
        }
        return ans;
    }
};
