class Solution {
public:
    //TC O(n^2 + n^2) =O(n^2)
    //SC O(n^2)
 int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        int ans=0;
       unordered_map<int,int> mp;
        for(auto p:nums1){
             for(auto q:nums2){
                 mp[p+q]++;
             }
        }
        
        for(auto r:nums3)
        {
            for(auto s:nums4)
            {
                if(mp.count(-r-s))
                    ans+=(mp[-r-s]);
            }
        }
        return ans;
    }
};
