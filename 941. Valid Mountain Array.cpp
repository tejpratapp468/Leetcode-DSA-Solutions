class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(1)
    bool validMountainArray(vector<int>& a) {
        int n=a.size();
        if(n<3) return false;
        int i=0;
        // walk up
        while(i<n-1 && a[i]<a[i+1]) i++;
        
        // peak can't be first or last
        if(i==0 || i==n-1) return false;
        
        // walk down
        while(i<n-1 && a[i]>a[i+1]) i++;
        
        if(i==n-1) return true;
        return false;
    }
};
