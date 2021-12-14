//Optimized solution using BST property
class Solution {
public:
    //n=number of nodes
   //h=height of tree in worst case h=n(skewed tree), best case log(n) (balanced tree)
    //Time complexity O(n)
    //Space Complexity O(h), 
    int ans=0;
    void helper(TreeNode* root,int low,int high){
       if(root==NULL) return;
        if(root->val<low) helper(root->right,low,high);
        else if(root->val>high) helper(root->left,low,high);
        else{
            ans+=root->val;
            helper(root->left,low,high);
            helper(root->right,low,high);
        }
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root,low,high);
        return ans;
    }
};

//Basic Solution 
class Solution {
public:
        //n=number of nodes
//h=height of tree in worst case h=n(skewed tree), best case log(n) (balanced tree)
    //Time complexity O(n)
    //Space Complexity O(h), 
    int ans=0;
    void inorder(TreeNode* root,int low,int high)
    {
        if(!root) return;
        inorder(root->left,low,high);
        if(root->val>=low && root->val<=high) ans+=root->val;
        inorder(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root,low,high);
        return ans;
    }
};



//Iterative Solution
class Solution {
public:
    //n=number of nodes
    //Time complexity O(n)
    //Space Complexity O(n), 
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        queue<TreeNode*> q;q.push(root);
        while(!q.empty()){
            auto f=q.front();q.pop();
            if(f==NULL) continue;
            if(f->val<low) q.push(f->right);
            else if(f->val>high) q.push(f->left);
            else{
                ans+=f->val;
                q.push(f->left);
                q.push(f->right);
            }
        }
        return ans;
    }
};
