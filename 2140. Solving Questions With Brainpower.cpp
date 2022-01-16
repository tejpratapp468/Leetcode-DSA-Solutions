class Solution {
public:
    #define ll long long
    //TC O(n)
    //O(n+n) =O(n)
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<ll> profit(n),rightMax(n);
        
        profit[n-1]=q[n-1][0];
        rightMax[n-1]=profit[n-1];
        ll ans=profit[n-1];
    
        for(int i=n-2;i>=0;i--){ // [points,nextSkip]
            profit[i]=q[i][0];
            ll next=i+q[i][1]+1;
            if(next<n) profit[i]+=rightMax[next];
            ans=max(ans,profit[i]);
            rightMax[i]=max(rightMax[i+1],profit[i]);

        }
        
        return ans;
    }
};
