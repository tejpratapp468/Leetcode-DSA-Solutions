//Space optimized DP Solution
class Solution {
public:
    //Time Complexity O(m*n)
    //Space Complexity O(n) linear space 
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(); //m=no. of rows, n=no. of columns 
        vector<int> dp(n,0);
        vector<int> prev(n,0);
        int largest=0; //to store length of largest side of square
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                     if(i==0 || j==0) {
                         dp[j]=1;largest=max(largest,dp[j]);
                     }
                    else{
                        dp[j]=1+min({dp[j-1],prev[j-1],prev[j]});
                        largest=max(largest,dp[j]);
                    }
                }
                else{
                    dp[j]=0;
                }
            }
            prev=dp;
        }
        int area=largest*largest;
        return area;
    }
};

//DP solution with m*n (2-D) space and m*n time complexity
class Solution {
public:
    //Time Complexity O(m*n)
    //Space Complexity O(m*n)
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(); //m=no. of rows, n=no. of cols
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxsqlen=0; //to store length of maximum area square
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                     if(i==0 || j==0) {
                         dp[i][j]=1;
                         maxsqlen=max(maxsqlen,dp[i][j]);
                     }
                    else{
                        dp[i][j]=1+min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
                       maxsqlen=max(maxsqlen,dp[i][j]);
                    }
                }   
            }
        }
        int area=maxsqlen*maxsqlen;
        return area;
    }
};

//Brute force Solution
class Solution {
public:
    //Time Complexity O((m*n)^2) m=no. of rows, n=no. of cols
    //Space Complexity O(1)
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        int maxsqlen = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    int sqlen = 1;
                    bool flag = true;
					// check how many rows and columns that wrap this point.
                    while (sqlen + i < rows && sqlen + j < cols && flag) {
						// check a column for 1's
                        for (int k = j; k <= sqlen + j; k++) {
                            if (matrix[i + sqlen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
						// check a row for 1's
                        for (int k = i; k <= sqlen + i; k++) {
                            if (matrix[k][j + sqlen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            sqlen++;
                    }
                    if (maxsqlen < sqlen) {
                        maxsqlen = sqlen;
                    }
                }
            }
        }
        int area =  maxsqlen * maxsqlen;
        return area;
    }
};
