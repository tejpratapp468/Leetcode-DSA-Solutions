class Solution {
public:
     
    //Tc O(n)   n=number of nodes
    //SC O(L) + O(h) h=height of tree, L=length of our path from source to destination
    bool Path(int dest,TreeNode *root,string &ans)
    {
        if(root==NULL) return false;
        if(root->val==dest)
        {
            return true;
        }
        ans.push_back('L');
        bool l = Path(dest,root->left,ans);
        if(!l)
        {
            ans.pop_back();
        }
        else return true;
        ans.push_back('R');
        bool r = Path(dest,root->right,ans);
        if(!r)
        {
            ans.pop_back();
        }
        else return true;
        return false;
    }

     TreeNode* lca(TreeNode* root, int a, int b) {
        if(root==NULL) return NULL;
        if(root->val==a || root->val==b) return root;
        TreeNode *left = lca(root->left,a,b);
        TreeNode *right = lca(root->right,a,b);
        if(left&&right) return root;
        if(left) return left;
        return right;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *LCA = lca(root,startValue,destValue);
        string L="";
        string R="";
        Path(startValue,LCA,L);
        Path(destValue,LCA,R);
        for(char& c:L) c='U';
        return L+R;
    }
};


//BFS Approach giving Memory Limit Exceeded(MLE)
class Solution {
public:
  //Time Complexity O(n)  n=number of nodes
  //Space Complexity O(n*L) L=length of our path from source to destination
    unordered_map<TreeNode*,TreeNode*> par;
    TreeNode *start, *dest;
    void dfs(TreeNode* root,TreeNode* parent,int startValue,int destValue){
        if(!root) return;
        if(root->val==startValue){
            start=root;
        }
        else if(root->val==destValue){
            dest=root;
        }
        par[root]=parent;
        dfs(root->left,root,startValue,destValue);
        dfs(root->right,root,startValue,destValue);
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        dfs(root,NULL,startValue,destValue);
        unordered_set<TreeNode*> vis;
        queue<pair<TreeNode*,string>> q;
        string s="";
        q.push({start,s});vis.insert(start);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto tp=q.front();q.pop();
                string ans=tp.second;
                auto node=tp.first;
                if(node==dest) return ans;
                if(par[node]!=NULL && vis.count(par[node])==0){
                    vis.insert(par[node]);
                    ans.push_back('U');
                    q.push({par[node],ans});
                    ans.pop_back();
                }
                if(node->left && vis.count(node->left)==0){
                    vis.insert(node->left);
                    ans.push_back('L');
                    q.push({node->left,ans});
                    ans.pop_back();
                }
                if(node->right && vis.count(node->right)==0){
                    vis.insert(node->right);
                    ans.push_back('R');
                    q.push({node->right,ans});
                    ans.pop_back();
                }
            }
        }
       
        return s;
    }
};
