//Optimal Solution
class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(1)
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],prev=nums[0];
        for(int i=1;i<n;i++)
        {
            int curr=nums[i];
            if(prev>0) curr+=prev;
            ans=max(ans,curr);
            prev=curr;
        }
        return ans;
    }
};


//Method 2
class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(n)
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        int ans=dp[0];
        
        for(int i=1;i<n;i++){
            dp[i]=nums[i];
            if(dp[i-1]>0) dp[i]+=dp[i-1];
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};


//Method3 Brute force Solution
class Solution {
public:
    //Time Complexity O(n*n)
    //Space Complexity O(1)
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=-1e9;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};
