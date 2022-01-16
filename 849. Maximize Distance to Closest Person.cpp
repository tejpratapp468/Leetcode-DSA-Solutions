//method 1
class Solution {
public:
    //TC O(n+n+n)=O(n)
    //SC O(n+n)=O(n)
    int maxDistToClosest(vector<int>& seats) {
       int n=seats.size();
       vector<int> left(n,n),right(n,n);

       for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) left[i] = 0;
            else if (i > 0) left[i] = left[i-1] + 1;
        }

        for (int i = n-1; i >= 0; --i) {
            if (seats[i] == 1) right[i] = 0;
            else if (i < n-1) right[i] = right[i+1] + 1;
        }
     
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
             if (seats[i] == 0){
                 int res=min(left[i],right[i]);
                 ans = max(ans, res);
             }
        }
        return ans;
    }
};

//Method 2 with O(1) Space
class Solution {
public:
    //TC O(n)
    //SC O(1)
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int ans=0;
        int cnt=0,first=0,last=0;
        if(seats[0]==1) first=1;
        for(int i=0;i<n;i++)
        {
            if(seats[i]==0) cnt++;
            else{
                if(first==0){
                    ans=cnt;first=1;
                }
                else{
                    ans=max(ans,(cnt+1)/2);
                }
                cnt=0;
            }
            if(i==n-1 && cnt>0) last=cnt;
        }
        ans=max(ans,last);
        return ans;
    }
};
