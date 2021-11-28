//optimal Solution 
class Solution {
public:
    //TC O(n)
    //SC O(1)
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int cnt=0,sm=0;; 
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) cnt++;
            else if(nums[i]<target) sm++;
        }
        for(int i=sm;i<sm+cnt;i++){
            ans.push_back(i);
        }
        return ans;
    }
};

//Naive Solution
class Solution {
public:
    //TC O(nlogn)
    //SC O(1)
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) ans.push_back(i);
        }
        return ans;
    }
};
