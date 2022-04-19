//DFS
//TC O(V+E) V=n, E=n-1
//SC O(V+E)
class Solution {
public:
    int res=0;
    int helper(int src,vector<int> adj[],string& s)
    {
        int ans = 1;
        int mx1=0,mx2=0;
        for(auto v:adj[src])
        {
            int p = helper(v,adj,s);
            if(s[src]!=s[v]) {
                if(p>mx1){
                    mx2=mx1; mx1=p;
                } 
                else if(p>mx2){
                    mx2=p;
                }
            }
        }
        res = max(mx1+1+mx2,res);
        return 1+mx1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<int> adj[n+1];
        res = 0;
        for(int i=1;i<n;i++)
        {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }
        helper(0,adj,s);
        return res;
    }
};
