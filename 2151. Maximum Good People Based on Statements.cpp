class Solution {
public:
    //TC O(2^n * (n^2))
    //SC O(n)
    int n, ans = 0;
    int maximumGood(vector<vector<int>>& st) {
        n = st.size();
        vector<int> cur;
        int good=0;
        dfs(st, cur, 0, good);
        return ans;
    }
    
    void dfs(vector<vector<int>>& st, vector<int>& cur, int i, int good) {
        if(i == n) {
            if(valid(st, cur)) { // if valid, update ans to store maximum good person found till now
                ans = max(ans, good);
            }
            return;
        }
        cur.push_back(0);
        dfs(st, cur, i+1, good);        // assuming ith person is bad
        cur.pop_back(); //backtrack
        
        cur.push_back(1);
        dfs(st, cur, i+1, good + 1);    // assuming ith person is good
        cur.pop_back();   //backtrack     
    }
    
    bool valid(vector<vector<int>>& st, vector<int>& cur) {
        for(int i = 0; i < n; i++) {
             if(cur[i] == 1) {
                  for(int j = 0; j < n; j++){
                      if(st[i][j] != 2 && st[i][j] != cur[j] ) return false; //our current assignment of good and bad person is not valid
                  }
             }
        }
        return true; //our current assignment of good and bad person is valid
    }
};
