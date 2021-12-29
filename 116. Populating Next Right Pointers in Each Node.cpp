//Optimal Solution O(N) Time & O(1) Space
class Solution {
public:
    //Time Complexity O(N)
    //Space Complexity O(1)
   Node* connect(Node *root) {
    if (root == NULL) return root;
    Node *pre = root;
    Node *curr = NULL;
    //we check pre->left bcz given tree is perfect binary tree 
    while(pre->left) {
        curr=pre;
        while(curr){
            curr->left->next=curr->right;
            if(curr->next) curr->right->next=curr->next->left;
            curr=curr->next;
        }
        pre=pre->left;
     }
     return root;
  }
};

//Solution with O(N) Time & O(N) Space
class Solution {
public:
    //Time Complexity O(n*2) = Tc (n)
    //Space Complexity O(n)
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=1;i<=s;i++){
                auto f=q.front();q.pop();
                
                if(i<s)f->next=q.front();
                else f->next=NULL;
                
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return root;
    }
};
