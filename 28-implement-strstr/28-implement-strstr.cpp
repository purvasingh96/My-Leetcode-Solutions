class Solution {
public:
    int strStr(string haystack, string needle) {
        // KMP algorithm
        int m = haystack.length();
        int n = needle.length();
        
        vector<int> table(n, 0);
        
        int j=0;
        
        for(int i=1;i<n;) {
            
            if(needle[i] == needle[j]) {
                
                table[i] = j+1;
                i+=1;
                j+=1;
                
            } else{
                
                if(j>0) {
                    j = table[j-1];
                } else{
                    i+=1;
                }
                
            }
            
        }
        
        
        for(int i=0, match_pos=0;i<m;) {
            
            if(haystack[i] == needle[match_pos]) {
                
                if(match_pos == n-1) {
                    
                    return (i - (n - 1));
                    
                } else{
                    
                    i+=1;
                    match_pos+=1;
                    
                }
                
            } else{
                
                if(match_pos == 0) {
                    i+=1;
                } else{
                    match_pos = table[match_pos-1];
                }
                
            }
            
            
        }
        
        return -1;
        
        
    }
};