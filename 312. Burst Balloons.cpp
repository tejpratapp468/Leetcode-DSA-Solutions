class Solution {
public:
    //Time Complexity O(n*n*n)
    //Space Complexity O(n*n)
    int maxCoins(vector<int>& nums) {
        int n=nums.size();int s=n+2;
        vector<int> a(s,1);
        for(int i=1;i<=n;i++) a[i]=nums[i-1];
        int dp[s][s];
        memset(dp,0,sizeof(dp));
        for(int len=1;len<=n;len++)
        {
            for(int left=1;left<=n-len+1;left++)
            {
                int right=left+len-1; //left and right boundaries of current len
                for(int k=left;k<=right;k++)
                {
                    int val=a[left-1]*a[k]*a[right+1];
                    
                    dp[left][right]=max(dp[left][right],
                                        dp[left][k-1]+val+dp[k+1][right]);
                }
            }
        }

        return dp[1][n];
    }
};
