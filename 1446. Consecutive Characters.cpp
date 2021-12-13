class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(1)
    int maxPower(string s) {
        int n=s.size();
        int ans=1,count=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) count++;
            else count=1;
            ans=max(ans,count);
        }
        return ans;
    }
};
