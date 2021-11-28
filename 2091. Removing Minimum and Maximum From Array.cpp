class Solution {
public:
    #define ll long long
    //O(n)  TC
    //O(1)  SC
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int mx=-1e7,mn=1e7;
        for(auto x:nums) mx=max(mx,x),mn=min(mn,x);
        
        int mxIdx,mnIdx;
        for(int i=0;i<n;i++){
            if(nums[i]==mx) mxIdx=i;
            else if(nums[i]==mn) mnIdx=i;
        }
        int ans=0;
        int small=min(mxIdx,mnIdx),high=max(mxIdx,mnIdx);
        ans=(small+1)+(n-high); //option 1
        ans=min(ans,high+1); //option 2
        ans=min(ans,n-small);  //option 3
        return ans;
    }
};
