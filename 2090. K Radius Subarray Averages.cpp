//optimal solution
class Solution {
public:
    #define ll long long
    //Time Complexity O(n)
    //Space Complexity O(n)
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<ll> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=nums[i]+pref[i-1];
        for(int i=0;i<n;i++){
            int lIdx=i-k,rIdx=i+k;
            if(lIdx<0 || rIdx>=n) continue;
            ll sum=pref[rIdx];
            if(lIdx>0) sum-=pref[lIdx-1];
            ans[i]=(sum)/(k+k+1);
        }
        return ans;
    }
};

//Brute force SOlution
class Solution {
public:
    #define ll long long
    //Time Complexity O(n*n)
    //Space Complexity O(1)
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int lIdx=i-k,rIdx=i+k;
            if(lIdx<0 || rIdx>=n) continue;
            ll sum=0;
            for(int j=lIdx;j<=rIdx;j++) sum+=nums[j];
            ans[i]=(sum)/(k+k+1);
        }
        return ans;
    }
};
