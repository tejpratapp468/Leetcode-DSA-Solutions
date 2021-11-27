class Solution {
public:
    //TC O(n)
    //SC O(1)
    int minimumBuckets(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='H'){
                if(i>0 && s[i-1]=='B') continue; //1st condition
                if(i<n+1 && s[i+1]=='.') { //2nd Condition
                    s[i+1]='B';ans++;
                }
                else if(i>0 && s[i-1]=='.'){ //3rd Condition
                    s[i-1]='B';ans++;
                }
                else return -1; //placing bucket is not possible for current house
            }
        }
        return ans;
    }
};
