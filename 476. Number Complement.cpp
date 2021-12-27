class Solution {
public:
    //Time Complexity O(logn)
    //Space Complexity O(1)
    int findComplement(int n) {
        if(n==0) return 1;
        int ans=0,p=1;
        while(n){
            int bit=n&1;
            if(bit==0) ans+=p;
            p<<=1; //p*=2  //p<<=i => p*(2^i)
            n>>=1; // n/=2 //n>>=i // n/(2^i)
        }
        return ans;
    }
};
