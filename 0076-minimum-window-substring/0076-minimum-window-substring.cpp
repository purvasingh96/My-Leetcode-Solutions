class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;
        
        for(auto x:t){
            mt[x]+=1;
        }
        
        string ans="";
        int l=0, c=0, minlen=INT_MAX;
        for(int r=0;r<s.length();r++){
            if(mt.find(s[r])!=mt.end()){
                ms[s[r]]+=1;
                if(ms[s[r]] <= mt[s[r]]){
                    c+=1;
                }
                
                if(c == t.length()){
                    while(l<r && mt.find(s[l]) == mt.end() || ms[s[l]] > mt[s[l]]){
                        ms[s[l]]-=1;
                        l+=1;
                    }
                    
                    if(r-l+1 < minlen){
                        minlen = r-l+1;
                        ans = s.substr(l, minlen);
                    }
                }
            }
        }
        
        return ans;
        
    }
};