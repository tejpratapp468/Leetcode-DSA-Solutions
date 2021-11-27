//Optimal O(n) time and O(1) space Solution
class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        //ans[i]=left[i-1]*[righti+1]
        // Calculate lefts products in left  and store in ans[i]
        int left=1;
        for(int i=0;i<n;i++){
            if(i>0) left=left*nums[i-1];
            ans[i]=left;
        }
        
        // Calculate rights product in right from end of array and multiplying with ans[i]
        int right=1;
        for(int i=n-1;i>=0;i--){
            if(i<n-1) right=right*nums[i+1];
            ans[i]=ans[i]*right;
        }
        return ans;
    }
};

//Method 2
class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> left(n),right(n);
        left[0]=nums[0],right[n-1]=nums[n-1];
        for(int i=1;i<n;i++) left[i]=nums[i]*left[i-1];
        for(int i=n-2;i>=0;i--) right[i]=nums[i]*right[i+1];
        
        for(int i=0;i<n;i++){
            int p=1;
            //ans[i]=left[i-1]*right[i+1]
            if(i>0) p=p*left[i-1];
            if(i<n-1) p=p*right[i+1];
            ans[i]=p;
        }
        return ans;
    }
};


//Method 3 Brute force
class Solution {
public:
     //Time Complexity O(n*n)
    //Space Complexity O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int p=1;
            for(int j=0;j<n;j++){
                if(j!=i) p*=nums[j];
            }
            ans[i]=p;
        }
        return ans;
    }
};
