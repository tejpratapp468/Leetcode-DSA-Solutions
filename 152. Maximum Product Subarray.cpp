//optimal Solution
class Solution {
public:
    //TC O(n)
    //SC O(1)
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],maxVal=nums[0],minVal=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0) swap(maxVal,minVal);
            maxVal=max(nums[i],maxVal*nums[i]);
            minVal=min(nums[i],minVal*nums[i]);
            ans=max(ans,maxVal);
        }
        return ans;
    }
};


//Brute Force Solution 
class Solution {
public:
    //Time Complexity O(n*n)
    //Space Complexity O(1)
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=0;i<n;i++){
            int prod=1;
            for(int j=i;j<n;j++){
                prod=prod * nums[j];
                ans=max(ans,prod);
            }
        }
        return ans;
    }
};
