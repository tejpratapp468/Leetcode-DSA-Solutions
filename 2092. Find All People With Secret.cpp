//Method 1: Greedy Min Heap Solution
class Solution {
public:
    #define pii pair<int,int>
    //Time Complexity O(MlogM + N) //M=No. of meetings , N=No. of Persons
    //Space Complexity O( N )
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> ans;
        vector<pair<int,int>> adj[n];
        for(auto& x:meetings){
            int p1=x[0],p2=x[1],tm=x[2];
            adj[p1].push_back({p2,tm});
            adj[p2].push_back({p1,tm});
        }
        
        vector<int> knowing(n,0);
        priority_queue<pii,vector<pii>,greater<pii>> pq; //[T,P]
        
        pq.push({0,0});pq.push({0,firstPerson});
        while(!pq.empty()){
            auto T=pq.top();pq.pop();
            int currT=T.first,currP=T.second;
            
            if(knowing[currP]==1) continue;
            knowing[currP]=1;
            for(auto& x:adj[currP]){
                int p=x.first,tm=x.second;
              
                if(tm>=currT && knowing[p]==0){
                    pq.push({tm,p});
                }
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(knowing[i]) ans.push_back(i);
        }
        return ans;
    }
};



//Method 2: DSU Solution (easy Solution)
class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int p){
        if(par[p]==p) return p;
        return par[p]=find(par[p]);
    }
    void Union(int a,int b)
    {
        int p1=find(a),p2=find(b);
        int u=rank[p1],v=rank[p2];
        if(u==v) par[p2]=p1,rank[p1]++;
        else if(u>v) par[p2]=p1;
        else par[p1]=p2;
    }
    
    
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    
    void reset(int a) { par[a] = a; }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;
        Union(0,firstPerson);
        
        vector<int> ans;
        sort(meetings.begin(),meetings.end(),[](vector<int>& a,vector<int>& b){
            if(a[2]<b[2]) return 1;
            return 0;
        });
        
        int m=meetings.size();
        int i=0;
        while(i<m){
           int currT=meetings[i][2]; 
            vector<int> persons;
            while(i<m && meetings[i][2]==currT){
                int a=meetings[i][0],b=meetings[i][1];
                Union(a,b);
                persons.push_back(a);
                persons.push_back(b);
                i++;
            }
            for(int& x:persons){
                if(!connected(0,x)) reset(x);
            }
        }
        for(int i=0;i<n;i++){
            if(connected(0,i)) ans.push_back(i);
        }
        return ans;
    }
};
