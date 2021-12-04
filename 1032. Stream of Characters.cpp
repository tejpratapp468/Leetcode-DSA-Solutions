class Trie{
    public:
    bool isLeaf;
    Trie* child[26];
    
    Trie(){
       this->isLeaf=0;
       for(int i=0;i<26;i++) this->child[i]=NULL;
    }
    
};

 Trie* buildtree(vector<string>& words,int& maxLength){
        Trie* root=new Trie();
        for(auto& s:words){
            reverse(s.begin(),s.end());
            int n=s.size();
            maxLength=max(maxLength,n);
            Trie* tmp=root;
            for(int i=0;i<n;i++){
                int p=s[i]-'a';
                if(tmp->child[p]==NULL) tmp->child[p]=new Trie();
                tmp=tmp->child[p];
            }
            tmp->isLeaf=1;
        }
        return root;
}

class StreamChecker {
public:
    Trie* root;
    deque<char> queries;  
    int maxLength;
    StreamChecker(vector<string>& words) {
        root=buildtree(words,maxLength);
    }
    
    bool query(char letter) {
        queries.push_front(letter);
        // keep in queries only the "longest word" last queries, because we don't need the other ones anymore
        if (queries.size() > maxLength) queries.pop_back();
        Trie* cur = root;
        for (char c:queries)
        {
            if (cur->isLeaf) return true;
            if (cur->child[c -'a'] == NULL) return false;
            cur = cur->child[c-'a'];
        }
        return cur->isLeaf;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */







