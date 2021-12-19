Find Easy Explanation for LIS in O(nlogn) time: https://youtu.be/8FJlFKz80Tg

class Solution {
public:
    //TC O(nlogn)
    //SC O(n)
      int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;v.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=v.back()) v.push_back(nums[i]);  // Append to LIS if new element is >= last element in LIS
            else{
                int idx=upper_bound(v.begin(),v.end(),nums[i])-v.begin(); //Find the index of the smallest number > x
                v[idx]=nums[i]; // Replace that index number with nums[i]
            }
        }
        return v.size();
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int ans=0;
        int n=arr.size();
        
        for(int i=0;i<k;i++){
            vector<int> tmp;
            for(int j=i;j<n;j+=k) tmp.push_back(arr[j]);
            int curr=lengthOfLIS(tmp);
            ans+=(tmp.size()-curr);
        }

        return ans;
    }
};
