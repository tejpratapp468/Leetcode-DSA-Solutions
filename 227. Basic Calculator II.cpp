class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(n)
    int calculate(string s) {
        int n=s.size();
        stack<int> tp;
        char op='+';long num=0;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i])) //s[i]>='0' && s[i]<='9'
                num=num*10 + s[i]-'0';
            
            if((!isdigit(s[i])&& !isspace(s[i])) || i==n-1)
            {
                if(op=='+')
                {
                    tp.push(num);
                }
                else if(op=='-')
                {
                    tp.push(-num);
                }
                else if(op=='*')
                {
                    int top=tp.top();tp.pop();
                    num=top*num;
                    tp.push(num);
                }
                else
                {
                    int top=tp.top();tp.pop();
                    num=top/num;
                    tp.push(num);
                }
                op=s[i];num=0;
            }
        }
        int ans=0;
        while(!tp.empty()){
             ans+=tp.top(),tp.pop();
        }
        
        return ans;
    }
};
