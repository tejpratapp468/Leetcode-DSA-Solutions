class Solution {
public:
    //p=number of characters in pattern, q=number of characters in s 
    //Space Complexity O(p+q)
    //Time Complexity O(p+q)
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        stringstream st(s);
        string temp="";
        while(st>>temp){
            v.push_back(temp);
        }
        int n=pattern.size(),m=v.size();
        if(n!=m) return 0;
        unordered_map<char,string> domain; 
        unordered_map<string,char> codomain;
        for(int i=0;i<n;i++){
            char c=pattern[i]; //v[i] is corresponding string
            if(codomain.count(v[i]) && codomain[v[i]]!=c) return 0;
            if(domain.count(c) && domain[c]!=v[i]) return 0;
            domain[c]=v[i];
            codomain[v[i]]=c;
        }
        return 1;
    }
};
