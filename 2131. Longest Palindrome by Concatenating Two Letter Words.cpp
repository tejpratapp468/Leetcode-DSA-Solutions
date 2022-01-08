class Solution {
public:
    //n=number of strings
    //Time Complexity O(n+n) =O(n)
    //Space Complexity O(n)  
    int longestPalindrome(vector<string>& words) {
       
        unordered_map<string,int> avail;
        int res = 0;
        for(auto &s:words)
        {
            string p = s;
            reverse(p.begin(),p.end());
            string rev=p;
            if(avail[rev]>0)
            {
                res+=4;
                avail[rev]--;
            }
            else{
                avail[s]++;
            }
        }
        for(auto &c:avail)
        {
            string s=c.first;
            int cnt=c.second; 
            if(c.second>0 && s[0]==s[1])
            {
                res+=2;
                break;
            }
        }
        return res;
    }
};


