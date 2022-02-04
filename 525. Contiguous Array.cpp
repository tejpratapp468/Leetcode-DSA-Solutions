//Optimal Solution
class Solution {
public:
    //TC O(n+n) =O(n)
    //SC O(n)
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) if(nums[i]==0) nums[i]=-1;
        int ans=0;
        unordered_map<int,int>  mp;
        int curr=0;
        for(int i=0;i<n;i++) {
            curr+=nums[i];
            if(curr==0) ans=i+1;
            if(mp.count(curr)){
                ans=max(ans,i-mp[curr]);
            } 
           else mp[curr]=i;
        }
        return ans;
    }
};


//Basic Solution
class Solution {
public:
  //TC O(n*n)
  //SC O(1)
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int start=0;start<n;start++){
            int one=0,zero=0;
            for(int end=start;end<n;end++){
                if(nums[end]==1) one++;
                else zero++;
                if(one==zero) ans=max(ans,end-start+1);
            }
        }
        return ans;
    }
};
