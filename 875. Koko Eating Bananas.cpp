class Solution {
public:
    //TC O(n*log(r))
    //SC O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mx=0;
        for(int i=0;i<n;i++) mx=max(mx,piles[i]);
        int l=1,r=mx;
        int ans=mx;
        while(l<=r){
            int mid=(l+r)/2;
            int curr=0;
            for(int i=0;i<n;i++){
                curr+=piles[i]/mid;
                if(piles[i]%mid>0) curr++;
            }
            if(curr<=h){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
