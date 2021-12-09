/* Guys Make this a Rule whenever You have to find whether you can reach a particular indexor not then use either BFS or DFS */

//BFS Solution
class Solution {
public:
    //Algo: BFS
    //Time Complexity O(n)
    //Space Complexity O(n)
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        vector<int> vis(n,0);
        q.push(start);vis[start]=1;
        while(!q.empty()){
            int f=q.front();q.pop();
            if(arr[f]==0) return 1; // we reach an index with value 0.
    
            int back=f-arr[f],front=f+arr[f];
            if(back>=0 && vis[back]==0) {
                q.push(back);vis[back]=1;
            }
            if(front<n && vis[front]==0) {
                q.push(front);vis[front]=1;
            }
        }
        return 0;
    }
};


//DFS Solution
class Solution {
public:
    //Algo: DFS
    //Time Complexity O(n)
    //Space Complexity O(n)
    vector<int> vis;
    bool helper(int idx, vector<int>& arr){
        if(idx<0 || idx>=arr.size()) return 0; //outside array
        if(vis[idx]==1) return 0;
        if(arr[idx]==0) return 1;
        vis[idx]=1;
        bool op1=helper(idx-arr[idx],arr); //left jump
        bool op2=helper(idx+arr[idx],arr); //right  jump
        if(op1 || op2) return 1;
        return 0;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vis.resize(n,0);
        bool ans=helper(start,arr);
        return ans;
    }
};
