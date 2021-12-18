class Solution {
public:
    //digitsN=number of digits in N, choices=length of digits array
//Time Complexity O((digitsN*choices)*logN) = (81*logN) = O(logN) bcz 81 is constant
    //Space Complexity O(1)
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string NS = to_string(N);
        int digit = NS.size(), choices = D.size(), ans = 0;
        
        for (int i = 1 ; i < digit ; ++i)
            ans += pow(choices, i);
        
        for (int i = 0 ; i < digit ; ++i) { //56  [2,5,6]
            bool hasSameNum = false;
            for (string &d : D) {
                if (d[0] < NS[i]) 
                {
                    //cout<<d[0]<<" "<<NS[i]<<endl;
                    ans += pow(choices, digit - i - 1);
                }
                else if (d[0] == NS[i]) 
                    hasSameNum = true;
            }
            if (!hasSameNum) return ans;
        }               
        return ans+1; //If the elements of D can compose entired N, answer + 1
    }
};

