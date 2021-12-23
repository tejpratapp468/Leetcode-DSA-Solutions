class Solution {
public:
    //V= number of courses , E=number of edges
    //TC O(V+E ) =complexity of BFS
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> in(n,0);
        for(auto& p:pre){
            adj[p[1]].push_back(p[0]); //p=[a,b]
            in[p[0]]++;
        }
        queue<int> q;
        vector<int> top;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int tp=q.front();q.pop();
            for(auto& x:adj[tp]){
                in[x]--;
                if(in[x]==0) q.push(x);
            }
            top.push_back(tp);
        }
        if(top.size()!=n){
            vector<int> v;return v;
        }
        return top;
    }
};
