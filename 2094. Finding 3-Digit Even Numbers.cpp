class Solution {
public:
    //Time Complexity O(n + 900)
    //SC O(10)
    vector<int> findEvenNumbers(vector<int>& a) {
        int n=a.size();
        vector<int> ans;
      vector<int> mp(10,0); //vector<int> mp(10);
        for(auto x:a)mp[x]++;
        for(int i=100;i<=999;i++){
            string s=to_string(i);
            vector<int> v(10,0); //constant space O(10)
            int d1=s[0]-'0',d2=s[1]-'0',d3=s[2]-'0';
            v[d1]++,v[d2]++,v[d3]++;
            if(mp[d1]>=v[d1] && mp[d2]>=v[d2] && mp[d3]>=v[d3]){
                if(i%2==0) ans.push_back(i);
            }
        }
        return ans;
    }
};
