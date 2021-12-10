//Bottom up DP
class Solution {
public:
    //bottom up
    //Time Complexity O(n)
    //Space Complexity O(n)
    int numTilings(int n) {
        int mod=1e9 + 7;
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1,dp[1]=1,dp[2]=2,dp[3]=5;
        for(int i=4;i<=n;i++) {
            dp[i]=((2*dp[i-1])%mod+dp[i-3])%mod;
        }
        return dp[n];
    }
};


//Space Optimized SOlution
class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(1)
    int numTilings(int n) {
        int mod=1e9 + 7;
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        int p1=5,p2=2,p3=1,ans;
        for(int i=4;i<=n;i++) {
            ans=((2*p1)%mod+p3)%mod;
            p3=p2,p2=p1,p1=ans;
        }
        return ans;
    }
};
