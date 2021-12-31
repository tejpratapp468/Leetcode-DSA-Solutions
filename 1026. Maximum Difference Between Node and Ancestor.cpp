class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(h) h=height of tree, best case h=(logn), worst case h=n;
    int ans=0;
    void helper(TreeNode* root,int mx,int mn){
       if(!root) return;
        mx=max(root->val,mx);
        mn=min(root->val,mn);
        ans=max(ans,mx-mn);
        helper(root->left,mx,mn);
        helper(root->right,mx,mn);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int mx=-1e9,mn=1e9;
        helper(root,mx,mn);
        return ans;
    }
};
