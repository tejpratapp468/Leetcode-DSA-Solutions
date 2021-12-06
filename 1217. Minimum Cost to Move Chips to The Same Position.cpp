class Solution {
public:
    //Time Complexity O(N)
    //Space Complexity O(1)    
    int minCostToMoveChips(vector<int>& pos) {
        int n=pos.size();
        int oddPos=0,evenPos=0;
        for(int x:pos){
            if(x%2==0) evenPos++;
            else oddPos++;
        }
        int ans=min(oddPos,evenPos);
        return ans;
    }
};
