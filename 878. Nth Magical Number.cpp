//Optimal Binary Search Solution
class Solution {
public:
    //Binary Search
    //Time Complexity: O( log(n * min(a, b)) ).
    //Space Complexity: O(1).
    #define ll long long
    ll gcd(ll x, ll y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
    int nthMagicalNumber(int n, int a, int b) {
        ll l=min(a,b);
        ll r=(ll)n*min(a,b);
        ll lcm=(a*b)/gcd(a,b);   //gcd(a,b) = __gcd(a,b)
        ll ans=r;
        while(l<=r){
            ll mid=(l+r)/2;  
            ll curr=(mid/a)+(mid/b)-(mid/lcm);
            if(curr>=n){
                ans=mid;r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ll mod=1e9 + 7;
        ans=ans%mod;
        return ans;
    }
};

//Brute force solution
class Solution {
public:
//Time Complexity = O(n*min(a,b)); //O(10^14) //TLE
    //SPace Complexity O(1)
    #define ll long long
    int nthMagicalNumber(int n, int a, int b) {
        ll mx=(ll)n*min(a,b);
        ll ans=0,cnt=0;
        for(ll i=1;i<=mx;i++){
            if(i%a==0 || i%b==0) cnt++;
            if(cnt==n){
                ans=i;break;
            }
        }
        return ans;
    }
};
