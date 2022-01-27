//TC O(n*32)
//SC O(n*32)
class Trie{
    int val;
    Trie* child[2];
    public:
    Trie()
    {
        this->val=0;
        this->child[0]=NULL;
        this->child[1]=NULL;
    }
    
    void insert(Trie* root, int key)
    {
        Trie* tmp=root;
        for(int i=31;i>=0;i--)
        {
            bool bit=(key&(1<<i));
            if(tmp->child[bit]==NULL)
            tmp->child[bit]=new Trie();
            
            tmp=tmp->child[bit];
        }
        tmp->val=key;
    }
    
    int xorutil(Trie* root,int key)
    {
        Trie* tmp=root;
        for(int i=31;i>=0;i--)
        {
            bool bit=(key&(1<<i));
            if(tmp->child[1-bit]!=NULL) tmp=tmp->child[1-bit];
            else tmp=tmp->child[bit];
        }
        return (key xor tmp->val);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        int n=a.size();
        int ans=0;
        Trie *root=new Trie();
        for(int i=0;i<n;i++) root->insert(root,a[i]);
        for(int i=0;i<n;i++)
        {
            ans=max(ans,root->xorutil(root,a[i]));
        }
        return ans;
    }
};
