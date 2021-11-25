//optimal solution
class Solution {
public:
    //TC O(n+m)
    //SC O(1)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int n=first.size(),m=second.size();
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<n && j<m){
            int start=max(first[i][0],second[j][0]);
            int end=min(first[i][1],second[j][1]);
            if(start<=end){
                ans.push_back({start,end});
            }
            if(first[i][1]<second[j][1]) i++;
            else j++;
        }
        return ans;
    }
};



//Brute force Solution
class Solution {
public:
    //TC O(n*m)
    //SC O(1)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second)     {
        int n=first.size(),m=second.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            int start=max(first[i][0],second[j][0]);
            int end=min(first[i][1],second[j][1]);
            if(start<=end){
                ans.push_back({start,end});
            }  
        }
      }
        return ans;
  }
};
