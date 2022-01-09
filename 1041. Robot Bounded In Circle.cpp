class Solution {
public:
    //TC O(n) n=number of Instructions in Order
    //SC O(1)
    bool isRobotBounded(string instructions) {
        char dir='N';  // E,W,N,S
        int x=0,y=0;
        for(char c:instructions){
            if(c=='G'){
                if (dir=='N') y += 1;
                else if (dir=='S') y-=1;
                else if(dir=='E') x += 1;
                else x-= 1;
            }
            
            else if(c=='L'){
                if(dir=='N') dir='W';
                else if(dir=='S') dir='E';
                else if(dir=='E') dir='N';
                else dir='S';
            }
            
            else{ //c=='R'
                if(dir=='N') dir='E';
                else if(dir=='S') dir='W';
                else if(dir=='E') dir='S';
                else dir='N';
            }
        }
        if(x==0 && y==0) return 1;
        if(dir!='N') return 1;
        return 0;
    }
};
