//optimal solution
class Solution {
public: 
    //time Complexity O(n) , n=number of nodes
    //Space Complexity O(h), h=height of tree worst case h=n, best case h=log(n)
    int ans=0;
    int helper(TreeNode* root){
        if(!root) return 0;
        int ls=helper(root->left);
        int rs=helper(root->right);
        ans+=abs(ls-rs);
        return (ls+rs+root->val);
    }
    int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
};


//Basic Solution
class Solution {
public:
    //time Complexity O(n*n) , n=number of nodes
    //Space Complexity O(h), h=height of tree worst case h=n, best case h=log(n) bcause of recursion system memory is consumed
    int sum(TreeNode* root)
    {
        if(!root) return 0;
        return (sum(root->left)+root->val+sum(root->right));
    }
    void helper(TreeNode* root,int& ans)
    {
        if(!root) return;
        int l=sum(root->left);
        int r=sum(root->right);
        ans+=abs(l-r);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        helper(root,ans);
       return ans;
    }
};

