class Solution {
public:
    int strStr(string haystack, string needle) {
        // rabin karp
        if(haystack.length()==0 || needle.length()==0) return -1;
        
        int base = 31, n = haystack.length(), m = needle.length();
        int mod = 1e9+7;
        
        long long h = 1;
        // abcd: h(abc) = a*31^2 + b*31^1 + c*31^0 => ()
        for(int i=0;i<m-1;i++){
            h = (h*base)%mod;
        }
        
        long long sHash=0, pHash = 0;
        int j=0;
        // first iteration
        for(int i=0;i<m;i++){
            sHash = (sHash* base + haystack[i])%mod;
            pHash = (pHash*base + needle[i])%mod;
        }
        
        //cout<<sHash<<" "<<pHash;
        
        for(int i=0;i<=(n-m);i++){
            if(sHash == pHash){
                //cout<<"here";
                for(j=0;j<m;j++){
                    if(haystack[i+j] != needle[j]) break;
                }
            }
            
            if(j==m) return i;
            
            if(i < (n-m)){
                sHash = ((sHash - h*haystack[i])*base + haystack[i+m])%mod;
                if(sHash<0) sHash += mod;
            }
        }
        
        return -1;
        
    }
};