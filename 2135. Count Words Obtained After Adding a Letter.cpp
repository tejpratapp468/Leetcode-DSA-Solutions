class Solution {
public:
    //m=number of strings in startWord, n=number of stringsin target word
    //Time Complexity O(mlogm+ nlogn + n*26)
    //Space Complexity O(m)
    int wordCount(vector<string>& start, vector<string>& target) {
        int ans=0;
        for(auto& x:start) sort(x.begin(),x.end());
        for(auto& x:target) sort(x.begin(),x.end());
        set<string> st{start.begin(),start.end()};
        
        for(string& s:target){
            bool ok=0;
            for(int i=0;i<s.size();i++){ //"acit"
                string curr=s.substr(0,i)+s.substr(i+1); //a+it =ait
                if(st.count(curr)){
                    ok=1;break;
                }
            }
            if(ok==1) ans++;
        }
        return ans;
    }
};
