//method 1  //sorting + 1 traversals
class Solution {
public:
    //sorting + 1 traversals
    //Time Complexity O(nlogn + n ) => O(nlogn)
    //Space Complexity O(1)
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>> ans;
        int n=a.size();
        sort(a.begin(),a.end());
        int minDiff=1e9;
        for(int i=1;i<n;i++) {
            int currDiff=a[i]-a[i-1];
            if(currDiff==minDiff)ans.push_back({a[i-1],a[i]});
            else if(currDiff<minDiff){
                minDiff=currDiff;
                ans.clear();
                ans.push_back({a[i-1],a[i]});
            }
        }
        
        return ans;
    }
};

//method 2  //sorting + 2 traversals
class Solution {
public:
    //sorting + 2 traversals
    //Time Complexity O(nlogn + n + n) => O(nlogn)
    //Space Complexity O(1)
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>> ans;
        int n=a.size();
        sort(a.begin(),a.end());
        int minDiff=1e9;
        for(int i=1;i<n;i++) {
            minDiff=min(minDiff,a[i]-a[i-1]);
        }
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]==minDiff) ans.push_back({a[i-1],a[i]});
        }
        return ans;
    }
};


//method 3 bri=ute force solution
class Solution {
public:
    //Brute force Solution
    //Time Complexity O(n*n + nlogn)
    //Space Complexity O(1)
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>> ans;
        int n=a.size();
        int minDiff=1e9;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++){
                minDiff=min(minDiff,abs(a[i]-a[j]) );
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                  if(abs(a[i]-a[j])==minDiff){
                      int x=min(a[i],a[j]), y=max(a[i],a[j]);
                      ans.push_back({x,y});
                  }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
