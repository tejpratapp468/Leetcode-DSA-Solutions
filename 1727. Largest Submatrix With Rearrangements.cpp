Simple conversion from Largest Submatrix With Rearrangements to Largest Rectangle in Histogram
Idea:

1.for each a[i][j] cell count number of continuos 1's in its column,so we have column height of a[i][j];
2.for each row we will sort the row in descending order of column heights since you are allowed to rearrange the columns of the matrix in any order and for each row apply largest area of histogram concept to find largest area possible by row of column heights.

A Dry run of above approach
e.g. [[0,0,1],
[1,1,1],
[1,0,1]]
step 1:calculating column hegiht for each cell as:
[[0,0,1],
[1,1,2],
[2,0,3]]

step 2:for each row sort it in descending order of column heights and apply gest area of histogram concept
for row 1 we have [1,0,0] largest area=1;
for row 2 we have [2,1,1] largest area=3;
for row 3 we have [3,2,0] largest area=4;
hence our answer is 4;

Hope this help :)
Please upvote if this help;


Code:
class Solution {
public:
    int hist(int h[],int n){
        stack<int> s;
        //cout<<Jai Shree Ram
        int i=0,ans=0;
        while(i<n)
        {
            if(s.empty() || h[s.top()]<=h[i])
            {
                s.push(i++);
            }
            else
            {
                int tp=s.top();s.pop();
                int res=h[tp]*(s.empty()?i:i-s.top()-1);
                ans=max(ans,res);
            }
        }
        while(!s.empty())
        {
            int tp=s.top();s.pop();
            int res=h[tp]*(s.empty()?i:i-s.top()-1);
            ans=max(ans,res);
        }
        return ans;
    }
    int largestSubmatrix(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int v[n][m];memset(v,0,sizeof(v));
        for(int i=0;i<m;i++)
        {
            int cnt=0;int start,end;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]) cnt++;
                else cnt=0;
                v[j][i]=cnt;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            sort(v[i],v[i]+m,greater<int>());
        for(int i=0;i<n;i++)
        {
            ans=max(ans,hist(v[i],m));
        }
        return ans;
    }
};

Time Complexity: 
-Since for each a[i][j] cell count number of continuos 1's in its column,so we have column height of a[i][j], 
there are total O(n*m) cells, n=number of rows, m=number of columns
- Also for each row we will sort the row in descending order of column height, total n rows and at each row we have m cells(columns) this will take O(n*(mlogm)) 
- Also we are applying largest area of histogram concept to find largest area possible at each row row of column heights , This will take O(n*m) time.
  So overall Time complexity = O(n*m + n*(mlogm) + n*m)
  
  
 Space Complexity = O(m), since in hist function we are using stack of size m.




