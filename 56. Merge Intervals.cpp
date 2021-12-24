class Solution {
public:
    //TC O(nlogn + n) =O(nlogn)
    //SC O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end()); //start value basis sort
        
        int start=intervals[0][0], end=intervals[0][1];
        for(int i=1;i<n;i++){
            int currStart=intervals[i][0], currEnd=intervals[i][1];
            if(currStart<=end){
                end=max(end,currEnd);
            }
            else{
                ans.push_back({start,end});
                start=currStart, end=currEnd;
            }
        }
        ans.push_back({start,end});
        
        return ans;
    }
};
