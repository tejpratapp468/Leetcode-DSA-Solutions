//Solution using concept of largest rectangular area in histogram
class Solution {
public:
    //n=no. of rows, m=no.cols
    //Time Complexity O(n*m + n*m) = O(n*m)
    //Space Complexity O(m)
    int largestRectangleArea(vector<int>& h) {
       int m=h.size();
       stack<int> s;
        int i=0,ans=0;
        while(i<m)
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
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n==0) return 0;
        int m=mat[0].size();
        int ans=0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){         
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0') {
                   height[j]=0;
                }
                else height[j]=height[j]+1;
            }
            
            int curr=largestRectangleArea(height);
            ans=max(ans,curr);
        }
        return ans;
    }
};

//Brute force Solution
class Solution {
public: 
    //n=no. of rows, m=no.cols
    //Time Complexity O(n*m*n)
    //Space Complexity O(n*m)
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size();
        if(n==0) return 0;
        int m=mat[0].size();
        int ans=0;
        vector<vector<int>> v(n,vector<int>(m,0));
        //Maintaining right to left continuous 1's sum
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]=='1') {
                    v[i][j]=1;
                    if(j<m-1) v[i][j]+=v[i][j+1];
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]>=1){
                    int width=v[i][j];
                    int k=i;
                    while(k<n && v[k][j]>0){
                         width=min(width,v[k][j]);
                         int length=k-i+1;
                         ans=max(ans,width*length);
                         k++;
                    }
                }
            }
        }
        return ans;;
    }
};






