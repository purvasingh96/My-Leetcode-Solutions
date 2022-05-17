class Solution {
private:
    string calculatePrefix(string a, string b) {
        string prefix="";
        for(int i=0;i<min(a.length(), b.length());i++) {
            
            if(a[i]!=b[i]) return prefix;
            else{
                prefix += a[i];
            }
        }
        return prefix;    
    }
    
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string prefix = strs[0];
        
        for(int i=1;i<strs.size();i++) {
            
            prefix = calculatePrefix(prefix, strs[i]);
            
            if(prefix == "") return "";
            
        }
        
        return prefix;
    }
};