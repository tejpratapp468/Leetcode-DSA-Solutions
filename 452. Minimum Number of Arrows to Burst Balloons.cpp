class Solution {
public:
    //TC O(nlogn)
    //SC O(1)
    static bool sortbyend(vector<int>& p,vector<int>& q)
    {
        return p[1]<q[1];
    }
    int findMinArrowShots(vector<vector<int>>& a) {
        int n=a.size();
        if(n==0) return 0;
        sort(a.begin(),a.end(),sortbyend);
        int cnt=1,end=a[0][1];
        for(int i=1;i<n;i++)
        {
            if(end<a[i][0])
            {
                cnt++; end=a[i][1]; 
            }
        }
        return cnt;
    }
};


//sorting with lambda
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n=a.size();
        if(n==0) return 0;
        sort(a.begin(),a.end(),[](auto&p ,auto& q){
            return p[1]<q[1];
        });

        int cnt=1,end=a[0][1];
        for(int i=1;i<n;i++)
        {
            if(end<a[i][0])
            {
                cnt++; end=a[i][1]; 
            }
        }
        return cnt;
    }
};
