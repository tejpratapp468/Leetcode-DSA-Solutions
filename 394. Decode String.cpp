//Recursive Solution
class Solution {
public:
    //n=length of string
    //Time Complexity O(n)
    //SPace Complexity O(n)
    string decodeString(string s) {
        int i=0;
        return help(s,i);
    }
    string help(string& s,int& i)
    {
        string ans="";
        while(i<s.size() && s[i]!=']') 
        {
            if(isalpha(s[i])) //s[i]>='a' && s[i]<='z'
                ans+=s[i++];
            else
            {
                int d=0;
                while(isdigit(s[i])) d=(d*10)+(s[i++]-'0'); //s[i]>='0' && s[i]<='9'
                i++; //[
                string tp=help(s,i);
                i++; //]
                while(d--) ans+=tp;
            }
        }
        return ans;
    }
};

//Stack Solution
class Solution {
public:
    //n=length of string
    //Time Complexity O(n)
    //SPace Complexity O(n)
    string decodeString(string s) {
        int n=s.size();
        stack<int> nums;
        stack<string> st;
        string ans="",res="";int d=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='['){
                nums.push(d);
                st.push(ans);
                d=0;ans="";
            }
            else if(s[i]==']'){
                int g=nums.top();nums.pop();
                res=st.top();st.pop();
                while(g--)
                    res+=ans;
                ans=res;
            }
            else if(isdigit(s[i])){
                 d=d*10+(s[i]-'0');
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};
