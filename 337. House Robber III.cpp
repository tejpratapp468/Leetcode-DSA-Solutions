class Solution {
public:
    //DP on trees
    //Time Complexity O(N) N=number of nodes
    //Space Complexity O(N)
    unordered_map<TreeNode*,int> mp;
    int helper(TreeNode* root){
       if(root==NULL) return 0;   
        if(mp.count(root)) return mp[root];
       //option 1: rob current node
        int op1=root->val;
        if(root->left) op1+=helper(root->left->left) + helper(root->left->right);
        if(root->right) op1+=helper(root->right->left) + helper(root->right->right);
        
        //option 2: not rob current node
        int op2=helper(root->left)+helper(root->right);
        
        return mp[root]=max(op1,op2);
    }
    
    int rob(TreeNode* root) {
       int ans=helper(root);
       return ans;
    }
};
