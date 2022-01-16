
class Solution {
public: 
    //TC O(m*log(r-l) + m)
    //SC O(1)
    #define ll  long long
    long long maxRunTime(int n, vector<int>& arr){
        int m=arr.size();
        sort(arr.rbegin(),arr.rend());
        ll sum=0;
        for(ll x:arr) sum+=x;
        ll l=arr[n-1],r=sum/n,ans=1;
         
        while(l<=r){
            ll mid=(l+r)/2;
            ll need=n*mid;
            bool ok=1;
            ll curr=0;
            for(int i=0;i<m;i++){
                if(arr[i]>mid) curr+=mid;
                else curr+=(arr[i]);
            }
            
            if(curr>=need){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }        
        return ans;    
    }
};
