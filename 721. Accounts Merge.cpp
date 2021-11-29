//Method 1 DFS Solution
class Solution {
public:
    unordered_map<string,vector<string>> adj; //graph
    unordered_set<string> visited;
    
    void dfs(string& src,vector<string>& mergedAccounts){
        visited.insert(src);
        mergedAccounts.push_back(src);
        for(auto& x:adj[src]){
            if(visited.count(x)==0){
                dfs(x,mergedAccounts);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++){
            string firstEmail=accounts[i][1];
            
            for(int j=2;j<accounts[i].size();j++){
                string email=accounts[i][j];
                adj[firstEmail].push_back(email);
                adj[email].push_back(firstEmail);
            }
        }
        
        for(int i=0;i<n;i++){
            string accName=accounts[i][0];
            
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                
                if(visited.find(email)==visited.end()){
                    vector<string> mergedAccounts;
                    dfs(email,mergedAccounts);
                    sort(mergedAccounts.begin(), mergedAccounts.end());
                    mergedAccounts.insert(mergedAccounts.begin(),accName);
                    ans.push_back(mergedAccounts);
                }
            }
        }
       return ans;
    }
};

/*
• Time complexity: O(NK * log{NK})
Here N is the number of accounts and K is the maximum length of an account.
In the worst case, all the emails will end up belonging to a single person. The total number of emails will be N*K, and we need to sort these emails,O(logNK). DFS traversal will take NK operations as no email will be traversed more than once.

• Space complexity: O(NK)
Building the adjacency list will take O(NK) space. In the end, visited will contain all of the emails hence it will use O(NK) space. Also, the call stack for DFS will use O(NK)space in the worst case.

*/


//Method 2 DSU Union-Find Solution
class Solution {
    vector<int> par;
    
    int find(int nodeid) { 
        // par[nodeid] = nodeid is the leader, representative of the group
        if (par[nodeid] != nodeid)
            par[nodeid] = find(par[nodeid]);  // set the ancestor
        
        return par[nodeid];
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        par = vector<int>(n); 
        unordered_map<string, int> em2id;  // email to union-find id, so we can easily group it
        
        for (int i = 0; i < n; ++i) {
            par[i] = i;  // init union-find
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (em2id.find(accounts[i][j]) != em2id.end())  // this email already seen, so union this i with previous seen
                    par[find(em2id[accounts[i][j]])] = find(i);
                else  // this email not seen, we set it point to parent of i
                    em2id[accounts[i][j]] = par[i];
            }
        }
        
        unordered_map<int, vector<string>> newaccs;
        for (auto &e: em2id)  // group by union-find set
            newaccs[find(e.second)].push_back(e.first);
        
        vector<vector<string>> res;  // construct result
        for (auto &a: newaccs) {
            auto &emails = a.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[a.first][0]);
            res.emplace_back(emails);
        }
        return res;
    }
};



/*
• Time complexity: O(NK * log{NK})
Here N is the number of accounts and K is the maximum length of an account.
In the worst case, all the emails will end up belonging to a single person. The total number of emails will be N*K, and we need to find their parents, thia will takeO(logNK). The total number of emails will be N*K, and we need to sort these emails,O(logNK)

Space complexity: O(NK)

parents array, size store information corresponding to each group so will take O(N) space. All emails get stored in emailGroup and component hence space used is O(NK).
*/



