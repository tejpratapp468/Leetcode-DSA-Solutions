//method 1
class Solution {
public:
    int dp[100];
    //Top down DP (rec+memo)
    //Tc O(n)
    //SC O(n)
    int helper(int idx,vector<int>& nums){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int op1=nums[idx]+helper(idx+2,nums); //rob
        int op2=helper(idx+1,nums); //not rob
        return dp[idx]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,nums);
        return ans;
    }
};

//method 2
class Solution {
public:
    //DP Bottom UP
    //Time Complexity O(n)
    //Space Complexity O(n)
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int dp[n];memset(dp,-1,sizeof(dp));
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int op1=nums[i]+dp[i-2];
            int op2=dp[i-1];
            dp[i]=max(op1,op2);
        }
        int ans=dp[n-1];
        return ans;
    }
};

//method 3 with optimization of space
class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(1)
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int incl=nums[0]; //index 0
        int excl=0;  //index 0
        for(int i=1;i<n;i++){
            int excl_new=max(incl,excl); //incl and excl of prev index
            incl=nums[i]+excl; //incl for curr index
            excl=excl_new; //excl for curr index;
        }
        int ans=max(incl,excl);
        return ans;
    }
};
