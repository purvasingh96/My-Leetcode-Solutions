class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m = haystack.length(), n = needle.length(), base=26;
        int mod = 1e9+7,j;
        
        if(m==0 || n==0) return -1;
        
        long long h=1;
        
        for(int i=0;i<n-1;i++){
            h = (h*base);
            h = h%mod;
        }
        
        long long sHash=0, pHash=0;
        
        for(int i=0;i<n;i++){
            sHash = (sHash*base + haystack[i])%mod;
            pHash = (pHash*base + needle[i])%mod;
        }
        
        for(int i=0;i<=(m-n);i++){
            if(sHash == pHash){
                for(j=0;j<n;j++){
                    if(haystack[i+j] != needle[j]) break;
                }
                
                if(j==n) return i;
            }
            
            if(i<(m-n)){
                
                sHash = ((sHash - h*haystack[i])*base + haystack[i+n])%mod;
                if(sHash<0) sHash += mod;
                
            }
        }
        
        return -1;
        
    }
};