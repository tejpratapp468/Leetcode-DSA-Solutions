//Binary Search SOlution Most optimal
class Solution {
public:
    //TC O(logn)    
    //SC O(1)
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int pos=-1;
        while(l<=r){
            int mid=l+(r-l)/2; //(l+r)/2
            int curr=nums[mid];
            if(curr==target) return mid;
            if(curr<target) l=mid+1;
            else{
                pos=mid;r=mid-1;
            }
        }
        if(pos==-1) pos=n;
        return pos;
    }
};


//method 2 SOlution with help of STL
class Solution {
public:
    //TC O(logn)
    //SC O(1)
    int searchInsert(vector<int>& nums, int target) {
        int pos=lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return pos;
    }
};

//Brute Force SOlution
class Solution {
public:
    //TC O(n)
    //SC O(1)
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target) return i;
            else if(nums[i]>target){
               return i;
            }
        }
        int pos=n;
        return pos;
    }
};
