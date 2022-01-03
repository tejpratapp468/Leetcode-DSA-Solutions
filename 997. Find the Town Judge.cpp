//Method 1
class Solution {
public:
    //TC O(n+n)=O(n)
    //SC O(n+n) =O(n)
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustedByPeople(n+1,0);
        vector<int> trusting(n+1,0);
        for(auto& x: trust){
           trustedByPeople[x[1]]++; //x={a,b}
           trusting[x[0]]++; 
        }
        for(int i=1;i<=n;i++){
            if(trustedByPeople[i]==n-1 && trusting[i]==0) return i;
        }
        return -1;
    }
};

//Method 2
class Solution {
public:
    //TC O(n+n)=O(n)
    //SC O(n)
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n+1,0);
        for(auto& x: trust){
           trustScore[x[1]]++; //x={a,b}
           trustScore[x[0]]--; 
        }
        for(int i=1;i<=n;i++){
            if(trustScore[i]==n-1) return i;
        }
        return -1;
    }
};
