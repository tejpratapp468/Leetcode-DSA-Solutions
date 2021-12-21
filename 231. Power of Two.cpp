//method 1
class Solution {
public:
    //TC O(logn)
    //SC O(1)
    bool isPowerOfTwo(int n) {
       if(n<=0) return 0;
        while(n%2==0){
            n/=2;
        }
        return n==1;
    }
};

//method 2
class Solution {
public:
    //TC O(logn)
    //SC O(1)
    bool isPowerOfTwo(int n) {
     if(n<=0) return 0;
       int count=0;
        while(n){
            int bit=n&1; //checks if n's rightmost bit set or not
            if(bit==1) count++;
            n/=2;
        }
        return count==1;
    }
};

//method 3 : This is same as method 2 but we are using STL Functionfor counting set bits
class Solution {
public:
    //TC O(logn)
    //SC O(1)
    bool isPowerOfTwo(int n) {
     if(n<=0) return 0;
        int setBits= __builtin_popcount(n); //Using STL
        return setBits==1;
    }
};

//method 4
class Solution {
public:
    //TC O(1)
    //SC O(1)
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        bool res=(n&(n-1));
        return res==0;
    }
};

//method 5
class Solution {
public:
    //TC O(1)
    //SC O(1)
    bool isPowerOfTwo(int n) {
     if(n<=0) return 0;
      if(1073741824 % n == 0) return 1; //2^30 = 1073741824
      else return 0;
    }
};
