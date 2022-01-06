class Solution {
public:
    //TC O(n+1000*2) =O(n+2000)
    //SC O(1002)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> passCnt(1002,0);
        for(int i=0;i<n;i++){
            int cnt=trips[i][0],from=trips[i][1],to=trips[i][2];
            passCnt[from]+=cnt;
            passCnt[to]-=cnt;
        }
        
        for(int i=1;i<=1000;i++) passCnt[i]+=passCnt[i-1]; //calculating prefix sum
        
        for(int i=0;i<=1000;i++){
            if(passCnt[i]>capacity) return 0;
        }
        return 1;
    }
};
