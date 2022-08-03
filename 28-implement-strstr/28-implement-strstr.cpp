class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length()==0 || needle.length()==0) return -1;
        
        int base = 31, m = needle.length(), n = haystack.length();
        int mod = 1e9+7;
        
        long long h=1;
        
        for(int i=0;i<m-1;i++){
            h = ((long long)(h*base))%mod;
        }
        
        long long pHash=0, sHash=0;
        
        // calculate for first iteration
        for(int i=0;i<m;i++){
            //cout<<(251+needle[i])<<"\n";
            pHash = (base*pHash + needle[i])%mod;
            sHash = (base*sHash + haystack[i])%mod;
        }
        
        //cout<<sHash<<" "<<pHash;
        
        int j=0;
        
        for(int i=0;i<=(n-m);i++){
            if(pHash == sHash) {
                for(j=0;j<m;j++){
                    if(haystack[i+j] != needle[j]) break;
                }
            }
            
            if(j==m) return i;
            
            if(i<(n-m)){
                sHash = (sHash - h*haystack[i]);
                sHash = sHash%mod;
                sHash *= base;
                sHash = sHash%mod;
                sHash += haystack[i+m];
                if(sHash<0) sHash+=mod;
            }
            
        }
        
        return -1;
        
    }
};