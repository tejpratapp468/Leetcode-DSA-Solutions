//Top Down DP
class Solution {
public:
    //Top down DP (rec+memo)
    //n=200, req=10000
    //Time Compleity O(n*req) => O(200*10000)=O(2* 10^6)
    //space Complexity O(n*req)
    int dp[200][10001];
    bool helper(int idx,int currSum,int req,vector<int>& nums){
        if(idx>=nums.size()) return 0;
        if(currSum==req) return 1;
        if(currSum>req) return 0;
        if(dp[idx][currSum]!=-1) return dp[idx][currSum];
        bool op1=helper(idx+1,currSum+nums[idx],req,nums);//taken
        bool op2=helper(idx+1,currSum,req,nums); //not taken
        return dp[idx][currSum]=(op1 || op2);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return 0;
        int req=sum/2;
        int currSum=0;
        bool ans=helper(0,currSum,req,nums);
        return ans;
    }
};

//Bottom UP DP (2-D)Space
class Solution {
public:
    //bottom up
    //n=200, req=10000
    //Time Compleity O(n*req) => O(200*10000)=O(2* 10^6)
    //space Complexity O(n*req)
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return 0;
        int req=sum/2;
        int dp[n+1][req + 1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=1;j<=req;j++){
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];//not taken
                }
                else{
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][req];
    }
};


//Bottom up DP with optimized SPace
class Solution {
    public:
    //n=200, req=10000
    //Time Compleity O(n*req) => O(200*10000)=O(2* 10^6)
    //space Complexity O(req) //linear
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return 0;
        int req=sum/2;
        int dp[req+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=req;j>=nums[i];j--) dp[j]=dp[j] | dp[j-nums[i]];
        }
        return dp[req];
    }
};
