//2133. Check if Every Row and Column Contains All Numbers
class Solution {
public:
    //TC O(n*n)
    //SC O(1)
    bool checkValid(vector<vector<int>>& mat) {
        int n=mat.size();
        int Xor=0;
        for(int i=1;i<=n;i++) Xor^=i;
        
        for(int i=0;i<n;i++){ //rows
            int currRow=Xor;
            for(int j=0;j<n;j++){
                currRow^=mat[i][j];
            }
            if(currRow!=0) return 0;
        }
        for(int i=0;i<n;i++){
            int currCol=Xor;
            for(int j=0;j<n;j++){
                currCol^=mat[j][i];
            }
            if(currCol!=0) return 0;
        }

        return 1;
    }
};


//2134. Minimum Swaps to Group All 1's Together II
class Solution {
public:
    //TC O(n+n)=O(n)
    //SC O(1)
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnto=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnto++;
            }
            if(i>0) nums[i]+=nums[i-1];
        }
        if(cnto==0) return 0;
        int ans=1e8;
        for(int i = 0; i < n; i++){
            int j=i+cnto-1;
            int curr=0;
            if(j<n){
                curr=nums[j];
                if(i>0) curr-=nums[i-1];
            }
            else{
                curr=nums[n-1];
                if(i>0) curr-=nums[i-1];
                j=j%n;
                curr+=nums[j];
            }
           
            ans=min(ans,cnto-curr);
        }      
           
        return ans;
    }
};
