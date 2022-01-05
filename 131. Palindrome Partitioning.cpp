class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> path;
        helper(0,path,s);
        return ans;
    }
    void helper(int idx,vector<string>& path,string& s){
        if(idx>=s.size()){
            ans.push_back(path);return;
        }
        for(int i=idx;i<s.size();i++){
            string curr=s.substr(idx,i-idx+1); //(start idx, length of substring)
            if(ispal(curr)){
                path.push_back(curr);
                helper(i+1,path,s);
                path.pop_back(); //backtracking
            }
        }
    }
    bool ispal(string& s){
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++,j--;
        }
        return 1;
    }
};




/*  Time Complexity
    # At each character we have 2 choices (except 1st character):
    # - Join with previous string & form a palindrome 
    # - start a new partition
    # For each choice, we need O(n) time to both: check if palindrome & slice substring
    # Together: O((n + n) * 2^(n-1)) -> O(2n * 2^(n-1)) -> O(n * 2^n)
    
    Space Complexity
    # O(n) Since we are using path vector which will store all characters of our string at a time and pushthem to our answer in the end.
*/




//Method 2 DP Solution
class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
        vector<string> path;
        Pal(s);
        dfs(0,path,s);
        return ans;
    }
    void dfs(int idx,vector<string>& path,string& s){
        if(idx>=s.size()){
            ans.push_back(path);return;
        }
        for(int i=idx;i<s.size();i++){
            if(dp[idx][i]){
                string curr=s.substr(idx,i-idx+1);
                path.push_back(curr);
                dfs(i+1,path,s);
                path.pop_back(); //backtrack
            }
        }
    }
    void Pal(string& s){
        int n=s.size();
        dp.resize(n,vector<bool>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(len==2 && s[i]==s[j]) dp[i][j]=1;
                else if(dp[i+1][j-1]==1 && s[i]==s[j]) dp[i][j]=1;
            }
        }
    }
};


/*  Time Complexity
    # O(n^2) to find all palindromic substrings
    # At each character we have 2 choicesb (except 1st character):
    # - Join with previous string & form a palindrome 
    # - start a new partition
    # For each choice, we need O(n) time to :  slice substring
    # Together: O((n^2) + (n * 2^(n-1)) -> O((n^2) + n* 2^(n-1)) -> O( n * 2^n)
    
    Space Complexity
    # O(n^2 + n) =>  (n^2 for dp vector, n for path vector)
*/
