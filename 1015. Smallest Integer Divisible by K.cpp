class Solution {
public:
    //Time Complexity O(k)
    //Space Complexity O(1)
    int smallestRepunitDivByK(int k) {
        int unitD=k%10;
        if(unitD==0 || unitD==2 || unitD==4 || unitD==6 || unitD==8) return -1;  //we can write line 7 of our code as: if(k%2==0) return -1;
        if(k==1) return 1;
        long rem=0;
        for(int i=1;i<=k;i++)
        {
            rem=(rem*10 +1)%k;
            if(rem==0) return i;
        }
        return -1;
    }
};
