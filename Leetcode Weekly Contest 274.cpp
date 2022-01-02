// 2124. Check if All A's Appears Before All B's
class Solution {
public:
    //TC O(n)
    //SC O(1)
    bool checkString(string s) {
        int n=s.size();
        bool foundB=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' && foundB==1) return 0;
            if(s[i]=='b') foundB=1;
        }
        return 1;
    }
};

// 2125. Number of Laser Beams in a Bank
class Solution {
public:
    //TC O(n*m)
    //SC O(1)
    int numberOfBeams(vector<string>& b) {
        int n=b.size(), m=b[0].size();
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<m;j++){
                if(b[i][j]=='1') curr++;
            }
            if(curr>0){
               ans+=(prev*curr);
               prev=curr;
            }
        }
        
        return ans;
    }
};

//2126. Destroying Asteroids
class Solution {
public:
    //TC O(nlogn)
    //SC O(1)
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        long currMass=mass;
        for(int i=0;i<n;i++){
            if(currMass>=a[i]){
                currMass+=a[i];
            }
            else return 0;
        }
        return 1;
    }
};
