class Solution {
public:
    int dp[70][70][70] = {};
    int newCol1[3]={-1,0,1};
    int newCol2[3]={-1,0,1};
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return helper(grid, m, n, 0, 0, n - 1);
    }
    int helper(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
        if (r == m) return 0; // Reach to bottom row
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int cherries = 0; //cherries at present r,c1,c2
        if(c1==c2) cherries = grid[r][c1];
        else cherries = grid[r][c1]+grid[r][c2];
        
        int next = 0;
        for (int i = 0; i <=2; i++) { //col1-1,col1,col1+1
            for (int j = 0; j <= 2; j++) { //col2-1,col2,col2+1
                int nc1 = c1 + newCol1[i], nc2 = c2 + newCol2[j];
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    next = max(next, helper(grid, m, n, r + 1, nc1, nc2));
                }
            }
        }
        
        return dp[r][c1][c2] = next + cherries;
    }
};
/*   
Time Complexity: O(9 * m * n^2), where m is number of rows, n is number of cols of grid.
Explain: There are total m * n^2 states in dp, each state has 9 options to choose maximum.
Space Complexity: O(m * n^2)
*/
