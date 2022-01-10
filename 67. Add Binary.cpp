class Solution {
public:
    //Time Complexity O(n+m)
    //Space Complexity O(1)
    string addBinary(string a, string b) {
        int n=a.size(), m=b.size();
        string ans="";
        int i=n-1,j=m-1, carry=0;
        while(i>=0 || j>=0){
            int sum=0;
            if(i>=0) sum+=(a[i]-'0'); //we will get integer c-'0'
            if(j>=0) sum+=(b[j]-'0');
            sum+=carry;
            int uD=sum%2;
            carry=sum/2;
            char d=uD+'0';  // we will get char from int , int+'0'
            ans=d+ans;
            if(i>=0) i--;
            if(j>=0) j--;
        }
        if(carry>0) ans=('1')+ans;
        return ans;
    }
};
