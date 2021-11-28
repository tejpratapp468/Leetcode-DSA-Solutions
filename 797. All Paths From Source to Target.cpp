class Solution {
public:
    //Time Complexity O(2^n)
    //Space Complexity O(n* 2^n)
    vector<vector<int>> ans;
    void helper(int src,int dest,vector<int>& path,vector<vector<int>>& graph){
        if(src==dest){
            ans.push_back(path);                
            return;
        }
      
        for(auto x:graph[src]){
            path.push_back(x);
            helper(x,dest,path,graph);
            path.pop_back();
        }  
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> path{0};
        helper(0,n-1,path,graph);
        return ans;
    }
};
