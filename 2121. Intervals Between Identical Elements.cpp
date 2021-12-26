//Optimal Approach
class Solution {
public:
    //TC O(n+n) =O(n)
    //SC O(n)
    #define ll long long
    vector<ll> getDistances(vector<int>& a) {
        ll n = a.size();
        vector<ll> ans(n,0);
        unordered_map<ll,pair<ll,ll>> left; //pair<ll,ll> => {count,sum}
        for(int i = 0;i<n;i++) //left-right
        {
            ll leftCount=left[a[i]].first; //count of current elememt left to current index
            ll leftSum=left[a[i]].second;  //sum of indexes of current elemet left to current index 
            ans[i] = leftCount*i - leftSum;
            left[a[i]].first+=1; //leftCount of current eleemnt increases by 1
            left[a[i]].second+=i; //leftSum of indexes for current element increases by current index
        }

        unordered_map<ll,pair<ll,ll>> right; //pair<ll,ll> => {count,sum}
        for(int i=n-1;i>=0;i--) //right ->left
        {
            ll rightCount=right[a[i]].first; //count of current elememt right to current index
            ll rightSum=right[a[i]].second;  //sum of indexes of current elemet right to current index 
            ans[i] += rightSum - rightCount*i;
            right[a[i]].first+=1;  //rightCount of current element increases by 1
            right[a[i]].second+=i;  //rightSum of indexes for current element increases by current index
        }
        return ans;
    }
};


//Brute force solution
class Solution {
public:
    //TC O(n*n)
    //SC O(1)
    #define ll long long
    vector<ll> getDistances(vector<int>& a) {
        ll n = a.size();
        vector<ll> ans(n,0);
        for(int i=0;i<n;i++){
            ll curr=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(a[i]==a[j]){
                    curr+=abs(i-j);
                }
            }
            ans[i]=curr;
        }
        return ans;
    }
};
