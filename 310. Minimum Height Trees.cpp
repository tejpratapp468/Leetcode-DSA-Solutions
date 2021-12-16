class Solution {
public:
    //Time Complexity O(N)
    //Space Complexity O(N)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        
        vector<int>degrees(n,0);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);//creating adjacent list
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++;//updating how many edges each node has
            degrees[edges[i][0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==1)//adding all the leave nodes
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
           vector<int> tmp;
            int s=q.size();
            while(s--)
            {
               int par=q.front();q.pop();
                tmp.push_back(par);
                for(auto child:adj[par])
                {
                    degrees[child]--;
                    if(degrees[child]==1) q.push(child);
                } 
            }      
            ans=tmp;
        }
        return ans;
    }
};

//Brute Force Solution
class Solution {
public:
    //Time Complexity O(N^2)
    //Space Complexity O(N)
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> adj[n];
        for(auto x:edges){ //creating graph
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int minHeight=1e5;
        vector<int> height(n,0);
        
        for(int i=0;i<n;i++){ //For n nodes
            //applying BFS with TC O(n)
            queue<int> q;q.push(i);
            vector<int> vis(n,0);vis[i]=1;
            int currHeight=0;
            while(!q.empty()){
                int s=q.size();
                currHeight++;
                while(s--){
                    int par=q.front();q.pop();
                    for(int child: adj[par]){
                        if(vis[child]==0)
                        {
                            q.push(child);vis[child]=1;
                        }
                    }
                }
            }
           minHeight=min(currHeight-1,minHeight);
            height[i]=currHeight-1;
        }
        
        for(int i=0;i<n;i++) {
            if(height[i]==minHeight) ans.push_back(i);
        }
        return ans;
    }
};
