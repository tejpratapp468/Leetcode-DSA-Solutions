class LockingTree {
public:
    vector<int> adj[2001];
    vector<int> lockStatus;;
    int n;
    vector<int> par;
    
    void checkDesLock(int src,bool& ok){ //condition 2
        for(auto x:adj[src]){
            if(lockStatus[x]>0){
                ok=1;
            }
            checkDesLock(x,ok);
        }
    }
    
    void   unlock(int src){
        for(auto x:adj[src]){
            if(lockStatus[x]>0) lockStatus[x]=0;
              unlock(x);
        }
    }
    
    void checkAncestor(int src,bool& ok){ //condition 3
        while(par[src]!=-1){
            int x=par[src];
            if(lockStatus[x]>0) ok=0;
            src=x;
        }
    }
    
    LockingTree(vector<int>& parent) {
        n=parent.size();
        par=parent;
        lockStatus.resize(n+5,0);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(lockStatus[num]==0){
            lockStatus[num]=user;return 1;
        }
        return 0;
    }
    
    bool unlock(int num, int user) {
        if(lockStatus[num]==user){
            lockStatus[num]=0;return 1;
        }
        return 0;
    }
    
    bool upgrade(int num, int user) {
        if(lockStatus[num]>0) return 0;//condition 1
        bool ok=0;
        checkDesLock(num,ok); //condition 2
        if(ok==0) return 0;
        ok=1;
        checkAncestor(num,ok);//condition 3
        if(ok==0) return 0;
          unlock(num);
        lockStatus[num]=user;
        return 1;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lockStatus(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
