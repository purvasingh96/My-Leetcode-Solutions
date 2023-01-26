class Solution {
public:
    int strStr(string haystack, string needle) {
        int base = 26, mod=1e9+7;
        long long h=1;
        long long hhash=0, nhash=0;
        int m = haystack.length(), n = needle.length();
        
        for(int i=0;i<n-1;i++){
            h = h*base;
            h = h%mod;
        }
        
        for(int i=0;i<n;i++){
            hhash = (hhash*base + haystack[i])%mod;
            nhash = (nhash*base + needle[i])%mod;
        }
        
        for(int i=0;i<=(m-n);i++){
            if(hhash == nhash) return i;
            
            if(i<(m-n)){
                hhash = (((hhash - haystack[i]*h)*base) + haystack[i+n])%mod;
                if(hhash<0) hhash += mod;
            }
            
        }
        
        return -1;
        
    }
};