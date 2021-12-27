
//Brute Force Solution using map
class Solution {
public:
    //n=length of recipes, p=length of ingredients for each recipe
    //Time Complexity (n*n*p) => O(100*100*100) = O(10^6)
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string> avail{supplies.begin(),supplies.end()};
        int n=recipes.size();
        bool ok=1;
        vector<string> ans;
        unordered_map<string,int> rem;
        for(int i=0;i<n;i++) {
            rem[recipes[i]]=i;
        }
       unordered_map<string,int> temp=rem;
        
        while(ok){
            ok=0;
            temp=rem;
            for(auto& x:rem){
                bool can=1;
                string curr=x.first;
                int currIdx=x.second;
                for(string& need: ingredients[currIdx]){
                    if(avail.count(need)==0){
                        can=0;break;
                    }
                }
                if(can==1){
                    avail.insert(curr);ans.push_back(curr);
                    temp.erase(curr);
                    ok=1;
                }
            }   
            rem=temp;
        }
        
        return ans;
    }
};


//Optimal Solution Using Kahn's Algorithm for topological Sorting
class Solution {
public:
    //  v=number of recipes(nodes), e=number of dependencies(directed edges), p=length of ingredient for a recipe
    //O(v+e) + O(v*p) = O(v*v) , p can be equal to v
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string,vector<string>> graph;
        int n = rec.size();
        unordered_set<string> s;
        for(auto x : sup) s.insert(x);     //store all the supplies in unordered set
		
        unordered_map<string,int> indegree;   //to store the indegree of all recipes
        for(auto x : rec)indegree[x] = 0;    //initially take the indegree of all recipes to be 0
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int)ing[i].size(); j++){
                if(s.find(ing[i][j]) == s.end()){     
                    graph[ing[i][j]].push_back(rec[i]);    //if the ingredient required to make a recipe is not in supplies then  
                    indegree[rec[i]]++;                     //we need to make a directed edge from that ingredient to recipe
                }
            }
        }
        
        //KAHN'S ALGORITHM for topological sorting
        queue<string> q;
        for(auto x : indegree){
            if(x.second == 0){
                q.push(x.first);
            }
        }
        
        vector<string> ans;
        while(!q.empty()){
            int c = q.size();
            while(c != 0){
                string tmp = q.front();
                q.pop();
                ans.push_back(tmp);
                for(auto nbr : graph[tmp]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0)
                        q.push(nbr);
                }
                c--;
            }
        }
        return ans;
    }
};

