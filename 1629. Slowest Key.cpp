class Solution {
public:
    char slowestKey(vector<int>& relT, string keyP) {
        int n=keyP.size();
        unordered_map<char,int> mp;
        int mxT=0; //track maxpress dur
        for(int i=0;i<n;i++){
            char x=keyP[i];
            if(i==0){
                mp[x]=relT[i];
            }else{
                mp[x]=max(mp[x],relT[i]-relT[i-1]);
            }
            mxT=max(mxT,mp[x]);
        }
        char ans='0';
        for(auto x:mp){
            char key=x.first;
            int time=x.second;
            if(time==mxT){
                if(ans=='0') ans=key;
                else ans=max(ans,key);//lexi largest ans
            }
        }
        return ans;
    }
};
