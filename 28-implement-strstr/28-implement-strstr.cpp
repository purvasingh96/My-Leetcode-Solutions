class Solution {
private:
    vector<int> generateLPS(string sub){
        int n = sub.length();
        vector<int> lps(n,0);
        
        for(int i=1,j=0;i<n;){
            if(sub[i] == sub[j]){
                lps[i]=j+1;
                i+=1;
                j+=1;
            } else{
                if(j>0) {
                    j = lps[j-1];
                } else{
                    i+=1;
                }
            }
        }
        
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        auto lps = generateLPS(needle);
        int n = haystack.length();
        
        for(int i=0,j=0;i<n;){
            
            if(haystack[i] == needle[j]){
                i+=1;
                j+=1;
            } else{
                
                if(j>0){
                    j = lps[j-1];
                } else{
                    i+=1;
                }
                
            }
            
            if(j == needle.length()){
                return i-j;
            }
            
        }
        
        return -1;
    }
};