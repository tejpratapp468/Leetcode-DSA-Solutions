class Solution {
public:
    int ans=0;
    void helper(int prev,TreeNode* root){
        if(root==NULL) return;
        int curr=(prev<<1)+(root->val); //p<<i =>p*2^i
        if(root->left==NULL && root->right==NULL){ //leaf Node
            ans+=curr;return;
        }
        helper(curr,root->left);
        helper(curr,root->right);
    }
    int sumRootToLeaf(TreeNode* root) {
        int prev=0;
        helper(prev,root);
        return ans;
    }
};

/*
Time complexity:O(N), where N is a number of nodes, since we are visiting each node once.

Space complexity: O(H) for recursive calls  where H is a tree height. in balanced tree H logN, in worst case(skewed tree) H=N
*/
