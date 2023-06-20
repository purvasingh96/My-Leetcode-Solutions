class Solution {
public:
    string minWindow(string s, string t) {
        int c=0;
        int l=0, r=0;
        string str="";
        int len = INT_MAX;
        
        unordered_map<char, int> ms;
        unordered_map<char, int> mt;
        
        for(auto c:t) mt[c] += 1;
        
        for(;r<s.length();r++){
            
            if(mt.find(s[r])!=mt.end()){
                ms[s[r]]+=1;
                if(ms[s[r]] <= mt[s[r]]){
                    c+=1;
                }
            }
            
            if(c == t.length()){
                
                while(l<r && (mt.find(s[l])==mt.end() || (ms[s[l]] > mt[s[l]]))){
                    ms[s[l]]-=1;
                    l+=1;
                    
                }
                
                if(r-l+1 < len){
                    len = r-l+1;
                    str = s.substr(l,len);
                }
                
            }
            
            
            
        }
        
        return str;
        
    }
};