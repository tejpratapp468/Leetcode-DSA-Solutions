//Optimal Solution Using Prefix and Suffix Array
class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(n)
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
        int n=sec.size();
        vector<int> leftInc(n,0),rightInc(n,0);
        int cnt=0;
        for(int i=1;i<n;i++){
            if(sec[i]<=sec[i-1]){
                cnt++;
                leftInc[i]=cnt;
            }
            else cnt=0;
        }
        cnt=0;
        for(int i=n-2;i>=0;i--){
            if(sec[i]<=sec[i+1]){
                cnt++;
                rightInc[i]=cnt;
            }
            else cnt=0;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(leftInc[i]>=time && rightInc[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};


//brute force Solution
class Solution {
public:
    //Time Complexity O(n*n)
    //Space Complexity O(1)
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
        int n=sec.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int leftInc=0,rightInc=0;
            int prev=sec[i];
            for(int j=i-1;j>=0;j--){
                int curr=sec[j];
                if(curr>=prev) {
                    leftInc++;prev=curr;
                }
                else break;
            }
            prev=sec[i];
            for(int j=i+1;j<n;j++){
                int curr=sec[j];
                if(curr>=prev) {
                    rightInc++;prev=curr;
                }
                else break;
            }
            if(leftInc>=time && rightInc>=time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
