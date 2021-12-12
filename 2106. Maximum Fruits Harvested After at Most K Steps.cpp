class Solution {
public:
    //Binary search + Prefix sum
    //TC O(nlogn)
    //SC O(n)
    int helper(int p,int start,int k,vector<vector<int>>& fruits){
        int midPos=fruits[p][0];
        if(midPos!=start) k-=abs(start-midPos);
        int n=fruits.size();
        vector<int> pref(n,0);
        pref[0]=fruits[0][1];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+fruits[i][1];

        int ans=0;
        for(int i=p;i>=0;i--){  //moving first left and then right
            int currPos=fruits[i][0];
            int diff=abs(midPos-currPos);
            if(diff>k) {
                break;
            }
            int currFruits=pref[p]; //(i to p) fruits
            if(i>0) currFruits-=pref[i-1];
            int rem=k-2*diff;  //remaining distance that we can move right
            int s=p+1,e=n-1;
            int rightFruits=0;
            while(s<=e){
                int mid=s+(e-s)/2; //(s+e)/2
                currPos=fruits[mid][0];
                diff=abs(midPos-currPos);
                if(diff>rem) e=mid-1;//reduce the rang/distance that we can move in right
                else{
                    rightFruits=pref[mid]-pref[p]; //(p+1 to mid)fruits
                    s=mid+1; //we want to cover larger range in right
                }
            }
            ans=max(ans,currFruits+rightFruits);
        }
        
        for(int i=p;i<n;i++){  //moving first right and then left
            int currPos=fruits[i][0];
            int diff=abs(midPos-currPos);
            if(diff>k) {
                break;
            }
            int currFruits=pref[i]; //(p to i) fruits
            if(p>0) currFruits-=pref[p-1];
            int rem=k-2*diff; //remaining distance that we can move left
            int s=0,e=p-1;
            int leftFruits=0;
            while(s<=e){
                int mid=s+(e-s)/2;
                currPos=fruits[mid][0];
                diff=abs(midPos-currPos);
                if(diff>rem) s=mid+1;//reduce the rang/distance that we can move in left
                else{
                    leftFruits=pref[p-1]; //(mid to p-1) fruits
                    if(mid>0) leftFruits-=pref[mid-1];
                    e=mid-1;  //we want to cover larger range in left
                }
            }
            ans=max(ans,currFruits+leftFruits);
        }
        return ans;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int start, int k) {
        int n=fruits.size();     
        int p=0;
        int l=0,r=n-1;
        //position, amount
        while(l<=r){
            int mid=l+(r-l)/2;
            if(fruits[mid][0]>start){
                r=mid-1;
            }
            else{
               p=mid;l=mid+1; 
            }
        }
        int ans=0;
        if(fruits[p][0]==start){
            ans=helper(p,start,k,fruits);
        }
        else{
            ans=helper(p,start,k,fruits);
            if(p+1<n) ans=max(ans,helper(p+1,start,k,fruits));
        }
        
        return ans;
    }
};
