class Solution {
public:
    int minCost(vector<int>& start, vector<int>& home, vector<int>& rowCosts, vector<int>& colCosts) {
        int sx=start[0],sy=start[1];
        int ex=home[0], ey=home[1];
        int ans=0;
        
        //covering rows
        if(sx<ex){ //move from up to down
           while(sx<ex){ 
             ans+=rowCosts[sx+1];sx++;
          } 
        }
        else if(sx>ex){ //move from down to up
             while(sx>ex){
               ans+=rowCosts[sx-1];sx--;
             }
        }
        
        //covering columns
        if(sy<ey){ //move from left to right
            while(sy<ey){ 
              ans+=colCosts[sy+1];sy++;
            }
        }
        else if(sy>ey){ //move from right to left
             while(sy>ey){ 
               ans+=colCosts[sy-1];sy--;
             }
        }
            
        return ans;
    }
};
