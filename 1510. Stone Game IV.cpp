class Solution {
public:
    //TC O(n*sqrt(n))
    //SC O(n)
    bool winnerSquareGame(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k*k<=i;k++)
            {
                if(dp[i-k*k]==0)
                {
                    dp[i]=1;break;
                }
            }
        }
      
        return dp[n];
    }
};
