class Solution {
public:
    //Time Complexity O(nlogn)
    //Space Complexity O(n)
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        int n=plant.size();
        vector<pair<int,int>> v; //{grow,plant}
        for(int i=0;i<n;i++){
            v.push_back({grow[i],plant[i]});
        }
        sort(v.rbegin(),v.rend()); //sorting plants on the basis of grow time in descending order
        int ans=0,curr=0;
        for(int i=0;i<n;i++){  
            int growTime=v[i].first, plantTime=v[i].second;
            curr+=plantTime;
            ans=max(ans,curr+growTime);
        }
        return ans;
    }
};
